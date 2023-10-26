#include "pet.h"

Pet::Pet(string name, int hunger, int boredom, int happiness, int health) {
    this->name = name;
    this->hunger = hunger;
    this->boredom = boredom;
    this->happiness = happiness;
    this->health = health;
}

Pet::~Pet() {}

string Pet::getName() {
    return name;
}

int Pet::getHunger() {
    return hunger;
}

int Pet::getBoredom() {
    return boredom;
}

int Pet::getHappiness() {
    return happiness;
}

int Pet::getHealth() {
    return health;
}

void Pet::setName(string name) {
    this->name = name;
}

void Pet::setHunger(int hunger) {
    this->hunger = hunger;
}

void Pet::setBoredom(int boredom) {
    this->boredom = boredom;
}

void Pet::setHappiness(int happiness) {
    this->happiness = happiness;
}

void Pet::setHealth(int health) {
    this->health = health;
}

void Pet::play() {
    boredom -= 10;
    happiness += 10;
}

void Pet::feed() {
    hunger -= 10;
    health += 5;
}

void Pet::sleep() {
    boredom += 10;
    hunger += 5;
}

void Pet::nextHour() {
    hunger += 5;
    boredom += 5;
    happiness -= 5;
    health -= 5;
    if (hunger > 40) {
        cout << name << " is hungry!" << endl;
    }
    if (boredom > 40) {
        cout << name << " is bored!" << endl;
    }
    if (happiness < 10) {
        cout << name << " is unhappy!" << endl;
    }
    if (health < 50) {
        cout << name << " is sick!" << endl;
    }
}

void Pet::draw() {}

void Pet::save() {
    ofstream file(name + ".txt");
    file << name << " " << hunger << " " << boredom << " " << happiness << " " << health << endl;
    file.close();
}

void Pet::load() {
    ifstream file(name + ".txt");
    if (file.is_open()) {
        file >> name >> hunger >> boredom >> happiness >> health;
        file.close();
    }
}
