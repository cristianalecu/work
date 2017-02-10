import { Component } from '@angular/core';
import { routing } from './app.routing';

@Component({
  selector: 'my-app',
  template: `
  <ul>
    <li><a routerLink="/">Home</a></li>
    <li><a routerLink="/tasks">Tasks</a></li>
    <li><a routerLink="/about">About</a></li>
  </ul>
  <hr />
  <router-outlet> </router-outlet>`,
})
export class AppComponent  { 
  
}
