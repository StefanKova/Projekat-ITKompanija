#ifndef TIMOVI_HPP_INCLUDED
#define TIMOVI_HPP_INCLUDED
#include "Radnik.hpp"
#include <vector>
class Timovi
{
protected:
    string naziv;
    vector<Radnik> r;
public:
    Timovi()
    {
        naziv="Nema naziv";
    }
    Timovi(string Naziv, vector<Radnik> R)
    {
        naziv=Naziv;
        r=R;
    }
    Timovi(const Timovi& t)
    {
        naziv=t.naziv;

    }

    string getNaziv()
    {
        return naziv;
    }

    vector<Radnik> getRadnici()
    {
        return r;
    }


    void setRadnici(vector<Radnik> R)
    {
        r=R;

    }
    int brojClanova()
    {
        return r.size();
    }

    void clanoviTima(){
        for(auto it=r.begin(); it<r.end();it++){
         cout<<*it<<" ";

         cout<<endl;

        }

    }

        friend ostream& operator<<(ostream& izlaz, const Timovi& o)
    {


        izlaz<<"Naziv tima : "<<o.naziv<<endl;
        izlaz<<"Clanovi tima su: "<<endl;
        for(auto it=o.r.begin(); it!=o.r.end(); it++ ){

            izlaz<<"\t";
            izlaz<<*it<<endl;
        }


        return izlaz;

    }


    void dodavanjeRadnika(Radnik o)
{
    r.push_back(o);
    cout<<"Radnik je uspsno ubacen u tim"<<endl;
}


void uklanjanjeRadnika()
{
    int x;
    cout<<"Unesite broj pozicije radnika kojeg zelite da uklonite: ";
    cin>>x;
    r.erase(r.begin()+x);
    cout<<"Radnik na mestu "<<x<<" je uklonjen"<<endl;
}


};


#endif // TIMOVI_HPP_INCLUDED
