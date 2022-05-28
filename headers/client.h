#include <bits/stdc++.h>
#include "../sources/client.cpp"

#include "date.h"

class Client{
private:
  std::string cod, nume;
  Date retur;
  int nrImp;

public:
  Client(std::string s1, std::string s2);
  virtual void print();

  std::string get_cod();
  std::string get_nume();
  Date get_date();
  int get_nrImp();
};
