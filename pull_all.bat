call git config --global user.email "cristian.alecu@gmail.com"
call git config --global user.name "Cristian Alecu"
if %computername%==L560-CNA set https_proxy=http://192.168.1.29:8080

cd GitWork 
call git pull
cd ..

cd Django 
call git pull 
cd ..

cd DeapLearn 
call git pull 
cd ..


cd Financiar 
call git pull 
cd ..

cd Bets 
call git pull 
cd ..

cd FinAng 
call git pull 
cd ..

pause 0

:END_INIT
