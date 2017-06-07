
IF NOT EXIST www\NUL md www

IF EXIST node_modules\NUL goto AFTER_INTALL

call npm install

<<<<<<< HEAD
=======
rem call npm install @ngx-translate/core @ngx-translate/http-loader --save

>>>>>>> afc00cc3e8648d3fb7ee56be10c291e5bcd093b6
:AFTER_INTALL
ionic serve