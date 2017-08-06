import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';
import {TranslateService} from '@ngx-translate/core';
import { AlertController } from 'ionic-angular';
import { PlayerType, tPlayer } from '../../classes/player';

@Component({
  selector: 'page-players',
  templateUrl: 'players.html'
})
export class PlayersPage {
  nrPlayers: number = 0;
  player_user: number;
  player_user_old: number;
  player_index: number;
  players: Array<tPlayer>;
  points: Array<Array<number>>;
  translater: TranslateService;
  userLang: string;
  usr_name:string;
  usr_email:string;
  usr_points:string;
  visibleEdit = false;
  addUser = false;

  msgDelete: string;
  msgSave: string;
  msgAreYouSure: string;
  msgMustFillName: string;
  msgYes: string;
  msgNo: string;
  msgOK: string;

  constructor(public navCtrl: NavController, translate: TranslateService, private alertCtrl: AlertController) 
  {
    this.translater = translate;    
    this.userLang = '';
    this.players = Array();
    this.points = Array();
    this.getDefaults();
    this.checkLanguage();
  }

  presentConfirm() {
    let alert = this.alertCtrl.create({
      title: this.msgDelete,
      message: this.msgAreYouSure,
      buttons: [
        {
          text: this.msgNo,
          role: 'cancel',
          handler: () => {
            console.log('Cancel clicked');
          }
        },
        {
          text: this.msgYes,
          handler: () => {
            this.player_user_old = -1;
            this.playerDelete();
          }
        }
      ]
    });
    alert.present();
  }
  presentInputError() {
    let alert = this.alertCtrl.create({
      title: this.msgSave,
      message: this.msgMustFillName,
      buttons: [
        {
          text: this.msgOK,
          handler: () => {
            
          }
        }
      ]
    });
    alert.present();
  }
  getDefaults(){
    this.nrPlayers = parseInt(localStorage.getItem('nrPlayers'));
    this.player_user = parseInt(localStorage.getItem('player_user'));
    if(this.nrPlayers > 0)
    {
      var usr_name: string;
      var usr_type :PlayerType;
      var usr_id: number;
      var usr_email: string;
      var index, index2, index3 : number;
      var nPoints : Array<number>;  // position in list , wins, loses

      for (index = 0; index < this.nrPlayers; index++) 
      {
        usr_name = localStorage.getItem('usr_name'+index);
        usr_type = parseInt(localStorage.getItem('usr_type'+index));
        usr_id = parseInt(localStorage.getItem('usr_id'+index));
        usr_email = localStorage.getItem('usr_email'+index);
        if(usr_type == PlayerType.User || usr_type == PlayerType.Computer)
        {
          nPoints = Array(0,0,0);
          for (index2 = 0; index2 < this.nrPlayers; index2++) 
          {
            nPoints[1] += parseInt(localStorage.getItem('nPoints_'+index+"_"+index2)); // victories
            nPoints[2] += parseInt(localStorage.getItem('nPoints_'+index2+"_"+index)); // loses   
          }
          index2 = 0;
          while(index2 < index) // sorted by winings
          {
            if(this.points[index2][1] < nPoints[1])
            {
              for (index3 = index; index3 > index2; index3--) 
              {
                this.players[index3] = this.players[index3-1];
                this.points[index3] = this.points[index3-1];
                this.points[index3][0]++;
              }
              nPoints[0]=index2;
              this.players[index2] = { name: usr_name, id: usr_id, pType: usr_type, email: usr_email };
              this.points[index2] = nPoints;
              break;
            }
            index2++;
          }
          if(index2 == index)  //no bigger one found
          {
            nPoints[0]=index2;
            this.players[index2] = { name: usr_name, id: usr_id, pType: usr_type, email: usr_email };
            this.points[index2] = nPoints;
          }
          this.player_index = index2;
          this.usr_name = this.players[this.player_index].name;
          this.usr_email = this.players[this.player_index].email;
          this.usr_points = this.points[this.player_index][1] + " / " + this.points[this.player_index][2]
          //if(this.player_user == usr_id)
          //  this.player_user = index2
        }
      }
    }
  }

