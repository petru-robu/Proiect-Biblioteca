#include "../headers/profesor.h"

Profesor::Profesor(std::string s1, std::string s2, std::string s3): Client(s1, s2), materie(s3){}

void Profesor::print()
{
  std::cout<<"COD:  "<<cod<<'\n'<<"NUM:  "<<nume<<'\n';
  std::cout<<"MAT:  "<<materie<<'\n';
  std::cout<<"RET:  "<<retur<<'\n'<<"NRI:  "<<nrImp;
}

std::string Profesor::get_materie()
{
  return materie;
}
