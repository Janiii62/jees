#include <iostream>

using namespace std;

// luodaan kaavion mukainen ''Chef'' luokka suojatussa tilassa
class Chef {
protected:
    string chefName;
// luodaan julkinen
public:
    Chef(string name) : chefName(name) {
        std::cout << "Chef " << chefName << " konstruktori" << std::endl;
    }

    virtual ~Chef() {
        std::cout << "Chef " << chefName << " destruktori" << std::endl;
    }
// luodaan salaatille ja sopalle muuttujat
    int makeSalad(int items) {
        int portions = items / 5;
        std::cout << "Chef " << chefName << " with " << items << " items can make salad " << portions << " portions" << std::endl;
        return portions;
    }

    int makeSoup(int items) {
        int portions = items / 3;
        std::cout << "Chef " << chefName << " with " << items << " items can make soup " << portions << " portions\n" << std::endl;
        return portions;
    }
};

// tehdään about sama kuin aiemmin mutta italialainen kokki tulee paikalle lol

class ItalianChef : public Chef {
private:
    string password = "pizza";
    int flour;
    int water;

    int makePizza() {
        int pizzas = (flour + water) / 12;
        std::cout << "ItalianChef " << chefName << " with " << flour << " flour and " << water << " water can make " << pizzas << " pizzas" << std::endl;
        return pizzas;
    }

public:
    ItalianChef(string name) : Chef(name) {
        std::cout << "ItalianChef " << chefName << " konstruktori" << std::endl;
    }

    ~ItalianChef() {
        std::cout << "ItalianChef " << chefName << " destruktori" << std::endl;
    }
// kysytään salasanaa saadakseen salainen pizza resepti hommeli
    bool askSecret(string pw, int flourAmount, int waterAmount) {
        if (pw == password) {
            std::cout << "Password is correct you absolute genius >:3\n" << std::endl;
            flour = flourAmount;
            water = waterAmount;
            makePizza();
            return true;
        }
        return false;
    }
};


int main()
{
//hehehe nimistä tulee Mashus Potatus, melkee mashed potatos heheheh

    Chef chef("Potatus");
    chef.makeSalad(11);
    chef.makeSoup(14);

    ItalianChef italianChef("Mashus");
    italianChef.makeSalad(9);
    italianChef.askSecret("pizza", 12, 12);

    return 0;
}
