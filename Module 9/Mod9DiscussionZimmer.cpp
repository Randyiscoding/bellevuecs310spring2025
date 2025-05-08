/*
Student's Name: Eric Zimmer
Course:         CS310-T301 Programming with C++
Assignment:     M9: Discussion
Professor:      Dr. Robert Flowers
Date:           05/06/2025
File Name:      M9_Discussion.cpp
Description:    This program defines a 'Character' class. 'Mario' and 'Luigi' classes inherit from the 'Character' class.
It then demonstrates some of the methods used for 'Mario' and 'Luigi'.
It has two errors. Find them.

Developed and tested (before errors) in Visual Studio 2022 (Windows).
Compiled with Microsoft (R) C/C++ Optimizing Compiler Version 19.43.34810.
*/

#include <iostream>
#include <string>

using namespace std;

class Character {
private:
    string name;
    int lives = 3;

public:
    // Constructor using initializer list
    Character(const string& n) : name(n) {}

    // Getters
    string getName() const {
        return name;
    }
    int getLives() const {
        return lives;
    }

    // Setters
    void setLives(int x) {
        if (x < 0) {
            lives = 0;
        }
        else {
            lives = x;
        }
    }

    // Prints that character has joined the game
    void introMessage() const {
        cout << getName() << " has joined the game." << endl;
    }

    // Standard jump method
   virtual void jump() const { //added virtual so that luigi's override works here.
        cout << getName() << " does a standard jump." << endl;
    }
};

class Mario: public Character {
private:
    string color = "red";

public:
    using Character::Character; //Mario didn't inherit the charter classes so my mans had no lives,name, etc

    // Mario's special attack is Cappy
    void specialAttack() const {
        cout << "Mario uses cappy!" << endl;
    }
};

class Luigi: public Character {
private:
    string color = "green";

public:
    // Inherit Character's constructor
    using Character::Character;

    // Luigi's special attack is vacuum
    void specialAttack() const {
        cout << "Luigi uses vacuum!" << endl;
    }

    // Luigi has a higher, floatier jump than Mario
    void jump() const override {
        cout << "Luigi does a higher, floaty jump." << endl;
    }
};

int main() {
    // Create a Mario character and use some of his methods
    Mario mario = Mario("Mario");
    mario.introMessage();
    mario.jump();
    mario.specialAttack();

    // Separate the two characters for easier reading
    cout << "\n";

    // Create a Luigi character and use some of his methods
    Luigi luigi = Luigi("Luigi");
    luigi.introMessage();
    luigi.jump();
    luigi.specialAttack();

    return 0;
}