import { NgModule, ErrorHandler } from '@angular/core';
import { IonicApp, IonicModule, IonicErrorHandler } from 'ionic-angular';
import { MyApp } from './app.component';
import { PageStartup } from '../pages/pagestartup/pagestartup';
import { PagePlay } from '../pages/pageplay/pageplay';
import { PageNivel } from '../pages/pagenivel/pagenivel';
import { PageStatistica } from '../pages/pagestatistica/pagestatistica';
import { PageSettings } from '../pages/pagesettings/pagesettings';

@NgModule({
  declarations: [
    MyApp,
    PageStartup,
    PagePlay,
    PageNivel,
    PageStatistica,
    PageSettings
  ],
  imports: [
    IonicModule.forRoot(MyApp)
  ],
  bootstrap: [IonicApp],
  entryComponents: [
    MyApp,
    PageStartup,
    PagePlay,
    PageNivel,
    PageStatistica,
    PageSettings
  ],
  providers: [{provide: ErrorHandler, useClass: IonicErrorHandler}]
})
export class AppModule {}
