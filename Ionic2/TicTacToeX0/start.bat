
IF NOT EXIST www\NUL md www

IF EXIST node_modules\NUL goto AFTER_INTALL

call npm install

:AFTER_INTALL
ionic serve