
rem C:\Users\cna\AppData\Local\Android\sdk\platform-tools>adb devices
rem C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE>adb devices

IF EXIST platforms\android\NUL goto AFTER_PLATFORM

cordova platform add android

:AFTER_PLATFORM

call ionic cordova plugin rm cordova-plugin-console

call ionic cordova build --release android

"C:\Program Files\Java\jre1.8.0_111\bin\keytool.exe" -genkey -v -keystore TintarMill.keystore -alias TintarMill -keyalg RSA -keysize 2048 -validity 10000

"C:\Program Files\Java\jdk1.8.0_111\bin\jarsigner" -verbose -sigalg SHA1withRSA -digestalg SHA1 -keystore TintarMill.keystore build\outputs\apk\android-release-unsigned.apk TintarMill

C:\Users\cna\AppData\Local\Android\sdk\build-tools\25.0.3\zipalign -v 4 build\outputs\apk\android-release-unsigned.apk TintarMill.apk