#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct elementListy {
    string kod="qqq";
    int pozycja = 1;
    long int czestosc=0;
    struct  elementListy* next;
    struct  elementListy* prev;
};

struct Lista {
    elementListy* first;
    elementListy* last;
    int number;
};

void dodajnakoncu(Lista*& list, string kod, int pozycja, int czestosc) {
    elementListy* temp;
    if (!list) {
        list = new Lista;
        list->first = new elementListy;
        list->last = list->first;
        list->number = 1;
        temp = list->first;
        temp->kod = kod;
        temp->next = 0;
        temp->prev = 0;
    }
    else {
        temp = list->last;
        temp->next = new elementListy;
        temp->next->prev = temp;
        temp = temp->next;
        temp->pozycja = temp->prev->pozycja;
        temp->pozycja++;
        temp->next = 0;
        temp->kod = kod;
        temp->czestosc = 0;
        temp->pozycja = pozycja;
        list->last = temp;
        list->number++;
    }
}

void  usunelement(Lista* list) {
    elementListy* temp;
    if (!list) {
        cout << "Lista pusta";
    }
    else {
        temp = list->last;
        if (list->number > 1) {
            temp->prev->next = 0;
            list->last = temp->prev;
            list->number--;
            delete temp;
        }
        else {
            delete temp;
            list->number--;
            list->first = 0;
            list->last = 0;
        }
    }
}

void wypiszliste (Lista* list) {
    if (!list) {
        cout << "Lista pusta";
    }
    else {
        cout << "Lista zawiera: " << list->number << " elementow." << endl;
        cout << "Zawartosc listy: " << endl;
        elementListy* temp = list->first;
        do {
            cout << "Pozycja: " << temp->pozycja << endl;
            cout << "gen: " << temp->kod<<endl;
            cout << "Czestosc : " << temp->czestosc<< endl;
            cout << "*************" << endl;
            temp = temp->next;
        } while (temp);
    }
}

void zliczanieczestostliwosc(Lista* list, string  t)
{
    
    if (!list) {
        return;
    }
    else {
      
        elementListy* temp = list->first;
        do {
            if (t == temp->kod)
            temp->czestosc = temp->czestosc + 1;
            temp = temp->next;
        } while (temp);
    }
    
};
int zadanie1(Lista* list)
{
    int licznik =0;
    if (!list) {
        return 0;
    }
    else {

        elementListy* temp = list->first;
        do {
            if (temp->czestosc != 0)licznik++;
            temp = temp->next;
        } while (temp);
    }
    cout << licznik;
    return licznik;
}
int zadanie2(Lista* list,string szukany)
{
    if (!list) {
        return 0;
    }
    else {

        elementListy* temp = list->first;
        do {
                if (szukany == temp->kod)

                {
                    cout << "gen: " << temp->kod << endl;
                    cout << "Czestosc : " << temp->czestosc << endl;
                    return 0;
                }
            temp = temp->next;
        } while (temp);
    }
}
int zadanie3(Lista* list, int min, int max)
{
    if (!list) {
        return 0;
    }
    else {

        elementListy* temp = list->first;
        do {
        
            
               if (temp->czestosc>=min&&temp->czestosc<=max)
                {
                    cout << "gen: "<<temp->kod<<endl;
                  
                    cout << "Czestosc : " << temp->czestosc << endl;                  
                }

            temp = temp->next;
        } while (temp);
    } return 0;
}
int szukajmax(Lista* list)
{int max=0;
    if (!list) {
        return 0;
    }
    else {
        elementListy* temp = list->first;
        do {
            if (temp->czestosc > max)
            {
                max = temp->czestosc;
            }
             temp = temp->next;
        } while (temp);
    }  return max;
}
int szukajmin(Lista* list,int max)
{
    int min = max ;
    if (!list) {
        return 0;
    }
    else {
        elementListy* temp = list->first;
        do {
            if (temp->czestosc < min)
            {
                min = temp->czestosc;
            }
            temp = temp->next;
        } while (temp);
    }  return min;
}
int zadanie4(Lista* list, int max ,int min)
{

    if (!list) {
        cout << "Lista pusta";
    }
    else {
        cout << "Lista zawiera: " << list->number << " elementow." << endl;
        cout << "Zawartosc listy wedlug czestosci wystepowania: " << endl;
        elementListy* temp = list->first;
        do {
            do {
                if (temp->czestosc == max)
                {
                    cout << "Pozycja: " << temp->pozycja << endl;
                    cout << "Gen: " << temp->kod << endl;
                    cout << "Czestosc : " << temp->czestosc << endl;
                    cout << "*************" << endl;
                }

                temp = temp->next;
            } while (temp);
            temp = list->first;
            max--;
        } while (max != min-1);
    }
    return 1;
}




