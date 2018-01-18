

IF EXIST platforms\broser\NUL goto AFTER_INTALL

call ionic cordova platform add browser

:AFTER_INTALL

ionic cordova run browser

