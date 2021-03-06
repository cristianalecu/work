export enum SyncEvery { Never, Hour, Day, Week }  
export enum ObjLevel { Supreem, Major, Current }  
export enum RepeatType { None, Dayly, Weekly, Monthly, Yearly }    
export enum valueType { Once, Numeric, Percentage }
export enum ReminderType { None, OnTyme, HourBefore, DayBefore }
export enum AlarmType { None, Notify, Vibrate, Sound }
export enum SortBy { NameAlphabeticalAsc, NameAlphabeticalDesc, DateAsc, DateDesc, CategAsc, CategDesc, PrioAsc, PrioDesc, ImportantAsc, ImportantDesc, AuthorAsc, AuthorDesc }

export type SyncParams = { syncType: SyncEvery, last_datetime_sync: string, track_history: boolean, email?: string };
export type Objective = { title: string, level: ObjLevel, priority: number, until: Date, picture: string, why: string, to_be: string; to_know: string; to_do: string };
export type Category = {title: string, about: string, picture: string, userDefined: boolean };
export type Task = {
  title: string, done: number, for_objective: Objective, for_categ: Category, start_date: Date, end_date: Date, priority: number, importance: number,
  time: Date, repeat: RepeatType, alarm: AlarmType, target: valueType, targetValue: number, remind: ReminderType, every: number, fromDate: Date, duration: number,
  notes: string, picture: string, 
};
export type Author = { title: string, about: string, picture: string, lastUpdated: string, userDefined: boolean };
export type Book = { title: string, author: number, category: number, until: Date, pages: number, page: number, link: string, files: Array<string>, photos: Array<string>, updates: Array<Array<string>> };
  
export class Storage {

  //Settings
  version: number;
  userLang: string
  sync_every: SyncEvery;
  account_email: string;
  last_datetime_sync: string;
  track_history: boolean;
  last_action: string;
  sort_authors: SortBy;
  sort_books: SortBy;

  nr_categories: number;
  categories: Array<Category>;
  nr_authors: number;
  authors: Array<Author>;
  nr_books: number;
  books: Array<Book>;

  constructor()
  {
    if (localStorage.getItem('cnaobj_version') == null) 
    {
      this.InitSettings();
      this.SaveSettings();
    }
    else
      this.LoadSettings();

    if (localStorage.getItem('cnaobj_nr_categories') == null) {
      this.InitCategories();
      this.SaveCategories();
    }
    else
      this.LoadCategories();

    if (localStorage.getItem('cnaobj_nr_authors') == null) {
      this.InitAuthors();
      this.SaveAuthors();
    }
    else
      this.LoadAuthors();

    if (localStorage.getItem('cnaobj_nr_books')== null)  
    {
      this.InitBooks();
      this.SaveBooks();
    }
    else
      this.LoadBooks();
  }

  InitAll()
  {
    this.InitSettings();
    this.InitCategories();
    this.InitAuthors();
    this.InitBooks();
    this.InitObjectives();
    this.InitTasks();
  }
  InitSettings() {
    this.version = 1;
    this.userLang = '';
    this.sync_every = SyncEvery.Never
    this.account_email = '';
    this.last_datetime_sync = '2017-01-01 12:30:00';
    this.track_history = false;
    this.last_action = "";
    this.sort_authors = SortBy.NameAlphabeticalAsc;
    this.sort_books = SortBy.NameAlphabeticalAsc;
  }
  InitCategories() {
    this.nr_categories = 5;
    this.categories = Array();
    this.categories[0] = { title: "Spiritual", about: "Be strong and stable spiritually, disciplined and determined.", picture: "1_spiritual.jpg", userDefined: false };
    this.categories[1] = { title: "Social", about: "Be responsible and educated so family and friends can rely on you.", picture: "2_family.png", userDefined: false };
    this.categories[2] = { title: "Profession", about: "Be good professionist and perfectionist", picture: "3_profession.png", userDefined: false };
    this.categories[3] = { title: "Health", about: "Be healthy, sportive and mind sharpen", picture: "4_health.jpg", userDefined: false };
    this.categories[4] = { title: "Finacial", about: "Be financially independent", picture: "5_financiar.jpg", userDefined: false };
  }
  InitAuthors() {
    this.nr_authors = 3;
    this.authors = Array();
    this.authors[0] = { title: "Necunoscut", about: "Autor necunoscut.", picture: "anonymous.png", lastUpdated: "0", userDefined: false };
    this.authors[1] = { title: "Robert Kiyosaki", about: "American businessman and author of the Rich Dad, Poor Dad series of books.", picture: "RobertKiyosaki.jpg", lastUpdated: "0", userDefined: false };
    this.authors[2] = { title: "Brian Tracy", about: "American motivational public speaker and self-development author.", picture: "BrianTracy.jpg", lastUpdated: "1", userDefined: false };
  }

  InitObjectives()
  {
  }

