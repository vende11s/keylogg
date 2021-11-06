# Keylogg
## Description
* Keylogger that sends you it logs to telegram channel
## Using
* [Create and set a telegram bot](#Create-and-set-a-telegram-bot)
* [Set const variables](#Set-const-variables)
* [Compile](#Compile)
* [Install on victim pc](#install-on-victim-pc)
* [Autostart](#Autostart)
* [About project](#About-Project)
* [Disclaimer](#Disclaimer)

### Create and set a telegram bot
#### Create your bot
* First in Telegram's search bar write `@BotFather`
* In chat with `BotFather` text him `/newbot`
* Name your bot
* `BotFather` will send you your api token, save it somewhere, you'll need it later
* Text to BotFather `/setprivacy`
* Choose your bot
* Text him `Disable`
#### Create a channel
* Create a new channel
* Add your bot as admin

### Set const variables
* First send any message on your telegram channel
* Then go to `https://api.telegram.org/bot<api Token>/getUpdates` and find `"id"` 
* Your token is [there](#Create-and-set-a-telegram-bot) 
* After that set `keylogg.hpp - > BOTAPI` as your api token
* And `keylogg.hpp -> CHAT_ID` as your id that you find before
* Set `keylogg.hpp -> LOGFILENAME` as name of file where logs will be

### Compile
* To directory with repo put [cpr](https://github.com/whoshuu/cpr) lib
#### MSVC
* Create project with `keylogg.hpp` and `main.cpp`
* Go to Project -> <Project Name> propeties -> Advanced -> Character Set -> Use Multi-Byte
* Compile
* If you have problem with compiling or anything else DM me on Discord (my tag is in github profile description)
 
 ### Install on victim pc
* Put it anywhere you want (If you have turned on [autostart](#autostart) it will copy itself to %temp% else you have to hide it manually and add it to autostart)
* Run it
* enjoy unethical but beautiful spying!
 
 ### Autostart
* you can put your executable whenever you want, it will automaticly copy it self to %temp% and add to autostart
 
 ### About Project
 Actually I'm developing it solo but if you want to help me with this half shitty and half stackoverflow code text me on discord (my tag in github profile description), if you have any problems with using this soft text me too
 
### Disclaimer
Whole this project is only for eductional purposes, I am not responsible for anything you did or will do with this software

