#include <bits/stdc++.h>
#include "biblioteca.h"
using namespace std;

int main()
{
  Biblioteca b;
  b.adaugaStudent("1", "Petru1", "Liceu Sava", 10);
  b.adaugaStudent("2", "Johnny1", "Facultatea de Matematica Informatica", 3);
  b.adaugaProfesor("3", "Johnny2", "Informatica");
  b.adaugaProfesor("4", "Petru2", "Smecherie");

  b.adaugaCarte("1", "Carte1", "Autor1", "Gen1", 210);
  b.adaugaCarte("2", "Carte2", "Autor2", "Gen2", 112);
  b.adaugaCarte("3", "Carte3", "Autor3", "Gen3", 145);
  b.adaugaCarte("4", "Carte4", "Autor4", "Gen4", 317);

  b.afiseazaClienti();
  b.afiseazaCarti();

  b.imprumutaCarte("1", "Johnny1");
  b.imprumutaCarte("2", "Petru1");
  b.imprumutaCarte("3", "Petru2");
  b.imprumutaCarte("4", "Johnny2");
  b.afiseazaCarti();

  b.returneazaCarte("2", "Petru1");
  b.returneazaCarte("3", "Johnny1");
  b.imprumutaCarte("2", "Petru1");
  b.imprumutaCarte("4", "Johnny2");
  b.imprumutaCarte("4", "Johnny2");
  b.imprumutaCarte("2", "Petru1");
  b.imprumutaCarte("4", "Johnny2");
  b.imprumutaCarte("4", "Johnny2");

  b.afiseazaClienti();
  b.afiseazaCarti();
  b.sorteazaClienti();

}
