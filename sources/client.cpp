
Client::Client(std::string s1, std::string s2): cod(s1), nume(s2)
{
  retur.mm=0; retur.dd=0; retur.yy=0;
  nrImp=0;
}

virtual void Client::print()
{
  std::cout<<"COD:  "<<cod<<'\n'<<"NUM:  "<<nume<<'\n';
  std::cout<<"RET:  "<<retur<<'\n'<<"NRI:  "<<nrImp;
}

std::string Client::get_cod()
{
  return cod;
}
std::string Client::get_nume()
{
  return nume;
}
Date Client::get_retur()
{
  return retur;
}
int Client::get_nrImp()
{
  return nrImp;
}
