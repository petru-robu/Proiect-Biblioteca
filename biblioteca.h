#include <bits/stdc++.h>

class Carte{
public:
  std::string isbn, titlu, autor, gen;
  int nrPag;
  Carte(std::string isbn, std::string titlu,
    std::string autor,std::string gen, int nrPag): isbn(isbn), titlu(titlu), autor(autor), gen(gen), nrPag(nrPag){}

};

class Date{
public:
  int dd, mm, yy;

  friend std::ostream& operator<< (std::ostream& out,const Date &d)
  {
    out<<d.dd<<'.'<<d.mm<<'.'<<d.yy;
    return out;
  }
};

class Client{
public:
  std::string cod, nume;
  Date retur;
  int nrImp;
  Client(std::string s1, std::string s2): cod(s1), nume(s2){
    retur.mm=0; retur.dd=0; retur.yy=0;
    nrImp=0;
  }

  virtual void print()
  {
    std::cout<<"COD:  "<<cod<<'\n'<<"NUM:  "<<nume<<'\n';
    std::cout<<"RET:  "<<retur<<'\n'<<"NRI:  "<<nrImp;
    std::cout<<'\n';
  }


};

class Profesor: public Client{
public:
  std::string materie;
  Profesor(std::string s1, std::string s2, std::string s3): Client(s1, s2), materie(s3){}

  void print() override
  {
    std::cout<<"COD:  "<<cod<<'\n'<<"NUM:  "<<nume<<'\n';
    std::cout<<"MAT:  "<<materie<<'\n';
    std::cout<<"RET:  "<<retur<<'\n'<<"NRI:  "<<nrImp;
    std::cout<<'\n';
  }

};

class Student: public Client{
public:
  std::string facultate;
  int anStudiu;

  Student(std::string s1, std::string s2, std::string s3, int a): Client(s1, s2), facultate(s3), anStudiu(a){}

  void print() override
  {
    std::cout<<"COD:  "<<cod<<'\n'<<"NUM:  "<<nume<<'\n';
    std::cout<<"FAC:  "<<facultate<<'\n'<<"ANS:  "<<anStudiu<<'\n';
    std::cout<<"RET:  "<<retur<<'\n'<<"NRI:  "<<nrImp;
    std::cout<<'\n';
  }

};

class Biblioteca{
private:
  std::vector<Client*> listaClienti;
  std::vector<Carte> listaCarti;

public:
  void adaugaStudent(std::string s1, std::string s2, std::string s3, int a)
  {
    listaClienti.push_back(new Student(s1,s2,s3,a));
  }

  void adaugaProfesor(std::string s1, std::string s2, std::string s3)
  {
    listaClienti.push_back(new Profesor(s1,s2,s3));
  }

  void afiseazaClienti()
  {
    for(auto cl : listaClienti)
    {
      cl->print();
      std::cout<<"\n\n";
    }
  }


};
