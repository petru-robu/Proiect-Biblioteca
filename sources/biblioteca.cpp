#include "../headers/biblioteca.h"

Biblioteca* Biblioteca::instance = 0;

Biblioteca* Biblioteca::getInstance()
{
  if(!instance)
    instance = new Biblioteca;
  return instance;
}

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
    if(listaCarti[i].get_isbn() == isbn)
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
    if(listaCarti[i].get_titlu() == titlu)
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
    if(listaClienti[i]->get_nume() == nume)
    {
      posClient=i;
      break;
    }
  }
  return posClient;
}

bool Biblioteca::disp(Carte c)
{
  return c.get_status();
}

bool Biblioteca::disp(Client *c)
{
  if((c->get_retur()).dd == 0)
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
    if(carte.get_status())
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

  listaClienti[posClient]->set_retur(randomDate());
  listaCarti[posCarte].set_status(false);
  listaClienti[posClient]->set_nrImp(listaClienti[posClient]->get_nrImp()+1);
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
        listaClienti[posClient]->set_retur(ret);
        listaCarti[posCarte].set_status(true);
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
    {listaCarti.erase(listaCarti.begin()+pos); std::cout<<"S-a sters cu succes!\n";}
  else
    std::cout<<"Nu s-a putut sterge!\n";
}

void Biblioteca::stergeClient(std::string nume)
{
  int pos = findPosClient(nume);
  if(pos!=-1)
    {listaClienti.erase(listaClienti.begin()+pos); std::cout<<"S-a sters cu succes!\n";}
  else
    std::cout<<"Nu s-a putut sterge!\n";
}

void Biblioteca::celMaiFidelCititor()
{
  int posmax=0;
  int nrmax = listaClienti[0]->get_nrImp();
  for(int i=0; i<listaClienti.size(); i++)
  {
    if(listaClienti[i]->get_nrImp() > nrmax)
    {
      nrmax = listaClienti[i]->get_nrImp();
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
      if(c_listaCarti[j].get_nrPag() < c_listaCarti[i].get_nrPag())
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
      if(c_listaClienti[j]->get_nume() < c_listaClienti[i]->get_nume())
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
    if(carte.get_gen() == gen)
      carte.print(), std::cout<<"\n\n";
  }
  std::cout<<"\n\n\n";
}
