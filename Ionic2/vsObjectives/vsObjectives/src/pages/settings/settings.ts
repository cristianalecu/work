import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';

@Component({
  selector: 'page-settings',
  templateUrl: 'settings.html'
})
export class SettingsPage {

  /** 0 - never     
    * 1 - hour
    * 2 - day
    * 3 - week     */
  sync_every = 0;

  last_datetime_sync = '2017-01-01 12:30:00';

  account_email = "";

  track_history = 0;

  constructor(public navCtrl: NavController)
  {
    this.getStorage();

  }

  getStorage()
  {
    if (localStorage.getItem('track_history') != null)
    {
      this.track_history = parseInt(localStorage.getItem('track_history'));
      this.sync_every    = parseInt(localStorage.getItem('sync_every'));
      this.account_email = localStorage.getItem('account_email');
      this.last_datetime_sync = localStorage.getItem('last_datetime_sync');
    }
    else    //initialize 
    {
    }


  }
}
