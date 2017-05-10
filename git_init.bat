
IF EXIST GitWork\NUL goto AFTER_GITWORK

git config --global user.email "cristian.alecu@gmail.com"
git config --global user.name "Cristian Alecu"
git config --global http.proxy 192.168.1.29:8080

git clone https://github.com/cristianalecu/work.git

rename work GitWork

:AFTER_GITWORK

cd GitWork 

git pull origin master

:END_INIT