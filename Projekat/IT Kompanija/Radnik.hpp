#ifndef RADNICI_HPP_INCLUDED
#define RADNICI_HPP_INCLUDED
#include "Kvalifikacije.hpp"
#include <iostream>
#include "Radnik.hpp"
#include <vector>

enum  Pozicija {junior,medior,senior};

class Radnik
{

protected:
    string ime;
    string prezime;
    string adresa;
    Kvalifikacije k;
    Pozicija pozicija;
    double koefPlata;
    double plata;

public:
    static int ukupnoZaposlenih;
    Radnik(): k()
    {
        ime="Nepoznato";
        prezime="Nepoznato";
        adresa="Nepoznato";
        koefPlata=0;
        pozicija=junior;
    }
    Radnik(string Ime,string Prezime,string Adresa, Kvalifikacije K,Pozicija Poz, double KoefPlata) : k(K)
    {
        ime=Ime;
        prezime=Prezime;
        adresa=Adresa;
        k=K;
        pozicija=Poz;
        koefPlata=KoefPlata;
        ukupnoZaposlenih++;

    }
    Radnik(const Radnik& r)
    {
        ime=r.ime;
        prezime=r.prezime;
        adresa=r.adresa;
        k=r.k;
        pozicija=r.pozicija;
        koefPlata=r.koefPlata;
    }
    string getIme()
    {
        return ime;
    }
    string getPrezime()
    {
        return prezime;
    }
    string getAdresa()
    {
        return adresa;
    }
    Pozicija getPozicija()
    {
        return pozicija;
    }
    Kvalifikacije getKvalifikacije()
    {
        return k;
    }
    double getKoefPlata()
    {
        return koefPlata;
    }
    double getPlata()
    {
        return plata;
    }

    void setIme(string Ime)
    {
        ime=Ime;
    }
    void setPrezime(string Prezime)
    {
        prezime=Prezime;
    }
    void setAdresa(string Adresa)
    {
        adresa=Adresa;
    }

    void setKvalifikacije(Kvalifikacije K)
    {
        k=K;
    }

    void setPozicija(Pozicija Poz)
    {
        pozicija=Poz;
    }
    void setKoefPlata(double KoefPlata)
    {
        koefPlata=KoefPlata;
    }


    void IzracunajPlatu (int radnisati)
    {
        if(radnisati>180)
            koefPlata*=1.2;

        plata = koefPlata*radnisati;
    }

    friend ostream& operator<<(ostream& izlaz, const Radnik& o)
    {
        string x;
        if(o.pozicija==0)
        {
            x="junior";
        }
        if(o.pozicija==1)
        {
            x="medior";
        }
        if(o.pozicija==2)
        {
            x="senior";
        }
        izlaz<<"Ime radnika : "<<o.ime<<endl;
        izlaz<<"Prezime radnika : "<<o.prezime<<endl;
        izlaz<<"Znanje radnika : "<<x<<endl;

        return izlaz;

    }

};
int Radnik::ukupnoZaposlenih=0;

#endif // RADNICI_HPP_INCLUDED
