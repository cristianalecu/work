import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';

@Component({
  selector: 'page-objectives',
  templateUrl: 'objectives.html'
})
export class ObjectivesPage {

  version = 1;

  constructor(public navCtrl: NavController)
  {
    this.getStorage();
  }

  getStorage() {
    if (localStorage.getItem('version') != null) {
      this.version = parseInt(localStorage.getItem('version'));
    }
    else    //initialize 
    {
      localStorage.setItem('version', '' + this.version);
      localStorage.setItem('sync_every', '0');
      localStorage.setItem('account_email', '');
      localStorage.setItem('last_datetime_sync', '2017-01-01 12:30:00');
      localStorage.setItem('track_history', '0');
    }


  }
}
