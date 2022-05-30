#ifndef INCLUDED_CARTE
#define INCLUDED_CARTE

#include <bits/stdc++.h>

class Carte
{
private:
  std::string isbn, titlu, autor, gen;
  int nrPag;
  bool available;

public:
  Carte(std::string isbn, std::string titlu, std::string autor, std::string gen, int nrPag);

  std::string get_isbn();
  std::string get_titlu();
  std::string get_autor();
  std::string get_gen();
  int get_nrPag();
  bool get_status();

  void set_status(bool b);

  void print();
  
  bool operator==(const Carte c);
};

#endif
