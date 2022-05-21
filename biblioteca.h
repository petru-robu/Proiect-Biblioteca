#include <bits/stdc++.h>

class Carte{
public:
  std::string isbn, titlu, autor, gen;
  int nrPag;
  bool available;
  Carte(std::string isbn, std::string titlu,
    std::string autor, std::string gen, int nrPag): isbn(isbn), titlu(titlu), autor(autor), gen(gen), nrPag(nrPag)
    {
      available = true;
    }
  void print()
  {
      std::cout<<"COD:  "<<isbn<<"\nTIT:  "<<titlu<<"\nAUT:  "<<autor<<"\nGEN:  "<<gen;
      std::cout<<"\nNRP:  "<<nrPag;
      std::cout<<"\nSTR:  ";
      if(available)
        std::cout<<"DISPONIBILA";
      else
        std::cout<<"INDISPONIBILA";
  }
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
  }

};

class Biblioteca{
private:
  std::vector<Client*> listaClienti;
  std::vector<Carte> listaCarti;

  int random(int min, int max);
  int findPosCarte(std::string isbn);
  int findPosClient(std::string nume);
  bool disp(Carte c);
  bool disp(Client *c);

public:
  void adaugaStudent(std::string s1, std::string s2, std::string s3, int a);
  void adaugaProfesor(std::string s1, std::string s2, std::string s3);
  void adaugaCarte(std::string isbn, std::string titlu,std::string autor, std::string gen, int nrPag);

  void afiseazaClienti();
  void afiseazaStudenti();
  void afiseazaProfesori();
  void afiseazaCarti();
  void afiseazaCartiDisponibile();

  void imprumutaCarte(std::string isbn, std::string nume);
  void returneazaCarte(std::string isbn, std::string nume);

};

int Biblioteca::random(int min, int max)
{
  bool first = true;
  if(first)
  {
      std::srand( std::time(NULL) );
      first = false;
  }
  return min + std::rand() % (( max + 1 ) - min);
}

int Biblioteca::findPosCarte(std::string isbn)
{
  int posCarte=-1;
  for(int i=0; i<listaCarti.size(); i++)
  {
    if(listaCarti[i].isbn == isbn && listaCarti[i].available)
    {
      posCarte=i;
      break;
    }
  }
  return posCarte;
}

int Biblioteca::findPosClient(std::string nume)
{
  int posClient=-1;
  for(int i=0; i<listaClienti.size(); i++)
  {
    if(listaClienti[i]->nume == nume)
    {
      posClient=i;
      break;
    }
  }
  return posClient;
}

bool Biblioteca::disp(Carte c)
{
  return c.available;
}

bool Biblioteca::disp(Client *c)
{
  if((c->retur).dd == 0)
    return true;
  else
    return false;
}

void Biblioteca::adaugaStudent(std::string s1, std::string s2, std::string s3, int a)
{
  listaClienti.push_back(new Student(s1,s2,s3,a));
}

void Biblioteca::adaugaProfesor(std::string s1, std::string s2, std::string s3)
{
  listaClienti.push_back(new Profesor(s1,s2,s3));
}

void Biblioteca::adaugaCarte(std::string isbn, std::string titlu, std::string autor, std::string gen, int nrPag)
{
    Carte c(isbn, titlu, autor, gen, nrPag);
    listaCarti.push_back(c);
}

void Biblioteca::afiseazaClienti()
{
  std::cout<<"Lista Clienti: \n\n";
  for(auto cl : listaClienti)
  {
    cl->print();
    std::cout<<"\n\n";
  }
  std::cout<<"\n\n\n";
}

void Biblioteca::afiseazaStudenti()
{
  std::cout<<"Lista Studenti: \n\n";
  for(auto cl : listaClienti)
  {
    auto result = dynamic_cast<Student*>(cl);
    if(result!=nullptr)
    {
      cl->print();
      std::cout<<"\n\n";
    }
  }
  std::cout<<"\n\n\n";
}

void Biblioteca::afiseazaProfesori()
{
  std::cout<<"Lista Profesori: \n\n";
  for(auto cl : listaClienti)
  {
    auto result = dynamic_cast<Profesor*>(cl);
    if(result!=nullptr)
    {
      cl->print();
      std::cout<<"\n\n";
    }
  }
  std::cout<<"\n\n\n";
}

void Biblioteca::afiseazaCarti()
{
  std::cout<<"Lista Carti: \n\n";
  for(auto carte : listaCarti)
  {
    carte.print();
    std::cout<<"\n\n";
  }
  std::cout<<"\n\n\n";
}

void Biblioteca::afiseazaCartiDisponibile()
{
  std::cout<<"Lista Carti Disponibile: \n\n";
  for(auto carte : listaCarti)
  {
    if(carte.available)
    {
      carte.print();
      std::cout<<"\n\n";
    }
  }
  std::cout<<"\n\n\n";
}

void Biblioteca::imprumutaCarte(std::string isbn, std::string nume)
{
  int posCarte = findPosCarte(isbn), posClient= findPosClient(nume);
  if(posCarte==-1||posClient==-1)
  {
    std::cout<<"Nu s-a putut imprumuta\n";
    return;
  }

  if(disp(listaCarti[posCarte]) && disp(listaClienti[posClient]))
  {
    Date ret;
    ret.mm = random(1, 12);
    if((ret.mm%2==1 && ret.mm<=7) || (ret.mm%2==0 && ret.mm>=8))
      ret.dd = random(1, 31);
    else
      {
        if(ret.mm != 2)
          ret.dd = random(1, 31);
        else
          ret.dd = random(1, 28);
      }
    ret.yy = 2022;

    listaClienti[posClient]->retur = ret;
    listaCarti[posCarte].available = false;
    listaClienti[posClient]->nrImp++;
    std::cout<<"S-a imprumutat cu succes!\n\n";
  }

}

void Biblioteca::returneazaCarte(std::string isbn, std::string nume)
{
  int posCarte = findPosCarte(isbn), posClient= findPosClient(nume);
  if(posCarte==-1||posClient==-1)
  {
    std::cout<<"Nu s-a putut returna\n";
    return;
  }

  if(!disp(listaCarti[posCarte]) && !disp(listaClienti[posClient]))
  {
    Date ret;
    ret.mm=0; ret.dd=0; ret.yy=0;

    listaClienti[posClient]->retur = ret;
    listaCarti[posCarte].available = true;
    std::cout<<"S-a returnat cu succes!\n\n";
  }
}
