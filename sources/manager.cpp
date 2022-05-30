#include "../headers/manager.h"

Manager* Manager::instance = 0;

Manager* Manager::getInstance()
{
  if(!instance)
    instance = new Manager;
  return instance;
}

void Manager::query(std::string &string, std::istream &cin)
{
  Map.insert(std::pair<int, std::string>(1, "adaugaStudent"));
  Map.insert(std::pair<int, std::string>(2, "adaugaProfesor"));
  Map.insert(std::pair<int, std::string>(3, "afiseazaClienti"));
  Map.insert(std::pair<int, std::string>(4, "afiseazaStudenti"));
  Map.insert(std::pair<int, std::string>(5, "adaugaCarte"));
  Map.insert(std::pair<int, std::string>(6, "afiseazaCarti"));
  Map.insert(std::pair<int, std::string>(7, "afiseazaCartiDisponibile"));
  Map.insert(std::pair<int, std::string>(8, "cautaCarte"));
  Map.insert(std::pair<int, std::string>(9, "filtreazaCartiDupaGen"));
  Map.insert(std::pair<int, std::string>(10, "sorteazaCarti"));
  Map.insert(std::pair<int, std::string>(11, "sorteazaClienti"));
  Map.insert(std::pair<int, std::string>(12, "celMaiFidelCititor"));
  Map.insert(std::pair<int, std::string>(13, "imprumutaCarte"));
  Map.insert(std::pair<int, std::string>(14, "returneazaCarte"));
  Map.insert(std::pair<int, std::string>(15, "stergeCarte"));
  Map.insert(std::pair<int, std::string>(16, "stergeClient"));
  Map.insert(std::pair<int, std::string>(17, "exit"));

  cin>>string;
  if(Map[1]==string)
  {
    std::string s1, s2, s3; int a;
    cin>>s1>>s2>>s3>>a;
    b->adaugaStudent(s1,s2,s3,a);
  }
  if(Map[2]==string)
  {
    std::string s1, s2, s3;
    cin>>s1>>s2>>s3;
    b->adaugaProfesor(s1,s2,s3);
  }
  if(Map[3]==string)
  {
    b->afiseazaClienti();
  }
  if(Map[4]==string)
  {
    b->afiseazaStudenti();
  }
  if(Map[5]==string)
  {
    std::string s1, s2, s3, s4; int a;
    cin>>s1>>s2>>s3>>s4>>a;
    b->adaugaCarte(s1,s2,s3,s4,a);
  }
  if(Map[6]==string)
  {
    b->afiseazaCarti();
  }
  if(Map[7]==string)
  {
    b->afiseazaCartiDisponibile();
  }
  if(Map[8]==string)
  {
    std::string s1;
    cin>>s1;
    b->cautaCarte(s1);
  }
  if(Map[9]==string)
  {
    std::string s1;
    cin>>s1;
    b->filtreazaCartiDupaGen(s1);
  }
  if(Map[10]==string)
  {
    b->sorteazaCarti();
  }
  if(Map[11]==string)
  {
    b->sorteazaClienti();
  }
  if(Map[12]==string)
  {
    b->celMaiFidelCititor();
  }
  if(Map[13]==string)
  {
    std::string s1, s2;
    cin>>s1>>s2;
    b->imprumutaCarte(s1, s2);
  }
  if(Map[14]==string)
  {
    std::string s1, s2;
    cin>>s1>>s2;
    b->returneazaCarte(s1, s2);
  }
  if(Map[15]==string)
  {
    std::string s1;
    cin>>s1;
    b->stergeCarte(s1);
  }
  if(Map[16]==string)
  {
    std::string s1;
    cin>>s1;
    b->stergeClient(s1);
  }
}
