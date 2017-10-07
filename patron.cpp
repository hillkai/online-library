/*****************************
 * Program: patron.cpp
 * Author: Kaitlin Hill
 * Date: 4/30/17
 * Description: does patron options
 * Input: none
 * Output: patron information
 * ***********************/
#include "./patron.h"
/********************
 * Function: constuctor
 * Description: sets variables to values
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
patron::patron(){
   id = 0;
   books_checked_out = 0;
   num_of_books = 0;
   books = NULL;
}
/********************
 * Function: destructor
 * Description: deletes dynamic mem
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: heap is free
 * Return: none
 * *****************/
patron::~patron(){
   for(int i=0; i<num_of_books; i++){
      delete [] books[i].authors;
      books[i].authors = NULL;
   }
   delete [] books;
   books = NULL;
}
/********************
 * Function: copy constructor
 * Description: copies info to a new class
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
patron::patron(const patron &other){
   id = other.id;
   books_checked_out = other.books_checked_out;
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
 * Function: operator overload
 * Description: copies over information
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void patron::operator=(const patron &other){
   if(num_of_books == 0){
      books = NULL;
      num_of_books = other.num_of_books;
      id = other.id;
      books_checked_out = other.books_checked_out;
   }
   else{
      for(int i=0; i<num_of_books; i++){
	 delete [] books[i].authors;
      }
      delete [] books;
      
      id = other.id;
      num_of_books = other.num_of_books;
      books_checked_out = other.books_checked_out;
      
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
 * Function: get_id
 * Description: accessor
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: id
 * *****************/
int patron::get_id() const{
   return id;
}
/********************
 * Function: set_id
 * Description: mutator
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void patron::set_id(const int new_id){
   id = new_id;
}
/********************
 * Function: get_books_checked_out
 * Description: accessor
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: books_check_out
 * *****************/
int patron::get_books_checked_out() const{
   return books_checked_out;
}
/********************
 * Function:set_books_checked_out
 * Description: mutator
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void patron::set_books_checked_out(int new_books_checked_out){
   books_checked_out = new_books_checked_out;
}
/********************
 * Function: check_pat_id
 * Description: check if id is good
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: true of false
 * *****************/
bool patron::check_pat_id(const int user_id) const{
   int id;
   ifstream read;
   read.open("id_patron.txt");
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
 * Function: fill_up_books
 * Description: fill up book
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values, heap mem used
 * Return: none
 * *****************/
void patron::fill_up_books(){
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
 * Post-conditions: variables are filled with values, heap mem used
 * Return: none
 * ****************/
void patron::set_mem(){
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
 * Function: delete_mem
 * Description: frees heap mem
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: heap is free
 * Return: none
 * *****************/
void patron::delete_mem(){
    for(int i=0; i<num_of_books; i++){
      delete [] books[i].authors;
      books[i].authors = NULL;
   }
   delete [] books; 
   books = NULL;
}
/********************
 * Function: patron_choices
 * Description: gives patron choices
 * Parameters: ca
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void patron::patron_choices(cart &ca){
   char options;
   bool again;
   do{
      fill_up_books();
      cout << "Would you like to view all books in library (press v), search our books (press s), view your currently checked out books (press c), check out a book (press o), check in" 
	 << " a book (press i), or login as a different user (press any other key)?" << endl;
      cin >> options;
      cin.ignore();
      if (options == 'v' || options == 'V'){
	 view_all_books();
	 again = true;
	 delete_mem();
      }
      else if (options == 's' || options == 'S'){
	 search_all_books(); 
	 again = true;
	 delete_mem();
      }
      else if (options == 'c' || options == 'C'){
	 view_checked_out_books();
	 again = true;
	 delete_mem();
      }
      else if (options == 'o' || options == 'O'){
	 ca.cart_cycle_check_out();
	 again = true;
	 delete_mem();
      }
      else if (options == 'i' || options == 'I'){
	 ca.cart_cycle_check_in();
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
 * Function: view_checked_out_books
 * Description: view checked out books
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void patron::view_checked_out_books(){
   int id_checker;
   char checker[256];
   string book_out;
   ifstream read;
   read.open("checked_out_books.txt");
   while(read >> checker){
      id_checker = atoi(checker);
      if(id_checker == id){
	 read >> book_out;
	 cout << book_out << endl;
	 read >> id_checker;
	 for(int j=0; j<id_checker; j++){
	    read >> book_out;
	    cout << book_out << endl;
	 }
	 read >> book_out;
	 cout << book_out << endl;
      }
   }
   read.close();
}
/********************
 * Function: view_all_books
 * Description: view all books in library
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void patron::view_all_books(){
   for(int i=0; i<num_of_books; i++){
      cout << books[i].title << endl;
      for(int j=0; j<books[i].num_authors; j++){
	 cout << books[i].authors[j] << endl;
      }
      cout << books[i].year << endl;
      cout << books[i].copies << endl;
   }
}
/********************
 * Function: for_loop_search_title
 * Description: searches by title
 * Parameters: search
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void patron::for_loop_search_title(string const search) const{
   for(int i=0; i<num_of_books; i++){
      if(books[i].title == search){
	 cout << books[i].title << endl;
	 for(int j=0; j<books[i].num_authors; j++){
	    cout << books[i].authors[j] << endl;
	 }
	 cout << books[i].year << endl;
	 cout << books[i].copies << endl;
      }
   } 
}
/********************
 * Function: for_loop_search_author
 * Description: loops through and searches
 * Parameters: search
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void patron::for_loop_search_author(string const search) const{
   for(int i=0; i<num_of_books; i++){
      for(int j=0; j<books[i].num_authors; j++){
         if(books[i].authors[j] == search){
	    cout << books[i].title << endl;
	    for(int t=0; t<books[i].num_authors; t++){
	       cout << books[i].authors[t] << endl;
	    }
	    cout << books[i].year << endl;
	    cout << books[i].copies << endl;
         } 
      }
   }
}
/********************
 * Function: for_loop_search
 * Description: loops through and searches 
 * Parameters: search
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void patron::for_loop_search_int(int const search) const{
   for(int i=0; i<num_of_books; i++){
      if(books[i].year == search){
	 cout << books[i].title << endl;
	 for(int j=0; j<books[i].num_authors; j++){
	    cout << books[i].authors[j] << endl;
	 }
	 cout << books[i].year << endl;
	 cout << books[i].copies << endl;
      }
   } 
}
/********************
 * Function: search_all_boks
 * Description: search books
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void patron::search_all_books() const{
   char search_by;
   string search;
   int search_int;
   cout << "What would you like to search by: title (press t), author (press a), or year (press any other key)" << endl;
   cin >> search_by;
   cin.ignore();
   if (search_by == 't' || search_by == 'T'){
      cout << "Please enter the title, if there are spaces please enter an underscore instead ex. Moby_Dick" << endl;
      cin >> search;
      cin.ignore();
      for_loop_search_title(search);
   }
   else if (search_by == 'a' || search_by == 'A'){
      cout << "Please enter one author, if there are spaces please enter an underscore, and if there is a period, do not put a space. ex Dr.Suess or  Mark_Twain" << endl;
      cin >> search;
      cin.ignore();
      for_loop_search_author(search);
   }
   else{
      cout << "Please enter the year of the book" << endl;
      cin >> search_int;
      cin.ignore();
      for_loop_search_int(search_int);
   }
}
