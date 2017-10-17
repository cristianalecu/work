
IF NOT EXIST www\NUL md www

IF EXIST node_modules\NUL goto AFTER_INTALL

call npm install


rem call npm install @ngx-translate/core @ngx-translate/http-loader --save
:AFTER_INTALL
ionic serve