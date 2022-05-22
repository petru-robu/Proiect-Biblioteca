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
  bool operator==(const Carte c)
  {
    if(isbn == c.isbn)
      return true;
    else
      return false;
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
  std::vector<std::pair<Client*, Carte>> listaImprumuturi;

  int random(int min, int max);
  Date randomDate();
  int findPosCarte(std::string isbn);
  int findPosCarteTitlu(std::string titlu);
  int findPosClient(std::string nume);
  bool disp(Carte c);
  bool disp(Client *c);

public:
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

Date Biblioteca::randomDate()
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
  return ret;
}

int Biblioteca::findPosCarte(std::string isbn)
{
  int posCarte=-1;
  for(int i=0; i<listaCarti.size(); i++)
  {
    if(listaCarti[i].isbn == isbn)
    {
      posCarte=i;
      break;
    }
  }
  return posCarte;
}

int Biblioteca::findPosCarteTitlu(std::string titlu)
{
  int posCarte=-1;
  for(int i=0; i<listaCarti.size(); i++)
  {
    if(listaCarti[i].titlu == titlu)
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

  if(posCarte==-1||posClient==-1||!disp(listaCarti[posCarte])||!disp(listaClienti[posClient]))
  {
    std::cout<<"Nu s-a putut imprumuta\n";
    return;
  }

  listaImprumuturi.push_back(std::make_pair(listaClienti[posClient], listaCarti[posCarte]));

  listaClienti[posClient]->retur = randomDate();
  listaCarti[posCarte].available = false;
  listaClienti[posClient]->nrImp++;
  std::cout<<"S-a imprumutat cu succes!\n\n";

}

void Biblioteca::returneazaCarte(std::string isbn, std::string nume)
{
  int posCarte = findPosCarte(isbn), posClient= findPosClient(nume);

  if(posCarte==-1||posClient==-1||disp(listaCarti[posCarte])||disp(listaClienti[posClient]))
  {
    std::cout<<"Nu s-a putut returna!\n\n";
    return;
  }

  for(int i=0; i<listaImprumuturi.size(); i++)
  {
    if(listaImprumuturi[i].first == listaClienti[posClient] && listaImprumuturi[i].second == listaCarti[posCarte])
      {
        Date ret;
        ret.mm=0; ret.dd=0; ret.yy=0;
        listaClienti[posClient]->retur = ret;
        listaCarti[posCarte].available = true;
        listaImprumuturi.erase(listaImprumuturi.begin()+i);

        std::cout<<"S-a returnat cu succes!\n\n";
        return;
      }
  }
  std::cout<<"Nu s-a putut returna!\n\n";

}

void Biblioteca::cautaCarte(std::string titlu)
{
  int pos = findPosCarteTitlu(titlu);
  if(pos!=-1)
    listaCarti[pos].print();
}

void Biblioteca::stergeCarte(std::string titlu)
{
  int pos = findPosCarteTitlu(titlu);
  if(pos!=-1)
    listaCarti.erase(listaCarti.begin()+pos);
}

void Biblioteca::stergeClient(std::string nume)
{
  int pos = findPosClient(nume);
  if(pos!=-1)
    listaClienti.erase(listaClienti.begin()+pos);
}

void Biblioteca::celMaiFidelCititor()
{
  int posmax=0;
  int nrmax = listaClienti[0]->nrImp;
  for(int i=0; i<listaClienti.size(); i++)
  {
    if(listaClienti[i]->nrImp > nrmax)
    {
      nrmax = listaClienti[i]->nrImp;
      posmax = i;
    }
  }
  listaClienti[posmax]->print();
  std::cout<<"\n\n";
}

void Biblioteca::sorteazaCarti()
{
  std::vector<Carte> c_listaCarti(listaCarti);
  for(int i=0 ; i<c_listaCarti.size()-1; i++)
    for(int j=i; j<c_listaCarti.size(); j++)
      if(c_listaCarti[j].nrPag < c_listaCarti[i].nrPag)
        std::swap(c_listaCarti[j], c_listaCarti[i]);

  for(auto carte:c_listaCarti)
  {
    carte.print();
    std::cout<<"\n\n";
  }
  std::cout<<"\n\n\n";
}

void Biblioteca::sorteazaClienti()
{
  std::vector<Client*> c_listaClienti(listaClienti);
  for(int i=0 ; i<c_listaClienti.size()-1; i++)
    for(int j=i; j<c_listaClienti.size(); j++)
      if(c_listaClienti[j]->nume < c_listaClienti[i]->nume)
        std::swap(c_listaClienti[j], c_listaClienti[i]);

  for(auto cl:c_listaClienti)
  {
    cl->print();
    std::cout<<"\n\n";
  }
  std::cout<<"\n\n\n";
}

void Biblioteca::filtreazaCartiDupaGen(std::string gen)
{
  std::cout<<"Lista Carti: \n\n";
  for(auto carte : listaCarti)
  {
    if(carte.gen == gen)
      carte.print(), std::cout<<"\n\n";
  }
  std::cout<<"\n\n\n";
}


class Manager
{
private:
  std::map<int, std::string> Map;
  Biblioteca b;
public:
  Manager()
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
  }

  void command(std::string &string, std::istream &cin)
  {
    cin>>string;
    if(Map[1]==string)
    {
      std::string s1, s2, s3; int a;
      cin>>s1>>s2>>s3>>a;
      b.adaugaStudent(s1,s2,s3,a);
    }
    if(Map[2]==string)
    {
      std::string s1, s2, s3;
      cin>>s1>>s2>>s3;
      b.adaugaProfesor(s1,s2,s3);
    }
    if(Map[3]==string)
    {
      b.afiseazaClienti();
    }
    if(Map[4]==string)
    {
      b.afiseazaStudenti();
    }
    if(Map[5]==string)
    {
      std::string s1, s2, s3, s4; int a;
      cin>>s1>>s2>>s3>>s4>>a;
      b.adaugaCarte(s1,s2,s3,s4,a);
    }
    if(Map[6]==string)
    {
      b.afiseazaCarti();
    }
    if(Map[7]==string)
    {
      b.afiseazaCartiDisponibile();
    }
    if(Map[8]==string)
    {
      std::string s1;
      cin>>s1;
      b.cautaCarte(s1);
    }
    if(Map[9]==string)
    {
      std::string s1;
      cin>>s1;
      b.filtreazaCartiDupaGen(s1);
    }
    if(Map[10]==string)
    {
      b.sorteazaCarti();
    }
    if(Map[11]==string)
    {
      b.sorteazaClienti();
    }
    if(Map[12]==string)
    {
      b.celMaiFidelCititor();
    }
    if(Map[13]==string)
    {
      std::string s1, s2;
      cin>>s1>>s2;
      b.imprumutaCarte(s1, s2);
    }
    if(Map[14]==string)
    {
      std::string s1, s2;
      cin>>s1>>s2;
      b.returneazaCarte(s1, s2);
    }
    if(Map[15]==string)
    {
      std::string s1;
      cin>>s1;
      b.stergeCarte(s1);
    }
    if(Map[16]==string)
    {
      std::string s1;
      cin>>s1;
      b.stergeClient(s1);
    }
  }

};
