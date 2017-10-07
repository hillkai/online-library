#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;

struct hours{
   string name;
   string time;
};

struct book{
   string title;
   int num_authors;
   string *authors;
   int year;
   int copies;
};
