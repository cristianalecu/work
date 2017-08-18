
rem C:\Users\cna\AppData\Local\Android\sdk\platform-tools>adb devices
rem C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE>adb devices

IF EXIST platforms\android\NUL goto AFTER_INTALL

cordova platform add android

:AFTER_INTALL

call ionic cordova build android

ionic cordova run android --MNHQGUHUY5O7NRAU
