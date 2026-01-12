#include <iostream>

using namespace std;
// lisätään peli osio tänne erikseeen, muuten maini ei tykkää
int game(int maxnum);

int main() {

    // srand pysyneen ekana koska se ei halua antaa muutaku 1 jos on inttien alla lol
    std::srand((int) time(NULL));

    int maxnum = 100;
    int numberOfGuesses = game(maxnum);

    std::cout << "Number of guesses: " << numberOfGuesses << std::endl;

    return 0;
}

int game(int maxnum){

    int svalue = rand() % maxnum;
    int guess = 0;
    int counter = 0;



    // rakennetaan while looppi
    while(guess != svalue){
        std::cout << "Guess the number between 1-" << maxnum << ": ";
        std::cin >> guess;
        counter++;

        if(guess < svalue){
            std::cout << "The correct number is higher\n" << std::endl;
        }
        else if(guess > svalue){
            std::cout << "The correct number is lower\n" << std::endl;
        }
        else{
            std::cout << "You are correct! Here is a cookie!" << std::endl;
            return counter;
        }
    }
}
