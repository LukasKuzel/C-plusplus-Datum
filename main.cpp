#include <iostream>
#include <cstdlib>
#include "datum.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    int r=0;
    int m=0;
    int d=0;

    cout<< "Zadejte den: ";
    cin>>d;
    cout<< "Zadejte mesic: ";
    cin>>m;
    cout<< "Zadejte rok: ";
    cin>>r;
    Datum d2(d,m,r);
    cout<< "Zadane datum je: "<< d2 << endl;
    cout<< "Pocet dni od 1.1.1900 je " << d2.pocetDniOdData() << endl;
    cout<< "Den v tydnu je: "<< d2.denVTydnu()<<"."<< endl;

    Datum d1;
    cout<<"Dnesni datum je: " << d1 << endl;
    cout<< "Pocet dni od 1.1.1900 je " << d1.pocetDniOdData()<< endl;
    cout<< "Den v tydnu je: "<< d1.denVTydnu()<< "."<< endl;
    return 0;
}
