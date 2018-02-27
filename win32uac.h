#ifndef WIN32UAC_H
#define WIN32UAC_H

// some method for user access control in win32:
// method:
//  1. selfELevation, to kacquire Administrative Privileges
class WIN32UAC {
private:
    WIN32UAC();
    ~WIN32UAC();
public:
    static bool isRunAsAdmin();
    static bool elevate();
};
void g();
#endif // WIN32UAC_H
