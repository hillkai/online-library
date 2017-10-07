#include "./patron.h"

class librarian{
   private:
      int id;
      int num_of_books;
      book *books;
   public:
      librarian();
      ~librarian();
      librarian(const librarian &);
      void operator=(const librarian &other);
      int get_lib_id() const;
      void set_lib_id(const int);
      int get_num_books() const;
      void set_num_books(const int);
      bool check_lib_id(int) const;
      void librarian_choices(hours[]);
      void change_library_hours(hours[]);
      void view_checked_out_books() const;
      void add_books_to_database();
      void remove_books_from_database();
      void set_books();
      void set_mem();
      void delete_mem();
      void add_books_p2();
      void add_books_p3(book *, int);
};
