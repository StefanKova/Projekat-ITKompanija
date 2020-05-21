#ifndef KANCELARIJE_HPP_INCLUDED
#define KANCELARIJE_HPP_INCLUDED
#include "HardverskaOprema.hpp"
#include "SoftverskiAlati.hpp"
#include "Oprema.hpp"
#include <map>
#include <vector>
class Kancelarije
{

protected:
    string adresa;
    int brojRadnihMesta;
    vector<Oprema*> opreme;

public:

    Kancelarije(string Adresa, int BrojRadnihMesta){
        adresa=Adresa;
        brojRadnihMesta=BrojRadnihMesta;
    }

    void dodavanjeOpreme(Oprema &o)
{
    opreme.push_back(&o);
    cout<<"Oprema dodata"<<endl;
}
void uklanjanjeOpreme()
{
    int x;
    cout<<"Unesite broj pozicije objekta koji zelite da uklonite: ";
    cin>>x;
    opreme.erase(opreme.begin()+x);
    cout<<"Oprema na mestu "<<x<<" je uklonjena"<<endl;
}

void pretraga()
{
    bool x;
    cout<<"Unesite 0 ako zelite da pretrazimo hardver, a neki veci broj ako zelite da pretrazimo softver: ";
    cin>>x;
    if(x)
    {
        cout<<"Pretraga je izvrsena, pronadjen je softver"<<endl;
    }
    else
        cout<<"Pretraga je izvrsena, pronadjen je hardver"<<endl;
}
void ispisOpreme()
{
    for(auto it=opreme.begin(); it!=opreme.end(); it++)
        cout<<**it<<" ";
}
    friend ostream& operator<<(ostream& izlaz, const Kancelarije& o)
    {


        izlaz<<"Adresa : "<<o.adresa<<endl;
        izlaz<<"Broj radnih mesta koje kancelarija moze da podrzi: "<<o.brojRadnihMesta<<endl;
        for(auto it=o.opreme.begin();it<o.opreme.end(); it++){
            izlaz<<"\t";
            izlaz<<*it<<endl;
        }


        return izlaz;

    }




};


#endif // KANCELARIJE_HPP_INCLUDED
