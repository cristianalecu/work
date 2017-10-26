export enum SyncEvery { Never, Hour, Day, Week }  
export enum ObjLevel { Supreem, Major, Current }  
export enum RepeatType { None, Dayly, Weekly, Monthly, Yearly }    
export enum tastType { Once, Numeric, Percentage }
export enum ReminderType { None, OnTyme, HourBefore, DayBefore }
export enum AlarmType { None, OnTyme, HourBefore, DayBefore }

export type SyncParams = { syncType: SyncEvery, last_datetime_sync: string, track_history: boolean, email?: string };
export type Objective = { title: string, level: ObjLevel, priority: number, until: Date, picture: File, why: string, to_be: string; to_know: string; to_do: string };
export type Category = { title: string, about: string, picture: File };
export type Task = {
  title: string, done: number, for_objective: Objective, for_categ: Category, start_date: Date, end_date: Date, priority: number, importance: number,
  time: Date, repeat: RepeatType, alarm: AlarmType, picture: File, why: string, to_be: string; to_know: string; to_do: string
};

export class Storage {
  version: number;

  constructor()
  {
    this.version = 1;

  }

  Save()
  {

  }
}
