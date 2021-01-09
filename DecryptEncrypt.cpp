//abadon all hope, those who enter here
#define ll long long
#include <iostream>
#include <string>

using namespace std;

string encrypt(string text) {
	int len = text.length();
	for (int i = 0; i < len; i++)
	{
		text[i]++;
	}
	return text;
}
string decrypt(string text) {
	int len = text.length();
	for (int i = 0; i < len; i++)
	{
		text[i]--;
	}
	return text;
}


int main() {
	string text;
	cout << "\'d\'= decrypt, \'e\' = encrypt, and after that your text (usage: d something)\n ";
	while (true)
	{
		char switcH;
		cin >> switcH;
		if (switcH == 'd')
		{
			getline(cin, text);
			text.erase(0, 1);
			cout << decrypt(text);
		}
		else if (switcH == 'e')
		{
			getline(cin, text);
			text.erase(0, 1);
			cout << encrypt(text);
		}
		else
		{
			cout << "Wrong char!\n";
			continue;
		}
			cout << "\n\n";
	}

	
	

	return 0;
}
