#include <iostream>

using namespace std;

#include "Kompanija.hpp"
#include "Kancelarije.hpp"
#include "Radnik.hpp"
#include "Timovi.hpp"
#include "Projekti.hpp"
#include "SoftverskiAlati.hpp"
#include "Oprema.hpp"
#include "Klijenti.hpp"
#include "Prihodi.hpp"
#include "Rashodi.hpp"
#include "Kvalifikacije.hpp"
#include "VodjaTima.hpp"
#include <vector>
#include <iostream>
#include <fstream>

void citajTxt(string nazivFajla)
{
    string linija;
    ifstream fajl (nazivFajla.c_str());
    if (fajl.is_open())
    {
        while ( getline (fajl,linija) )
        {
            cout << linija << '\n';
        }
        fajl.close();
    }

    else
        cout << "Neuspesno otvoren fajl";

}



int main()
{
    Kvalifikacije FrontEndProgramer(true,false,true,false,true,false,"balbal");
    Kvalifikacije Programer(true,true,true,true,true,true,"balbal");

    Radnik Pera("Pera","Peric","Negde daleko",FrontEndProgramer,junior,5.45);

    cout<<"Plata od: "<<Pera.getIme()<<" je "<<Pera.getPlata()<<"e"<<endl;

    Radnik Miki("Miki","Peric","Negde daleko od kuce",FrontEndProgramer,medior,10.45);

    Radnik Stefan("Stefan","K","Negde daleko od kuce",Programer,senior,15.45);



    vector<Radnik> r;
    r.push_back(Pera);
    r.push_back(Stefan);
    r.push_back(Miki);
    Timovi timA("Tim A", r);

    timA.setRadnici(r);


    cout<<"Naziv tima je "<<timA.getNaziv()<<endl;

    cout<<"Broj clanova je: "<<timA.brojClanova()<<endl;

    VodjaTima StefanVT1(Stefan,timA,8,10);
    cout<<"Rejting vodje tima A je "<<StefanVT1.Rejting()<<endl;

    Timovi timB("Tim B",r);
    VodjaTima vodjaTima2(timB,7,10,"Stefan","K","",Programer,senior,12);
    cout<<"Rejting vodje tima B je "<<vodjaTima2.Rejting()<<endl;


    cout<<"Vodja tima 1 ima realizovanih projekata: "<<StefanVT1.getRealizovaniProjekti()<<endl;
    cout<<"Vodja tima 1 ima ukupno projekata projekata: "<<StefanVT1.getUkupnoProjekata()<<endl;
    cout<<"Rejting vodje tima 1 je "<<StefanVT1.Rejting()<<endl;
    StefanVT1.dodajRealizovaneProjekte(2);
    cout<<"Vodja tima 1 ima realizovanih projekata: "<<StefanVT1.getRealizovaniProjekti()<<endl;
    cout<<"Vodja tima 1 ima ukupno projekata projekata: "<<StefanVT1.getUkupnoProjekata()<<endl;
    cout<<"Rejting vodje tima A je "<<StefanVT1.Rejting()<<endl;
    StefanVT1.IzracunajPlatu(20000);

    Stefan.IzracunajPlatu(111);


    StefanVT1.dodajNerealizovaneProjekte(200);
    cout<<"Vodja tima 1 ima realizovanih projekata: "<<StefanVT1.getRealizovaniProjekti()<<endl;
    cout<<"Vodja tima 1 ima ukupno projekata projekata: "<<StefanVT1.getUkupnoProjekata()<<endl;
    cout<<"Rejting vodje tima A je "<<StefanVT1.Rejting()<<endl;

    cout<<"Stefan vodja ima platu: "<<StefanVT1.getPlata()<<endl;
    cout<<"Stefan radnik ima platu: "<<Stefan.getPlata()<<endl;

    StefanVT1.setKoefPlata(Stefan.getKoefPlata()+30);
    cout<<"Stefan vodja ima platu: "<<StefanVT1.getPlata()<<endl;

    cout<<"Stefan vodja tima 1 ima koef plate: "<<StefanVT1.getKoefPlata()<<endl;
    cout<<"Stefan vodja tima 1 ima rejting: "<<StefanVT1.Rejting()<<endl;
    cout<<"Stefan vodja tima 1 ima real projekata: " <<StefanVT1.getRealizovaniProjekti()<<endl;
    StefanVT1.dodajRealizovaneProjekte(1000);
    cout<<"Stefan vodja tima 1 ima real projekata: " <<StefanVT1.getRealizovaniProjekti()<<endl;
    cout<<"Stefan vodja tima 1 ima rejting: "<<StefanVT1.Rejting()<<endl;
    StefanVT1.Bonus(StefanVT1.Rejting());
    cout<<"Stefan vodja tima 1 ima koef plate: "<<StefanVT1.getKoefPlata()<<endl;



    //Uvesti sve kancelarije kojima ce raspolagati kompanija.

    //Zatim cu radnike smestiti u vec napomenute kancelarije, po kojima ce se formirati i timovi.

    //Zatim cu dodati klijente koji ce dodeljivati projekte, a klijente ce pronalaziti sluzba za marketing.

    //Sluzba za marketing ce biti obican radnik koji ce imati odredjene razlicitosti.

    //Na projektima ce raditi timovi, s vodjom tima na celu koji ce snositi sve posledice.

    //Da bi timovi mogli da rade koristice odredjenu opremu, hardver i softberske alate, koji ce se uracunavati u rashode.

    //Prihodi ce se racunati iskljucivo na osnovu projekata i odrzavanja na mesecnom nivou istih, dakle projekat ce imati pocetnu cenu za koju je klijenat kupi i ugovor koliko ce morati da koristi isti za odredjenu cenu na mesecnom  nivou.

    //Rashodi ce se racunati na osnovu skoro svega, od obicne plate radnika do racuna, npr. potrosnja struje pa sve do komunalija ili do nekih nepredvidivih okolnosti kao na primer sto je ova sad.

    //Dobit firme cu izracunati tek na kraju, nakon striknog definisanja prihoda i rashoda.

    //Sa dobitom firme cu vrsiti funkcionalost tako sto cu manipulisati njenom vrednoscu i odredjidjivati u kom smeru ce novac ici.Npr. imacu knjigu utisaka u koju ce moci da pisu radnici i klijenti, pa cu tako napraviti prostor za napredak firme.

    //Od konkretnih funkcionalosti program ce posedovati npr, izracunavanje plate svakog pojedinacnog radnika, izracunavanje kranje dobiti u svakom trenutku, izracunavanjee dobiti u buducnosti ako firma nastavi u odredjenom smeru, upozoravati ako je odredjena licenca za softver pri kraju, ako klijenat kasni sa uplacivanjem, ako vodja tima ima los rejting ili ima rejting iznad proseka da se nagradi s odredjenim bonusima. Bukvalno ce raditi sve automatizovaano za jednu IT-firmu da se ne bi desilo da ista promakne i da ta firma ide u svom najbolljem mogucem smeru.


    Klijenti Samsung("samsungg","Amerika","44455","samo@ffice.com",veliko);
    Klijenti LG("LG","Amerika","22222","LG@tralaala.com",malo);
    Klijenti Nokia("Nokia","Daleka proslost","231231231","nekadbilapopularna@proslost.com",veliko);

    if(!Samsung.PostojiKlijentUFajlu())
        Samsung.DodajKlijentaUFajl();

    if(!LG.PostojiKlijentUFajlu())
        LG.DodajKlijentaUFajl();

    if(!Nokia.PostojiKlijentUFajlu())
        Nokia.DodajKlijentaUFajl();




    citajTxt("Klijenti.txt");

    cout << "Ukupno zaposlenih(primer staticnog polja): " << Radnik::ukupnoZaposlenih<< endl;

    cout<<Stefan<<endl;
    cout<<StefanVT1<<endl;
    cout<<Samsung<<endl;


    for(int i=0; i<10;i++){
    cout<<endl;};
    HardverskaOprema h(10, 2, true, "Hardver", true);
    h.VrstaOpreme();
    cout<<endl;


    Oprema o("Aparat za kafu",false);
    SoftverskiAlati s("Alat", "Verzija 2.0", true);
    SoftverskiAlati s1("alat", "Verzija 1.0", true);


    /*s.dodavanjeOpreme(s);
    s.dodavanjeOpreme(s1);
    s.ispisOpreme();
    s.uklanjanjeOpreme();
    s.ispisOpreme();

    cout<<endl<<endl;
    cout<<o<<endl;
    s.pretraga();*/

    //

    Oprema* o2=&s;
    o2->VrstaOpreme();

    /*printf("Molimo Vas izaberite akciju!\n"
        "1.Prikazi Kupce                          4.Dodaj Kupca                             7.Brisi Kupca\n"
        "2.Prikazi Destinacije                    5.Dodaj Destinaciju                       8.Brisi Destinaciju\n"
        "3.Prikazi Aranzmane                      6.Dodaj Aranzman                          9.Brisi Aranzman\n\n"

        "0.Izlaz"

                                        );



    int n = -1;
    while (n != 0)
    {
        printf("\n> ");

        scanf("%d", &n);


        switch (n)
        {
        case PrikaziKupce:
            printf("Podaci o kupcima: \n");
            PrikaziPodatkeOKupcima();

            break;
        case PrikaziDestinacije:
            printf("Podaci o destinacijama: \n");
             PrikaziPodatkeODestinacijama();
            break;
        case PrikaziAranzmane:
            printf("Podaci o aranzmanima: \n");
            PrikaziPodatkeOAranzmanu();
            break;
        case DodajKupca:
            printf("Dodavanje novog kupca: \n");
            DodajNovogKupca();
            break;

        case DodajDestinaciju:
            printf("Dodavanje nove destinacije: \n");
            DodajNovuDestinaciju();
            break;

        case DodajAranzman:
            printf("Dodavanje novog aranzmana: \n");
            DodajNoviAranzman();
            break;

        case BrisiKupca:
            printf("Brisanje kupca: \n");
            BrisanjeKupca();

            break;

        case BrisiDestinaciju:
            printf("Brisanje destinacije: \n");
            BrisanjeDestinacije();
            break;

        case BrisiAranzman:
            printf("Brisanje aranzmana: \n");
            break;
        case 0:
            printf("Izasli ste iz programa \n");
            break;


        default:
            printf("Nepoznata akcija\n");
        }
    }
*/
    cout<<s;

    Kancelarije k("Zmaj Jovina 1G",20);
    k.dodavanjeOpreme(o);
    cout<<k;

    cout<<StefanVT1<<endl;
    cout<<"rad";

    cout<<timA.brojClanova();

    //timA.dodavanjeRadnika(Stefan);

    cout<<timB.brojClanova();


    cout<<Stefan;
    cout<<StefanVT1;

    timA.clanoviTima();

     for(int i=0; i<10;i++){
    cout<<endl;};


    cout<<StefanVT1;

    timA.dodavanjeRadnika(Stefan);

    cout<<timA<<endl;

     for(int i=0; i<10;i++){
    cout<<endl;};

     for(int i=0; i<10;i++){
    cout<<endl;};


    cout<<StefanVT1<<endl; //neradii popraviti


    cout<<timA<<endl;

     for(int i=0; i<10;i++){
    cout<<endl;};

     for(int i=0; i<10;i++){
    cout<<endl;};

     for(int i=0; i<10;i++){
    cout<<endl;};

     for(int i=0; i<10;i++){
    cout<<endl;};

     for(int i=0; i<10;i++){
    cout<<endl;};

     for(int i=0; i<10;i++){
    cout<<endl;};




    Oprema oprema22("neki naziv",true);


    SoftverskiAlati sof("softver11","3.0",false);

    cout<<sof;

    HardverskaOprema har(12,4,true,"hardver",true);

    cout<<har<<endl;


    //ispis vodje ne radi u potrpunosti, ispis da li je hardver i softver takodje,zasto se oprema u kancelariji ispisuje kao adresa, ispis kompanije u potpunosti;
     cout<<k;

return 0;
}
