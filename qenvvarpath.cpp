#include "qenvvarpath.h"

#include <QDebug>
#include <QChar>
#include <QString>
#include <QStringList>
#include <QMap>

#include <windows.h>
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "user32.lib")

#define LIMIT_REGISTRY_VALUE_LENGTH 16383 // refer to msdn, win32 api

QEnvVarPath::QEnvVarPath() {  }

QEnvVarPath::~QEnvVarPath() {  }

namespace str {

class Info {
public:
    HKEY hKey;
    LPCWSTR pathRegEnv;
    QString OpenFailed;
    QString QueryFailed;
    QString SetFailed;
    Info(HKEY inKey, LPCWSTR iPath, QString iOpenFailed, QString iQueryFailed, QString iSetFailed) :
        hKey(inKey), pathRegEnv(iPath), OpenFailed(iOpenFailed),
        QueryFailed(iQueryFailed), SetFailed(iSetFailed) { }

};
static QString OpenFailed("Failed to access the 'Path' ");
static QString QueryFailed("Failed to query the 'Path' ");
static QString SetFailed("Failed to set the new 'Path' ");

static QString SysSuffix("from Sys Env ");
Info Sys(
        HKEY_LOCAL_MACHINE,
        L"SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment",
        str::OpenFailed + str::SysSuffix,
        str::QueryFailed + str::SysSuffix,
        str::SetFailed + str::SysSuffix);

static QString UsrSuffix("from Usr Env ");
Info Usr(
        HKEY_CURRENT_USER,
        L"Environment",
        str::OpenFailed + str::UsrSuffix,
        str::QueryFailed + str::UsrSuffix,
        str::SetFailed + str::UsrSuffix);
};

bool QEnvVarPath::Success = true;
bool QEnvVarPath::Failure = false;

static bool setCore(/*in*/const QStringList & strList, str::Info & tInfo) {
    HKEY key;
    LONG retval;
    DWORD dwBUFS = 0;
    BYTE *buf;
    QString newStrPath;
    int lenNewStrPath;

    retval = RegOpenKeyEx(tInfo.hKey, tInfo.pathRegEnv,
                          0, KEY_ALL_ACCESS, &key);
    if(retval != ERROR_SUCCESS) {
        qDebug() << tInfo.OpenFailed;
        return QEnvVarPath::Failure;
    }

    newStrPath = strList.join(';');
    lenNewStrPath = newStrPath.length();
    buf = new BYTE[LIMIT_REGISTRY_VALUE_LENGTH];
    QChar *newStrPathPt = (QChar *)newStrPath.unicode();
    for(int i = 0; i < lenNewStrPath; ++i) {
        buf[i*2] = newStrPathPt[i].unicode();
        buf[i*2 + 1] = '\0';
    }
    dwBUFS = lenNewStrPath * 2;

    retval = RegSetValueEx(key, L"Path", NULL,
                           REG_EXPAND_SZ, buf, dwBUFS);
    delete [] buf;
    RegCloseKey(key);

    if(retval != ERROR_SUCCESS) {
        qDebug() << tInfo.SetFailed;
        return QEnvVarPath::Failure;
    }

    SendMessageTimeout(HWND_BROADCAST, WM_SETTINGCHANGE, NULL,
                       (LPARAM)L"Environment", SMTO_ABORTIFHUNG, 50, NULL);

    return QEnvVarPath::Success;

}

static bool getCore(/*out*/QStringList & strList, str::Info & tInfo) {
    HKEY key;
    LONG retval;
    DWORD dwType = REG_EXPAND_SZ;
    DWORD dwBUFS = LIMIT_REGISTRY_VALUE_LENGTH;
    BYTE * buf = new BYTE[LIMIT_REGISTRY_VALUE_LENGTH];
    QString retStrPath;

    retval = RegOpenKeyEx(tInfo.hKey, tInfo.pathRegEnv,
                          0, KEY_ALL_ACCESS, &key);

    if(retval != ERROR_SUCCESS) {
        delete [] buf;
        qDebug() << tInfo.OpenFailed;
        return QEnvVarPath::Failure;

    }

    retval = RegQueryValueEx(key, L"Path", NULL, &dwType, buf, &dwBUFS);

    if(retval != ERROR_SUCCESS) {
        delete [] buf;
        qDebug() << "getCore: " << tInfo.QueryFailed;
        RegCloseKey(key);
        return QEnvVarPath::Failure;
    }

    RegCloseKey(key);

    for(uint i = 0; i < dwBUFS; i += 2) {
        QChar qchar = QChar((unsigned short)(*(buf + i)));
        if(qchar.isNull() == false)
            retStrPath.append(qchar);
        else
            break;
    }

    delete [] buf;

    strList = retStrPath.split(';');
    return QEnvVarPath::Success;
}

bool QEnvVarPath::setSys(/*in*/const QStringList & strList){
    return setCore(strList, str::Sys);
}

bool QEnvVarPath::getSys(/*out*/QStringList & strList) {
    return getCore(strList, str::Sys);
}

bool QEnvVarPath::setUsr(/*in*/const QStringList & strList) {
    return setCore(strList, str::Usr);
}

bool QEnvVarPath::getUsr(/*out*/QStringList & strList) {
    return getCore(strList, str::Usr);
}
