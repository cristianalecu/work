import { Injectable } from '@angular/core';

import { HttpEvent, HttpHandler, HttpInterceptor, HttpRequest } from '@angular/common/http';

import { Observable } from 'rxjs/observable';

@Injectable()
export class GithubAuthInterceptor implements HttpInterceptor {
    intercept(req: HttpRequest<any>, next: HttpHandler): Observable<HttpEvent<any>> {
        const authReq = req.clone({
            //headers: req.headers.set('Authorization', 'Basic saturn:Go4Cristi')
            headers: req.headers.set('Authorization', 'token 941acdba61c2c1c5b13008e15' + 'fabd5066407d490')
            // take token from -> Profile  -> Developer Settings -> Tokens -> Generate Token (selecting users)
        });

        return next.handle(authReq);
    }
}
