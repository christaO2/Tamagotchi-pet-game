#include "Dog.h"

Dog::Dog(string name, int hunger, int boredom, int happiness, int health, int loyalty) : Pet(name, hunger, boredom, happiness, health) {
    this->loyalty = loyalty;
}

Dog::~Dog() {}

void Dog::draw() {
  cout << " |\\_/|                  " << endl;
    cout << " | @ @   Woof!          " << endl;
    cout << " |   <>              _  " << endl;
    cout << " |  _/\\------____ ((| |))" << endl;
    cout << " |               `--' | " << endl;
    cout << " ____|_       ___|   |___.' " << endl;
    cout << "/_/_____/____/_______|" << endl;

}

void Dog::save() {
    ofstream file(name + ".txt");
    file << name << " " << hunger << " " << boredom << " " << happiness << " " << health << " " << loyalty << endl;
    file.close();
}

void Dog::load() {
    ifstream file(name + ".txt");
    if (file.is_open()) {
        file >> name >> hunger >> boredom >> happiness >> health >> loyalty;
        file.close();
    }
}

void Dog::bark() {
    boredom -= 5;
    happiness += 5;
}

void Dog::wagTail() {
    loyalty += 10;
    happiness += 5;
}
void Dog::play() {
    bark();
    wagTail();
}