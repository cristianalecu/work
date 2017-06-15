import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';
import {TranslateService} from '@ngx-translate/core';
import { AlertController } from 'ionic-angular';

@Component({
  selector: 'page-home',
  templateUrl: 'home.html'
})
export class HomePage 
{
  /** 0 - Easy      
   *  1 - Normal     
   *  2 - Hard       
   *  3 - Extpert    */ 
  dificulty: number; 
  
  /** 1 - Single player   
   *  2 - Two players     */
  nr_players: number;


  /** Player who has to move   
   *  0 - Player 2 (0)         
   *  1 - Player 1 (X)         */
  player: number;

  /** 0 - Player 2 (0)  
   *  1 - Player 1 (X)    */
  player_computer: number;

  /** Move that has to be made - 0 based */
  move: number;    

  /** 1 2 3  
   *  4 5 6  
   *  7 8 9  */
  moves: Array<number>;
  board: Array<string>;
  targets: Array<Array<number>>;
  statistics: Array<Array<number>>;

  translater: TranslateService;
  userLang: string;
  logMsg: string;

  msgNewGame: string;
  msgAreYouSure: string;
  msgYes: string;
  msgNo: string;

  constructor(public navCtrl: NavController, translate: TranslateService, private alertCtrl: AlertController) 
  {
      this.dificulty = 0;
      this.nr_players = 1;
      this.player_computer = 1;
      this.init_game();
      this.targets= [[1, 5, 9]
                    ,[3, 5, 7]
                    ,[1, 2, 3]
                    ,[4, 5, 6]
                    ,[7, 8, 9]
                    ,[1, 4, 7]
                    ,[2, 5, 8]
                    ,[3, 6, 9]];
      this.statistics=[[0,0],[0,0],[0,0],[0,0]
                      ,[0,0],[0,0],[0,0],[0,0]];
      this.translater = translate;
      this.userLang = 'en';

      this.checkLanguage();
      this.getCurrentGame();
  }

  init_game()
  {
      this.player = 1;
      this.move = 0;
      this.moves = [0, 0, 0, 0, 0, 0, 0, 0, 0];
      this.board = ['', '', '', '', '', '', '', '', ''];
  }

 //** return 0 if is new or successfully reset */
  ask_new_game()
  {
    if(this.move != 0)
    {
      this.presentConfirm();
    }
  }
  presentConfirm() {
    let alert = this.alertCtrl.create({
      title: this.msgNewGame,
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
            this.move=0;
          }
        }
      ]
    });
    alert.present();
  }
  getCurrentGame()
  {
    var index;
    if(localStorage.getItem('dificulty') != null) 
      this.dificulty = parseInt(localStorage.getItem('dificulty'));
    if(localStorage.getItem('nr_players') != null) 
      this.nr_players = parseInt(localStorage.getItem('nr_players'));
    if(localStorage.getItem('player') != null) 
      this.player = parseInt(localStorage.getItem('player'));
    if(localStorage.getItem('move') != null) 
      this.move = parseInt(localStorage.getItem('move'));
    if(localStorage.getItem('player_computer') != null) 
      this.player_computer = parseInt(localStorage.getItem('player_computer'));
    if(this.move > 0)
    {
      for (index = 0; index < this.move; index++)
      {
        this.moves[index] = parseInt(localStorage.getItem('moves'+index));
        if(index % 2 == 0)
          this.board[this.moves[index]] = 'X';
        else
          this.board[this.moves[index]] = '0';
      }
    }
    for (index = 0; index < 8; index++)
      if(localStorage.getItem('statistics0'+index) != null)
      {
        this.statistics[index][0] = parseInt(localStorage.getItem('statistics0'+index));
        this.statistics[index][1] = parseInt(localStorage.getItem('statistics1'+index));
      }
  }

  saveCurrentGame()
  {
    var index;
    localStorage.setItem('dificulty', ''+this.dificulty);
    localStorage.setItem('nr_players', ''+this.nr_players);
    localStorage.setItem('player', ''+this.player);
    localStorage.setItem('move', ''+this.move);
    localStorage.setItem('player_computer', ''+this.player_computer);
    if(this.move > 0)
    {
      for (index = 0; index < this.move; index++) 
        localStorage.setItem('moves'+index, ''+this.moves[index]);
    }
    for (index = 0; index < 8; index++)
      {
        localStorage.setItem('statistics0'+index, ''+this.statistics[index][0]);
        localStorage.setItem('statistics1'+index, ''+this.statistics[index][1]);
      }
  }

  checkLanguage()
  {
    this.userLang = navigator.language.split('-')[0];
    this.userLang = /(ro|en)/gi.test(this.userLang) ? this.userLang : 'en';
 
   this.translater.setDefaultLang('en');
   this.translater.use(this.userLang);

   this.translater.get('NEW GAME').subscribe(   value => {
      this.msgNewGame = value; 
    } ) ;  
   this.translater.get('ARE YOU SURE TO START A NEW GAME?').subscribe(  value => {
      this.msgAreYouSure = value; 
    } ) ;  
   this.translater.get('YES').subscribe(   value => {
      this.msgYes = value; 
    } ) ; 
   this.translater.get('NO').subscribe(   value => {
      this.msgNo = value; 
    } ) ;    
  }

  togglePlayers()
  {
    this.ask_new_game();
    if(this.move == 0)
    {
      this.nr_players = 2 - this.nr_players;
      this.player_computer = 0;
      this.saveCurrentGame();
    }
  }

  toggleDifficulty(difi: number)
  {
    this.dificulty = difi;
  }
}

export class SchedulePage {
    constructor(translate: TranslateService) {
        // this language will be used as a fallback when a translation isn't found in the current language
        translate.setDefaultLang('en');
    }
}