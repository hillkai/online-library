/****************************
 * Program: cart.cpp
 * Author: Kaitlin Hill
 * Date: 4/30/17
 * Description: add things to the cart
 * Input: none
 * Output: none
 * *********************/
#include "./cart.h"

/********************
 * Function: constuctor
 * Description: gives intial values
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
cart::cart(){
   all_books = NULL;
   num_of_books = 0;
   books_on_cart = NULL;
   num_books_on_cart = 0;
}
/********************
 * Function: destuctor
 * Description: delete dynamic memory
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
cart::~cart(){
   for(int i=0; i<num_of_books; i++){
      delete [] all_books[i].authors;
      all_books[i].authors = NULL;
   }
   delete [] all_books;
   all_books = NULL;

   for(int i=0; i<num_books_on_cart; i++){
      delete [] books_on_cart[i].authors;
      books_on_cart[i].authors = NULL;
   }
   delete [] books_on_cart;
   books_on_cart = NULL;
}
/********************
 * Function: copy constuctor
 * Description: copies class into a new one
 * Parameters: other
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
cart::cart(const cart &other){
   num_books_on_cart = other.num_books_on_cart;
   num_of_books = other.num_of_books;

   all_books = new book[num_of_books];
   for(int i=0; i<num_of_books; i++){
      all_books[i].title = other.all_books[i].title;
      all_books[i].num_authors = other.all_books[i].num_authors;
      all_books[i].authors = new string[other.all_books[i].num_authors];
      for(int j=0; j<all_books[i].num_authors; j++){
         all_books[i].authors[j] = other.all_books[i].authors[j];
      }
      all_books[i].year = other.all_books[i].year;
      all_books[i].copies = other.all_books[i].copies;
   }
   books_on_cart = new book[num_books_on_cart];
   for(int i=0; i<num_books_on_cart; i++){
      books_on_cart[i].title = other.books_on_cart[i].title;
      books_on_cart[i].num_authors = other.books_on_cart[i].num_authors;
      books_on_cart[i].authors = new string[books_on_cart[i].num_authors];
      for(int j=0; j<books_on_cart[i].num_authors; j++){
         books_on_cart[i].authors[i] = other.books_on_cart[i].authors[j];
      }
      books_on_cart[i].year = other.books_on_cart[i].year;
      books_on_cart[i].copies = other.books_on_cart[i].copies;
   }
}
/********************
 * Function: operator overload
 * Description: called to give values of class to another class
 * Parameters: other
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void cart::operator=(const cart &other){
   all_books = NULL;
   num_of_books = 0;
   books_on_cart = NULL;
   num_books_on_cart;
   if(num_of_books == 0 && num_books_on_cart == 0){
      all_books = NULL;
      num_of_books = other.num_of_books;
      books_on_cart = NULL;
      num_books_on_cart = other.num_books_on_cart;
   }
   else if(num_of_books == 0 && num_books_on_cart != 0){
      for(int i=0; i<num_books_on_cart; i++){
         delete [] books_on_cart[i].authors;
      }
      delete [] books_on_cart;
      
      num_of_books = other.num_of_books;
      num_books_on_cart = other.num_books_on_cart;
      all_books = NULL;
      
      books_on_cart = new book[num_books_on_cart];
      for(int i=0; i<num_books_on_cart; i++){
	 books_on_cart[i].title = other.books_on_cart[i].title;
	 books_on_cart[i].num_authors = other.books_on_cart[i].num_authors;
	 books_on_cart[i].authors = new string[books_on_cart[i].num_authors];
	 for(int j=0; j<books_on_cart[i].num_authors; j++){
	    books_on_cart[i].authors[i] = other.books_on_cart[i].authors[j];
	 }
	 books_on_cart[i].year = other.books_on_cart[i].year;
	 books_on_cart[i].copies = other.books_on_cart[i].copies;
      }
   }
   else if(num_of_books != 0 && num_books_on_cart == 0){
      for(int i=0; i<num_of_books; i++){
	 delete [] all_books[i].authors;
      }
      delete [] all_books;
      
      num_of_books = other.num_of_books;
      num_books_on_cart = other.num_books_on_cart;
      books_on_cart = NULL;
      all_books = new book[num_of_books];
      for(int i=0; i<num_of_books; i++){
         all_books[i].title = other.all_books[i].title;
         all_books[i].num_authors = other.all_books[i].num_authors;
         all_books[i].authors = new string[other.all_books[i].num_authors];
         for(int j=0; j<all_books[i].num_authors; j++){
            all_books[i].authors[j] = other.all_books[i].authors[j];
         }
         all_books[i].year = other.all_books[i].year;
         all_books[i].copies = other.all_books[i].copies;
      }
   }  
   else{
      for(int i=0; i<num_of_books; i++){
	 delete [] all_books[i].authors;
      }
      delete [] all_books;
      for(int i=0; i<num_books_on_cart; i++){
	 delete [] books_on_cart[i].authors;
      }
      delete [] books_on_cart;
      
      num_of_books = other.num_of_books;
      num_books_on_cart = other.num_books_on_cart;
      
      books_on_cart = new book[num_books_on_cart];
      for(int i=0; i<num_books_on_cart; i++){
	 books_on_cart[i].title = other.books_on_cart[i].title;
	 books_on_cart[i].num_authors = other.books_on_cart[i].num_authors;
	 books_on_cart[i].authors = new string[books_on_cart[i].num_authors];
	 for(int j=0; j<books_on_cart[i].num_authors; j++){
	    books_on_cart[i].authors[i] = other.books_on_cart[i].authors[j];
	 }
	 books_on_cart[i].year = other.books_on_cart[i].year;
	 books_on_cart[i].copies = other.books_on_cart[i].copies;
      }
      
      all_books = new book[num_of_books];
      for(int i=0; i<num_of_books; i++){
         all_books[i].title = other.all_books[i].title;
         all_books[i].num_authors = other.all_books[i].num_authors;
         all_books[i].authors = new string[other.all_books[i].num_authors];
         for(int j=0; j<all_books[i].num_authors; j++){
            all_books[i].authors[j] = other.all_books[i].authors[j];
         }
         all_books[i].year = other.all_books[i].year;
         all_books[i].copies = other.all_books[i].copies;
      }
   }
}
/********************
 * Function: get_books_on_cart
 * Description: accessor
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: books_on_cart
 * *****************/
