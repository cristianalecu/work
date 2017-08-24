call pip install --upgrade pip
call python -m venv poolsenv
call poolsenv\Scripts\activate.bat
call pip install Django==1.11.4
call django-admin.py startproject pollsite .
call python manage.py migrate
call python manage.py createsuperuser
call python manage.py startapp polls
code .
