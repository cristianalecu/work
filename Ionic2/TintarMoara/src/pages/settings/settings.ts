import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';
import { PlayerType, tPlayer } from '../../classes/player';

@Component({
  selector: 'page-settings',
  templateUrl: 'settings.html'
})

export class SettingsPage {
  nrPlayers: number = 0;
  player_user: number;
  player_oponent: number;
  players: Array<tPlayer>;
  oponents: Array<tPlayer>;
  scores: Array<Array<number>>;

  /** true if player 1 plays with X     
   *  flase if player 1 plays with 0          */
  playwith = false;

  /** true if player 1 plays with X or 0 always   */
  playwithalways = false;

  constructor(public navCtrl: NavController) 
  {
    this.players = Array();
    this.oponents = Array();
    this.scores = Array();
    this.getDefaults();
  }

  getDefaults(){
    this.player_user = parseInt(localStorage.getItem('player_user'));
    this.player_oponent = parseInt(localStorage.getItem('player_oponent'));
    this.playwith = (localStorage.getItem('playwith') == 'true') ? true : false;
    this.playwithalways = (localStorage.getItem('playwithalways') == 'true') ? true : false;
    this.nrPlayers = parseInt(localStorage.getItem('nrPlayers'));
    if(this.nrPlayers > 0)
    {
      var usr_name: string;
      var usr_type :PlayerType;
      var usr_id: number;
      var usr_email: string;
      var index : number;
      var nPoints : number;

      for (index = 0; index < this.nrPlayers; index++) 
      {
        usr_name = localStorage.getItem('usr_name'+index);
        usr_type = parseInt(localStorage.getItem('usr_type'+index));
        usr_id = parseInt(localStorage.getItem('usr_id'+index));
        usr_email = localStorage.getItem('usr_email'+index);
        if(usr_type == PlayerType.User)
          this.players[this.players.length] = { name: usr_name, id: usr_id, pType: usr_type, email: usr_email };
        if(usr_type == PlayerType.User || usr_type == PlayerType.Computer)
          this.oponents[this.oponents.length] = { name: usr_name, id: usr_id, pType: usr_type, email: usr_email };
        for (var index2 = 0; index2 < this.nrPlayers; index2++) 
        {
          nPoints = parseInt(localStorage.getItem('nPoints_'+index+"_"+index2));
          if(this.scores[index] == undefined)
            this.scores[index] = Array();
          this.scores[index][index2] = nPoints;
          nPoints = parseInt(localStorage.getItem('nPoints_'+index2+"_"+index));
          if(this.scores[index2] == undefined)
            this.scores[index2] = Array();
          this.scores[index2][index] = nPoints;
        }
      }
    }
  }

  forceNewGame()
  {
    localStorage.setItem('winner', '-1');
    localStorage.setItem('player', '1');
    localStorage.setItem('move', '0');
  }
  changePlaywith()
  {
    var playwith = (localStorage.getItem('playwith') == 'true') ? true : false;
    if(playwith != this.playwith)
    {
      localStorage.setItem('playwith', ""+this.playwith);
      this.forceNewGame();
    }
  }

  changePlaywithAlways()
  {
    var playwithalways = (localStorage.getItem('playwithalways') == 'true') ? true : false;
    if(playwithalways != this.playwithalways)
    {
      localStorage.setItem('playwithalways', ""+this.playwithalways);
      this.forceNewGame();
    }
  }  

  changePlayerUser()
  {
    var player_user = parseInt(localStorage.getItem('player_user'));
    if(player_user != this.player_user)
    {
      localStorage.setItem('player_user', ""+this.player_user);
      this.forceNewGame();
    }
  }

  changePlayerOponent()
  {
    var player_oponent = parseInt(localStorage.getItem('player_oponent'));
    if(player_oponent != this.player_oponent)
    {
      localStorage.setItem('player_oponent', ""+this.player_oponent);
      this.forceNewGame();
      if(this.player_oponent == 0)
        localStorage.setItem('secondPlayer', ""+this.player_user);
      else
        localStorage.setItem('secondPlayer', ""+this.player_oponent);
    }
  }
}