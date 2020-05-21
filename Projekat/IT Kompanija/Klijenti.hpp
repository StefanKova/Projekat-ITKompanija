#ifndef KLIJENTI_HPP_INCLUDED
#define KLIJENTI_HPP_INCLUDED
#include <iostream>
#include <fstream>

enum TipPreduzeca {malo,srednje,veliko};
class Klijenti
{
protected:

    string naziv;
    string adresa;
    string kontaktTelefon;
    string email;
    TipPreduzeca tip;


public:

    Klijenti()
    {
        naziv="Nepoznato";
        adresa="Nepoznata";
        kontaktTelefon="Nepoznato";
        email="nepoznato";
        tip=malo;
    }
    Klijenti(string Naziv, string Adresa, string KontaktTelefon,string Email,TipPreduzeca Tip)
    {
        naziv=Naziv;
        adresa=Adresa;
        kontaktTelefon=KontaktTelefon;
        email=Email;
        tip=Tip;
    }
    Klijenti(const Klijenti& k)
    {
        naziv=k.naziv;
        adresa=k.adresa;
        kontaktTelefon=k.kontaktTelefon;
        email=k.email;
        tip=k.tip;
    }
    string getNaziv()
    {
        return naziv;
    }
    string getAdresa()
    {
        return adresa;
    }
    string getKontaktTelefon()
    {
        return kontaktTelefon;
    }
    string getEmail()
    {
        return email;
    }
    TipPreduzeca getTip()
    {
        return tip;
    }
    void setNaziv(string Naziv)
    {
        naziv=Naziv;
    }
    void setAdresa(string Adresa)
    {
        adresa=Adresa;
    }
    void setKontaktTelefon(string KontaktTelefon)
    {
        kontaktTelefon=KontaktTelefon;
    }
    void setEmail(string Email)
    {
        email=Email;
    }
    void setTip(TipPreduzeca Tip)
    {
        tip=Tip;
    }

    void DodajKlijentaUFajl()
    {
        ofstream fajl;
        fajl.open ("Klijenti.txt", ios_base::app);
        fajl << getNaziv() << ";" << getAdresa() << ";" << getKontaktTelefon() << ";" << getEmail() << ";" << getTip() << endl;
        fajl.close();
    }

    bool PostojiKlijentUFajlu()
    {
        string linija;
        string nazivIzFajla;
        ifstream fajl("Klijenti.txt");
        if (fajl.is_open())
        {
            while(getline(fajl, linija))
            {
                nazivIzFajla=" ";
                for(int i = 0; i < linija.size(); i++)
                {
                    if(linija[i] == ';')
                    {
                        break;
                    }
                    nazivIzFajla += linija[i];
                }
                if(naziv == nazivIzFajla)
                {
                    fajl.close();
                    return true;
                }
            }
            fajl.close();
            return false;
        }

        return true;
    }
    friend ostream& operator<<(ostream& izlaz, const Klijenti& o)
    {
        string x;
        if(o.tip==0)
        {
            x="malo";
        }
        if(o.tip==1)
        {
            x="srednje";
        }
        if(o.tip==2)
        {
            x="veliko";
        }
        izlaz<<"Naziv : "<<o.naziv<<endl;
        izlaz<<"Tip preduzeca : "<<x<<endl;
        izlaz<<"E-mail : "<<o.email<<endl;

        return izlaz;

    }

};

#endif // KLIJENTI_HPP_INCLUDED
