import { Component } from '@angular/core';
import { NavController, NavParams } from 'ionic-angular';
import { PlayerType, tPlayer } from '../../classes/player';

@Component({
  selector: 'page-players',
  templateUrl: 'players.html'
})
export class PlayersPage {

  constructor(public navCtrl: NavController) {
  }
  
}
