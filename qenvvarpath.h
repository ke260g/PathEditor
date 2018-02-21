#ifndef QENVVARPATH_H
#define QENVVARPATH_H

#include <QStringList>
class QEnvVarPath
{
public:
    static bool Success;
    static bool Failure;
    static bool setUsr(/*in*/const QStringList & strList);
    static bool getUsr(/*out*/QStringList & strList);

    static bool setSys(/*in*/const QStringList & strList);
    static bool getSys(/*out*/QStringList & strList);

private:
    QEnvVarPath();
    ~QEnvVarPath();
};

#endif // QENVVARPATH_H
