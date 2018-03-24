15
npm install -g @angular/cli
	
ng new my-first-app
cd my-first-app
npm install --save bootstrap@3

in .angular-cli.json  inside   "apps": ["styles": [] ]   first  add:
  "../node_modules/bootstrap/dist/css/bootstrap.min.css",

in app.moduels.ts  add:

import { FormsModule } from '@angular/forms'

  imports: [
    FormsModule, 


ng serve --host localhost --port 4255


HOW TO CREATE A COMPONENT manually

ceate for example in  src\app\server\    the files   server.component.ts, server.component.css and server.component.html
in src\app\app.module.ts  add ServerComponent is  declarations: []  and   and 
import { ServerComponent } from './server/server.component';


HOW TO CREATE A COMPONENT with cli

ng generate component servers
ng g c servers