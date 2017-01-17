import { Injectable } from '@angular/core';
import { Hero } from '../classes/hero';
import { HEROES } from '../mocks/mock-heroes';

@Injectable()
export class HeroService {
    // getHeroes(): Hero[] {
    //     return HEROES;
    // }

    getHeroes(): Promise<Hero[]> {
        //return Promise.resolve(HEROES);
        return new Promise(resolve => {
            // Simulate server latency with 2 second delay
            setTimeout(() => resolve(this.getHeroes()), 5000);
        });
    }
}