book* cart::get_books_on_cart() const{
   return books_on_cart;
}
/********************
 * Function: get_all_books
 * Description: accessor
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: all_books
 * ********************/
book* cart::get_all_books() const{
   return all_books;
}
/********************
 * Function: get_num_books
 * Description: accessor
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: num_of_books
 * *****************/
int cart::get_num_books() const{
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
void cart::set_num_books(const int new_num_books){
   num_of_books = new_num_books;
}
/********************
 * Function: get_num_books
 * Description: gets books on cart
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: none
 * Return: num_books_on_cart
 * *****************/
int cart::get_num_books_on_cart() const{
   return num_books_on_cart;
}
/********************
 * Function: set_num_books_on_cart
 * Description: set variable
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void cart::set_num_books_on_cart(const int new_num_cart){
   num_books_on_cart = new_num_cart;
}
/********************
 * Function: set_all_books
 * Description: sets all book array
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: heap being used
 * Return: none
 * *****************/
void cart::set_all_books(){
   ifstream read;
   read.open("books.txt");
   read >> num_of_books;
   num_books_on_cart = 0;
   all_books = new book[num_of_books];
   for(int i=0; i<num_of_books; i++){
      read >> all_books[i].title;
      read >> all_books[i].num_authors;
      all_books[i].authors = new string[all_books[i].num_authors];
      for(int j=0; j<all_books[i].num_authors; j++){
         read >> all_books[i].authors[j];
      }
      read >> all_books[i].year;
      read >> all_books[i].copies;
   }
   read.close();
}
/********************
 * Function: set_mem
 * Description: sets mem and creates mem
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: heap memory is being used
 * Return: none
 * *****************/
void cart::set_mem(){
   num_of_books = 1;
   num_books_on_cart = 1;
   
   all_books = new book[num_of_books];
   for(int i=0; i<num_of_books; i++){
      all_books[i].title = "Moby_Dick";
      all_books[i].num_authors = 1;
      all_books[i].authors = new string[all_books[i].num_authors];
      for(int j=0; j<all_books[i].num_authors; j++){
         all_books[i].authors[j] = "Mark_Twain";
      }
      all_books[i].year = 1920;
      all_books[i].copies = 2;
   }
   books_on_cart = new book[num_books_on_cart];
   for(int i=0; i<num_books_on_cart; i++){
      books_on_cart[i].title = "Moby_Dick";
      books_on_cart[i].num_authors = 1;
      books_on_cart[i].authors = new string[books_on_cart[i].num_authors];
      for(int j=0; j<books_on_cart[i].num_authors; j++){
         books_on_cart[i].authors[j] = "Mark_Twain";
      }
      books_on_cart[i].year = 1920;
      books_on_cart[i].copies = 2;
   }
}
/********************
 * Function: delete_mem
 * Description: frees heap memory
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: heap mem is free
 * Return: none
 * *****************/
void cart::delete_mem(){
   for(int i=0; i<num_of_books; i++){
      delete [] all_books[i].authors;
      all_books[i].authors = NULL;
   }
   delete [] all_books;
   all_books = NULL;

   for(int i=0; i<num_books_on_cart; i++){
      delete [] books_on_cart[i].authors;
      books_on_cart[i].authors = NULL;
   }
   delete [] books_on_cart;
   books_on_cart = NULL;
}
/********************
 * Function: cart_cycle_check_in
 * Description: runs the cycle of checking in
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void cart::cart_cycle_check_in(){
   int counter;
   string title;
   int year;
   set_all_books();
   counter = add_to_cart(title, year);
   cout << "Here is the book you are going to check in" << endl;
   display_cart();
   check_in_database(counter);
   remove_check_out_file(title, year);
   delete_mem();
}
/********************
 * Function: cart_cycle_check_out
 * Description: runs the cycle of checking a book out
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void cart::cart_cycle_check_out(){
   int counter;
   string title;
   int year;
   set_all_books();
   counter = add_to_cart(title, year);
   cout << "Here is the book you are going to check out" << endl;
   display_cart();
   check_out_database(counter);
   add_to_check_out_file();
   delete_mem();
}
/********************
 * Function: remove_check_out_file
 * Description: remove check out file
 * Parameters: title, year
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void cart::remove_check_out_file(const string title, const int year){
   int num_in_file;
   ifstream read;
   read.open("checked_out_books.txt");
   read >> num_in_file;
   book *temp = new book[num_in_file];
   int id[num_in_file];
   for(int i=0; i<num_in_file; i++){
      read >> id[i];
      read >> temp[i].title;
      read >> temp[i].num_authors;
      temp[i].authors = new string[temp[i].num_authors];
      for(int j=0; j<temp[i].num_authors; j++){
	 read >> temp[i].authors[j];
      }
      read >> temp[i].year;
   }
   read.close();
   remove_p2(num_in_file, temp, title, year, id);
}
/********************
 * Function: remove_p2
 * Description: part 2 of remove
 * Parameters: num_in_file, temp, title, year, id
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void cart::remove_p2(int num_in_file, book *temp, string title, int year, int id[]){
   int user_id;
   num_in_file -= 1;
   ofstream write;
   write.open("checked_out_books.txt");
   write << num_in_file << endl;
   cout << "Enter your id" << endl;
   cin >> user_id;
   cin.ignore();
    for(int i=0; i<num_in_file+1; i++){
      if((title == temp[i].title) && (user_id == id[i]) && (year == temp[i].year)){
      }
      else{
	 write << id[i] << endl;
	 write << temp[i].title << endl;
	 write << temp[i].num_authors << endl;
	 for(int j=0; j<temp[i].num_authors; j++){
	    write << temp[i].authors[j] << endl;
	 }
	 write << temp[i].year << endl;
      }
   }
   write.close();
   for(int i=0; i<num_in_file+1; i++){
      delete [] temp[i].authors;
      temp[i].authors = NULL;
   }
   delete [] temp;
   temp = NULL;
}
/********************
 * Function: add_to_check_out_file
 * Description: adds to check out file
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void cart::add_to_check_out_file(){
   int num_in_file;
   ifstream read;
   read.open("checked_out_books.txt");
   read >> num_in_file;
   num_in_file += 1;
   book *temp = new book[num_in_file];
   int id[num_in_file];
   for(int i=0; i<num_in_file-1; i++){
      read >> id[i];
      read >> temp[i].title;
      read >> temp[i].num_authors;
      temp[i].authors = new string[temp[i].num_authors];
      for(int j=0; j<temp[i].num_authors; j++){
	 read >> temp[i].authors[j];
      }
      read >> temp[i].year;
   }
   read.close();
   add_p2(temp, id, num_in_file);
}
/********************
 * Function: add_p2
 * Description: adds books
 * Parameters: temp, id, num_in_file
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void cart::add_p2(book *temp, int id[], int num_in_file){
   ofstream write;
   write.open("checked_out_books.txt");
   write << num_in_file << endl;
   for(int i=0; i<num_in_file-1; i++){
      write << id[i] << endl;
      write << temp[i].title << endl;
      write << temp[i].num_authors << endl;
      for(int j=0; j<temp[i].num_authors; j++){
         write << temp[i].authors[j] << endl;
      }
      write << temp[i].year << endl;
   }
   cout << "Enter your id" << endl;
   int id_again;
   cin >> id_again;
   cin.ignore();
   write << id_again << endl;
   for(int i=0; i<num_books_on_cart; i++){
      write << books_on_cart[i].title << endl;
      write << books_on_cart[i].num_authors << endl;
      for(int j=0; j<books_on_cart[i].num_authors; j++){
         write << books_on_cart[i].authors[j] << endl;;
      }
      write << books_on_cart[i].year << endl;
   }
   write.close();
   for(int i=0; i<num_in_file-1; i++){
      delete [] temp[i].authors;
      temp[i].authors = NULL;
   }
   delete [] temp;
   temp = NULL;
}
/********************
 * Function: check_in_database
 * Description: check in books
 * Parameters: counter
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void cart::check_in_database(const int counter){
   ofstream write;
   write.open("books.txt");
   if(counter != -50){
      write << num_of_books << endl;
      all_books[counter].copies +=1;
      for(int i=0; i<num_of_books; i++){
         write << all_books[i].title << endl;
	 write << all_books[i].num_authors << endl;
	 for(int j=0; j<all_books[i].num_authors; j++){
	    write <<all_books[i].authors[j] << endl;
	 }
         write << all_books[i].year << endl;
	 write << all_books[i].copies << endl;
      }
   }
   write.close();
}
/********************
 * Function: check_out_database
 * Description: checks out book
 * Parameters: counter
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void cart::check_out_database(const int counter){
   ofstream write;
   write.open("books.txt");
   if(counter != -50){
      write << num_of_books << endl;
      all_books[counter].copies -= 1;
      for(int i=0; i<num_of_books; i++){
	 write << all_books[i].title << endl;
	 write << all_books[i].num_authors << endl;
	 for(int j=0; j<all_books[i].num_authors; j++){
	    write << all_books[i].authors[j] << endl;
	 }
	 write << all_books[i].year << endl;
	 write << all_books[i].copies << endl;
      }
   }
   write.close();
}
/********************
 * Function: resize_books
 * Description: resizes books array
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void cart::resize_books(){
   book temp_arr[num_books_on_cart];
   if(num_books_on_cart == 0){
      num_books_on_cart += 1;
      books_on_cart = new book[num_books_on_cart];
   }
   else{
      for(int i=0; i<num_books_on_cart; i++){
	 temp_arr[i].title = books_on_cart[i].title;
	 temp_arr[i].num_authors = books_on_cart[i].num_authors;
         temp_arr[i].year = books_on_cart[i].year;
	 temp_arr[i].copies = books_on_cart[i].copies;
	 temp_arr[i].authors[temp_arr[i].num_authors];
	 for(int j=0; j<books_on_cart[i].num_authors; j++){
	    temp_arr[i].authors[j] = books_on_cart[i].authors[j];
	 }
      }
      for(int i=0; i<num_books_on_cart; i++){
	 delete [] books_on_cart[i].authors;
	 books_on_cart[i].authors = NULL;
      }
      delete [] books_on_cart;
      books_on_cart = NULL;
      num_books_on_cart += 1;
      books_on_cart = new book[num_books_on_cart];
      for(int i=0; i<num_books_on_cart-1; i++){
         books_on_cart[i].title = temp_arr[i].title;
	 books_on_cart[i].num_authors = temp_arr[i].num_authors;
	 books_on_cart[i].year = temp_arr[i].year;
	 books_on_cart[i].copies = temp_arr[i].copies;
	 books_on_cart[i].authors = new string[temp_arr[i].num_authors];
	 for(int j=0; j<books_on_cart[i].num_authors; j++){
	    books_on_cart[i].authors[j] = temp_arr[i].authors[j];
         }
      }
   }
}
/********************
 * Function: display_cart
 * Description: displays cart
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: none
 * *****************/
void cart::display_cart() const{
   for(int i=0; i<num_books_on_cart; i++){
      cout << books_on_cart[i].title << endl;
      for(int j=0; j<books_on_cart[i].num_authors; j++){
         cout << books_on_cart[i].authors[j] << endl;
      }
      cout << books_on_cart[i].year << endl;
   }
}
/********************
 * Function: add_to_cart
 * Description: adds books to cart
 * Parameters: title, year
 * Pre-condtions: none
 * Post-conditions: variables are filled with values
 * Return: counter
 * *****************/
int cart::add_to_cart(string &title, int &year){
   int counter = -50;
   cout << "Enter the title of the book you would like to add to cart (ex. Moby_Dick)" <<endl;
   cin >> title;
   cin.ignore();
   cout << "Enter the year of the book you would like to add to cart" << endl;
   cin >> year; 
   cin.ignore();
   for (int i=0; i<num_of_books; i++){
      if(all_books[i].title == title){
	 if(all_books[i].year == year){
	    counter = i;
	    resize_books();
	    books_on_cart[num_books_on_cart-1].title = all_books[i].title;
	    books_on_cart[num_books_on_cart-1].num_authors = all_books[i].num_authors;
	    books_on_cart[num_books_on_cart-1].year = all_books[i].year;
	    books_on_cart[num_books_on_cart-1].copies = all_books[i].copies;
	    if(num_books_on_cart-1 == 0){
	       books_on_cart[num_books_on_cart-1].authors = new string[books_on_cart[num_books_on_cart-1].num_authors];
	    }
	    for(int j=0; j<books_on_cart[num_books_on_cart-1].num_authors; j++){
	       books_on_cart[num_books_on_cart-1].authors[j] = all_books[i].authors[j];
	    }
	 }
      }
   }
   return counter;
}
