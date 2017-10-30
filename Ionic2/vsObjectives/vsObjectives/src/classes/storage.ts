export enum SyncEvery { Never, Hour, Day, Week }  
export enum ObjLevel { Supreem, Major, Current }  
export enum RepeatType { None, Dayly, Weekly, Monthly, Yearly }    
export enum valueType { Once, Numeric, Percentage }
export enum ReminderType { None, OnTyme, HourBefore, DayBefore }
export enum AlarmType { None, Notify, Vibrate, Sound }

export type SyncParams = { syncType: SyncEvery, last_datetime_sync: string, track_history: boolean, email?: string };
export type Objective = { title: string, level: ObjLevel, priority: number, until: Date, picture: string, why: string, to_be: string; to_know: string; to_do: string };
export type Category = { title: string, about: string, picture: File };
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

  constructor()
  {
    this.version = 1;
    this.userLang = '';
  }

  SaveSettings() {
    //
  }
  SaveCategories() {
    //
  }
  SaveObjectives() {
    //
  }
  SaveTasks() {
    //
  }
  SaveAuthors() {
    //
  }
  SaveBooks() {
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
