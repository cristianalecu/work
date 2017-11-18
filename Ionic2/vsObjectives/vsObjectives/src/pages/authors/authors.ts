import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';
import { TranslateService } from '@ngx-translate/core';
import { AlertController } from 'ionic-angular';
import { Storage } from '../../classes/storage.ts';
import { AuthorPage } from '../../pages/author/author';

@Component({
  selector: 'page-authors',
  templateUrl: 'authors.html'
})
export class AuthorsPage {
  sortOrder = "Most recent";
  storage: Storage;
  translater: TranslateService;
  languageSet: boolean;
  nr_authors: number;
  authors: Array<Array<string>>;

  constructor(public navCtrl: NavController, translate: TranslateService, private alertCtrl: AlertController)
  {
    this.translater = translate;
    this.languageSet = false;
    this.storage = new Storage;
    this.storage.LoadSettings();
    this.storage.LoadCategories();
    this.nr_authors = this.storage.nr_authors;
    this.fillsort();
  }

  fillsort()
  {
    var index;
    var picture;

    this.authors = Array();
    for (index = 0; index < this.nr_authors; index++) {
      picture = this.storage.authors[index].picture;
      if (!this.storage.authors[index].userDefined)
        picture = "assets/imgs/" + this.storage.authors[index].picture;
      this.authors[index] = Array(this.storage.authors[index].title, picture, '' + index);
    }
  }

  checkLanguage() {
    var lang;
    lang = navigator.language.split('-')[0];
    lang = /(ro|en)/gi.test(lang) ? lang : 'en';

    if (this.storage.userLang == '') {
      this.storage.userLang = lang;
      this.storage.SaveSettings();
    }

    if (this.languageSet)
      return;

    //this.translater.setDefaultLang('en');
    //this.translater.use(this.storage.userLang);
  }

  editAuthor(index: string) {
    this.storage.last_action = "editAuthor" + index;
    this.storage.SaveSettings();
    this.navCtrl.push(AuthorPage);
  }

  addAuthor() {
    this.storage.last_action = "newAuthor";
    this.storage.SaveSettings();
    this.navCtrl.push(AuthorPage);
  }
  
}
