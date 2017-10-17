import { Component, ViewChild } from '@angular/core';
import { Nav, Platform } from 'ionic-angular';
import { StatusBar, Splashscreen } from 'ionic-native';

import { ObjectivesPage } from '../pages/objectives/objectives';
import { ObjectivePage } from '../pages/objective/objective';
import { CategoryPage } from '../pages/category/category';
import { CategoriesPage } from '../pages/categories/categories';
import { AuthorsPage } from '../pages/authors/authors';
import { AuthorPage } from '../pages/author/author';
import { BooksPage } from '../pages/books/books';
import { BookPage } from '../pages/book/book';
import { TasksPage } from '../pages/tasks/tasks';
import { TaskPage } from '../pages/task/task';
import { SettingsPage } from '../pages/settings/settings';



@Component({
  templateUrl: 'app.html'
})
export class MyApp {
  @ViewChild(Nav) nav: Nav;

  rootPage: any = ObjectivesPage;

  pages: Array<{title: string, component: any}>;

  constructor(public platform: Platform) {
    this.initializeApp();

    // used for an example of ngFor and navigation
    this.pages = [
      { title: 'Objectives', component: ObjectivesPage },
      { title: 'Tasks', component: TasksPage },
      { title: 'Books', component: BooksPage },
      { title: 'Categories', component: CategoriesPage },
      { title: 'Authors', component: AuthorsPage },
      { title: 'Settings', component: SettingsPage },
       ];

  }

  initializeApp() {
    this.platform.ready().then(() => {
      // Okay, so the platform is ready and our plugins are available.
      // Here you can do any higher level native things you might need.
      StatusBar.styleDefault();
      Splashscreen.hide();
    });
  }

  openPage(page) {
    // Reset the content nav to have just this page
    // we wouldn't want the back button to show in this scenario
    this.nav.setRoot(page.component);
  }
}
