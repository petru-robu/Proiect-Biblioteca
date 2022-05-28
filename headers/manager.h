#include <bits/stdc++.h>
#include "../sources/manager.cpp"

#include "biblioteca.h"


class Manager
{
private:
  std::map<int, std::string> Map;
  Biblioteca b;

public:
  Manager();
  void command(std::string &string, std::istream &cin);
};
