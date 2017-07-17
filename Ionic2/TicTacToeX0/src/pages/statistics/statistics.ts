import { Component } from '@angular/core';
import { NavController, NavParams } from 'ionic-angular';

@Component({
  selector: 'page-statistics',
  templateUrl: 'statistics.html'
})

enum PlayerType 
{ User, Computer 
, LAN, Bluetooth   // for tuture use
}

type tPlayer = { name: string, id: number, pType: PlayerType, email?: string };

export class StatisticsPage {
  nrPlayers;
  players: Array<tPlayer>;

  constructor(public navCtrl: NavController, public navParams: NavParams) 
  {
    this.nrPlayers = 1;
    this.players[1] = {name:"Computer", id:1, pType: PlayerType.Computer, email:" "};
    this.getDefaults();
  }

  getDefaults(){
    if(localStorage.getItem('nrPlayers') != null) {
      this.nrPlayers = parseInt(localStorage.getItem('nrPlayers'));
    }
  }

  setDefaults(){
    localStorage.setItem('nrPlayers', this.nrPlayers);
    //this.navCtrl.push(HomePage);
  }
}
