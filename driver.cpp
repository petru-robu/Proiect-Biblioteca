#include <bits/stdc++.h>
#include "biblioteca.h"
using namespace std;

ifstream fin("comenzi.in");

int main()
{
  Manager m;
  string s;
  while(s!="exit")
    m.command(s, fin);

  s="";
  while(s!="exit")
    m.command(s, cin);


}
