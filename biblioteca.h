#include <bits/stdc++.h>
using namespace std;

class Data
{
public:
  int mm, dd, yy;
  friend ostream& operator<<(ostream& out, Data date)
  {
    out<<date.dd<<'.'<<date.mm<<'.'<<date.yy;
    return out;
  }
};

class Client
{
public:
  string cod, nume;
  int nrImp;
  Data retur;
  Client(string a, string b): cod(a), nume(b) {}
};

class Profesor:public Client
{
public:
  string materie;
  Profesor(string a, string b, string c): Client(a,b), materie(c) {}

};

class Student:public Client
{
public:
  string facultate;
  int anStudiu;
  Student(string a, string b, string c, int d): Client(a,b), facultate(c), anStudiu(d){}
};
