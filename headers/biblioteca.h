#ifndef INCLUDED_BIBLIOTECA
#define INCLUDED_BIBLIOTECA

#include <bits/stdc++.h>

#include "carte.h"
#include "student.h"
#include "profesor.h"


class Biblioteca{
private:

  static Biblioteca *instance;
  Biblioteca(){}

  std::vector<Client*> listaClienti;
  std::vector<Carte> listaCarti;
  std::vector<std::pair<Client*, Carte>> listaImprumuturi;

  static int random(int min, int max);
  static Date randomDate();

  int findPosCarte(std::string isbn);
  int findPosCarteTitlu(std::string titlu);
  int findPosClient(std::string nume);
  bool disp(Carte c);
  bool disp(Client *c);

public:

  static Biblioteca* getInstance();

  void adaugaStudent(std::string s1, std::string s2, std::string s3, int a);
  void adaugaProfesor(std::string s1, std::string s2, std::string s3);
  void adaugaCarte(std::string isbn, std::string titlu,std::string autor, std::string gen, int nrPag);

  void stergeCarte(std::string titlu);
  void stergeClient(std::string nume);

  void afiseazaClienti();
  void afiseazaStudenti();
  void afiseazaProfesori();
  void afiseazaCarti();
  void afiseazaCartiDisponibile();

  void imprumutaCarte(std::string isbn, std::string nume);
  void returneazaCarte(std::string isbn, std::string nume);
  void cautaCarte(std::string titlu);

  void celMaiFidelCititor();
  void sorteazaCarti();
  void sorteazaClienti();
  void filtreazaCartiDupaGen(std::string gen);

};

#endif
