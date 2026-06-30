#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void dostepne()
{
    ifstream plik("dostepne_ksiazki.txt");

    if(!plik)
    {
        cout<<"Blad otwarcia pliku"<<endl;
        return;
    }

    int id, cena;
    string nazwa;

    cout<<"id tytul cena"<<endl;

    while(plik>>id>>nazwa>>cena)
    {
        cout<<id<<" "<<nazwa<<" "<<cena<<endl;
    }

    plik.close();
}

void podsumowanie()
{
    ifstream plik("kupione_ksiazki.txt");

    if(!plik)
    {
        cout<<"Blad otwarcia pliku"<<endl;
        return;
    }

    int id, cena;
    string nazwa;
    int suma=0;

    cout<<"id tytul cena"<<endl;

    while(plik>>id>>nazwa>>cena)
    {
        suma+=cena;
        cout<<id<<" "<<nazwa<<" "<<cena<<endl;
    }

    cout<<"suma wydatkow "<<suma<<endl;

    plik.close();
}

void kupowanie()
{
    cout<<"WYBIERZ ID KSIAZKI ";
    int wybrane;
    cin>>wybrane;

    ifstream plik("dostepne_ksiazki.txt");

    if(!plik)
    {
        cout<<"Blad otwarcia pliku"<<endl;
        return;
    }

    vector<int> ids;
    vector<string> tytuly;
    vector<int> ceny;

    int id, cena;
    string nazwa;

    bool czy_dostepna=false;

    while(plik>>id>>nazwa>>cena)
    {
        if(id==wybrane)
        {
            czy_dostepna=true;

            ofstream zapis("kupione_ksiazki.txt",ios::app);

            zapis<<id<<" "<<nazwa<<" "<<cena<<endl;

            zapis.close();

            cout<<"ksiazka zostala zakupiona i dodana do listy zakupionych ksiazek"<<endl;
            cout<<"kliknij 7 zeby podsumowac twoje zakupy lub inny klawisz aby kontynuowac ";

            int klikniecie;
            cin>>klikniecie;

            if(klikniecie==7)
            {
                podsumowanie();
            }

            continue;
        }

        ids.push_back(id);
        ceny.push_back(cena);
        tytuly.push_back(nazwa);
    }

    plik.close();

    if(czy_dostepna==false)
    {
        cout<<"wybrana ksiazka nie jest dostepna"<<endl;
        return;
    }

    ofstream nadpisywanie("dostepne_ksiazki.txt");

    for(int i=0;i<ids.size();i++)
    {
        nadpisywanie<<ids[i]<<" "<<tytuly[i]<<" "<<ceny[i]<<endl;
    }

    nadpisywanie.close();
}

void szukanie()
{
    cout<<"wpisz fraze od ktorej zaczyna sie tytul ksiazki ktorej szukasz ";

    string wzorzec;
    cin>>wzorzec;

    ifstream plik("dostepne_ksiazki.txt");

    if(!plik)
    {
        cout<<"Blad otwarcia pliku"<<endl;
        return;
    }

    int id,cena;
    string nazwa;

    cout<<"znalezione ksiazki:"<<endl;
    cout<<"id tytul cena"<<endl;

    bool czy_znalezione=false;

    while(plik>>id>>nazwa>>cena)
    {
        if(nazwa.find(wzorzec)==0)
        {
            cout<<id<<" "<<nazwa<<" "<<cena<<endl;
            czy_znalezione=true;
        }
    }

    if(czy_znalezione==false)
    {
        cout<<"Nie znaleziono"<<endl;
    }

    plik.close();
}

void anulowanie()
{
    ifstream plik("kupione_ksiazki.txt");

    if(!plik)
    {
        cout<<"Brak zakupionych ksiazek"<<endl;
        return;
    }

    ofstream zapis("dostepne_ksiazki.txt",ios::app);

    int id,cena;
    string nazwa;

    while(plik>>id>>nazwa>>cena)
    {
        zapis<<id<<" "<<nazwa<<" "<<cena<<endl;
    }

    plik.close();
    zapis.close();

    ofstream plik2("kupione_ksiazki.txt",ios::trunc);
    plik2.close();

    cout<<"Zakup pomyslnie anulowany"<<endl;
}

