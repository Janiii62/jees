#include "game.h"
#include <iostream>
#include <string>
using namespace std;

Game::Game(int maxNumber) {
    this->maxNumber = maxNumber;
    numOfGuesses = 0;

    srand(time(0));
    randomNumber = rand() % maxNumber + 1;

    cout << "GAME CONSTRUCTOR: object initialized with " << maxNumber << " as maximum value" << endl;
}

Game::~Game(){
    cout << "GAME DESTRUCTOR: object cleared from stack memory" << endl;
}

void Game::play(){

    do{
        cout << "Give your guess between 1-" << maxNumber << endl;
        cin >> playerGuess;

        numOfGuesses++;

        if(playerGuess < randomNumber){
            cout << "Your number is too low" << endl;
        }
        else if(playerGuess > randomNumber){
            cout << "Your number is too high" << endl;
        }
        else{
            cout << "Your guess is right = " << randomNumber << endl;
        }
    }while(playerGuess != randomNumber);

    printGameResult();
}

void Game::printGameResult(){
    cout << "You guessed the right answer = " << randomNumber << " with " << numOfGuesses << " guesses" << endl;
}
