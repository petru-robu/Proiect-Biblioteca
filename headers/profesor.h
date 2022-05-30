#ifndef INCLUDED_PROFESOR
#define INCLUDED_PROFESOR

#include <bits/stdc++.h>
#include "client.h"

class Profesor: public Client
{
private:
  std::string materie;

public:
  Profesor(std::string s1, std::string s2, std::string s3);
  void print() override;

  std::string get_materie();
};

#endif
