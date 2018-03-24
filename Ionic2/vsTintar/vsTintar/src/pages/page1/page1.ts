import { Component } from '@angular/core';

import { NavController } from 'ionic-angular';
import {TranslateService} from '@ngx-translate/core';
import { AlertController } from 'ionic-angular';


@Component({
    selector: 'page-page1',
    templateUrl: 'page1.html'
})
export class Page1 {
  translater: TranslateService;
  languageSet: boolean;


  constructor(public navCtrl: NavController, translate: TranslateService, private alertCtrl: AlertController)
  {
    this.translater = translate;
    this.languageSet = false;

    this.checkLanguage();      
  }

  checkLanguage()
  {
    var lang;
    lang = navigator.language.split('-')[0];
    lang = /(ro|en)/gi.test(lang) ? lang : 'en';
 
    this.translater.setDefaultLang('en');
    this.translater.use(lang);
  }

    onLink(url: string) {
        window.open(url);
    }
}

export class SchedulePage {
    constructor(translate: TranslateService) {
        // this language will be used as a fallback when a translation isn't found in the current language
        translate.setDefaultLang('en');
    }
}
