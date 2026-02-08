#include <iostream>
#include "notifikaattori.h"
#include "seuraaja.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    //return 0;

    Notifikaattori n;
    seuraaja* s1 = new seuraaja("Gertrude");
    seuraaja* s2 = new seuraaja("Pirkko");
    seuraaja* s3 = new seuraaja("Bernard");

    n.tulosta();
    n.postita("Wassaaaaa");
    n.poistaa(s2);

    n.lisaa(s1);
    n.lisaa(s2);
    n.lisaa(s3);
    n.tulosta();
    n.postita("Wassaaaaa");

    n.poistaa(s2);
    n.tulosta();
    n.poistaa(s1);
    n.poistaa(s3);
    n.tulosta();

    return 0;
}
