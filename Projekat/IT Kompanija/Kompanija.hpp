#ifndef KOMPANIJA_HPP_INCLUDED
#define KOMPANIJA_HPP_INCLUDED
#include "Kancelarije.hpp"
#include <map>
#include <vector>


class Kompanija{

    protected:
        string naziv;
        int godinaOsnivanja;
        string www;
        vector <Kancelarije> kancelarije;
    public:
        Kompanija(){
         naziv="Nepoznat";
         godinaOsnivanja=0;
         www="Nepoznat";
        }
     Kompanija(string nazivKompanije,int godinaOsnivanjaKompanije, string wwwKompanije){
         naziv=nazivKompanije;
         godinaOsnivanja=godinaOsnivanjaKompanije;
         www=wwwKompanije;
     }
     string getNaziv(){
        return naziv;
     }
      int getGodinaOsnvianja(){
        return godinaOsnivanja;
     }
      string getWww(){
        return www;
     }
      void setNaziv(string nazivKompanije){
        naziv=nazivKompanije;
    }
     void setGodinaOsnivanjaKompanije(int godinaOsnivanjaKompanije){
        godinaOsnivanja=godinaOsnivanjaKompanije;
    }
     void setWwwKompanije(string wwwKompanije){
        www=wwwKompanije;
    }
    void Informacije()const{
        cout<<"Kompanija se zove"<<naziv<<", osnovana je"<<godinaOsnivanja<<", pristupiti na"<<www<<endl;
    }


    void dodavanjeKancelarije(Kancelarije o)
{
    kancelarije.push_back(o);
    cout<<"Kancelarija je dodata"<<endl;
}

     void uklanjanjeKancelarije()
{
    int x;
    cout<<"Unesite broj pozicije kancelarije koje zelite da uklonite: ";
    cin>>x;
    kancelarije.erase(kancelarije.begin()+x);
    cout<<"Kancelarija na mestu "<<x<<" je uklonjena"<<endl;
}


};



#endif // KOMPANIJA_HPP_INCLUDED


