import { Component, ViewChild } from '@angular/core';
import { Nav, Platform } from 'ionic-angular';
import { StatusBar } from '@ionic-native/status-bar';
import { SplashScreen } from '@ionic-native/splash-screen';
import {TranslateService} from '@ngx-translate/core';

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

  constructor(public platform: Platform, public statusBar: StatusBar, public splashScreen: SplashScreen, translate: TranslateService) {
    this.initializeApp();

    // used for an example of ngFor and navigation
    this.pages = [
      { title: 'OBJECTIVES'    , component: ObjectivesPage },
      { title: 'TASKS'         , component: TasksPage },
      { title: 'BOOKS'         , component: BooksPage },
      { title: 'CATEGORIES'    , component: CategoriesPage },
      { title: 'AUTHORS'       , component: AuthorsPage },
      { title: 'OBJECTIVE'     , component: ObjectivePage },
      { title: 'TASK'          , component: TaskPage },
      { title: 'BOOK'          , component: BookPage },
      { title: 'CATEGORY'      , component: CategoryPage },
      { title: 'AUTHOR'        , component: AuthorPage },
      { title: 'SETTINGS'      , component: SettingsPage },
    ];

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
