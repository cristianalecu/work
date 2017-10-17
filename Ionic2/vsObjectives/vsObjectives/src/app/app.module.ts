import { NgModule, ErrorHandler } from '@angular/core';
import { IonicApp, IonicModule, IonicErrorHandler } from 'ionic-angular';
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
    IonicModule.forRoot(MyApp)
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
