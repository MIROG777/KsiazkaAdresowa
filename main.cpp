#include <iostream>
#include <list>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


struct Adresat
{
    int id = 0;
    string imie = "", nazwisko = "", numerTelefonu = "", email = "", adres = "";
};
bool porownaj(Adresat i, Adresat j)
{
    return ( i.id < j.id );
}
void wprowadzanieDanychAdresata (vector <Adresat> &adresaci);
void sprawdzaniePoImieniu ( vector <Adresat> &adresaci);
void sprawdzaniePoNazwisku (vector <Adresat> &adresaci);
void wypisanieAdresatow ( vector <Adresat> &adresaci);
void zapisywanieAdresatowDoPliku(vector <Adresat> &adresaci);
void automatyczneWczytyawnieAdresatow(vector <Adresat> &adresaci);
void usuwanieAdresata(vector <Adresat> &adresaci);
void zmianaDanychAdresata(vector <Adresat> &adresaci);
string zamianaNaString(int num)
{
    string str = to_string(num);
    return str;
};
int zamianaStringNaInt(string str_num)
{
    int num = stoi(str_num);
    return num;
};

int main()
{
    char wybor;
    vector <Adresat> adresaci;
    string daneAdresoweZnajomego, skladowaDanychAdresowychZnajomego;


    automatyczneWczytyawnieAdresatow(adresaci);

    while(1)
    {
        system("cls");
        cout << "Podaj cyfre odpowiadajaca wybranej opcji" << endl;
        cout << "1. Dodaj Adresata" << endl;
        cout << "2. Szukaj Adresatow po imieniu" << endl;
        cout << "3. Szukaj Adresatow po nazwisku" << endl;
        cout << "4. Wypisz dane wszystkich Adresatow" << endl;
        cout << "5. Usun wybranego Adresata" << endl;
        cout << "6. Edytuj Adresata" << endl;
        cout << "9. Zakoncz program" << endl;
        cin >> wybor;

        if (wybor == '1')
        {
            wprowadzanieDanychAdresata(adresaci);
            zapisywanieAdresatowDoPliku(adresaci);

        }
        else if (wybor == '2' )
        {
            sprawdzaniePoImieniu (adresaci);
        }
        else if (wybor == '3' )
        {
            sprawdzaniePoNazwisku (adresaci);
        }
        else if (wybor == '4' )
        {
            wypisanieAdresatow(adresaci);
        }
        else if (wybor == '5' )
        {
            usuwanieAdresata(adresaci);
            zapisywanieAdresatowDoPliku(adresaci);
        }
        else if (wybor == '6' )
        {
            zmianaDanychAdresata(adresaci);
            zapisywanieAdresatowDoPliku(adresaci);
        }
        else if (wybor == '9' )
        {
            zapisywanieAdresatowDoPliku(adresaci);
            exit(0);
        }
    }

    return 0;
}
void wprowadzanieDanychAdresata (vector <Adresat> &adresaci)
{
    int liczbaSprawdzajacaDojscieDoKoncaPetli=0;
    Adresat adresat;
    cout << "Podaj imie Adresata: ";
    cin >> adresat.imie;
    cout << "Podaj nazwisko Adresata: ";
    cin >> adresat.nazwisko;
    cout << "Podaj numer Telefonu Adresata: ";
    cin >> adresat.numerTelefonu;
    cout << "Podaj email Adresata: ";
    cin >> adresat.email;
    cout << "Podaj adres Adresata: ";
    cin >> adresat.adres;
    system("PAUSE");
    if (adresaci.size()==0 || (adresaci.size()==1 && adresaci[0].id>1) )
    {
        adresat.id=1;
    }
    else if(adresaci.size()>=1)
    {
        adresat.id=adresaci[adresaci.size()-1].id+1;
        /*for(int i=0; i<=adresaci.size()-1; i++)
        {
            if(adresaci[i].id!=adresaci[i+1].id)
            {
                adresat.id=adresaci[i].id+1;
            }
            else
            {
                liczbaSprawdzajacaDojscieDoKoncaPetli++;
            }
            if(liczbaSprawdzajacaDojscieDoKoncaPetli==adresaci.size())
            {
                adresat.id=adresaci[liczbaSprawdzajacaDojscieDoKoncaPetli+1].id+1;
            }
        }*/
    }


    adresaci.push_back(adresat);
    sort(adresaci.begin(), adresaci.end(), porownaj);
}
void sprawdzaniePoImieniu (vector <Adresat> &adresaci)
{
    string imie;
    cout << "Podaj imie znajomego: ";
    cin >> imie;
    for (int i=0; i< adresaci.size(); i++)
    {
        if ( adresaci[i].imie == imie)
        {
            cout << "ID Adresata: " << adresaci[i].id << endl;
            cout << "Imie Adresata: " <<adresaci[i].imie << endl;
            cout << "nazwisko Adresata: " <<adresaci[i].nazwisko << endl;
            cout << "Numer Telefonu Adresata: " <<adresaci[i].numerTelefonu << endl;
            cout << "Adres Adresata: " <<adresaci[i].adres << endl;
            cout << "E-mail Adresata: " <<adresaci[i].email << endl;
            cout << endl << endl;

        }
    }
    system("PAUSE");
}
void sprawdzaniePoNazwisku (vector <Adresat> &adresaci)
{
    string nazwisko;
    cout << "Podaj nazwisko znajomego: ";
    cin >> nazwisko;
    for (int i=0; i< adresaci.size(); i++)
    {
        if ( adresaci[i].nazwisko == nazwisko)
        {
            cout << "ID Adresata: " << adresaci[i].id << endl;
            cout << "Imie Adresata: " <<adresaci[i].imie << endl;
            cout << "nazwisko Adresata: " <<adresaci[i].nazwisko << endl;
            cout << "Numer Telefonu Adresata: " <<adresaci[i].numerTelefonu << endl;
            cout << "Adres Adresata: " <<adresaci[i].adres << endl;
            cout << "E-mail Adresata: " <<adresaci[i].email << endl;
            cout << endl << endl;

        }
    }
    system("PAUSE");
}
void wypisanieAdresatow (vector <Adresat> &adresaci)
{

    for (int i=0; i< adresaci.size(); i++)
    {
        cout << "ID Adresata: " << adresaci[i].id << endl;
        cout << "Imie Adresata: " <<adresaci[i].imie << endl;
        cout << "nazwisko Adresata: " <<adresaci[i].nazwisko << endl;
        cout << "Numer Telefonu Adresata: " <<adresaci[i].numerTelefonu << endl;
        cout << "Adres Adresata: " <<adresaci[i].adres << endl;
        cout << "E-mail Adresata: " <<adresaci[i].email << endl;
        cout << endl << endl;


    }
    system("PAUSE");
}
void zapisywanieAdresatowDoPliku(vector <Adresat> &adresaci)
{
    Adresat adresat;
    string daneAdresata="";
    // fstream ksiazkaAdresowa;
    ofstream ksiazkaAdresowa;
    ksiazkaAdresowa.open("ksiazkaAdresowa.txt",ios::out | ios::trunc);
    ksiazkaAdresowa.close();
    ksiazkaAdresowa.open("ksiazkaAdresowa.txt",ios::out| ios::app);
    for(int i=0; i<=adresaci.size()-1; i++)
    {
        daneAdresata+=zamianaNaString(adresaci[i].id);
        daneAdresata+="|";
        daneAdresata+=adresaci[i].imie;
        daneAdresata+="|";
        daneAdresata+=adresaci[i].nazwisko;
        daneAdresata+="|";
        daneAdresata+=adresaci[i].numerTelefonu;
        daneAdresata+="|";
        daneAdresata+=adresaci[i].email;
        daneAdresata+="|";
        daneAdresata+=adresaci[i].adres;
        daneAdresata+="|";
        ksiazkaAdresowa << daneAdresata << endl;
        daneAdresata="";

    }
    ksiazkaAdresowa.close();
}
void automatyczneWczytyawnieAdresatow(vector <Adresat> &adresaci)
{
    Adresat adresat;
    int liczebnikDlaWprowadzaniaTypuDanychAdresata=1;
    string linia, skladowaDanychAdresta="";
    fstream ksiazkaAdresowa;
    ksiazkaAdresowa.open ("ksiazkaAdresowa.txt",ios::in);
    if (ksiazkaAdresowa.good()== true)
    {

        while (getline(ksiazkaAdresowa, linia))
        {
            for( int i=0; i<=linia.size(); i++)
            {
                if(linia[i]!='|' & i!=linia.size())
                {
                    skladowaDanychAdresta+=linia[i];

                }
                else if (linia[i]=='|' && liczebnikDlaWprowadzaniaTypuDanychAdresata==1)
                {
                    adresat.id=zamianaStringNaInt(skladowaDanychAdresta);
                    skladowaDanychAdresta="";
                    liczebnikDlaWprowadzaniaTypuDanychAdresata=2;
                }
                else if (linia[i]=='|' & liczebnikDlaWprowadzaniaTypuDanychAdresata==2)
                {
                    adresat.imie=skladowaDanychAdresta;
                    skladowaDanychAdresta="";
                    liczebnikDlaWprowadzaniaTypuDanychAdresata=3;
                }
                else if (linia[i]=='|' & liczebnikDlaWprowadzaniaTypuDanychAdresata==3)
                {
                    adresat.nazwisko=skladowaDanychAdresta;
                    skladowaDanychAdresta="";
                    liczebnikDlaWprowadzaniaTypuDanychAdresata=4;
                }
                else if (linia[i]=='|' & liczebnikDlaWprowadzaniaTypuDanychAdresata==4)
                {
                    adresat.numerTelefonu=skladowaDanychAdresta;
                    skladowaDanychAdresta="";
                    liczebnikDlaWprowadzaniaTypuDanychAdresata=5;
                }
                else if (linia[i]=='|' & liczebnikDlaWprowadzaniaTypuDanychAdresata==5)
                {
                    adresat.email=skladowaDanychAdresta;
                    skladowaDanychAdresta="";
                    liczebnikDlaWprowadzaniaTypuDanychAdresata=6;
                }
                else if (linia[i]=='|' & liczebnikDlaWprowadzaniaTypuDanychAdresata==6)
                {
                    adresat.adres=skladowaDanychAdresta;
                    skladowaDanychAdresta="";
                    liczebnikDlaWprowadzaniaTypuDanychAdresata=1;
                    adresaci.push_back(adresat);
                }

            }
        }
    }

    ksiazkaAdresowa.close();

}
void usuwanieAdresata(vector <Adresat> &adresaci)
{
    int idDoUsunieciaAdresata, liczbaPorzadkowaDlaUsunieciaAdresata=0;
    char potwierdzenie;
    cout<< "Podaj numer ID Adresata do usuniecia: ";
    cin >> idDoUsunieciaAdresata;
    cout <<"Czy na pewno chcesz usunac adresata?('t' na tak, 'n' na nie): ";
    cin >> potwierdzenie;
    if (potwierdzenie=='t')
    {
        for(int i=0; i<adresaci.size(); i++)
        {
            if (adresaci[i].id==idDoUsunieciaAdresata)
            {
                liczbaPorzadkowaDlaUsunieciaAdresata=i;
            }
        }
        if(liczbaPorzadkowaDlaUsunieciaAdresata!=0)
        {
            adresaci.erase(adresaci.begin()+liczbaPorzadkowaDlaUsunieciaAdresata);
        }
        // sort(adresaci.id.begin(), adresaci.id.end());
    }
}
void zmianaDanychAdresata(vector <Adresat> &adresaci)
{
    int idDoZmianyDanychAdresata, liczbaPorzadkowaDlaZmianyDanychAdresata, zmiennaOtwierajacaMenu=0;
    char wybor;
    cout<< "Podaj numer ID Adresata do zmiany danych: ";
    cin >> idDoZmianyDanychAdresata;
    for(int i=0; i<adresaci.size(); i++)
    {
        if ( adresaci[i].id==idDoZmianyDanychAdresata)
        {
            liczbaPorzadkowaDlaZmianyDanychAdresata=i;
            zmiennaOtwierajacaMenu=1;
            zmiennaOtwierajacaMenu=1;
        }
    }
    if (zmiennaOtwierajacaMenu!=0)
    while(1)
    {
        system("cls");
        cout << "Podaj cyfre odpowiadajaca wybranej opcji" << endl;
        cout << "1. Zmien imie" << endl;
        cout << "2. Zmien nazwisko" << endl;
        cout << "3. Zmien numer telefonu" << endl;
        cout << "4. Zmien email" << endl;
        cout << "5. Zmien adres" << endl;
        cout << "9. Powrot do menu " << endl;
        cin >> wybor;

        if (wybor == '1')
        {
            cout<<"Podaj nowe imie: ";
            cin >> adresaci[liczbaPorzadkowaDlaZmianyDanychAdresata].imie;
            cout <<"zmienione!"<< endl;
            system("PAUSE");
        }
        else if (wybor == '2' )
        {
            cout<<"Podaj nowe nazwisko: ";
            cin >> adresaci[liczbaPorzadkowaDlaZmianyDanychAdresata].nazwisko;
            cout <<"zmienione!"<< endl;
            system("PAUSE");
        }
        else if (wybor == '3' )
        {
            cout<<"Podaj nowy numer telefonu: ";
            cin >>adresaci[liczbaPorzadkowaDlaZmianyDanychAdresata].numerTelefonu;
            cout <<"zmienione!"<< endl;
            system("PAUSE");
        }
        else if (wybor == '4' )
        {
            cout<<"Podaj nowy emial: ";
            cin >> adresaci[liczbaPorzadkowaDlaZmianyDanychAdresata].email;
            cout <<"zmienione!"<< endl;
            system("PAUSE");
        }
        else if (wybor == '5' )
        {
            cout<<"Podaj nowy adres: ";
            cin >>adresaci[liczbaPorzadkowaDlaZmianyDanychAdresata].adres;
            cout <<"zmienione!"<< endl;
            system("PAUSE");
        }
        else if (wybor == '9' )
        {
            break;
        }
    }

}


