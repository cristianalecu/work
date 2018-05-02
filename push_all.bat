call git config --global user.email "cristian.alecu@gmail.com"
call git config --global user.name "Cristian Alecu"
if %computername%==L560-CNA set https_proxy=http://192.168.1.29:8080

cd GitWork 
call git push
cd ..


cd DeapLearn
call git push
cd ..


cd Django
call git push
cd ..


cd Financiar
call git push
cd ..


cd Bets 
call git push
cd ..

cd FinAng
call git push
cd ..


:END_INIT
