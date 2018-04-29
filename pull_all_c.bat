call git config --global user.email "cristian.alecu@gmail.com"
call git config --global user.name "Cristian Alecu"
if %computername%==L560-CNA set https_proxy=http://192.168.1.29:8080

IF EXIST GitWork\NUL goto AFTER_GitWork

md GitWork
cd GitWork

call git init
call git remote add origin https://github.com/cristianalecu/work.git
call git pull origin master
call git push --set-upstream origin master
cd ..

:AFTER_GitWork

cd GitWork 
call git pull
cd ..

IF EXIST Django\NUL goto AFTER_Django

md Django
cd Django

call git init
call git remote add origin https://github.com/cristianalecu/Django.git
call git pull origin master
call git push --set-upstream origin master
cd ..

:AFTER_Django

cd Django 
call git pull 
cd ..

IF EXIST DeapLearn\NUL goto AFTER_DeapLearn

md DeapLearn
cd DeapLearn

call git init
call git remote add origin https://github.com/cristianalecu/DeapLearn.git
call git pull origin master
call git push --set-upstream origin master
cd ..

:AFTER_DeapLearn

cd DeapLearn 
call git pull 
cd ..


IF EXIST Financiar\NUL goto AFTER_Financiar

md Financiar
cd Financiar

call git init
call git remote add origin https://github.com/cristianalecu/Financiar.git
call git pull origin master
call git push --set-upstream origin master
cd ..

:AFTER_Financiar

cd Financiar 
call git pull 
cd ..


IF EXIST Bets\NUL goto AFTER_Bets

md Bets
cd Bets

call git init
call git remote add origin https://github.com/cristianalecu/bets.git
call git pull origin master
call git push --set-upstream origin master
cd ..

:AFTER_Bets

cd Bets 
call git pull 
cd ..

IF EXIST FinAng\NUL goto AFTER_FinAng

md FinAng
cd FinAng

call git init
call git remote add origin https://github.com/cristianalecu/FinAng.git
call git pull origin master
call git push --set-upstream origin master
cd ..

:AFTER_FinAng

cd FinAng 
call git pull 
cd ..
pause 0

:END_INIT
