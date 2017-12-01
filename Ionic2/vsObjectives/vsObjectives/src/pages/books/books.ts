import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';
import { TranslateService } from '@ngx-translate/core';
import { AlertController } from 'ionic-angular';
import { Storage, SortBy } from '../../classes/storage.ts';
import { BookPage } from '../../pages/book/book';

@Component({
  selector: 'page-books',
  templateUrl: 'books.html'
})

export class BooksPage
{
  storage: Storage;
  translater: TranslateService;
  languageSet: boolean;
  nr_books: number;
  books: Array<Array<string>>;

  msgSortOrder = "Most recent";
  msgNameAscending = "Name Ascending";
  msgNameDescending = "Name Descending";
  msgAuthorAscending = "Author Ascending";
  msgAuthorDescending = "Author Descending";
  msgCategoryAscending = "Category Ascending";
  msgCategoryDescending = "Category Descending";
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
    this.storage.LoadCategories();
    this.storage.LoadBooks();
    this.nr_books = this.storage.nr_books;
    this.fillsort();
  }

  showSortMsg()
  {
    if (this.storage.sort_books == SortBy.NameAlphabeticalAsc)
      this.msgSortOrder = this.msgNameAscending;
    else if (this.storage.sort_books == SortBy.NameAlphabeticalDesc)
      this.msgSortOrder = this.msgNameDescending;
    else if (this.storage.sort_books == SortBy.AuthorAsc)
      this.msgSortOrder = this.msgAuthorAscending;
    else if (this.storage.sort_books == SortBy.AuthorDesc)
      this.msgSortOrder = this.msgAuthorDescending;
    else if (this.storage.sort_books == SortBy.CategAsc)
      this.msgSortOrder = this.msgCategoryAscending;
    else if (this.storage.sort_books == SortBy.CategDesc)
      this.msgSortOrder = this.msgCategoryDescending;
    else if (this.storage.sort_books == SortBy.DateAsc)
      this.msgSortOrder = this.msgDateAscending;
    else if (this.storage.sort_books == SortBy.DateDesc)
      this.msgSortOrder = this.msgDateDescending;
  }

  fillsort()
  {
    var index, index2, index3;
    var picture, title, date, categ, author;

    this.books = Array();
    this.storage.LoadBooks();
    if (this.nr_books > 0) 
    {
      for (index2 = 0; index2 < this.nr_books; index2++) 
      {
        index = 0; // index of the maximum
        title = "";
        date = "";
        categ = "";
        author = "";
        if (this.storage.sort_books == SortBy.NameAlphabeticalDesc)
          title = "÷z";
        if (this.storage.sort_books == SortBy.DateDesc)
          date = "÷z";
        if (this.storage.sort_books == SortBy.AuthorDesc)
          author = "÷z";
        if (this.storage.sort_books == SortBy.CategDesc)
          categ = "÷z";

        for (index3 = 0; index3 < this.nr_books; index3++)
        {
          if (typeof this.storage.books[index3] !== 'undefined')
          {
            if (this.storage.sort_books == SortBy.NameAlphabeticalAsc)
            {
              if (this.storage.books[index3].title > title)
              {
                index = index3;
                title = this.storage.books[index3].title;
              }
            }
            else if (this.storage.sort_books == SortBy.NameAlphabeticalDesc)
            {
              if (this.storage.books[index3].title < title)
              {
                index = index3;
                title = this.storage.books[index3].title;
              }
            }
            else if (this.storage.sort_books == SortBy.AuthorAsc)
            {
              if (this.storage.authors[this.storage.books[index3].author].title > author)
              {
                index = index3;
                author = this.storage.authors[this.storage.books[index3].author].title;
              }
            }
            else if (this.storage.sort_books == SortBy.AuthorDesc)
            {
              if (this.storage.authors[this.storage.books[index3].author].title < author)
              {
                index = index3;
                author = this.storage.authors[this.storage.books[index3].author].title;
              }
            }
            else if (this.storage.sort_books == SortBy.CategAsc)
            {
              if (this.storage.categories[this.storage.books[index3].category].title > categ)
              {
                index = index3;
                categ = this.storage.categories[this.storage.books[index3].category].title;
              }
            }
            else if (this.storage.sort_books == SortBy.CategDesc)
            {
              if (this.storage.categories[this.storage.books[index3].category].title < categ)
              {
                index = index3;
                categ = this.storage.categories[this.storage.books[index3].category].title;
              }
            }
            else if (this.storage.sort_books == SortBy.DateAsc)
            {
              if (this.storage.books[index3].updates[this.storage.books[index3].updates.length - 1][1] > date)
              {
                index = index3;
                date = this.storage.books[index3].updates[this.storage.books[index3].updates.length - 1][1];
              }
            }
            else if (this.storage.sort_books == SortBy.DateDesc)
            {
              if (this.storage.books[index3].updates[this.storage.books[index3].updates.length - 1][1] < date)
              {
                index = index3;
                date = this.storage.books[index3].updates[this.storage.books[index3].updates.length-1][1];
              }
            }
          }
        }
        title = this.storage.books[index].title;
        author = this.storage.authors[this.storage.books[index].author].title;
        categ = this.storage.categories[this.storage.books[index].category].title
        picture = this.storage.books[index].photos[0];
        if (!this.storage.books[index].userDefined)
          picture = "assets/imgs/" + this.storage.books[index].photos[0];
        this.books[index2] = Array(title, author, categ, picture, '' + index);
        delete this.storage.books[index];
      }
    }
  }

  sortName()
  {
    if (this.storage.sort_books == SortBy.NameAlphabeticalAsc)
      this.storage.sort_books = SortBy.NameAlphabeticalDesc
    else
      this.storage.sort_books = SortBy.NameAlphabeticalAsc

    this.showSortMsg();
    this.fillsort();
  }

  sortAuthor()
  {
    if (this.storage.sort_books == SortBy.AuthorAsc)
      this.storage.sort_books = SortBy.AuthorDesc
    else
      this.storage.sort_books = SortBy.AuthorAsc

    this.showSortMsg();
    this.fillsort();
  }

  sortCategory()
  {
    if (this.storage.sort_books == SortBy.CategAsc)
      this.storage.sort_books = SortBy.CategDesc
    else
      this.storage.sort_books = SortBy.CategAsc

    this.showSortMsg();
    this.fillsort();
  }

  sortDate()
  {
    if (this.storage.sort_books == SortBy.DateAsc)
      this.storage.sort_books = SortBy.DateDesc
    else
      this.storage.sort_books = SortBy.DateAsc

    this.showSortMsg();
    this.fillsort();
  }

  checkLanguage()
  {
    var lang;
    lang = navigator.language.split('-')[0];
    lang = /(ro|en)/gi.test(lang) ? lang : 'en';

    if (this.storage.userLang == '')
    {
      this.storage.userLang = lang;
      this.storage.SaveSettings();
    }

    if (this.languageSet)
      return;

    this.translater.setDefaultLang('en');
    this.translater.use(this.storage.userLang);

    this.translater.get("TITLE ASCENDING").subscribe(value =>
    {
      this.msgNameAscending = value;
      this.showSortMsg();
    });
    this.translater.get("TITLE DESCENDING").subscribe(value =>
    {
      this.msgNameDescending = value;
      this.showSortMsg();
    });
    this.translater.get("CATEGORY ASCENDING").subscribe(value =>
    {
      this.msgCategoryAscending = value;
      this.showSortMsg();
    });
    this.translater.get("CATEGORY DESCENDING").subscribe(value =>
    {
      this.msgCategoryDescending = value;
      this.showSortMsg();
    });
    this.translater.get("AUTHOR ASCENDING").subscribe(value =>
    {
      this.msgAuthorAscending = value;
      this.showSortMsg();
    });
    this.translater.get("AUTHOR DESCENDING").subscribe(value =>
    {
      this.msgAuthorDescending = value;
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

  editBook(index: string)
  {
    this.storage.last_action = "editBook" + index;
    this.storage.SaveSettings();
    this.navCtrl.push(BookPage);
    this.storage.last_action = "";
  }

  addBook()
  {
    this.storage.last_action = "newBook";
    this.storage.SaveSettings();
    this.navCtrl.push(BookPage);
  }




}
