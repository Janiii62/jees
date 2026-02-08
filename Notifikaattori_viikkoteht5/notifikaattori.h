#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H
#include "seuraaja.h"

class Notifikaattori
{
public:
    Notifikaattori();
    void lisaa(seuraaja*);
    void poistaa(seuraaja*);
    void tulosta();
    void postita(string);

private:
    seuraaja* seuraajat = nullptr;
};

#endif // NOTIFIKAATTORI_H
