#include "./cart.h"

class patron{
   private:
      int id;
      int books_checked_out;
      book *books;
      int num_of_books;
   public:
      patron();
      ~patron();
      patron(const patron &);
      void operator=(const patron &);
      int get_id() const;
      void set_id(const int);
      int get_books_checked_out() const;
      void set_books_checked_out(int);
      bool check_pat_id(const int) const;
      void fill_up_books();
      void patron_choices(cart &);
      void view_all_books();
      void search_all_books() const;
      void for_loop_search_title(const string) const;
      void for_loop_search_author(const string) const;
      void for_loop_search_int(int) const;
      void view_checked_out_books();
      void delete_mem();
      void set_mem();
};
