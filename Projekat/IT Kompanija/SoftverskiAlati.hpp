#ifndef SOFTVERSKIALATI_HPP_INCLUDED
#define SOFTVERSKIALATI_HPP_INCLUDED
#include "Oprema.hpp"
class SoftverskiAlati: public Oprema
{

protected:
    string verzija;
    bool aktivnaLicenca;
public:

SoftverskiAlati(string Naziv, string Verzija, bool al):Oprema(Naziv,vrsta){
    naziv=Naziv;
    verzija=Verzija;
    aktivnaLicenca=al;
}

void VrstaOpreme(){
    Oprema::VrstaOpreme();
}
int identifikacija(){return true;}



};


#endif // SOFTVERSKIALATI_HPP_INCLUDED