  checkLanguage()
  {
    var lang;
    lang = navigator.language.split('-')[0];
    lang = /(ro|en)/gi.test(lang) ? lang : 'en';

    if(this.userLang == lang)
      return;
 
    this.userLang = lang;

   this.translater.setDefaultLang('en');
   this.translater.use(this.userLang);

   this.translater.get('DELETE').subscribe(   value => {
      this.msgDelete = value; 
    });  
   this.translater.get('SAVE').subscribe(   value => {
      this.msgSave = value; 
    });
   this.translater.get('MUST FILL NAME').subscribe(   value => {
      this.msgMustFillName = value; 
    }); 
   this.translater.get('"ARE YOU SURE TO DELETE USER?').subscribe(  value => {
      this.msgAreYouSure = value; 
    });  
   this.translater.get('YES').subscribe(   value => {
      this.msgYes = value; 
    }); 
   this.translater.get('NO').subscribe(   value => {
      this.msgNo = value; 
    });
   this.translater.get('OK').subscribe(   value => {
      this.msgOK = value; 
    });
  }

  forceNewGame()
  {
    localStorage.setItem('winner', '-1');
    localStorage.setItem('player', '1');
    localStorage.setItem('move', '0');
  }

  changePlayerUser()
  {
    if(this.player_user_old != this.player_user)
    {
      this.player_user_old = this.player_user;
      for (var index = 0; index < this.players.length; index++) {
        if(this.players[index].id == this.player_user)
        {
          this.player_index = index;
          break;
        }
      }
      this.usr_name = this.players[this.player_index].name;
      this.usr_email = this.players[this.player_index].email;
      this.usr_points = this.points[this.player_index][1] + " / " + this.points[this.player_index][2];
      this.addUser = false;
    }
  }

  playerAdd()
  {
    this.addUser = true;
    this.player_user = -1;
    this.player_user_old = -1
    this.usr_name = "";
    this.usr_email = "";
    this.usr_points = "0 / 0";
    this.visibleEdit = true;
  }

  playerEdit()
  {
    if(this.player_user >= 0 )
    {
      this.visibleEdit = true;
      this.addUser = false;
    }
  }
  
  playerDelete()
  {
    var index2;
    if(this.player_user >= 0 )
    {
      if(this.player_user == this.player_user_old)
        this.presentConfirm();
      else
      {
        this.visibleEdit = false;
        localStorage.setItem('usr_type'+this.player_user, ''+PlayerType.Deleted);
        for (index2 = 0; index2 <= this.nrPlayers; index2++) 
        {
          localStorage.setItem('nPoints_'+this.player_user+"_"+index2, '0');
          localStorage.setItem('nPoints_'+index2+"_"+this.player_user, '0');
        }
        this.getDefaults();
      }
    }
  }
  
  playerSave()
  {
    var index2;
    if(this.usr_name.trim().length == 0)
    {
      this.presentInputError();
      return;
    }
    if(this.addUser)
    {
      this.addUser = false;

      this.player_index = this.players.length;
      this.points[this.points.length] = Array(this.player_index,0,0);
      this.players[this.players.length] = { name: this.usr_name, id: this.nrPlayers, pType: PlayerType.User, email: this.usr_email };
      this.player_user = this.nrPlayers;
      this.player_user_old = this.nrPlayers;
      localStorage.setItem('usr_name'+this.nrPlayers, ''+this.usr_name);
      localStorage.setItem('usr_id'+this.nrPlayers, ''+this.nrPlayers);
      localStorage.setItem('usr_type'+this.nrPlayers, ''+PlayerType.User);
      localStorage.setItem('usr_email'+this.nrPlayers, ''+this.usr_email);
      for (index2 = 0; index2 <= this.nrPlayers; index2++) 
      {
        localStorage.setItem('nPoints_'+this.nrPlayers+"_"+index2, '0');
        localStorage.setItem('nPoints_'+index2+"_"+this.nrPlayers, '0');
      }
      this.nrPlayers++;
      localStorage.setItem('nrPlayers', ''+this.nrPlayers);
    }
    else
    {
      if(this.players[this.player_index].name != this.usr_name)
      {
        this.players[this.player_index].name = this.usr_name;
        localStorage.setItem('usr_name'+this.player_user, ''+this.usr_name);
      }
      if(this.players[this.player_index].email != this.usr_email)
      {
        this.players[this.player_index].email = this.usr_email;
        localStorage.setItem('usr_email'+this.player_user, ''+this.usr_email);
      }
    }
  }
}