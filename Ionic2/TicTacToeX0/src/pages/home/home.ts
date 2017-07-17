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
  dificulty_save: number;
  
  /** 1 - Single player   
   *  2 - Two players     */
  nr_players: number;


  /** Player who has to move   
   *  0 - Player 2 (0)         
   *  1 - Player 1 (X)         */
  player: number;
  winner: number; // player that win current game
  player1name: string;
  player2name: string;
  computername: string;

  /** 1 if player 1 plays with X     
   *  0 if player 1 plays with 0   
   *  -1 does not matter           */
  playwith: number;

  /** 1 if player 1 plays with X or 0 always   */
  playwithalways: number;

  /** 0 - Player 2 (0)  
   *  1 - Player 1 (X)    */
  player_computer: number;

  /** 1 - Restart           
   *  2 - Change Players    
   *  3 - Change Dificulty  */
  newGameFor: number;

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
  msgSinglePlayer: string;
  msgTwoPlayers: string;
  msgPlayers: string;
  msgPlayer: string;
  msgWinner: string;

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
      this.winner = -1;
      this.player1name = "";
      this.player2name = "";
      this.computername = "";
      this.playwith = -1;
      this.playwithalways = -1;

      this.getCurrentGame();
      this.checkLanguage();      
  }

  init_game()
  {
      this.player = 1;
      this.move = 0;
      this.winner = -1;
      this.moves = [0, 0, 0, 0, 0, 0, 0, 0, 0];
      this.board = ['', '', '', '', '', '', '', '', ''];
  }

 //** return 0 if is new or successfully reset */
  ask_new_game()
  {
    this.msgPlayers = (this.nr_players == 1) ? this.msgSinglePlayer : this.msgTwoPlayers;
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
            if(this.newGameFor == 1) this.toggleNewGame();
            else if(this.newGameFor == 2) this.togglePlayers();
            else this.toggleDifficulty(this.dificulty_save);
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
    if(localStorage.getItem('winner') != null) 
      this.winner = parseInt(localStorage.getItem('winner'));
    if(localStorage.getItem('player1name') != null) 
      this.player1name = localStorage.getItem('player1name');
    if(localStorage.getItem('player2name') != null) 
      this.player2name = localStorage.getItem('player2name');
    if(localStorage.getItem('computername') != null) 
      this.computername = localStorage.getItem('computername');
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
    localStorage.setItem('winner', ''+this.winner);
    localStorage.setItem('player1name', ''+this.player1name);
    localStorage.setItem('player2name', ''+this.player2name);
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
    var lang;
    lang = navigator.language.split('-')[0];
    lang = /(ro|en)/gi.test(lang) ? lang : 'en';

    if(this.userLang == lang)
      return;
 
    this.userLang = lang;
    this.msgPlayers = (this.nr_players == 1) ? "SINGLE PLAYER" : "TWO PLAYERS";

   this.translater.setDefaultLang('en');
   this.translater.use(this.userLang);

   this.translater.get('NEW GAME').subscribe(   value => {
      this.msgNewGame = value; 
    });  
   this.translater.get('ARE YOU SURE TO START A NEW GAME?').subscribe(  value => {
      this.msgAreYouSure = value; 
    });  
   this.translater.get('YES').subscribe(   value => {
      this.msgYes = value; 
    }); 
   this.translater.get('NO').subscribe(   value => {
      this.msgNo = value; 
    });
    this.translater.get('SINGLE PLAYER').subscribe(  value => {
      this.msgSinglePlayer = value; 
      if(this.nr_players == 1)
        this.msgPlayers = value; 
    });
    this.translater.get('TWO PLAYERS').subscribe(   value => {
      this.msgTwoPlayers = value; 
      if(this.nr_players == 2)
        this.msgPlayers = value; 
    });
    this.translater.get('WINNER').subscribe(   value => {
      this.msgWinner = value; 
    });
    this.translater.get('PLAYER').subscribe(   value => {
      this.msgPlayer = value; 
    });
  }

  togglePlayers()
  {
    this.newGameFor = 2;
    this.ask_new_game();
    if(this.move == 0)
    {
      this.nr_players = 2 - this.nr_players;
      this.player_computer = 0;
      this.init_game();
      this.saveCurrentGame();
    }
  }

  getPlayers()
  {
    return (this.nr_players == 1) ? this.msgSinglePlayer : this.msgTwoPlayers;
  }

  toggleNewGame()
  {
    this.newGameFor = 1;
    this.ask_new_game();
    if(this.move == 0)
    {
      this.player_computer = 1 - this.player_computer;
      this.init_game();
      if(this.nr_players == 1 && this.player_computer == this.player) 
        this.playSuggest();
      this.saveCurrentGame();
    }
    this.logMsg = "";
  }

  playUndo()
  {
    if(this.move != 0)
    {
      this.board[this.moves[this.move-1]] = '';
      this.move--;
      this.player = 2 - this.player;
      if(this.nr_players == 1)
      {
        this.board[this.moves[this.move-1]] = '';
        this.move--;     
        this.player = 2 - this.player;   
      }
      this.saveCurrentGame();
      this.logMsg = "";
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
    var win = this.checkWinner(this.player);
    if(win >= 0)
    {
      this.showWinner(win);
    }
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
    var element = this.targets[target];
    if(this.player==1)
    {
      this.board[element[0]-1] = '(X)';
      this.board[element[1]-1] = '(X)';
      this.board[element[2]-1] = '(X)';
      this.statistics[this.dificulty][0] += 1;
      this.logMsg = this.msgWinner + ": " + this.msgPlayer + " 1 (X)";
    }
    else
    {
      this.board[element[0]-1] = '(0)';
      this.board[element[1]-1] = '(0)';
      this.board[element[2]-1] = '(0)';
      this.statistics[this.dificulty][1] += 1;
      this.logMsg = this.msgWinner + ": " + this.msgPlayer + " 2 (0)";
    }
  }

  toggleDifficulty(difi: number)
  {
    this.newGameFor = 3;
    this.dificulty_save = difi;
    this.ask_new_game();
    if(this.move == 0)
    {
      this.dificulty = difi;
      this.init_game();
      this.saveCurrentGame();
    }
  }
}

export class SchedulePage {
    constructor(translate: TranslateService) {
        // this language will be used as a fallback when a translation isn't found in the current language
        translate.setDefaultLang('en');
    }
}