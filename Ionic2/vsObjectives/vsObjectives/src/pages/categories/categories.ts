import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';
import { TranslateService } from '@ngx-translate/core';
import { AlertController } from 'ionic-angular';
import { Storage } from '../../classes/storage.ts';
import { CategoryPage } from '../../pages/category/category';

@Component({
  selector: 'page-categories',
  templateUrl: 'categories.html'
})
export class CategoriesPage {
  storage: Storage;
  translater: TranslateService;
  languageSet: boolean;
  nr_categories: number;
  categories: Array<Array<string>>;

  constructor(public navCtrl: NavController, translate: TranslateService, private alertCtrl: AlertController)
  {
    var index;
    var picture;

    this.translater = translate;
    this.languageSet = false;
    this.storage = new Storage;
    this.storage.LoadCategories();
    this.nr_categories = this.storage.nr_categories;
    this.categories = Array();
    for (index = 0; index < this.nr_categories; index++)
    {
      picture = "";
      if (! this.storage.categories[index].userDefined)
        picture = "assets/imgs/" + this.storage.categories[index].picture;
      this.categories[index] = Array(this.storage.categories[index].title, picture, ''+index);
      

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

  editCateg(index: string) {
    this.storage.last_action = "editCateg" + index;
    this.storage.SaveSettings();
    this.navCtrl.push(CategoryPage);
  }

  addCateg()
  {
    this.storage.last_action = "newCateg";
    this.storage.SaveSettings();
    this.navCtrl.push(CategoryPage);
  }
}
