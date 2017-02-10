import { ModuleWithProviders } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

import { UserComponent } from './components/user.component';
import { TasksComponent } from './components/tasks.component';
import { AboutComponent } from './components/about.component';

const appRoutes: Routes = [
    {
        path:'',
        component: UserComponent
    },
    {
        path: 'about',
        component: AboutComponent,
    },
    {
        path: 'tasks',
        component: TasksComponent,
    },
]

export const routing: ModuleWithProviders = RouterModule.forRoot(appRoutes);
