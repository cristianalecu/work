import { NgModule }      from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { FormsModule } from '@angular/forms';
import { HttpModule } from '@angular/http';
import { UserComponent }  from './components/user.component';
import { AboutComponent }  from './components/about.component';
import { routing } from './app.routing';
import { TasksComponent }  from './components/tasks.component';

import { AppComponent }  from './app.component';

@NgModule({
  imports:      [ BrowserModule, FormsModule, HttpModule, routing ],
  declarations: [ AppComponent, UserComponent, AboutComponent, TasksComponent ],
  bootstrap:    [ AppComponent ]
})
export class AppModule { }
