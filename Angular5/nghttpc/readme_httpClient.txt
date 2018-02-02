in app.module.ts

import { HttpClientModule } from '@angular/common/http';

...
imports: [
    HttpClientModule ,


in app.components.ts

import { Component, OnInit } from '@angular/core';
import { HttpClient } from '@angular/common/http';
...
export class AppComponent implements OnInit {
  constructor(private http: HttpClient ) 
  {
  }

  ngOnInit(): void {
    this.http.get('https://api.github.com/users/cristianalecu').subscribe(data => {
      
    console.log(data);
  
  })
  
  }


Improvements:

import { HttpClient, HttpHeaders, HttpErrorResponse } from '@angular/common/http';


interface UserResponse {
  login:string;
  bio:string;
  company: string;
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
  }



  Post :        inside  ngOnInit(): void {     put  :
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


Interceptors:  create new file   src\app\github.interceptor.ts 

import { Injectable } from '@angular/core';

import { HttpEvent, HttpHandler, HttpInterceptor, HttpRequest } from '@angular/common/http';

import { Observable } from 'rxjs/observable';

@Injectable()
export class GithubAuthInterceptor implements HttpInterceptor {
    intercept(req: HttpRequest<any>, next: HttpHandler): Observable<HttpEvent<any>> {
        return next.handle(req);
    }
}


in app.module.ts:

import { HttpClientModule, HTTP_INTERCEPTORS } from '@angular/common/http';
import { GithubAuthInterceptor } from "./github.interceptor";

...
  providers: [{
    provide: HTTP_INTERCEPTORS,
    useClass: GithubAuthInterceptor,
    multi: true,
  }],