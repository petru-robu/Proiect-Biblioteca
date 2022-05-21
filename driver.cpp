#include <bits/stdc++.h>
#include "biblioteca.h"
using namespace std;

int main()
{
  Biblioteca b;
  b.adaugaStudent("260406", "Petru", "Liceu Sava", 2);
  b.adaugaStudent("123456", "Johnny", "FMI", 3);
  b.adaugaProfesor("123456", "Johnny", "Info");
  b.afiseazaClienti();
  return 0;
}
