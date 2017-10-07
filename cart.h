#include"./structs.h"

class cart{
   private:
      book *books_on_cart;
      book *all_books;
      int num_of_books;
      int num_books_on_cart;
      void resize_books();
   public:
      cart();
      ~cart();
      cart(const cart &);
      void operator=(const cart &);
      void set_num_books_on_cart(const int);
      int get_num_books_on_cart() const;
      book* get_books_on_cart() const;
      book* get_all_books() const;
      int get_num_books() const;
      void set_num_books(const int);
      void set_all_books();
      int add_to_cart(string &, int &);
      void display_cart() const;
      void cart_cycle_check_in();
      void cart_cycle_check_out();
      void check_in_database(const int);
      void check_out_database(const int);
      void set_mem();
      void delete_mem();
      void add_to_check_out_file();
      void remove_check_out_file(const string, const int);
      void add_p2(book *, int [], int);
      void remove_p2(int, book *, string, int, int []);
};
