/*
Animal + Habitat Program

*Written by John-Michael Barron*
Using g++ compiler for C++ VScode

This C++ program uses two classes to model animals
within a habitat and outputs their species and diets
using object composition and encapsulation.
*/

#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
    string species;
    string diet; // herb or carn

public:
    Animal(string s, string d) {
        species = s;
        diet = d;

    }

    string getSpecies() const {return species; }
    string getDiet() const {return diet; } //In general can't have two functions with the same name in a given program
};

class Habitat {
private:
    Animal animals[3]; //no dynamic, fixed size for simplicity
    int count;

public:
    Habitat() : animals{
        Animal("Tiger", "carnivore"),
        Animal("Elephant", "herbivore"),
        Animal("Bear", "omnivore")
    }, count(3) {} //set count variable to 3 IMMEDIATELY

    void listAnimals() const {
        cout << "------Animals currently in our Zoo--------\n";
        for (int i = 0; i < 3; ++i) { //Only 3 items in array not 4, 4 caused out of bounds error
            cout << animals[i].getSpecies()
                 << " - " << animals[i].getDiet() << endl;
        }
        cout << "Our zoo is expanding, no need to judge the small amount of animals...\n";
    }
};

int main() {
    Habitat rainforest;
    rainforest.listAnimals(); //should be "listAnimals" not "getAnimals"
    return 0;
}