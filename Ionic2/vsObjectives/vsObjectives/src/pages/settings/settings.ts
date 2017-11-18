import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';
import { TranslateService } from '@ngx-translate/core';
import { AlertController } from 'ionic-angular';
import { Storage } from '../../classes/storage.ts';

@Component({
  selector: 'page-settings',
  templateUrl: 'settings.html'
})
export class SettingsPage {
  storage: Storage;
  translater: TranslateService;
  languageSet: boolean;

  constructor(public navCtrl: NavController, translate: TranslateService, private alertCtrl: AlertController)
  {
    this.translater = translate;
    this.languageSet = false;
    this.storage = new Storage;
    this.storage.LoadSettings();

  }

}
