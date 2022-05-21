#include <bits/stdc++.h>
#include "biblioteca.h"
using namespace std;

int main()
{
  Biblioteca b;
  b.adaugaStudent("1", "Petru", "Liceu Sava", 10);
  b.adaugaStudent("2", "Johnny", "Facultatea de Matematica Informatica", 3);
  b.adaugaStudent("3", "Matei", "Liceu Sava", 10);
  b.adaugaStudent("4", "Cristi", "Liceu Vianu", 9);
  b.adaugaStudent("5", "David", "Facultatea de Turism", 1);

  b.adaugaProfesor("6", "Johnney", "Informatica");
  b.adaugaProfesor("7", "Petru", "Smecherie");

  b.afiseazaClienti();

}
