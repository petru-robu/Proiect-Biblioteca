#ifndef INCLUDED_MANAGER
#define INCLUDED_MANAGER

#include <bits/stdc++.h>
#include "biblioteca.h"

class Manager
{
private:
  static Manager *instance;

  std::map<int, std::string> Map;
  Biblioteca* b = b->getInstance();

  Manager(){}

public:
  static Manager* getInstance();
  void query(std::string &string, std::istream &cin);
};

#endif
