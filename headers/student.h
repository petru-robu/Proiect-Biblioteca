#include <bits/stdc++.h>
#include "../sources/student.cpp"


#include "profesor.h"


class Student: public Client
{
private:
  std::string facultate;
  int anStudiu;

public:
  Student(std::string s1, std::string s2, std::string s3, int a);
  void print();

  std::string get_facultate();
  int get_anStudiu();
};
