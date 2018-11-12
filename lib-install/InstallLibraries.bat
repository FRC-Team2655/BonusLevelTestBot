@echo off
xcopy %~dp0\lib %userprofile%\wpilib\user\cpp\lib /e /d /y /h /r /c
xcopy %~dp0\include %userprofile%\wpilib\user\cpp\include/e /d /y /h /r /c
echo "RESTART ECLIPSE!!!"
pause