  InitBooks()
  {
    this.nr_books = 3;
    this.books = Array();
    this.books[0] = {
      title: "Pelerinul rus", author: 0, category: 0, until: new Date("2017-12-30"), page: 1, pages: 78,
      link: "https://www.crestinortodox.ro/carti-ortodoxe-audio/pelerinul-rus-audio/",
      files: Array("pelerinul-rus.pdf"), photos: Array("pelerinul_rus.jpg"), updates: Array(Array("1", "2017-01-01"))
    };
    this.books[1] = {
      title: "Psihologia succesului", author: 2, category: 2, until: new Date("2017-12-30"), page: 1, pages: 212,
      link: "https://florinrosoga.ro/blog/brian-tracy-carti/", files: Array("tracy-brian-succesul-in-viata.pdf"),
      photos: Array("psychologyofsuccess.jpg"), updates: Array(Array("1", "2017-01-01"))
    };
    this.books[2] = {
      title: "Tată bogat, tată sărac", author: 1, category: 4, until: new Date("2017-12-30"), page: 1, pages: 100,
      link: "https://florinrosoga.ro/blog/robert-kiyosaki-tata-bogat-tata-sarac/",
      files: Array("robert-kiyosaki-tata-bogat-tata-sarac.pdf"), photos: Array("tata-bogat-tata-sarac.jpg"), updates: Array(Array("1", "2017-01-01"))
    };
  }

  InitTasks()
  {
  }

