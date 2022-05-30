#ifndef INCLUDED_DATE
#define INCLUDED_DATE

#include <bits/stdc++.h>

struct Date{
  int dd, mm, yy;

  friend std::ostream& operator<< (std::ostream& out,const Date &d)
  {
    out<<d.dd<<'.'<<d.mm<<'.'<<d.yy;
    return out;
  }
};

#endif
