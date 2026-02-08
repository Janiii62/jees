#ifndef SEURAAJA_H
#define SEURAAJA_H
#include <string>
using namespace std;

class seuraaja
{
public:
    seuraaja* next = nullptr;
    seuraaja();
    seuraaja(string);
    string getNimi();
    void paivitys(string);

private:
    string nimi;
};

#endif // SEURAAJA_H
