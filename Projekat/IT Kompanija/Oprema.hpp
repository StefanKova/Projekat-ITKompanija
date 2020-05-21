#ifndef OPREMA_HPP_INCLUDED
#define OPREMA_HPP_INCLUDED
class Oprema
{

protected:
    string naziv;
    bool vrsta;
public:

Oprema(string Naziv, bool V){
    naziv=Naziv;
    vrsta=V;
}


virtual void VrstaOpreme(){

    if(vrsta==true)
    {
        cout<<"Ovo je softverski alat";
    }
    if(vrsta==false)
    {
        cout<<"Ovo je hardver";
    }
}

    friend ostream& operator<<(ostream& izlaz, const Oprema& o)
    {
        string x;
        if(o.vrsta==0){
            x="Softver";
        }
        if(o.vrsta==1){
            x="Hardver";
        }

        izlaz<<"Naziv : "<<o.naziv<<endl;
        izlaz<<"Vrsta opreme : "<<x<<endl;

        return izlaz;

    }
    bool getVrsta(){return vrsta;}

};


#endif // OPREMA_HPP_INCLUDED
