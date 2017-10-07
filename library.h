#include "./librarian.h"

class library{
   private: 
      hours week[7];
      int num_of_books;
      book *books;
      cart c;
      librarian l;
      patron p;
  public:
      library();
      ~library();
      library(const library &);
      void operator=(const library &);
      void set_num_books(int); 
      int get_num_books() const;
      book* get_books() const;
      cart get_cart() const;
      librarian get_librarian() const;
      patron get_patron() const;
      void set_patron(const patron &);
      void set_cart(const cart &);
      void set_librarian(const librarian &);
      void fill_week();
      void display_daily_or_weekly_hours();
      void display_daily_hours(string) const;
      void display_weekly_hours() const;
      void set_week(string, string);
      book* get_books();
      void login_as();
      void set_books();
      void delete_mem();
      void patron_login(int &, bool &, bool &);
};
