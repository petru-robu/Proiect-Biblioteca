#ifndef INCLUDED_CLIENT
#define INCLUDED_CLIENT

#include <bits/stdc++.h>
#include "date.h"

class Client{
protected:
  std::string cod, nume;
  Date retur;
  int nrImp;

public:
  Client(std::string s1, std::string s2);
  virtual void print();

  std::string get_cod();
  std::string get_nume();
  Date get_retur();
  int get_nrImp();

  void set_nrImp(int x);
  void set_retur(Date d);
};

#endif
