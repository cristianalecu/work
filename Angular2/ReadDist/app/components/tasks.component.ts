import { Component } from '@angular/core';

@Component({
  selector: 'tasks',
  template: `
  <button (click)="changeToggle()">{{toggle ? "Unset toggle" : "Set toggle"}}</button>
  <h4 [class.red] = "toggle">This is the Tasks Component</h4>
  <h4 [ngClass] = "{ red: toggle, blue: !toggle}">This is the Tasks Component</h4>
  <span>{{num}}</span><input [value]="num" (keyup)="num = $event.target.value"><span>{{sample}}</span>
  <button (click)="myClick()">let's start</button>
  <input [(ngModel)]="sample"><span>{{sample}}</span>
  <h5 *ngIf="toggle">Hello toggle</h5>
  <ul>
      <li *ngFor="let pip of people">
        {{pip}}
      </li>
  </ul>
  `,
  styles: [".red { color: red }", ".blue { color: blue }"],
})
export class TasksComponent  { 
  toggle: boolean = true;
  num: number = 7;
  sample: string = "";
  people: Array<string> = ['people 1', 'people2'];
  changeToggle() {
    this.toggle = !this.toggle;
  } 
  myClick() {
     this.sample = "Start";
     this.num = 7;
  }
}
