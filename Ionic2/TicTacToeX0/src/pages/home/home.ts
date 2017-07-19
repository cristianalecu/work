import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';
import {TranslateService} from '@ngx-translate/core';
import { AlertController } from 'ionic-angular';
import { PlayerType, tPlayer } from '../statistics/statistics';

@Component({
  selector: 'page-home',
  templateUrl: 'home.html'
})

export class HomePage 
{
  version: number; //version of the storage
  /** 0 - Easy      
   *  1 - Normal     
   *  2 - Hard       
   *  3 - Extpert    */ 
  dificulty: number; 
  dificulty_save: number;

  /** Player who has to move   
   *  0 - Player 2 (0)         
   *  1 - Player 1 (X)         */
  player: number;
  winner: number; // player that win current game
  secondPlayer: number;

  /** 1 if player 1 plays with X     
   *  0 if player 1 plays with 0   
   *  -1 does not matter           */
  playwith: number;

  /** 1 if player 1 plays with X or 0 always   */
  playwithalways: number;

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

  translater: TranslateService;
  userLang: string;
  logMsg: string;

  msgNewGame: string;
  msgAreYouSure: string;
  msgYes: string;
  msgNo: string;
  msgSinglePlayer: string;
  msgTwoPlayers: string;
  msgPlayer: string;
  msgWinner: string;
  msgComputer: string;
  msgPlaysWith: string;

  // LIST OF PLAYERS
  nrPlayers: number;
  player_user: number;
  player_oponent: number;
  players: Array<tPlayer>;
  scores: Array<Array<number>>;

  constructor(public navCtrl: NavController, translate: TranslateService, private alertCtrl: AlertController) 
  {
      this.targets= [[1, 5, 9]
                    ,[3, 5, 7]
                    ,[1, 2, 3]
                    ,[4, 5, 6]
                    ,[7, 8, 9]
                    ,[1, 4, 7]
                    ,[2, 5, 8]
                    ,[3, 6, 9]];
      this.translater = translate;    
      this.userLang = 'en';  
      this.init_game();

      this.version = 1;
      this.dificulty = 0;    
      this.winner = -1;
      this.playwith = 1;
      this.playwithalways = 0;

      this.player_user = 1;    //current user - Player 1
      this.player_oponent = 0; //Computer
      this.secondPlayer = 1;
      this.nrPlayers = 2;
      this.players = [];
      this.players[0] = {name:"", id:0, pType: PlayerType.Computer, email:""};    
      this.players[1] = {name:"", id:1, pType: PlayerType.User, email:""};
      this.scores=[[0,0],[0,0]];

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
    if(localStorage.getItem('version') != null) 
    {
      this.version = parseInt(localStorage.getItem('version'));
    }
    if(localStorage.getItem('dificulty') != null) 
      this.dificulty = parseInt(localStorage.getItem('dificulty'));
    if(localStorage.getItem('winner') != null) 
      this.winner = parseInt(localStorage.getItem('winner'));
    if(localStorage.getItem('player') != null) 
      this.player = parseInt(localStorage.getItem('player'));
    if(localStorage.getItem('playwith') != null) 
      this.playwith = parseInt(localStorage.getItem('playwith'));
    if(localStorage.getItem('playwithalways') != null) 
      this.playwithalways = parseInt(localStorage.getItem('playwithalways'));
    if(localStorage.getItem('player_user') != null) 
      this.player_user = parseInt(localStorage.getItem('player_user'));
    if(localStorage.getItem('player_oponent') != null) 
      this.player_oponent = parseInt(localStorage.getItem('player_oponent'));
    if(localStorage.getItem('secondPlayer') != null) 
      this.secondPlayer = parseInt(localStorage.getItem('secondPlayer'));
    if(localStorage.getItem('move') != null) 
      this.move = parseInt(localStorage.getItem('move'));
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
    if(localStorage.getItem('nrPlayers') != null) 
    {
      var usr_name: string;
      var usr_type :PlayerType;
      var usr_id: number;
      var usr_email: string;
      var nPoints: number;

      this.nrPlayers = parseInt(localStorage.getItem('nrPlayers'));
      for (index = 0; index < this.nrPlayers; index++) {
        usr_name = localStorage.getItem('usr_name'+index);
        usr_type = parseInt(localStorage.getItem('usr_type'+index));
        usr_id = parseInt(localStorage.getItem('usr_id'+index));
        usr_email = localStorage.getItem('usr_email'+index);
        if(! isNaN(usr_id))
          this.players[index] = { name: usr_name, id: usr_id, pType: usr_type, email: usr_email };
        for (var index2 = 0; index2 < this.nrPlayers; index2++) {
          nPoints = parseInt(localStorage.getItem('nPoints_'+index+"_"+index2));
          if(! isNaN(nPoints))
          {
            if(this.scores[index] == undefined)
              this.scores[index] = Array();
            this.scores[index][index2] = nPoints;
          }

          if(! isNaN(nPoints))
          {
            nPoints = parseInt(localStorage.getItem('nPoints_'+index2+"_"+index));
            if(this.scores[index2] == undefined)
              this.scores[index2] = Array();
            this.scores[index2][index] = nPoints;
          }
        }
      }
    }
  }

