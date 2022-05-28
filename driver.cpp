#include <bits/stdc++.h>
#include "headers/manager.h"

using namespace std;

ifstream fin("comenzi.in");

int main()
{
  Manager man;
  string s;
  while(s!="exit")
    man.command(s, fin);

  s="";
  while(s!="exit")
    man.command(s, cin);

}
