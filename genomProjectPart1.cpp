//Zuzanna Popławska 310320 1. część zadania

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main()
{
    int dlugosc;
    string program;
    long int z = 0;
    int t;
    char  gen;
    string tmp;
    cout << "podaj nazwe programu: ";
    cin >> program;//genomic.FNA powinniśmy podac w linii poleceń /
    cout << "podaj dlugosc ngramow: ";
    cin >> dlugosc;

    ifstream kod;
    kod.open(program, ios::in );
    if (!kod.good())
    {
        cerr << " Nie udalo sie otworzyc pliku kod." << endl;
        return 1;
    }
    else
    {
        cout << "Udalo sie otworzyc plik kod." << endl;
    }

    long  int a = 0;
    getline(kod, tmp);
    // zliczmy ilość liter w celu stworzenia analizatora
    while (!kod.eof())
    {
        kod >> gen;
        if (gen == 'A' || gen == 'C' || gen == 'G' || gen == 'N' || gen == 'T')
            a++;
    }
    cout << "a:" << a << endl;
    kod.close();
    kod.open(program, ios::in);
    fstream gramy;
    gramy.open("gramy.txt", ios::out | ios::in | ios::trunc);
    if (!gramy.good())
    {
        cerr << " Nie udalo sie otworzyc pliku gramy." << endl;
        return 1;
    }
    else
    {
        cout << "Udalo sie otworzyc plik gramy." << endl;
    }

    getline(kod, tmp);
    while (!kod.eof())

    {
        if (z != 0) {
            kod.seekg(-(dlugosc - 1), ios::cur);
        };

        t = 1;
        for (int i = dlugosc; i > 0; i--)
        {
            kod >> gen; gramy << gen;
            if (gen == 'N') { t = 0; }

        }
        if (t == 0)
            gramy.seekg(-dlugosc, ios::cur);
        else
            gramy << "\n";
        z++;
        if (a < 1000000) {
            if (z % 100 == 0)
            {
                cout << "analizator  " << (z * 100) / a << " %" << program << endl;
            }
        }
        else {
            if (z % 15000 == 0)
            {
                cout << "analizator  " << (z * 100) / a << " %  " << program << endl;
            }
        }
        if (z == a)break;
    };
    //usuwa ostatnia nadpisaną niepoprawną linię 
    for (int i = 0; i < dlugosc+2; i++)
        gramy.seekg(-1, ios::cur);
    for (int i = 0; i < dlugosc; i++)
       gramy << ' ';
  cout << "analizator 100 %  " << program << endl;
    gramy.close();
    kod.close();
    
    return 0;
    };


    



