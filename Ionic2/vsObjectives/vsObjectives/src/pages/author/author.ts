import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';
import { TranslateService } from '@ngx-translate/core';
import { AlertController } from 'ionic-angular';
import { Storage } from '../../classes/storage.ts';
import { Camera, CameraOptions } from '@ionic-native/camera';
import { DomSanitizer } from '@angular/platform-browser';
import { File } from '@ionic-native/file';

@Component({
  selector: 'page-author',
  templateUrl: 'author.html'
})

export class AuthorPage {
  storage: Storage;
  translater: TranslateService;
  languageSet: boolean;
  author_id: number;
  title: string;
  about: string;
  lastUpdated: string;
  picture: string;
  userDefined: boolean;
  isIOS: boolean;

  msgObjectives: string;
  msgAreYouSure: string;
  msgYes: string;
  msgNo: string;

  constructor(public navCtrl: NavController, translate: TranslateService, private alertCtrl: AlertController,
    private camera: Camera, private DomSanitizer: DomSanitizer, private fileProvider: File)
  {
    this.translater = translate;
    this.languageSet = false;
    this.storage = new Storage;
    this.storage.LoadSettings();
    this.storage.LoadAuthors();
    this.isIOS = false;

    if (this.storage.last_action.substr(0, 10) == "editAuthor")
    {
      this.author_id = parseInt(this.storage.last_action.substr(10));
      this.title = this.storage.authors[this.author_id].title;
      this.about = this.storage.authors[this.author_id].about;
      this.lastUpdated = this.storage.authors[this.author_id].lastUpdated;
      this.userDefined = this.storage.authors[this.author_id].userDefined;
      if (!this.userDefined)
        this.picture = "assets/imgs/" + this.storage.authors[this.author_id].picture;
      else
        this.picture = this.storage.authors[this.author_id].picture;
    }
    else
    {
      this.author_id = this.storage.nr_authors;  //still New
      this.userDefined = false;
      this.picture = "assets/imgs/anonymous.png";
      this.title = '';
      this.lastUpdated = '0';
      this.about = '';
    }
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

    this.translater.get('OBJEXTIVES').subscribe(value =>
    {
      this.msgObjectives = value;
    });
    this.translater.get('ARE YOU SURE TO DELETE?').subscribe(value =>
    {
      this.msgAreYouSure = value;
    });
    this.translater.get('YES').subscribe(value =>
    {
      this.msgYes = value;
    });
    this.translater.get('NO').subscribe(value =>
    {
      this.msgNo = value;
    });
  }

  takePicture()
  {
    const options: CameraOptions =
    {
      quality: 100,
      destinationType: this.camera.DestinationType.DATA_URL,
      encodingType: this.camera.EncodingType.JPEG,
      mediaType: this.camera.MediaType.PICTURE
    }

    this.camera.getPicture(options).then((imageData) =>
    {
      var d = new Date();
      // imageData is either a base64 encoded string or a file URI 
      // If it's base64:
      this.userDefined = true;
      this.picture = "data:image/jpeg;base64," + imageData;
      this.lastUpdated = "" + d.getFullYear() + "-" + (d.getMonth() + 1) + "-" + d.getDate() + " " + d.getHours() + ":" + d.getMinutes() + ":" + d.getSeconds();
    }, (err) => {
      // Handle error
    });
  }

  public onFileFromStorageChosen(filesEvent: any)
  {
    this.processFileFromStorage(filesEvent);
  }

  public processFileFromStorage(event: any)
  {
    let file = event.target.files[0];
    //you can read various properties of the file (like mimetype and size) from the file object.
    console.log(file);
    this.readfile(file);
  }

  //this one reads the contents of the file as a URL that contains its data:
  public readfile(file: any): void
  {
    let reader = new FileReader();
    let fileX = this.fileProvider;
    reader.onload = (e) => {
      fetch(reader.result,
        {
          method: "GET"
        }).then(res => res.blob()).then(blob => { 
          fileX.writeFile(fileX.dataDirectory, 'statement.pdf', blob, { replace: true }).then(res => {
            console.log('save ok' + res.toInternalURL());
          }).catch(err => {
            console.log('save error')
          });
        }).catch(err => {
          console.log('error')
        });
    };
    reader.readAsDataURL(file);
    let a = 5;
  }
  presentConfirm()
  {
    let alert = this.alertCtrl.create({
      title: this.msgObjectives,
      message: this.msgAreYouSure,
      buttons: [
        {
          text: this.msgNo,
          role: 'cancel',
          handler: () =>
          {
            console.log('Cancel clicked');
          }
        },
        {
          text: this.msgYes,
          handler: () =>
          {
            this.navCtrl.pop();
          }
        }
      ]
    });
    alert.present();
  }

  saveAuthor() {
    if (this.author_id == this.storage.nr_authors)
      this.storage.nr_authors++;

    this.storage.authors[this.author_id] = { title: this.title, about: this.about, picture: this.picture, lastUpdated: this.lastUpdated, userDefined: this.userDefined };
    this.storage.SaveAuthor(this.author_id);
  }
  deleteAuthor() {
    if (this.author_id == this.storage.nr_authors)
      this.navCtrl.pop();
    else
      this.presentConfirm();
  }
}
