import { Component, ViewChild } from '@angular/core';
import { Nav, Platform } from 'ionic-angular';
import { StatusBar } from '@ionic-native/status-bar';
import { SplashScreen } from '@ionic-native/splash-screen';
import {TranslateService} from '@ngx-translate/core';

import { Page1 } from '../pages/page1/page1';
import { Page2 } from '../pages/page2/page2';


@Component({
  templateUrl: 'app.html'
})
export class MyApp {
  @ViewChild(Nav) nav: Nav;

  rootPage: any = Page1;
  translater: TranslateService;
  languageSet: boolean;

  pages: Array<{title: string, component: any}>;

  constructor(public platform: Platform, public statusBar: StatusBar, public splashScreen: SplashScreen, translate: TranslateService) 
  {
    this.translater = translate;
    this.languageSet = false;
    this.initializeApp();


    this.checkLanguage();   


    // used for an example of ngFor and navigation
    this.pages = [
      { title: 'Page One', component: Page1 },
      { title: 'Page Two', component: Page2 }
    ];

  }

  checkLanguage()
  {
    var lang;
    lang = navigator.language.split('-')[0];
    lang = /(ro|en)/gi.test(lang) ? lang : 'en';
 
    this.translater.setDefaultLang('en');
    this.translater.use(lang);

    this.translater.get("PAGE1").subscribe(value =>
      {
        this.pages[0].title = value;
      });
    this.translater.get("PAGE2").subscribe(value =>
      {
        this.pages[1].title = value;
      });
  }

  initializeApp() {
    this.platform.ready().then(() => {
      // Okay, so the platform is ready and our plugins are available.
      // Here you can do any higher level native things you might need.
      this.statusBar.styleDefault();
      this.splashScreen.hide();
    });
  }

  openPage(page) {
    // Reset the content nav to have just this page
    // we wouldn't want the back button to show in this scenario
    this.nav.setRoot(page.component);
  }
}
