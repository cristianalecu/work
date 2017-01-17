import { Component, Input } from '@angular/core';
import { Hero } from '../classes/hero';

@Component({
  selector: 'my-hero-detail',
  template: `
  <div *ngIf="herox">
    <h2>{{herox.name}} details!</h2>
    <div><label>id: </label>{{herox.id}}</div>
    <div>
      <label>name: </label>
      <input [(ngModel)]="herox.name" placeholder="name"/>
    </div>
  </div>
`
})
export class HeroDetailComponent {
     @Input()
     herox: Hero;
}