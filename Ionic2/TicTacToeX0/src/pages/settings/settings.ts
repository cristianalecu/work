import { Component } from '@angular/core';
import { NavController, NavParams } from 'ionic-angular';
import { PlayerType, tPlayer } from '../../classes/player';

@Component({
  selector: 'page-settings',
  templateUrl: 'settings.html'
})

export class SettingsPage {
  nrPlayers: number;
  player_user: number;
  player_oponent: number;
  players: Array<tPlayer>;
  scores: Array<Array<number>>;

  /** 1 if player 1 plays with X     
   *  0 if player 1 plays with 0   
   *  -1 does not matter           */
  playwith: number;

  /** 1 if player 1 plays with X or 0 always   */
  playwithalways: number;

  constructor(public navCtrl: NavController, public navParams: NavParams) 
  {
    this.getDefaults();
  }

  getDefaults(){
    if(localStorage.getItem('nrPlayers') != null) {
      this.nrPlayers = parseInt(localStorage.getItem('nrPlayers'));
    }
    if(this.nrPlayers > 0)
    {
      var usr_name: string;
      var usr_type :PlayerType;
      var usr_id: number;
      var usr_email: string;
      var index : number;
      var nPoints : number;

      this.nrPlayers = parseInt(localStorage.getItem('nrPlayers'));
      for (index = 0; index < this.nrPlayers; index++) 
      {
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

  setDefaults(){
    localStorage.setItem('nrPlayers', ""+this.nrPlayers);
    //this.navCtrl.push(HomePage);
  }
}