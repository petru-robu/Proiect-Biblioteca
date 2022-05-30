#include "sources/biblioteca.cpp"
#include "sources/carte.cpp"
#include "sources/client.cpp"
#include "sources/manager.cpp"
#include "sources/profesor.cpp"
#include "sources/student.cpp"

#include <bits/stdc++.h>
#include "headers/manager.h"

using namespace std;

ifstream fin("fisier.in");

int main()
{
  Manager* manager = manager->getInstance();
  string s;
  while(s!="exit")
    manager->query(s, fin);

  s="";
  while(s!="exit")
    manager->query(s, cin);

}