  LoadSettings()
  {
    if (localStorage.getItem('cnaobj_version') != null) {
      this.version = parseInt(localStorage.getItem('cnaobj_version'));
      this.userLang = localStorage.getItem('cnaobj_userLang');
      this.sync_every = parseInt(localStorage.getItem('cnaobj_sync_every'));
      this.account_email = localStorage.getItem('cnaobj_account_email');
      this.last_datetime_sync = localStorage.getItem('cnaobj_last_datetime_sync');
      this.track_history = localStorage.getItem('cnaobj_track_history') == "true";
      this.last_action = localStorage.getItem('cnaobj_last_action');
      this.sort_authors = parseInt(localStorage.getItem('cnaobj_sort_authors'));
      this.sort_books = parseInt(localStorage.getItem('cnaobj_sort_books'));

      if (isNaN(this.sort_authors))
        this.sort_authors = SortBy.NameAlphabeticalAsc;
      if (isNaN(this.sort_books))
        this.sort_books = SortBy.NameAlphabeticalAsc;
    }
    else    //initialize 
    {
      this.InitAll();
      this.Save();
    }
  }
  LoadCategories()
  {
    var title;
    var about;
    var picture;
    var userDefined;
    var index;

    this.nr_categories = parseInt(localStorage.getItem('cnaobj_nr_categories'));
    this.categories = Array();
    if (this.nr_categories > 0)
    {

      for (index = 0; index < this.nr_categories; index++)
      {
        title = localStorage.getItem('cnaobj_categ' + index + '_title');
        about = localStorage.getItem('cnaobj_categ' + index + '_about');
        picture = localStorage.getItem('cnaobj_categ' + index + '_picture');
        userDefined = localStorage.getItem('cnaobj_categ' + index + '_userdef') == "true";

        this.categories[index] =
        {
          title: title, about: about, picture: picture, userDefined: userDefined
        }
      }
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
    var title;
    var about;
    var picture;
    var userDefined;
    var lastUpdated;
    var index;

    this.nr_authors = parseInt(localStorage.getItem('cnaobj_nr_authors'));
    this.authors = Array();
    if (this.nr_authors > 0)
    {
      for (index = 0; index < this.nr_authors; index++) {
        title = localStorage.getItem('cnaobj_author' + index + '_title');
        about = localStorage.getItem('cnaobj_author' + index + '_about');
        picture = localStorage.getItem('cnaobj_author' + index + '_picture');
        lastUpdated = localStorage.getItem('cnaobj_author' + index + '_lastUpdated');
        userDefined = localStorage.getItem('cnaobj_author' + index + '_userdef') == "true";

        this.authors[index] =
          {
            title: title, about: about, picture: picture, lastUpdated: lastUpdated, userDefined: userDefined
          }
      }
    }
  }
  LoadBooks()
  {
    var title;
    var author;
    var category;
    var link;
    var pages;
    var page;
    var until;
    var nlength;
    var index, ndx;

    this.nr_books = parseInt(localStorage.getItem('cnaobj_nr_books'));
    this.books = Array();
    if (this.nr_books > 0)
    {
      for (index = 0; index < this.nr_books; index++)
      {
        title = localStorage.getItem('cnaobj_book' + index + '_title');
        author = parseInt(localStorage.getItem('cnaobj_book' + index + '_author'));
        category = parseInt(localStorage.getItem('cnaobj_book' + index + '_category'));
        page = parseInt(localStorage.getItem('cnaobj_book' + index + '_page'));
        pages = parseInt(localStorage.getItem('cnaobj_book' + index + '_pages'));
        link = localStorage.getItem('cnaobj_book' + index + '_link');
        until = new Date(localStorage.getItem('cnaobj_book' + index + '_until'));

        this.books[index] =
          {
            title: title, author: author, category: category, page: page, pages: pages, until: until, link: link,
            files: Array(), photos: Array(), updates: Array()
          }
        nlength = parseInt(localStorage.getItem('cnaobj_book' + index + '_files_nr'));
        if (nlength > 0)
          for (ndx = 0; ndx < nlength; ndx++)
            this.books[index].files[ndx] = localStorage.getItem('cnaobj_book' + index + '_file' + ndx);
        nlength = parseInt(localStorage.getItem('cnaobj_book' + index + '_photos_nr'));
        if (nlength > 0)
          for (ndx = 0; ndx < nlength; ndx++)
            this.books[index].photos[ndx] = localStorage.getItem('cnaobj_book' + index + '_photo' + ndx);
        nlength = parseInt(localStorage.getItem('cnaobj_book' + index + '_updates_nr'));
        if (nlength > 0)
          for (ndx = 0; ndx < nlength; ndx++)
          {
            this.books[index].updates[ndx] = Array(localStorage.getItem('cnaobj_book' + index + '_updateDate' + ndx),
                                                   localStorage.getItem('cnaobj_book' + index + '_updatePages' + ndx));
          }
      }
    }
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
    localStorage.setItem('cnaobj_sort_authors', '' + this.sort_authors);
    localStorage.setItem('cnaobj_sort_books', '' + this.sort_books);
  }
  SaveCategories()
  {
    localStorage.setItem('cnaobj_nr_categories', '' + this.nr_categories);
    if (this.nr_categories > 0)
      for (var index = 0; index < this.nr_categories; index++)
        this.SaveCategory(index);
  }
  SaveCategory(index: number) {
    localStorage.setItem('cnaobj_nr_categories', '' + this.nr_categories);

    localStorage.setItem('cnaobj_categ' + index + '_title', this.categories[index].title);
    localStorage.setItem('cnaobj_categ' + index + '_about', this.categories[index].about);
    localStorage.setItem('cnaobj_categ' + index + '_picture', this.categories[index].picture);
    localStorage.setItem('cnaobj_categ' + index + '_userdef', '' + this.categories[index].userDefined);
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
    localStorage.setItem('cnaobj_nr_authors', '' + this.nr_authors);
    if (this.nr_authors > 0)
      for (var index = 0; index < this.nr_authors; index++)
        this.SaveAuthor(index);
  }
  SaveAuthor(index: number) {
    localStorage.setItem('cnaobj_nr_authors', '' + this.nr_authors);

    localStorage.setItem('cnaobj_author' + index + '_title', this.authors[index].title);
    localStorage.setItem('cnaobj_author' + index + '_about', this.authors[index].about);
    localStorage.setItem('cnaobj_author' + index + '_picture', this.authors[index].picture);
    localStorage.setItem('cnaobj_author' + index + '_lastUpdated', this.authors[index].lastUpdated);
    localStorage.setItem('cnaobj_author' + index + '_userdef', '' + this.authors[index].userDefined);
  }
  SaveBooks()
  {
    localStorage.setItem('cnaobj_nr_books', '' + this.nr_books);
    if (this.nr_books > 0)
      for (var index = 0; index < this.nr_books; index++)
        this.SaveBook(index);
  }
  SaveBook(index: number)
  {
    var ndx;

    localStorage.setItem('cnaobj_nr_books', '' + this.nr_books);

    localStorage.setItem('cnaobj_book' + index + '_title', this.books[index].title);
    localStorage.setItem('cnaobj_book' + index + '_author', ""+this.books[index].author);
    localStorage.setItem('cnaobj_book' + index + '_category', ""+this.books[index].category);
    localStorage.setItem('cnaobj_book' + index + '_link', this.books[index].link);
    localStorage.setItem('cnaobj_book' + index + '_page', '' + this.books[index].page);
    localStorage.setItem('cnaobj_book' + index + '_pages', '' + this.books[index].pages);
    localStorage.setItem('cnaobj_book' + index + '_until', this.books[index].until.getFullYear + '-' + this.books[index].until.getMonth + '-' + this.books[index].until.getDay);
    localStorage.setItem('cnaobj_book' + index + '_files_nr', '' + this.books[index].files.length);
    localStorage.setItem('cnaobj_book' + index + '_photos_nr', '' + this.books[index].photos.length);
    localStorage.setItem('cnaobj_book' + index + '_updates_nr', '' + this.books[index].updates.length);
    if (this.books[index].files.length > 0)
      for (ndx = 0; ndx < this.books[index].files.length; ndx++)
        localStorage.setItem('cnaobj_book' + index + '_file' + ndx, '' + this.books[index].files[ndx]);
    if (this.books[index].photos.length > 0)
      for (ndx = 0; ndx < this.books[index].photos.length; ndx++)
        localStorage.setItem('cnaobj_book' + index + '_photo' + ndx, '' + this.books[index].photos[ndx]);
    if (this.books[index].updates.length > 0)
      for (ndx = 0; ndx < this.books[index].updates.length; ndx++)
      {
        localStorage.setItem('cnaobj_book' + index + '_updateDate' + ndx, '' + this.books[index].updates[ndx][1]);
        localStorage.setItem('cnaobj_book' + index + '_updatePages' + ndx, '' + this.books[index].updates[ndx][2]);
      }
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
