/********************
 * Program: library.cpp
 * Author: Kaitlin Hill
 * Date: 4/30/17
 * Description: outputs library options
 * Input: none
 * Output: library information
 * **********************/
#include "./library.h"
/********************
 * Function: constructor
 * Description: gives initial values
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
library::library(){
   week;
   num_of_books = 0;
   books = NULL;
   c;
   l;
   p;
}
/********************
 * Function:destructor
 * Description: frees heap
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: heap is free
 * Return: none
 * *****************/
library::~library(){
   for(int i=0; i<num_of_books; i++){
      delete [] books[i].authors;
      books[i].authors = NULL;
   }
   delete [] books;
   books = NULL;
}
/********************
 * Function: copy constructor
 * Description: copies on to another
 * Parameters: other
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
library::library(const library &other){
   c = other.c;
   l = other.l;
   p = other.p;
   num_of_books = other.num_of_books;
   for(int i=0; i<7; i++){
      week[i].name = other.week[i].name;
      week[i].time = other.week[i].time;
   }
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
 * Function: operator overload
 * Description: copies one to another
 * Parameters: other
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void library::operator=(const library &other){
   if(num_of_books == 0){
      books = NULL;
      num_of_books = other.num_of_books;
      c = other.c;
      l = other.l;
      p = other.p;
   
      for(int i=0; i<7; i++){
         week[i].name = other.week[i].name;
         week[i].time = other.week[i].time;
      }
   }
   else{
      for(int i=0; i<num_of_books; i++){
	 delete [] books[i].authors;
      }
      delete [] books;
      
      num_of_books = other.num_of_books;
      c = other.c;
      l = other.l;
      p = other.p;
      
      for(int i=0; i<7; i++){
	 week[i].name = other.week[i].name;
	 week[i].time = other.week[i].time;
      }
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
 * Function: get_num_books
 * Description: accessor
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: num_of_books
 * *****************/
int library::get_num_books() const{
   return num_of_books;
}
/********************
 * Function: set_num_books
 * Description: mutator
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void library::set_num_books(int new_num_books){
   num_of_books = new_num_books;
}
/********************
 * Function: get_books
 * Description: accessor
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: books
 * *****************/
book* library::get_books() const{
   return books;
}
/********************
 * Function: get_cart
 * Description: returns c
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: c is returned
 * Return: c
 * *****************/
cart library::get_cart() const{
   return c;
}
/********************
 * Function: set_cart
 * Description: sets cart to new values
 * Parameters: new_cart
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void library::set_cart(const cart &new_cart){
   c = new_cart;
}
/********************
 * Function: get_librarian
 * Description: returns l
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: l
 * *****************/
librarian library::get_librarian() const{
   return l;
}
/********************
 * Function: set_librarian
 * Description: sets l
 * Parameters: new_librarian
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void library::set_librarian(const librarian &new_librarian){
   l = new_librarian;
}
/********************
 * Function: get_patron
 * Description: returns p
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: none
 * Return: p
 * *****************/
patron library::get_patron() const{
   return p;
}
/********************
 * Function: set_patron
 * Description: sets patron
 * Parameters: new_patron
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void library::set_patron(const patron &new_patron){
   p = new_patron;
}
/********************
 * Function: fill_week
 * Description: week week with stuff
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void library::fill_week(){
   week[0].name = "Sunday";
   week[1].name = "Monday";
   week[2].name = "Tuesday";
   week[3].name = "Wednesday";
   week[4].name = "Thursday";
   week[5].name = "Friday";
   week[6].name = "Saturday";
   week[0].time = "9-3";
   week[1].time = "8-5";
   week[2].time = "8-5";
   week[3].time = "8-5";
   week[4].time = "8-5";
   week[5].time = "8-5";
   week[6].time = "9-4";
}
/********************
 * Function: display_daily_or_weekly_hours
 * Description: choose to see daily or weekly hours
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void library::display_daily_or_weekly_hours(){
   char day_or_week;
   string day;
   cout << "Would you like to see daily (press d) or weekly hours (press any other key)?" << endl;
   cin >> day_or_week;
   cin.ignore();
   if(day_or_week == 'd'){
      cout << "What day of the week would you like to see?" << endl;
      cin >> day;
      cin.ignore();
      display_daily_hours(day);
   }
   else{
      display_weekly_hours();
   }
}
/********************
 * Function: display_weekly_hours
 * Description:displays the daily hours
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void library::display_weekly_hours() const{
   for(int i=0; i<7; i++){
      cout << week[i].name << ": ";
      cout << week[i].time << endl;
   }
}
/********************
 * Function: display_daily_hours
 * Description: displays daily hours
 * Parameters: day
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void library::display_daily_hours(string day) const{
   for(int i=0; i<7; i++){
      if(day == week[i].name){
         cout << week[i].name << ": ";
	 cout << week[i].time << endl;;
      }
   }
}
/********************
 * Function: set_week
 * Description: sets week
 * Parameters: day, new_hours
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void library::set_week(string day, string new_hours){
   for(int i=0; i<7; i++){
      if(week[i].name == day){
	 week[i].time = new_hours;
      }
   }
}
/********************
 * Function: delete_mem
 * Description: deletes memory
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: heap mem is free
 * Return: none
 * *****************/
void library::delete_mem(){
   for(int i=0; i<num_of_books; i++){
      delete [] books[i].authors;
      books[i].authors = NULL;
   }
   delete [] books;
   books = NULL;
}
/********************
 * Function: set_books
 * Description: sets books arr
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void library::set_books(){
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
 * Function: patron_login
 * Description: part two of login as
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void library::patron_login(int &id, bool &member, bool &again){
   cout << "Enter your id" << endl;
   cin >> id;
   cin.ignore();
   p.set_id(id);
   member = p.check_pat_id(id);
   if (member == true){
      p.patron_choices(c);
   }
   again = false;
   delete_mem();
}
/********************
 * Function: login_as
 * Description: drives process
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void library::login_as(){
   char login;
   int id;
   bool member;
   bool again;
   fill_week(); 
   do{
      set_books();
      cout << "Would you like to login as a patron (press p), a librarian (press l), see hours (press h), or quit (press any other key)" << endl;
      cin >> login;
      cin.ignore();
      if(login == 'p' || login == 'P'){
	 patron_login(id, member, again);
      }
      else if(login == 'l' || login == 'L'){
	 cout << "Enter your id" << endl;
	 cin >> id;
	 cin.ignore();
	 member = l.check_lib_id(id);
	 if(member == true){
	    l.librarian_choices(week);
	 }
	 again = false;
	 delete_mem();
      }
      else if(login == 'h' || login == 'H'){
	 display_daily_or_weekly_hours();
	 delete_mem();
      }
      else{
	 again = true;
	 l.set_mem();
	 p.set_mem();
	 c.set_mem();
      }
   }while(again == false);
}