  saveCurrentGame()
  {
    var index, index2;
    localStorage.setItem('version', ''+this.version);
    localStorage.setItem('dificulty', ''+this.dificulty);
    localStorage.setItem('winner', ''+this.winner);
    localStorage.setItem('playwith', ''+this.playwith);
    localStorage.setItem('playwithalways', ''+this.playwithalways);
    localStorage.setItem('player_user', ''+this.player_user);
    localStorage.setItem('player_oponent', ''+this.player_oponent);
    localStorage.setItem('secondPlayer', ''+this.secondPlayer);
    localStorage.setItem('player', ''+this.player);
    localStorage.setItem('move', ''+this.move);
    if(this.move > 0)
    {
      for (index = 0; index < this.move; index++) 
        localStorage.setItem('moves'+index, ''+this.moves[index]);
    }
    localStorage.setItem('nrPlayers', ''+this.nrPlayers);
    for (index = 0; index < this.nrPlayers; index++) 
    {
      localStorage.setItem('usr_name'+index, ''+this.players[index].name);
      localStorage.setItem('usr_id'+index, ''+this.players[index].id);
      localStorage.setItem('usr_type'+index, ''+this.players[index].pType);
      localStorage.setItem('usr_email'+index, ''+this.players[index].email);
      for (index2 = 0; index2 < this.nrPlayers; index2++) 
      {
        localStorage.setItem('nPoints_'+index+"_"+index2, ''+this.scores[index][index2]);
        localStorage.setItem('nPoints_'+index2+"_"+index, ''+this.scores[index2][index]);
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
    this.msgPlayer = "Player";
    this.msgSinglePlayer = "Single player";
    this.msgTwoPlayers = "Two players";
    this.msgComputer = "Computer";

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
    });
    this.translater.get('TWO PLAYERS').subscribe(   value => {
      this.msgTwoPlayers = value; 
    });
    this.translater.get('WINNER').subscribe(   value => {
      this.msgWinner = value; 
    });
    this.translater.get('PLAYER').subscribe(   value => {
      this.msgPlayer = value; 
      if(this.players[1].name == "")
      {
        this.players[1].name = this.msgPlayer + " 1";
        this.saveCurrentGame();
      }
    });
    this.translater.get('PLAYS WITH').subscribe(   value => {
      this.msgPlaysWith = value; 
    });
    this.translater.get('COMPUTER').subscribe(   value => {
      this.msgComputer = value; 
      if(this.players[0].name == "")
      {
        this.players[0].name = this.msgComputer;
        this.saveCurrentGame();
      }
    });
  }

