#include "seuraaja.h"
#include <iostream>
using namespace std;
/*
seuraaja();
seuraaja(string);
string getNimi();
void paivitys(string);
*/


seuraaja::seuraaja() {

    cout << "Seuraaja konstruktori" << endl;
}

seuraaja::seuraaja(string annettuNimi) {

    cout << "Seuraaja parametri konstruktori" << endl;
    nimi = annettuNimi;
}

string seuraaja::getNimi(){

    cout << "getN" << endl;
    return(nimi);
}

void seuraaja::paivitys(string viesti){

    cout << "paivitys" << endl;
    cout << "Viesti: " << viesti << endl;
};
