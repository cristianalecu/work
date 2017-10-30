import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';
import {TranslateService} from '@ngx-translate/core';
import { AlertController } from 'ionic-angular';


@Component({
  selector: 'page-objectives',
  templateUrl: 'objectives.html'
})
export class ObjectivesPage {
  storage: Storage;
  translater: TranslateService;
  languageSet: boolean;

  constructor(public navCtrl: NavController, translate: TranslateService, private alertCtrl: AlertController)
  {
    this.translater = translate;
    this.storage = new Storage;
    this.storage.getStorage();
    this.checkLanguage();      
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

  checkLanguage()
  {
    var lang;
    lang = navigator.language.split('-')[0];
    lang = /(ro|en)/gi.test(lang) ? lang : 'en';

    if (this.storage.userLang == '')
    {
      this.storage.userLang = lang;
      this.storage.SaveSettings;
    }


    if (this.storage.userLang == lang)
      return;


 
   this.translater.setDefaultLang('en');
   this.translater.use(this.userLang);
    
 
  }
}

export class SchedulePage {
    constructor(translate: TranslateService) {
        // this language will be used as a fallback when a translation isn't found in the current language
        translate.setDefaultLang('en');
    }
}