void edycja()
{
    cout<<"TWOJE ZAMOWIENIE: "<<endl;
    podsumowanie();
    cout<<"WYBIERZ 8 JESLI CHCESZ USUNAC KSIAZKE Z ZAMOWIENIA LUB"<<endl;
    cout<<"WYBIERZ 9 JESLI CHCESZ ZAMIENIC KSIAZKE NA INNA"<<endl;
    int wybor;
    cin>>wybor;
    if(wybor==8)
    {
        cout<<"wybierz id ksiazki, ktora chcesz usunac: "<<endl;
        int do_usuniecia;
        cin>>do_usuniecia;

        ifstream plik("kupione_ksiazki.txt");

        vector<int> ids;
        vector<string> tytuly;
        vector<int> ceny;

        int id, cena;
        string nazwa;
        bool czy_kupiona=true;
        while(plik>>id>>nazwa>>cena)
        {
            if(id==do_usuniecia)
            {
                ofstream zapis("dostepne_ksiazki.txt",ios::app);
                zapis<<id<<" "<<nazwa<<" "<<cena<<endl;
                zapis.close();
                cout<<"zakup ksiazki zostal anulowany"<<endl;
                czy_kupiona=false;
                continue;
            }
            ids.push_back(id);
            ceny.push_back(cena);
            tytuly.push_back(nazwa);
        }
        if(czy_kupiona==true)cout<<"Wybranej ksiazki nie ma w twoim zamowieniu"<<endl;
        plik.close();
        ofstream nadpisywanie("kupione_ksiazki.txt");

        for(int i=0;i<ids.size();i++)
        {
            nadpisywanie<<ids[i]<<" "<<tytuly[i]<<" "<<ceny[i]<<endl;
        }

        nadpisywanie.close();
        podsumowanie();

    }
    else if(wybor==9)
    {
       cout<<"wybierz id ksiazki, ktora chcesz zamienic: "<<endl;
        int do_usuniecia;
        cin>>do_usuniecia;

        ifstream plik("kupione_ksiazki.txt");

        vector<int> ids;
        vector<string> tytuly;
        vector<int> ceny;

        int id, cena;
        string nazwa;
        bool czy_kupiona=true;
        while(plik>>id>>nazwa>>cena)
        {
            if(id==do_usuniecia)
            {
                ofstream zapis("dostepne_ksiazki.txt",ios::app);
                zapis<<id<<" "<<nazwa<<" "<<cena<<endl;
                zapis.close();
                kupowanie();
                czy_kupiona=false;
                continue;
            }
            ids.push_back(id);
            ceny.push_back(cena);
            tytuly.push_back(nazwa);
        }
        if(czy_kupiona==true)cout<<"Wybranej ksiazki nie ma w twoim zamowieniu"<<endl;
        plik.close();
        ofstream nadpisywanie("kupione_ksiazki.txt");

        for(int i=0;i<ids.size();i++)
        {
            nadpisywanie<<ids[i]<<" "<<tytuly[i]<<" "<<ceny[i]<<endl;
        }

        nadpisywanie.close();
        podsumowanie();
    }
    else
    {
        cout<<"Niepoprawny wybor"<<endl;
    }

}
void wyswietlenie()
{
    cout<<" WYBIERZ :"<<endl;
    cout<<" 1.wyswietl liste dostepnych ksiazek."<<endl;
    cout<<" 2.kup ksiazke."<<endl;
    cout<<" 3.szukaj ksiazki."<<endl;
    cout<<" 4.pokaz zakupione ksiazki."<<endl;
    cout<<" 5.anuluj zakupy."<<endl;
    cout<<" 6.edytuj zamowienie."<<endl;
    cout<<" 0.wyjdz"<<endl;

    int wybor;
    cin>>wybor;

    while(wybor!=0)
    {
        if(wybor==1)
        {
            dostepne();
        }
        else if(wybor==2)
        {
            kupowanie();
        }
        else if(wybor==3)
        {
            szukanie();
        }
        else if(wybor==4)
        {
            podsumowanie();
        }
        else if(wybor==5)
        {
            anulowanie();
        }
        else if(wybor==6)
        {
            edycja();
        }
        else
        {
            cout<<"Niepoprawny wybor"<<endl;
        }

        cin>>wybor;
    }
    cout<<"DZIEKUJEMY"<<endl<<"DO ZOBACZENIA!";
}

int main()
{
    cout<<" _______________________________"<<endl<<endl;
    cout<<" WITAM W KSIEGARNI INTERNETOWEJ"<<endl;
    cout<<" _______________________________"<<endl<<endl;

    wyswietlenie();

    return 0;
}
