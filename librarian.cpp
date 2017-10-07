/*****************************
 * Program: librarian.cpp
 * Author: Kaitlin Hill
 * Description: what the librarian can do
 * Input: none
 * Output: librarian information
 * ********************/
#include "./librarian.h"
/********************
 * Function: constructor
 * Description: gives initial values
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
librarian::librarian(){
   id = 0;
   books = NULL;
   num_of_books = 0;
}
/********************
 * Function: destructor
 * Description: deletes dynamic memory
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: heap is free
 * Return: none
 * *****************/
librarian::~librarian(){
   for(int i=0; i<num_of_books; i++){
      delete [] books[i].authors;
      books[i].authors = NULL;
   }
   delete [] books;
   books = NULL;
}
/********************
 * Function: copy constructor
 * Description: copies from one class to a new class
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
librarian::librarian(const librarian &other){
   id = other.id;
   num_of_books = other.num_of_books;

   books = new book[num_of_books];
   for(int i=0; i<num_of_books; i++){
      books[i].title = other.books[i].title;
      books[i].num_authors = other.books[i].num_authors;
      books[i].authors = new string[other.books[i].num_authors];
      for(int j=0; j<books[i].num_authors; j++){
         books[i].authors[j] = other.books[i].authors[j];
      }
      books[i].year = other.books[i].year;
      books[i].copies = other.books[i].copies;
   }
}
/********************
 * Function:operator overload
 * Description: if a class needs this class info
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void librarian::operator=(const librarian &other){
   if(num_of_books == 0){
      books = NULL;
      num_of_books = other.num_of_books;
      id = other.id;
   }
   else{
      for(int i=0; i<num_of_books; i++){
	 delete [] books[i].authors;
      }
      delete [] books;
      
      id = other.id;
      num_of_books = other.num_of_books;
      
      books = new book[num_of_books];
      for(int i=0; i<num_of_books; i++){
	 books[i].title = other.books[i].title;
	 books[i].num_authors = other.books[i].num_authors;
         books[i].authors = new string[other.books[i].num_authors];
	 for(int j=0; j<books[i].num_authors; j++){
	    books[i].authors[j] = other.books[i].authors[j];
	 }
	 books[i].year = other.books[i].year;
	 books[i].copies = other.books[i].copies;
      }
   }
}
/********************
 * Function: get_lib_id
 * Description: accessor
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: id
 * *****************/
int librarian::get_lib_id() const{
   return id;
}
/********************
 * Function: set_lib_id
 * Description: mutator
 * Parameters: new_id
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void librarian::set_lib_id(const int new_id){
   id = new_id;
}
/********************
 * Function: get_num_books
 * Description: accessor
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: num_of_books
 * *****************/
int librarian::get_num_books() const{
   return num_of_books;
}
/********************
 * Function: set_num_books
 * Description: mutator
 * Parameters: new_book
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void librarian::set_num_books(const int new_book){
   num_of_books = new_book;
}
/********************
 * Function: delete_mem
 * Description: deletes mem
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: heap is free
 * Return: none
 * *****************/
void librarian::delete_mem(){
   for(int i=0; i<num_of_books; i++){
      delete [] books[i].authors;
      books[i].authors = NULL;
   }
   delete [] books;
   books = NULL;
}
/********************
 * Function: check_lib_id
 * Description: chec for valid id
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: true or false
 * *****************/
bool librarian::check_lib_id(int user_id) const{
   int id;
   ifstream read;
   read.open("id_librarian.txt");
   while(!read.eof()){
      read >> id;
      if(id == user_id){
         read.close();
	 return true;
      }
   }
      read.close();
      return false;
}
/********************
 * Function: set_books
 * Description: sets book arr
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void librarian::set_books(){
   ifstream read;
   read.open("books.txt");
   read >> num_of_books;
   books = new book[num_of_books];
   for(int i=0; i<num_of_books; i++){
      read >> books[i].title;
      read >> books[i].num_authors;
      books[i].authors = new string[books[i].num_authors];
      for(int j=0; j<books[i].num_authors; j++){
         read >> books[i].authors[j];
      }
      read >> books[i].year;
      read >> books[i].copies;
   }
   read.close();
}
/********************
 * Function: set_mem
 * Description: sets memory
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: heap is used
 * Return: none
 * *****************/
