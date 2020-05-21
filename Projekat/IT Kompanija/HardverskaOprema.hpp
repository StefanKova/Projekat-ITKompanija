#ifndef HARDVERSKAOPREMA_HPP_INCLUDED
#define HARDVERSKAOPREMA_HPP_INCLUDED
#include "Oprema.hpp"
class HardverskaOprema:public Oprema
{

protected:
    int brojKomada;
    int starost;
    bool uUpotrebi;

public:
HardverskaOprema(int bk, int st, bool uU, string n, bool V):Oprema( n, V)
{
    brojKomada=bk;
    starost=st;
    uUpotrebi=uU;
}
void VrstaOpreme()
{
    Oprema::VrstaOpreme();
    cout<<" i starost ove komponente je "<<starost<<" godine"<<endl;
}

int identifikacija(){return false;}

};


#endif // HARDVERSKAOPREMA_HPP_INCLUDED
