import { Component } from '@angular/core';
import { NavController, NavParams } from 'ionic-angular';

@Component({
  selector: 'page-statistics',
  templateUrl: 'statistics.html'
})

export class StatisticsPage {
  nrPlayers: number;
  player_user: number;
  player_oponent: number;
  players: Array<tPlayer>;

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
      var usr_type :tPlayer;
      var usr_id: number;
      var usr_email: string;

      //for (var index = 0; index < this.nrPlayers; index++) 
      //{
      //  usr_id = parseInt(localStorage.getItem('nrPlayers'));
      //  //this.players[index] = ;
      //}
    }
  }

  setDefaults(){
    localStorage.setItem('nrPlayers', ""+this.nrPlayers);
    //this.navCtrl.push(HomePage);
  }
}

export enum PlayerType 
{ User, Computer 
, LAN, Bluetooth   // for tuture use
}

export type tPlayer = { name: string, id: number, pType: PlayerType, email?: string };

