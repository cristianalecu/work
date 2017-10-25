import { BrowserModule } from '@angular/platform-browser';
import { NgModule, ErrorHandler } from '@angular/core';
import { IonicApp, IonicModule, IonicErrorHandler } from 'ionic-angular';
import { Http, HttpModule } from '@angular/http';
import { TranslateModule, TranslateLoader } from '@ngx-translate/core';
import { TranslateHttpLoader } from '@ngx-translate/http-loader';
import { MyApp } from './app.component';

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

@NgModule({
  declarations: [
    MyApp,
    ObjectivesPage,
    ObjectivePage,
    CategoryPage,
    CategoriesPage,
    AuthorsPage,
    AuthorPage,
    BooksPage,
    BookPage,
    TasksPage,
    TaskPage,
    SettingsPage
  ],
  imports: [
    BrowserModule,
    HttpModule,
    IonicModule.forRoot(MyApp),
    TranslateModule.forRoot({
      loader: {
        provide: TranslateLoader,
        useFactory: (createTranslateLoader),
        deps: [Http]
      }
    })
  ],
  bootstrap: [IonicApp],
  entryComponents: [
    MyApp,
    ObjectivesPage,
    ObjectivePage,
    CategoryPage,
    CategoriesPage,
    AuthorsPage,
    AuthorPage,
    BooksPage,
    BookPage,
    TasksPage,
    TaskPage,
    SettingsPage
  ],
  providers: [{provide: ErrorHandler, useClass: IonicErrorHandler}]
})
export class AppModule {}

export function createTranslateLoader(http: Http) {
  return new TranslateHttpLoader(http, './assets/i18n/', '.json');
}
