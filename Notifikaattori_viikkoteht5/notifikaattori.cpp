#include "notifikaattori.h"
#include <iostream>
using namespace std;
/*
Notifikaattori();
void lisaa(seuraaja*);
void poistaa(seuraaja*);
void tulosta();
void postita(string);
*/


Notifikaattori::Notifikaattori() {

    cout << "Notifikaattori konstruktori" << endl;
}

void Notifikaattori::lisaa(seuraaja* lisSeuraajaPtr){

    cout << "lisaa Seuraaja" << endl;
    if(lisSeuraajaPtr == nullptr){
        return;
    }
    if(seuraajat == nullptr){
        seuraajat = lisSeuraajaPtr;
        return;
    }
    lisSeuraajaPtr->next = seuraajat;
    seuraajat = lisSeuraajaPtr;
}

void Notifikaattori::poistaa(seuraaja* poistSeuraajaPtr){

    cout << "poista Seuraaja" << endl;
    if(poistSeuraajaPtr == nullptr){
        return;
    }
    if(seuraajat == nullptr){
        return;
    }
    if(seuraajat == poistSeuraajaPtr){
        seuraajat = seuraajat ->next;
        return;
    }
    seuraaja* seurTempNext = seuraajat->next;
    seuraaja* seurTempPrev = seuraajat;

    while(seurTempNext->next != nullptr){
        if(seurTempNext == poistSeuraajaPtr){
            seurTempPrev->next = seurTempNext->next;
            return;
        }
        seurTempPrev = seurTempNext;
        seurTempNext = seurTempNext->next;
    }
    if(seurTempNext == poistSeuraajaPtr){
        seurTempPrev->next = nullptr;
    }

}

void Notifikaattori::tulosta(){

    if(seuraajat == nullptr){
        cout << "Ei seuraajia sulla!" << endl;
        return;
    }
    seuraaja* seurTempNext = seuraajat;
    while(seurTempNext->next != nullptr){

        cout << seurTempNext->getNimi() << endl;
        seurTempNext = seurTempNext->next;
    }
    cout << seurTempNext->getNimi() << endl;
}

void Notifikaattori::postita(string viesti){

    if(seuraajat == nullptr){
        cout << "Ei seuraajia sulla!" << endl;
        return;
    }
    seuraaja* seurTempNext = seuraajat;

    while(seurTempNext->next != nullptr){

        seurTempNext->paivitys(viesti);
        seurTempNext = seurTempNext->next;
    }
    seurTempNext->paivitys(viesti);
}
