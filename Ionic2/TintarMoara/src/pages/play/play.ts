import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';
import {TranslateService} from '@ngx-translate/core';
import { AlertController } from 'ionic-angular';
import { PlayerType, tPlayer } from '../../classes/player';

@Component({
  selector: 'page-play',
  templateUrl: 'play.html'
})

export class PlayPage 
{
  /** version of the storage  */
  version: number;

  /** 0 - Easy      
   *  1 - Normal     
   *  2 - Hard       
   *  3 - Extpert    */ 
  dificulty: number; 
  /** temp for new dificulty during play  */
  dificulty_save: number;

  /** Player who has to move   
   *  0 - Black player             
   *  1 - White player         */
  player: number;
  /** player that win current game  */
  winner: number;
  /** if you switch on two players  */
  secondPlayer: number;

  /** 1 if I play with white     
   *  0 if I play with black   
   *  -1 does not matter           */
  playwith: number;

  /** 1 if I play with white or black always   */
  playwithalways: number;

  /**  black and white pieces remained to use */
  piecesToUse: Array<number> = [9, 9];
  /**  pieces taken by black and white player */
  piecesTaken: Array<number> = [0, 0];

  /** 1 - Restart           
   *  2 - Change Players    
   *  3 - Change Dificulty  */
  newGameFor: number;

  /** Move that has to be made - 0 based */
  move: number;    

  /** Processing board table, not yet displayed  
   *   0 -- --  1 -- --  2  
   *  ||  3 --  4 --  5 ||    
   *  || ||  6  7  8 || ||    
   *   9 10 11    12 13 14    
   *  || || 15 16 17 || ||    
   *  || 18 -- 19 -- 20 ||    
   *  21 -- -- 22 -- -- 23      */
  board: Array<number> = new Array(24);
  /** Processing board table, not yet displayed  
   *  01 -- -- 04 -- -- 07  
   *  || 09 -- 11 -- 13 ||    
   *  || || 17 18 19 || ||    
   *  22 23 24    26 27 28    
   *  || || 31 32 33 || ||    
   *  || 37 -- 39 -- 41 ||    
   *  43 -- -- 46 -- -- 49      */
  board_map: Array<number> =[1, 4, 7, 9, 11, 13, 17, 18, 19, 22, 23, 24, 26, 27, 28, 31, 32, 33, 37, 39, 41, 43, 46, 49];
  /** better view in debug for the table with pieces */
  board_table: Array<string> = [
       '0--0--0',
       '|0-0-0|',
       '||000||',
       '000 000',
       '||000||',
       '|0-0-0|',
       '0--0--0'];
  /** better view in debug for the table with order of moves */
  board_table2: Array<string> = [
    '   -- --    -- --   ',
    '||    --    --    ||',
    '|| ||          || ||',
    '                    ',
    '|| ||          || ||',
    '||    --    --    ||',
    '   -- --    -- --   '];

  /** what the user see  */
  board_show: Array<string> = new Array(49);

  /** list of moves          
   *  - Odds for white player    
   *  - Evens for black player   */
  moves: Array<Array<number>> = new Array();
  /** all possible moves - moving from 24 is placing a new piece on table */
  moves_allowed: Array<Array<number>> = [
    [1, 9],     // moves from 0 
    [0, 2, 4],  // moves from 1
    [1, 14],    // etc.
    [4, 10],
    [1, 3, 5, 7],
    [4, 13],
    [7, 11],
    [4, 6, 8],
    [7, 12],
    [0, 10, 21],
    [3, 9, 11, 18], // moves from 10
    [6, 10, 15],
    [8, 13, 17],
    [5, 12 ,14, 20],
    [2, 13, 23],
    [11, 16],
    [15, 17, 19],
    [12, 16],
    [10, 19],
    [16, 18,20, 22],
    [13, 19],       // moves from 10
    [9, 22],
    [19, 21, 23],
    [14, 22],
    [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,14,15,16,17,18,19,20,21,22,23] //moves from outside pplace on board
  ];
  /** winning positions  */
  targets: Array<Array<number>> = [[0,1,2],
                                 [3,4,,5],
                                 [6,7,8],
                                 [9,10,11],
                                 [12,13,14],
                                 [15,16,17],
                                 [18,19,20],
                                 [21,22,23],
                                 [0,9,21],
                                 [3,10,18],
                                 [6,11,15],
                                 [1,4,7],
                                 [16,19,22],
                                 [8,12,17],
                                 [5,13,20],
                                 [2,14,23]];

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
  locPlayers:Array<number>;
  scores: Array<Array<number>>;

