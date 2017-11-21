import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';
import { TranslateService } from '@ngx-translate/core';
import { AlertController } from 'ionic-angular';
import { Storage, SortBy } from '../../classes/storage.ts';
import { AuthorPage } from '../../pages/author/author';

@Component({
  selector: 'page-authors',
  templateUrl: 'authors.html'
})

export class AuthorsPage
{
  
  storage: Storage;
  translater: TranslateService;
  languageSet: boolean;
  nr_authors: number;
  authors: Array<Array<string>>;
  test: number;

  msgSortOrder = "Most recent";
  msgNameAscending = "Name Ascending";
  msgNameDescending = "Name Descending";
  msgDateAscending = "Date Ascending";
  msgDateDescending = "Date Descending";


  constructor(public navCtrl: NavController, translate: TranslateService, private alertCtrl: AlertController)
  {
    this.translater = translate;
    this.languageSet = false;
    this.storage = new Storage;
  }

  ionViewWillEnter()
  {
    this.storage.LoadSettings();
    this.storage.LoadAuthors();
    this.nr_authors = this.storage.nr_authors;
    this.fillsort();
  }

  showSortMsg()
  {
    if (this.storage.sort_authors == SortBy.NameAlphabeticalAsc)
      this.msgSortOrder = this.msgNameAscending;
    else if (this.storage.sort_authors == SortBy.NameAlphabeticalDesc)
      this.msgSortOrder = this.msgNameDescending;
    else if (this.storage.sort_authors == SortBy.DateAsc)
      this.msgSortOrder = this.msgDateAscending;
    else if (this.storage.sort_authors == SortBy.DateDesc)
      this.msgSortOrder = this.msgDateDescending;
  }

  fillsort()
  {
    var index, index2, index3;
    var picture, title, date;

    this.authors = Array();
    this.storage.LoadAuthors();
    if (this.nr_authors > 0) 
    {
      for (index2 = 0; index2 < this.nr_authors; index2++) 
      {
        index = 0; // index of the maximum
        title = "";
        date = "";
        if (this.storage.sort_authors == SortBy.NameAlphabeticalDesc)
          title = "÷z";
        if (this.storage.sort_authors == SortBy.DateDesc)
          date = "÷z";

        for (index3 = 0; index3 < this.nr_authors; index3++)
        {
          if (typeof this.storage.authors[index3] !== 'undefined')
          {
            if (this.storage.sort_authors == SortBy.NameAlphabeticalAsc)
            {
              if (this.storage.authors[index3].title > title)
              {
                index = index3;
                title = this.storage.authors[index3].title;
              }
            }
            else if (this.storage.sort_authors == SortBy.NameAlphabeticalDesc)
            {
              if (this.storage.authors[index3].title < title)
              {
                index = index3;
                title = this.storage.authors[index3].title;
              }
            }
            else if (this.storage.sort_authors == SortBy.DateAsc)
            {
              if (this.storage.authors[index3].lastUpdated > date)
              {
                index = index3;
                date = this.storage.authors[index3].lastUpdated;
              }
            }
            else if (this.storage.sort_authors == SortBy.DateDesc)
            {
              if (this.storage.authors[index3].lastUpdated < date)
              {
                index = index3;
                date = this.storage.authors[index3].lastUpdated;
              }
            }
          }
        }
        title = this.storage.authors[index].title;
        picture = this.storage.authors[index].picture;
        if (!this.storage.authors[index].userDefined)
          picture = "assets/imgs/" + this.storage.authors[index].picture;
        this.authors[index2] = Array(title, picture, '' + index);
        delete this.storage.authors[index];
      }
    }
  }

  sortName()
  {
    if (this.storage.sort_authors == SortBy.NameAlphabeticalAsc)
      this.storage.sort_authors = SortBy.NameAlphabeticalDesc
    else
      this.storage.sort_authors = SortBy.NameAlphabeticalAsc

    this.showSortMsg();
    this.fillsort();
  }


  sortDate()
  {
    if (this.storage.sort_authors == SortBy.DateAsc)
      this.storage.sort_authors = SortBy.DateDesc
    else
      this.storage.sort_authors = SortBy.DateAsc

    this.showSortMsg();
    this.fillsort();
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

    this.translater.setDefaultLang('en');
    this.translater.use(this.storage.userLang);

    this.translater.get("NAME ASCENDING").subscribe(value => {
      this.msgNameAscending = value;
      this.showSortMsg();
    });
    this.translater.get("NAME DESCENDING").subscribe(value =>
    {
      this.msgNameDescending = value;
      this.showSortMsg();
    });
    this.translater.get("DATE ASCENDING").subscribe(value =>
    {
      this.msgDateAscending = value;
      this.showSortMsg();
    });
    this.translater.get("DATE DESCENDING").subscribe(value =>
    {
      this.msgDateDescending = value;
      this.showSortMsg();
    });  
  }

  editAuthor(index: string) {
    this.storage.last_action = "editAuthor" + index;
    this.storage.SaveSettings();
    this.navCtrl.push(AuthorPage);
    this.storage.last_action = ""; 
  }

  addAuthor() {
    this.storage.last_action = "newAuthor";
    this.storage.SaveSettings();
    this.navCtrl.push(AuthorPage);
  }




}