  togglePlayers()
  {
    this.newGameFor = 2;
    this.ask_new_game();
    if(this.move == 0)
    {
      this.player_oponent = this.player_oponent ? 0 : this.secondPlayer;
      this.init_game();
      this.saveCurrentGame();
    }
    this.logMsg = "";
  }

  getPlayers()
  {
    return (this.player_oponent == 0) ? this.msgSinglePlayer : this.msgTwoPlayers;
  }

  getPlayerToMove()
  {
    var player: tPlayer;

    if(this.player == this.playwith)
      player = this.players[this.player_user];
    else
      player = this.players[this.player_oponent];
    
    return player.name + " " + this.msgPlaysWith + " " + ((this.player == 1) ? 'X' : "0");
  }

  toggleNewGame()
  {
    this.newGameFor = 1;
    this.ask_new_game();
    if(this.move == 0)
    {
      if(this.playwithalways != 1)
        this.playwith = (this.playwith == 1) ? 0 : 1;
      this.init_game();
      if(this.player_oponent == 0 && this.playwith != this.player) 
        this.playSuggest();
      this.saveCurrentGame();
    }
    this.logMsg = "";
  }

  getScore()
  {
    return this.players[this.player_user].name + " - " + this.players[this.player_oponent].name + " : " + 
        this.scores[this.players[this.player_user].id][this.players[this.player_oponent].id] + " - " + this.scores[this.players[this.player_oponent].id][this.players[this.player_user].id];
  }

  playUndo()
  {
    var player: tPlayer;
    if(this.move != 0)
    {
      this.board[this.moves[this.move-1]] = '';
      this.move--;
      this.player = 1 - this.player;
      if(this.player == this.playwith)
        player = this.players[this.player_user];
      else
        player = this.players[this.player_oponent];
      if(player.pType == PlayerType.Computer && this.winner != -1) //if player wins, the computer don't move any more
      {
        this.board[this.moves[this.move-1]] = '';
        this.move--;     
        this.player = 1 - this.player;   
      }
      if(this.winner != -1)
      {
        this.winner = -1;
        for (var index = 0; index < this.board.length; index++) 
          if(this.board[index].length > 1)
            this.board[index] = this.board[index].charAt(1);
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
      this.winner = this.player;
      this.showWinner(win);
    }
    this.player = 1 - this.player;
    this.saveCurrentGame();
  }

  playMove(button: number)
  {
    var win:number;
    var player: tPlayer;
    
    if(this.board[button] == '' && this.winner == -1)
    {
      this.board[button] = (this.player == 1) ? 'X' : '0';
      this.moves[this.move] = button;
      this.move++;      
      win = this.checkWinner(this.player);
      if(win >= 0)
      {
        this.winner = this.player;
        this.showWinner(win);
      }
      else
      {
        this.player = 1 - this.player;
        if(this.player == this.playwith)
          player = this.players[this.player_user];
        else
          player = this.players[this.player_oponent];
        if(player.pType == PlayerType.Computer)
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
      if(this.playwith == 1)
      {
        this.scores[this.player_user][this.player_oponent] += 1;
        this.logMsg = this.msgWinner + ": " + this.players[this.player_user].name + " (X)";
      }
      else
      {
        this.scores[this.player_oponent][this.player_user] += 1;
        this.logMsg = this.msgWinner + ": " + this.players[this.player_oponent].name + " (X)";
      }
    }
    else
    {
      this.board[element[0]-1] = '(0)';
      this.board[element[1]-1] = '(0)';
      this.board[element[2]-1] = '(0)';
      if(this.playwith == 1)
      {
        this.scores[this.player_oponent][this.player_user] += 1;
        this.logMsg = this.msgWinner + ": " + this.players[this.player_oponent].name + " (0)";
      }
      else
      {
        this.scores[this.player_user][this.player_oponent] += 1;
        this.logMsg = this.msgWinner + ": " + this.players[this.player_user].name + " (0)";
      }
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