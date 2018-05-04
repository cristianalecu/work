import { Component, OnInit } from '@angular/core';
import { HttpClient, HttpHeaders, HttpErrorResponse } from '@angular/common/http';

interface UserResponse {
  login:string;
  bio:string;
  company: string;
}

interface SnippetResponse {
  code: string;
  id:number;
  language: string;
  linenos:string;
  style: string;
  title: string;
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
    this.http.get<SnippetResponse>('http://127.0.0.1:5500/snippets/').subscribe(
      data => {
          console.log('User login ' + JSON.stringify(data));
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

    // const req = this.http.delete('http://127.0.0.1:5500/snippets/4/').subscribe(
    //   res => {
    //     console.log(res);
    //   },
    //   res => {
    //     console.log('Error occured');
    //   }
    // );    

    // const req = this.http.put('http://127.0.0.1:5500/snippets/12/',
    // {
    //   code: 'print 111',
    //   title: 'ppp',
    //   highlighted: "SDSDSD",
    // }).subscribe(
    //   res => {
    //     console.log(res);
    //   },
    //   res => {
    //     console.log('Error occured');
    //   }
    // );

    const req = this.http.post('http://127.0.0.1:5500/snippets/',
    {
      code: 'print 111',
      title: 'ppp',
      highlighted: "SDSDSD",
    }).subscribe(
      res => {
        console.log(res);
      },
      res => {
        console.log('Error occured');
      }
    );

  }


}