void librarian::set_mem(){
   num_of_books = 1;
   books = new book[num_of_books];
   for(int i=0; i<num_of_books; i++){
      books[i].title = "Moby_Dick";
      books[i].num_authors = 1;
      books[i].authors = new string[books[i].num_authors];
      for(int j=0; j<books[i].num_authors; j++){
	 books[i].authors[j] = "Mark_Twain";
      }
      books[i].year = 3000;
      books[i].copies = 2;
   }
}
/********************
 * Function: librarian_choices
 * Description: driver for librarian choices
 * Parameters: week
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void librarian::librarian_choices(hours week[]){
   char options;
   bool again;
   do{
      set_books();
      cout << "Would you like to change library hours (press h), view all books that are checked out (press o), add books to library database (press a), remove old books from library" 
	 << " database (press r), or quit (press any other key)?" << endl;
      cin >> options;
      cin.ignore();
      if (options == 'h' || options == 'H'){
	 change_library_hours(week);
	 again = true;
	 delete_mem();
      }
      else if (options == 'o' || options == 'O'){
	 view_checked_out_books();
	 again = true;
	 delete_mem();
      }
      else if (options == 'a' || options == 'A'){
	 add_books_to_database();
	 again = true;
	 delete_mem();
      }
      else if (options == 'r' || options == 'R'){
	 remove_books_from_database();
	 again = true;
	 delete_mem();
      }
      else{
	 again = false;
	 delete_mem();
      }
   }while(again == true);
}
/********************
 * Function: remove_books_from_database
 * Description: removes books from database
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void librarian::remove_books_from_database(){
   string title;
   int year;
   int counter = -1;
   ofstream write;
   write.open("books.txt");
   cout << "Enter title of book you would like to remove (ex. Moby_Dick)" << endl;
   cin >> title;
   cout << "Enter the year of the book" << endl;
   cin >> year;
   for(int i=0; i<num_of_books; i++){
      if(title == books[i].title){
         if(year == books[i].year){
	    counter = i;
	    num_of_books -= 1;
	 }
      }
   }
   write << num_of_books << endl;
   for(int i=0; i<=num_of_books; i++){
      if(i != counter){
         write << books[i].title << endl;
	 write << books[i].num_authors << endl;
	 for(int j=0; j<books[i].num_authors; j++){
	    write << books[i].authors[j] << endl;
	 }
	 write << books[i].year << endl;
	 write << books[i].copies << endl;
      }	 
   }
   write.close();
}
/********************
 * Function: change_library_hours
 * Description: change libray hours
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void librarian::change_library_hours(hours week[]){
   string day;
   string new_time;
   cout << "What day of the week would you like to change?" << endl;
   cin >> day;
   for(int i=0; i<7; i++){
      if(week[i].name == day){
	 cout << "Enter the new time (ex. 9-5)" << endl;
	 cin >> new_time;
	 week[i].time = new_time;
      }
   }
}
/********************
 * Function: view_check_out_books
 * Description: view all checked out books
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: none
 * Return: none
 * *****************/
void librarian::view_checked_out_books() const{
   string book_out;
   ifstream read;
   read.open("checked_out_books.txt");
   while(read >> book_out){
      cout << book_out << endl;
   }
   read.close();
}
/********************
 * Function: add_books_to_database
 * Description: adds books to database
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void librarian::add_books_to_database(){
   int num_in_file;
   ifstream read;
   read.open("books.txt");
   read >> num_in_file;
   book *temp = new book[num_in_file];
   num_in_file += 1;
   for(int i=0; i<num_in_file-1; i++){
      read >> temp[i].title;
      read >> temp[i].num_authors;
      temp[i].authors = new string[temp[i].num_authors];
      for(int j=0; j<temp[i].num_authors; j++){
	 read >> temp[i].authors[j];
      }
      read >> temp[i].year;
      read >> temp[i].copies;
   }
   read.close();
   add_books_p3(temp, num_in_file);
   add_books_p2();
}
/********************
 * Function: add_books_p3
 * Description: adds books to database
 * Parameters: temp, num_in_file
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void librarian::add_books_p3(book *temp, int num_in_file){
   ofstream write;
   write.open("books.txt");
   write << num_in_file << endl;
   for(int i=0; i<num_in_file-1; i++){
      write << temp[i].title << endl;
      write << temp[i].num_authors << endl;
      for(int j=0; j<temp[i].num_authors; j++){
         write << temp[i].authors[j] << endl;
      }
      write << temp[i].year << endl;
      write << temp[i].copies << endl;
   }
   for(int i=0; i<num_in_file-1; i++){
      delete [] temp[i].authors;
      temp[i].authors = NULL;
   }
   delete [] temp;
   temp = NULL;
}
/********************
 * Function: add_books_p2
 * Description: adds books to database
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void librarian::add_books_p2(){
   ofstream write;
   int writer_int;
   string writer;
   write.open("books.txt", ios::app);
   cout << "Enter the title (ex. Moby_Dick)" << endl;
   cin >> writer;
   cin.ignore();
   write << writer << endl;
   cout << "Enter the number of authors" << endl;
   cin >> writer_int;
   cin.ignore();
   write << writer_int << endl;
   for(int i=0; i<writer_int; i++){
      cout << "Enter author name (ex. C.S.Lewis or Mark_Twain)" << endl;
      cin >> writer;
      cin.ignore();
      write << writer << endl;
   }
   cout << "Enter in the year" << endl;
   cin >> writer;
   cin.ignore();
   write << writer << endl;
   cout << "Enter in the number of copies" << endl;
   cin >> writer;
   cin.ignore();
   write << writer << endl;
   write.close();
}