  /** how many moves ahead is */
  depthSearch:number;
  /** how many moves ahead was looking maximum */
  maxDepthSearch;
  /** how many moves ahead to look maximum is planned */
  maxDepthSearchLimit;
  /** how many moves checked in total until now */
  checks;

  constructor(public navCtrl: NavController, translate: TranslateService, private alertCtrl: AlertController) 
  {
    var index = 0;

      this.translater = translate;    
      this.userLang = '';  
      this.init_game();

      this.version = 1;
      this.dificulty = 0;    
      this.playwith = 1;
      this.playwithalways = 0;

      /** current user - Player 1 */
      this.player_user = 1; 
      /** if you select second player */
      this.secondPlayer = 1;
      /** Computer or second player */
      this.player_oponent = 0; 
      this.nrPlayers = 2;
      this.players = [];
      this.players[0] = {name:"", id:0, pType: PlayerType.Computer, email:""};    
      this.players[1] = {name:"", id:1, pType: PlayerType.User, email:""};
      this.scores=[[0,0],[0,0]];

      this.msgWinner = "Winner";

      this.getSettings();
      this.getCurrentGame();
      this.checkLanguage();      
  }

  /**  A player has max 9 pieces to use and max 7 pieces taken     
   *   This function tell if it has more that 7 in total       */
  showOutboardSecondLine(position: number)
  {
    if(position == 0)  // oponent
    {
      if(this.playwith == 1)
      {
        if( (this.piecesToUse[0] + this.piecesTaken[0]) > 7)
          return 1;
      }
      else
      {
        if( (this.piecesToUse[1] + this.piecesTaken[1]) > 7)
          return 1;
      }
    }
    else
    {
      if(this.playwith == 0)
      {
        if( (this.piecesToUse[0] + this.piecesTaken[0]) > 7)
          return 1;
      }
      else
      {
        if( (this.piecesToUse[1] + this.piecesTaken[1]) > 7)
          return 1;
      }
    }

    return 0;
  }

  /**  Image filename for the pieces  */  
  imgPiece(position: number)
  {
    if(position <= 14)  //first two lines - Oponent pieces To Use and Taken
    {
      if(position <= this.piecesToUse[0])
        return "assets/img/" + ( (this.playwith) );
    }
    else if(position > 56 )  //last two lines - My pieces To Use and Taken
    {

    }
    else
      return "assets/img/b.jpg";
    return  "assets/img/0.jpg";
  }

  board2table(show: boolean)
  {
    var index, line, col;

    for (index = 0; index < this.board.length; index++) 
    {
      line = index / 7;
      col = index % 7;
      if(this.board[index] == -1)
      {
        //this.board_table[line][col] = '0';
      }
    }

  }

