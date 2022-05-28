#include <bits/stdc++.h>
#include "../sources/profesor.cpp"


#include "client.h"



class Profesor: public Client
{
private:
  std::string materie;

public:
  Profesor(std::string s1, std::string s2, std::string s3);
  void print();

  std::string get_materie();
};
