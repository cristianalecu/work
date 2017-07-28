rem call  npm install -g cordova ionic
rem call  npm install -g angular-cli

rem call npm config set proxy http://192.168.1.29:8080
rem call npm config set https-proxy http://192.168.1.29:8080
rem call npm config set strict-ssl false
set PROXY=http://192.168.1.29:8080 

rem ionic start myApp blank   --v2
rem ionic start myApp tabs   --v2
rem ionic start ionDebugMenu sidemenu --v2
ionic start MoaraTintar sidemenu --v2

cd MoaraTintar

ionic serve
