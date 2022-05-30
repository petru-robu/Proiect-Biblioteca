#include "../headers/student.h"

Student::Student(std::string s1, std::string s2, std::string s3, int a): Client(s1, s2), facultate(s3), anStudiu(a){}

void Student::print()
{
  std::cout<<"COD:  "<<cod<<'\n'<<"NUM:  "<<nume<<'\n';
  std::cout<<"FAC:  "<<facultate<<'\n'<<"ANS:  "<<anStudiu<<'\n';
  std::cout<<"RET:  "<<retur<<'\n'<<"NRI:  "<<nrImp;
}

std::string Student::get_facultate()
{
  return facultate;
}
int Student::get_anStudiu()
{
  return anStudiu;
}