  init_game()
  {
    var index;
    this.piecesToUse[0] = 9;  //black
    this.piecesToUse[1] = 9;  //white
    this.piecesTaken[0] = 0;
    this.piecesTaken[1] = 0;

      this.player = 1;
      this.move = 0;
      this.winner = -1;
      for (index = 0; index < this.moves.length; index++) 
      {
        if(this.moves[index]===undefined)
          this.moves[index] = [];
        this.moves[index][0] = -1;
        this.moves[index][1] = -1;
        this.moves[index][2] = -1;
      }
      for (index = 0; index < this.board.length; index++) 
        this.board[index] = -1;

    this.board2table(true);
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

  getSettings()
  {
    if(localStorage.getItem('playwith') != null) 
    {
      this.playwith = parseInt(localStorage.getItem('playwith'));
      if(isNaN(this.playwith))
        this.playwith = (localStorage.getItem('playwith') == 'true') ? 1 : 0;
    }
    if(localStorage.getItem('playwithalways') != null) 
    {
      this.playwithalways = parseInt(localStorage.getItem('playwithalways'));
      if(isNaN(this.playwithalways))
        this.playwithalways = (localStorage.getItem('playwithalways') == 'true') ? 1 : 0;
    }
    if(localStorage.getItem('player_user') != null) 
      this.player_user = parseInt(localStorage.getItem('player_user'));
    if(localStorage.getItem('player_oponent') != null) 
      this.player_oponent = parseInt(localStorage.getItem('player_oponent'));
    if(localStorage.getItem('secondPlayer') != null) 
      this.secondPlayer = parseInt(localStorage.getItem('secondPlayer'));    

    this.locPlayers = Array(0, this.player_user);
    if(this.player_user != this.secondPlayer)
      this.locPlayers[2] = this.secondPlayer;
    if(localStorage.getItem('nrPlayers') != null) 
    {
      var usr_name: string;
      var usr_type :PlayerType;
      var usr_id: number;
      var usr_email: string;
      var nPoints: number;

      this.nrPlayers = parseInt(localStorage.getItem('nrPlayers'));    
      for (var index = 0; index < this.locPlayers.length; index++) 
      {
        usr_name = localStorage.getItem('usr_name'+this.locPlayers[index]);
        usr_type = parseInt(localStorage.getItem('usr_type'+this.locPlayers[index]));
        usr_id = parseInt(localStorage.getItem('usr_id'+this.locPlayers[index]));
        usr_email = localStorage.getItem('usr_email'+this.locPlayers[index]);
        this.players[this.locPlayers[index]] = { name: usr_name, id: usr_id, pType: usr_type, email: usr_email };
        for (var index2 = 0; index2 < this.locPlayers.length; index2++) 
        {
          nPoints = parseInt(localStorage.getItem('nPoints_'+this.locPlayers[index]+"_"+this.locPlayers[index2]));
          if(this.scores[this.locPlayers[index]] == undefined)
              this.scores[this.locPlayers[index]] = Array();
          this.scores[this.locPlayers[index]][this.locPlayers[index2]] = nPoints;

          nPoints = parseInt(localStorage.getItem('nPoints_'+this.locPlayers[index2]+"_"+this.locPlayers[index]));
          if(this.scores[this.locPlayers[index2]] == undefined)
            this.scores[this.locPlayers[index2]] = Array();
          this.scores[this.locPlayers[index2]][this.locPlayers[index]] = nPoints;
        }
      }
    }
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
    if(localStorage.getItem('move') != null) 
      this.move = parseInt(localStorage.getItem('move'));
    if(this.move > 0)
    {
      for (index = 0; index < this.move; index++)
      {
        this.moves[index][0] = parseInt(localStorage.getItem('moves0'+index));
        this.moves[index][1] = parseInt(localStorage.getItem('moves1'+index));
        if(index % 2 == 0)
          this.board[this.moves[index]] = 'X';
        else
          this.board[this.moves[index]] = '0';
      }
    }

    var win = this.checkWinner(this.player);
    if(win >= 0)
    {
      this.winner = this.player;
      this.showWinner(win);
    }
    
  }

  saveCurrentGame()
  {
    var index, index2;
    localStorage.setItem('version', ''+this.version);
    localStorage.setItem('dificulty', ''+this.dificulty);
    localStorage.setItem('winner', ''+this.winner);
    localStorage.setItem('player', ''+this.player);
    localStorage.setItem('move', ''+this.move);
    localStorage.setItem('player_oponent', ''+this.player_oponent);
    if(this.move > 0)
    {
      for (index = 0; index < this.move; index++) 
        localStorage.setItem('moves'+index, ''+this.moves[index]);
    }
    if(this.nrPlayers == 2)
    {
      localStorage.setItem('playwith', ''+this.playwith);
      localStorage.setItem('playwithalways', ''+this.playwithalways);
      localStorage.setItem('player_user', ''+this.player_user);
      localStorage.setItem('secondPlayer', ''+this.secondPlayer);
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
    else
    {
      localStorage.setItem('nPoints_'+this.player_user+"_"+this.player_oponent, ''+this.scores[this.player_user][this.player_oponent]);
      localStorage.setItem('nPoints_'+this.player_oponent+"_"+this.player_user, ''+this.scores[this.player_oponent][this.player_user]);
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
      var win = this.checkWinner(this.player);
      if(win >= 0)
      {
        this.winner = this.player;
        this.showWinner(win);
      }
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
      if(this.playwith == 0)
        this.playComputer(0);
      this.saveCurrentGame();
      this.logMsg = "";
    }
  }

  getPlayers()
  {
    return (this.player_oponent == 0) ? this.msgTwoPlayers : this.msgSinglePlayer;
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
        this.playComputer(0);
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
      if(this.winner >= 0)
        this.adjustScore(-1);
      else
        this.player = 1 - this.player;

      this.board[this.moves[this.move-1]] = '';
      this.move--;
      
      if(this.player == this.playwith)
        player = this.players[this.player_user];
      else
        player = this.players[this.player_oponent];

      //if(player.pType == PlayerType.Computer && this.winner == -1) //if player wins, the computer don't move any more
      if(player.pType == PlayerType.Computer)
      {
        if(this.move != 0)
        {
          this.board[this.moves[this.move-1]] = '';
          this.move--;     
          this.player = 1 - this.player;   
        }
        else
          this.playComputer(0);
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
    var player;
    if(this.winner == -1 && this.move < 9)
    {
      this.playComputer(1);
      if(this.player == this.playwith)
        player = this.players[this.player_user];
      else
        player = this.players[this.player_oponent];

      if(this.winner == -1 && player.pType == PlayerType.Computer)
        this.playComputer(0);
    }
  }

  playComputer(bIsSuggest: number)
  {
    if(bIsSuggest == 0)
    {                      // computer
      if(this.dificulty == 0 && this.move < 4)
        this.playRandom();
      else if(this.dificulty == 1 && this.move < 2)
        this.playRandom();
      else
      {
        //this.playLogic();
        this.depthSearch = 0;
        this.maxDepthSearch = 0;
        this.checks = 0;
        this.playMove(this.getMinMax(this.player));
      }
    }
    else
    {                     // sugest
      this.depthSearch = 0;
      this.maxDepthSearch = 0;
      this.checks = 0;
      this.playMove(this.getMinMax(this.player));
    }
  }

  playRandom()
  {
    var move: number;
    var moves: number;

    moves = 0;
    move = Math.floor((Math.random() * 10));
    while (this.board[move] != '' && moves < 11) 
    {
      moves++;
      move++;
      if(move > 9) 
        move = 0;
    }
    if(moves >= 11)
    {
      return;
    }
    this.playMove(move);
  }

  playLogic()
  {
    var move: number;

    var mymove=(this.player == 1) ? 'X' : '0';
    var yourmove=(this.player == 1) ? '0' : 'X';
    move = this.hasWinningMove(this.player);
    if(move == -1)
    {
      move = this.hasWinningMove(1-this.player); //cancel oponent win
      if(move == -1)
      {
        if(this.board[4] == '') //take center first
          move = 4;
        else if (this.board[4] == mymove)
        {
          if(this.board[0] == '' && this.board[8] == '') //then take corners
            move = 0;   
          else if(this.board[2] == '' && this.board[6] == '')
            move = 2;   
          else if(this.board[8] == '' && this.board[0] == '') 
            move = 8;   
          else if(this.board[6] == '' && this.board[2] == '')
            move = 6;   
          else if(this.board[1] == '' && this.board[7] == '') //then take middles
            move = 1;   
          else if(this.board[5] == '' && this.board[3] == '')
            move = 5;   
          else if(this.board[7] == '' && this.board[1] == '')
            move = 7;  
          else if(this.board[3] == '' && this.board[5] == '')
            move = 3;
        }
        else
        {
          if(this.board[0] == '' && ((this.board[1] != yourmove && this.board[2] != yourmove) || 
                                     (this.board[3] != yourmove && this.board[3] != yourmove))) //take corners
            move = 0;   
          else if(this.board[8] == '' && ((this.board[7] != yourmove && this.board[8] != yourmove) || 
                                          (this.board[0] != yourmove && this.board[3] != yourmove))) 
            move = 0; 
          else if(this.board[2] == '' && ((this.board[5] != yourmove && this.board[8] != yourmove) || 
                                          (this.board[0] != yourmove && this.board[1] != yourmove))) 
            move = 0; 
          else if(this.board[6] == '' && ((this.board[7] != yourmove && this.board[8] != yourmove) || 
                                          (this.board[0] != yourmove && this.board[3] != yourmove))) 
            move = 0; 
        }
        if(move == -1)
        {
          for (var index = 0; index < 9; index++) 
          { //take any remaining
            if (this.board[index] == '')
              move = index;
          }
        }
      }
    }
    
    this.playMove(move);
  }
  
  hasWinningMove(player: number)
  {
    var win;
    for (var index = 0; index < 9; index++) 
      {
        if(this.board[index] == '')
        {
          this.board[index] = (player == 1) ? 'X' : '0';
          win = this.checkWinner(player); //cancel oponent win
          this.board[index] = '';
          if(win >= 0)
            return index;
        }
      }
    return -1;
  }

  getMinMax(player: number)
  {
    /** Wins versus loses */
    var score:number = -2;
    var moveCount:number = 0; // moves checked in this loop
    var bestScore:number = -2;
    var bestMove:number = -1;

    this.checks++;
    if(this.depthSearch > this.maxDepthSearch)
      this.maxDepthSearch = this.depthSearch;

    if(this.depthSearch > 0)
    {
      score = this.EvalForWin(player); // 0 1 2
      if(score != 0)                   // 3 4 5
        return score;                  // 6 7 8 
    }

    for (var index = 0; index < 9; index++) 
    {
      if(this.board[index] == '')
      {
        moveCount++;
        this.board[index] = (player == 1) ? 'X' : '0';
        this.depthSearch++;
        this.moves[this.move] = index;
        this.move++;  
        score=-this.getMinMax(1-player);
        if(score > bestScore)
        {
          bestScore = score;
          bestMove=index;
        }
        this.board[index] = '';
        this.depthSearch--;
        this.move--;
        if(bestScore == 1)
          break;
      }
    }
    if(moveCount == 0)
      return this.EvalForWin(player);

    if(this.depthSearch > 0)
      return bestScore;
    else
      return bestMove;
  }

  EvalForWin(player: number)
  {
    if(this.checkWinner(player) >= 0)
      return 1;
    else if (this.checkWinner(1-player) >= 0)
      return -1;
    else 
      return 0;
  }

  playMove(move: number)
  {
    var win:number;
    var player: tPlayer;
    
    if(this.board[move] == '' && this.winner == -1)
    {
      this.board[move] = (this.player == 1) ? 'X' : '0';
      this.moves[this.move] = move;
      this.move++;      
      win = this.checkWinner(this.player);
      if(win >= 0)
      {
        this.winner = this.player;
        this.showWinner(win);
        this.adjustScore(1);
        this.saveCurrentGame();
      }
      else
      {
        this.player = 1 - this.player;
        if(this.player == this.playwith)
          player = this.players[this.player_user];
        else
          player = this.players[this.player_oponent];
        if(player.pType == PlayerType.Computer)
          this.playComputer(0);
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

  adjustScore(value: number)
  {
    if(this.player_user != this.player_oponent)
      if(this.player==this.playwith)
        this.scores[this.player_user][this.player_oponent] += value;
      else
        this.scores[this.player_oponent][this.player_user] += value;
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
        this.logMsg = this.msgWinner + ": " + this.players[this.player_user].name + " (X)";
      else
        this.logMsg = this.msgWinner + ": " + this.players[this.player_oponent].name + " (X)";
    }
    else
    {
      this.board[element[0]-1] = '(0)';
      this.board[element[1]-1] = '(0)';
      this.board[element[2]-1] = '(0)';
      if(this.playwith == 1)
        this.logMsg = this.msgWinner + ": " + this.players[this.player_oponent].name + " (0)";
      else
        this.logMsg = this.msgWinner + ": " + this.players[this.player_user].name + " (0)";
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
      if(this.playwith == 0)
        this.playComputer(0);
      this.saveCurrentGame();
      this.logMsg = "";
    }
  }
}

export class SchedulePage {
    constructor(translate: TranslateService) {
        // this language will be used as a fallback when a translation isn't found in the current language
        translate.setDefaultLang('en');
    }
}