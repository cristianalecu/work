import { Component, OnInit } from '@angular/core';
import { HttpClient, HttpHeaders, HttpErrorResponse } from '@angular/common/http';

interface UserResponse {
  login:string;
  bio:string;
  company: string;
}

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent implements OnInit {
  title = 'app';

  constructor(private http: HttpClient)
  {

  }

  ngOnInit(): void {
    this.http.get<UserResponse>('https://api.github.com/users/cristianalecu').subscribe(
      data => {
          console.log("User login " + data.login);
      }),
      (err:HttpErrorResponse) => {
        if(err.error instanceof Error)
        {
          console.log("Client Side Error occurd");
        }
        else
        {
          console.log("Server-side Error occurd");
        }
      }
    
    const req = this.http.post("http://jsonplaceholder.typicode.com/posts", 
    {
      title: 'foo',
      body: 'bar',
      userId: 1
    }).subscribe(
      res => {
        console.log(res);
      },
      res => {
        console.log("Error occured");
      }
    );  
  }


}
