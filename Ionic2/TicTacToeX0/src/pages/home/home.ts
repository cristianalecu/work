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
  msgSinglePlater: string;
  msgTwoPlayers: string;
  msgPlayers: string;

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
    this.msgPlayers = (this.nr_players == 1) ? this.msgSinglePlater : this.msgTwoPlayers;
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
    this.translater.get('SINGLE PLAYER').subscribe(   value => {
      this.msgSinglePlater = value; 
    } ) ;
    this.translater.get('TWO PLAYERS').subscribe(   value => {
      this.msgTwoPlayers = value; 
    } ) ;  
  }

  togglePlayers()
  {
    this.ask_new_game();
    if(this.move == 0)
    {
      this.nr_players = 2 - this.nr_players;
      this.msgPlayers = (this.nr_players == 1) ? this.msgSinglePlater : this.msgTwoPlayers;
      this.player_computer = 0;
      this.saveCurrentGame();
    }
  }

  toggleNewGame()
  {
    this.ask_new_game();
    if(this.move == 0)
    {
      this.player_computer = 1 - this.player_computer;
      this.saveCurrentGame();
    }
  }

  playUndo()
  {
    if(this.move != 0)
    {
      this.board[this.moves[this.move-1]] = '';
      this.move--;
      this.player = 2 - this.player;
      if(this.player_computer == 1)
      {
        this.board[this.moves[this.move-1]] = '';
        this.move--;     
        this.player = 2 - this.player;   
      }
      this.saveCurrentGame();
    }
  }

  playSuggest()
  {
    var move: number;

    move = Math.floor((Math.random() * 10));
    while (this.board[move] != '') 
    {
      move++;
      if(move > 9) 
        move = 0;
    }
    
    this.board[move] = (this.player == 1) ? 'X' : '0';
    this.moves[this.move] = move;
    this.move++;
    this.player = 1 - this.player;
    this.saveCurrentGame();
  }

  playMove(button: number)
  {
    var win:number;
    if(this.board[button] == '')
    {
      this.board[button] = (this.player == 1) ? 'X' : '0';
      this.moves[this.move] = button;
      this.move++;      
    }
    win = this.checkWinner(this.player);
    if(win >= 0)
    {
      this.showWinner(win);
    }
    else
    {
      this.player = 1 - this.player;
      if(this.nr_players == 1)
        this.playSuggest();
      else
        this.saveCurrentGame();
    }
  }  

  /** Returns target line index if the player wins   
   *         -1 otherwise    */
  checkWinner( player:number)
  {
    var index: number; 
    
    for (index = 0; index < this.targets.length; index++) {
      var element = this.targets[index];
      
      if(player==1)
      {
         if(this.board[element[0]-1] == 'X' && this.board[element[1]-1] == 'X' && this.board[element[2]-1] == 'X')
           return index;
      }
      else
      {
         if(this.board[element[0]-1] == '0' && this.board[element[1]-1] == '0' && this.board[element[2]-1] == '0')
           return index;
      }
    }
    return -1;
  }

  showWinner(target: number)
  {
    this.targets.forEach(element => {
      if(this.board[element[0]-1] == 'X' && this.board[element[1]-1] == 'X' && this.board[element[2]-1] == 'X')
        return 1;
      else if(this.board[element[0]-1] == '0' && this.board[element[1]-1] == '0' && this.board[element[2]-1] == '0')
        return 0;
    });
    return -1;
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