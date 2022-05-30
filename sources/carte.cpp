#include "../headers/carte.h"

Carte::Carte(std::string isbn, std::string titlu, std::string autor, std::string gen,
int nrPag):isbn(isbn), titlu(titlu), autor(autor), gen(gen), nrPag(nrPag)
{
  available = true;
}

void Carte::print()
{
    std::cout<<"COD:  "<<isbn<<"\nTIT:  "<<titlu<<"\nAUT:  "<<autor<<"\nGEN:  "<<gen;
    std::cout<<"\nNRP:  "<<nrPag;
    std::cout<<"\nSTR:  ";
    if(available)
      std::cout<<"DISPONIBILA";
    else
      std::cout<<"INDISPONIBILA";
}

bool Carte::operator==(const Carte c)
{
  if(isbn == c.isbn)
    return true;
  else
    return false;
}

std::string Carte::get_isbn()
{
  return isbn;
}

std::string Carte::get_titlu()
{
  return titlu;
}

std::string Carte::get_autor()
{
  return autor;
}

std::string Carte::get_gen()
{
  return gen;
}

int Carte::get_nrPag()
{
  return nrPag;
}

bool Carte::get_status()
{
  return available;
}

void Carte::set_status(bool b)
{
  available = b;
}
