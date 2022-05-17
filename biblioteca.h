#include <bits/stdc++.h>
using namespace std;

struct Data
{
  int mm, dd, yy;
};

class Client
{
public:
  string cod, nume;
  int nrImp;
  Data retur;
};

class Profesor:public Client
{
public:
  string materie;
}

class Student:public Client
{
public:
  string facultate;
  int anStudiu; //1-6
}

class Biblioteca{


};
