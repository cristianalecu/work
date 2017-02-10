import { Component } from '@angular/core';
import { PostsService } from '../services/posts.service';

@Component({
    moduleId: module.id,
    selector: 'user',
    templateUrl: 'user.component.html',
    providers: [ PostsService ],
})
export class UserComponent  { 
  name: string; 
  email: string;
  address: address;
  hobbies: string[];
  showHobbies: boolean;
  posts: Post[];

  constructor(private postsService: PostsService) {
      this.name = 'John Doe'; 
      this.email = 'john@gmail.com';
      this.address = {
        street: '20 Main st',
        city: 'Boston',
        state: 'MA',
     }
     this.hobbies = ['Reading', 'Religion', 'Sports'];
     this.showHobbies = false;

     this.postsService.getPosts().subscribe( xPosts => {
         this.posts = xPosts;
     });
  }

  toggleHobbies() {
      if(this.showHobbies == true) {
          this.showHobbies = false;
      } else {
          this.showHobbies = true;
      }
  }

  addHobby(hobby: string) {
      this.hobbies.push(hobby);
  }

  deleteHobby(i: number) {
      this.hobbies.splice(i, 1);
  }
}

interface address {
    street: string;
    city: string;
    state: string;
}

interface Post {
    id: number;
    title: string;
    body: string;
}