int main()
{
    string program;
    program = "gramy3.txt";
    string szukany;
    string t;
    fstream gramy;
    int szukanamin;
    int szukanamax;
    int max; int min;
    gramy.open(program);
    if (!gramy.good())
    {
        cerr << " Nie udalo sie otworzyc pliku gramy." << endl;
        return 1;
    }
    else
    {
        cout << "Udalo sie otworzyc plik gramy." << endl;
    }
    int n;
    getline(gramy, t);
    n = t.length();
    cout << "n :" << n << endl;
    
    
        int z = 4;
        for (int i = 1; i < n; i++)  z = (z * 4);
        char tab[4] = { 'A','C','G','T' };
        char gen[3] = { 'A','A','A' };
        string kod;
        string kodz;
        Lista* list = 0;
        for (int i = 1; i <= z; i++)
        {
            if (i % 4 == 1)gen[2] = 'A';
            if (i % 4 == 2)gen[2] = 'C';
            if (i % 4 == 3)gen[2] = 'G';
            if (i % 4 == 0)gen[2] = 'T';
            if (i % 16 == 1)gen[1] = 'A';
            if (i % 16 == 5)gen[1] = 'C';
            if (i % 16 == 9)gen[1] = 'G';
            if (i % 16 == 13)gen[1] = 'T';
            if (i % 64 == 1)gen[0] = 'A';
            if (i % 64 == 17)gen[0] = 'C';
            if (i % 64 == 33)gen[0] = 'G';
            if (i % 64 == 49)gen[0] = 'T';

            string kod = gen;
            kodz = kod.substr(0, 3);
            dodajnakoncu(list, kodz, i, 0);
        } 
        while (!gramy.eof())
        {
            zliczanieczestostliwosc(list, t);
            getline(gramy, t);
        }
   int q;
   char e;
   do {
       cout << "**************MENU**************" << endl << "Co chcesz zrobic ? (Wybierz numer)" << endl
           << "(1) wystepujace / mozliwe " << endl << "(2) kongretny ngram" << endl
           << "(3) konkretna czestotliowosc" << endl << " (4) wypisz wszytko zgodnie z czestotliowscia"
           << endl << "(5)wypisz w kolejnosci alfabetycznej" << endl << "(6) wypisz najczestszy i najrzadszy " << endl; cin >> q;

       switch (q)
       {
       case 1:
           zadanie1(list); cout << " / " << z;
           break;
       case 2:
           cout << "podaj szukany ngram :";
           cin >> szukany;
           zadanie2(list, szukany);
           break;
       case 3:
           cout << "podaj zakres szukanej czestotliwosci" << endl;
           cout << "MIN :"; cin >> szukanamin;
           cout << "MAX :"; cin >> szukanamax;
           zadanie3(list, szukanamin, szukanamax);
           break;
       case 4:
           max = szukajmax(list); cout << "MAX: " << max << endl;
           min = szukajmin(list, max); cout << "MIN: " << min << endl;
           zadanie4(list,max,min);
           break;
       case 5:
           wypiszliste(list);
           break;
       case 6:
           max = szukajmax(list); cout << "MAX: " << max << endl;
           min = szukajmin(list, max); cout << "MIN: " << min << endl;
           break;
       default:
           cout << "Wybrano niepoprawny  numer ." << endl;
           break;
       }
       cout << endl;
       cout << "Kontynuowac? (T/N)";
       cin >> e;
   } while (e == 'T' || e == 't');
        for (int i = 0; i < z; i++)
        {
            usunelement(list);
        }

        list = 0;
        delete list;
        gramy.close();
    return 0;
}

