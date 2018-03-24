import { Component, OnInit } from '@angular/core';

@Component({
  // selector: '[app-servers]',  // select  by attribute
  // selector: '.app-servers',   // select by class
  selector: 'app-servers',       // select by element name
  // template: `
  //  <app-server></app-server>
  //  <app-server></app-server>`,
  templateUrl: './servers.component.html',
  styleUrls: ['./servers.component.css'],
  // styles: [`
  //  h3 {
  //    color: dodgerblue;
  //  }
  // `]
})
export class ServersComponent implements OnInit {
  allowNewServer = false;
  serverCreationStatus = 'No server was created!';
  serverName = 'Testserver';
  username='';

  constructor() {
    setTimeout(() => {
      this.allowNewServer = true;
    }, 2000);
  }

  ngOnInit() {
  }

  onCreateServer() {
    this.serverCreationStatus = 'Server was created! Name is ' + this.serverName;
  }

  onUpdateServerName(event: Event) {
    this.serverName = (<HTMLInputElement>event.target).value;
  }

  onResetUsername() {
    this.username = '';
  }
}
