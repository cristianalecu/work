import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';
import { TranslateService } from '@ngx-translate/core';
import { AlertController } from 'ionic-angular';
import { Storage } from '../../classes/storage.ts';
import { Camera, CameraOptions } from '@ionic-native/camera';
import { DomSanitizer } from '@angular/platform-browser';
import { File } from '@ionic-native/file';
import { FileOpener } from '@ionic-native/file-opener';

@Component({
  selector: 'page-category',
  templateUrl: 'category.html'
})
export class CategoryPage {
  storage: Storage;
  translater: TranslateService;
  languageSet: boolean;
  categ_id: number;
  title: string;
  about: string;
  picture: string;
  userDefined: boolean;
  selfieImage: string;
  isIOS: boolean;

  constructor(public navCtrl: NavController, translate: TranslateService, private alertCtrl: AlertController,
          private camera: Camera, private DomSanitizer: DomSanitizer, private fileProvider: File, private fileOpener: FileOpener)
  {
    this.translater = translate;
    this.languageSet = false;
    this.storage = new Storage;
    this.storage.LoadSettings();
    this.storage.LoadCategories();
    this.isIOS = false;

    if (this.storage.last_action.substr(0, 9) == "editCateg") {
      this.categ_id = parseInt(this.storage.last_action.substr(9));
      this.title = this.storage.categories[this.categ_id].title;
      this.about = this.storage.categories[this.categ_id].about;
      this.userDefined = this.storage.categories[this.categ_id].userDefined;
      if (!this.userDefined)
        this.picture = "assets/imgs/" + this.storage.categories[this.categ_id].picture;
      else
        this.selfieImage = this.storage.categories[this.categ_id].picture;
    }
    else
    {
      this.categ_id = this.storage.nr_categories;  //still New
      this.userDefined = false;
      this.picture = "assets/imgs/3_profession.png";
      this.title = '';
      this.about = '';
    }
  }

  takePicture()
  {
    const options: CameraOptions = {
      quality: 100,
      destinationType: this.camera.DestinationType.DATA_URL,
      encodingType: this.camera.EncodingType.JPEG,
      mediaType: this.camera.MediaType.PICTURE
    }

    this.camera.getPicture(options).then((imageData) => {
      // imageData is either a base64 encoded string or a file URI
      // If it's base64:
      this.selfieImage = "data:image/jpeg;base64," + imageData;
      this.userDefined = true;
    }, (err) => {
      // Handle error
    });
  }

  public onFileFromStorageChosen(filesEvent: any) {
    this.processFileFromStorage(filesEvent);
  }

  public processFileFromStorage(event: any) {
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
    let fileO = this.fileOpener;
    reader.onload = (e) => {
      fetch(reader.result,
        {
          method: "GET"
        }).then(res => res.blob()).then(blob => {
          fileX.writeFile(fileX.dataDirectory, 'statement.pdf', blob, { replace: true }).then(res => {
            fileO.open(
              res.toInternalURL(),
              'application/pdf'
            ).then((res) => {

            }).catch(err => {
              console.log('open error')
            });
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


}
