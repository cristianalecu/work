import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';

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
   *  2 - Two players   */
  nr_players: number;

  /** Player who has to move
   *  0 - Player 2 (0)
   *  1 - Player 1 (X)   */
  player: number;

  /** 0 - Player 2 (0)  
   *  1 - Player 1 (X)    */
  player_computer: number;

  /** Move that has to be made - 0 based */
  move: number;    

  moves_hostory: Array<number>;

  constructor(public navCtrl: NavController) {
    this.getCurrentGame();
  }

  getCurrentGame(){
    if(localStorage.getItem('dificulty') != null) {
      this.dificulty = parseInt(localStorage.getItem('dificulty'));
    }
    else {
      this.dificulty = 0;
      this.nr_players = 1;
      this.player = 1;
      this.move = 0;
      this.player_computer = 0;
    }
  }
}
