export enum SyncEvery { Never, Hour, Day, Week }  
export enum ObjLevel { Supreem, Major, Current }  
export enum RepeatType { None, Dayly, Weekly, Monthly, Yearly }    
export enum valueType { Once, Numeric, Percentage }
export enum ReminderType { None, OnTyme, HourBefore, DayBefore }
export enum AlarmType { None, Notify, Vibrate, Sound }

export type SyncParams = { syncType: SyncEvery, last_datetime_sync: string, track_history: boolean, email?: string };
export type Objective = { title: string, level: ObjLevel, priority: number, until: Date, picture: string, why: string, to_be: string; to_know: string; to_do: string };
export type Category = {title: string, about: string, picture: string, userDefined: boolean };
export type Task = {
  title: string, done: number, for_objective: Objective, for_categ: Category, start_date: Date, end_date: Date, priority: number, importance: number,
  time: Date, repeat: RepeatType, alarm: AlarmType, target: valueType, targetValue: number, remind: ReminderType, every: number, fromDate: Date, duration: number,
  notes: string, picture: string, 
};
export type Author = { title: string, about: string, picture: File }; 
export type Book = { title: string, author: Author, category: Category, until: Date, pages: number, page: number, link: string, files: Array<File>, photos: Array<File> };
  
  
export class Storage {

  //Settings
  version: number;
  userLang: string
  sync_every: SyncEvery;
  account_email: string;
  last_datetime_sync: string;
  track_history: boolean;
  last_action: string;

  nr_categories: number;
  categories: Array<Category>;

  constructor()
  {
    if (localStorage.getItem('version') == null)
    {
      this.InitAll();
      this.Save();
    }

    this.LoadSettings();
  }

  InitAll()
  {
    this.version = 1;
    this.userLang = '';
    this.sync_every = SyncEvery.Never
    this.account_email = '';
    this.last_datetime_sync = '2017-01-01 12:30:00';
    this.track_history = false;
    this.last_action = "";

    this.nr_categories = 4;
    this.categories = Array();
    this.categories[0] = { title: "Spiritual", about: "Be strong and stable spiritually, disciplined and determined.", picture: "1_spiritual.jpg", userDefined: false };
    this.categories[1] = { title: "Social", about: "Be responsible and educated so family and friends can rely on you.", picture: "2_family.png", userDefined: false };
    this.categories[2] = { title: "Profession", about: "Be good professionist and perfectionist", picture: "3_profession.png", userDefined: false };
    this.categories[3] = { title: "Health", about: "Be healthy, sportive and mind sharpen", picture: "4_health.jpg", userDefined: false };
    this.categories[4] = { title: "Finacial", about: "Be financially independent", picture: "5_financiar.jpg", userDefined: false };
  }
  LoadSettings() {
    if (localStorage.getItem('cnaobj_version') != null) {
      this.version = parseInt(localStorage.getItem('cnaobj_version'));
      this.userLang = localStorage.getItem('cnaobj_userLang');
      this.sync_every = parseInt(localStorage.getItem('cnaobj_sync_every'));
      this.account_email = localStorage.getItem('cnaobj_account_email');
      this.last_datetime_sync = localStorage.getItem('cnaobj_last_datetime_sync');
      this.track_history = parseInt(localStorage.getItem('cnaobj_track_history')) > 0;
      this.last_action = localStorage.getItem('cnaobj_last_action');

    }
    else    //initialize 
    {
      this.InitAll();
      this.Save();
    }
  }
  LoadCategories()
  {
    this.nr_categories = parseInt(localStorage.getItem('cnaobj_nr_categories'));
    this.categories = Array();
    if (this.nr_categories > 0)
      for (var index = 0; index < this.nr_categories; index++) {
        this.categories[index].title = localStorage.getItem('cnaobj_categ' + index + '_title')
        this.categories[index].about = localStorage.getItem('cnaobj_categ' + index + '_about')
        this.categories[index].picture = localStorage.getItem('cnaobj_categ' + index + '_picture')
        this.categories[index].userDefined = parseInt(localStorage.getItem('cnaobj_categ' + index + '_userdef')) > 0;
      }
  }
  LoadObjectives()
  {
    //
  }
  LoadTasks()
  {
    //
  }
  LoadAuthors()
  {
    //
  }
  LoadBooks()
  {
    //
  }
  LoadAll()
  {
    this.LoadSettings();
    this.LoadCategories();
    this.LoadObjectives();
    this.LoadTasks();
    this.LoadAuthors();
    this.LoadBooks();
  }

  SaveSettings() {
    localStorage.setItem('cnaobj_version', '' + this.version);
    localStorage.setItem('cnaobj_userLang', this.userLang);
    localStorage.setItem('cnaobj_sync_every', '' + this.sync_every);
    localStorage.setItem('cnaobj_account_email', this.account_email);
    localStorage.setItem('cnaobj_last_datetime_sync', this.last_datetime_sync);
    localStorage.setItem('cnaobj_track_history', '' + this.track_history);
    localStorage.setItem('cnaobj_last_action', this.last_action);

  }
  SaveCategories()
  {
    localStorage.setItem('cnaobj_nr_categories', '' + this.nr_categories);
    if (this.nr_categories > 0)
      for (var index = 0; index < this.nr_categories; index++)
      {
        localStorage.setItem('cnaobj_categ' + index + '_title', this.categories[index].title);
        localStorage.setItem('cnaobj_categ' + index + '_about', this.categories[index].title);
        localStorage.setItem('cnaobj_categ' + index + '_picture', this.categories[index].title);
        localStorage.setItem('cnaobj_categ' + index + '_userdef', this.categories[index].title);
      }
  }
  SaveObjectives()
  {
    //
  }
  SaveTasks()
  {
    //
  }
  SaveAuthors()
  {
    //
  }
  SaveBooks()
  {
    //
  }
  Save()
  {
    this.SaveSettings();
    this.SaveCategories();
    this.SaveObjectives();
    this.SaveTasks();
    this.SaveAuthors();
    this.SaveBooks();
  }
}
