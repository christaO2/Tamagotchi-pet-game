#include "Turtle.h"

Turtle::Turtle(string name, int hunger, int boredom, int happiness, int health, int shellHardness) : Pet(name, hunger, boredom, happiness, health) {
    this->shellHardness = shellHardness;
}

Turtle::~Turtle() {}

void Turtle::draw() {
    cout << "                                                    ,'" << endl;
    cout << "                                                  ,;" << endl;
    cout << "                                                .'/ " << endl;
    cout << "           `-_                                .' / " << endl;
    cout << "             `;-_                           .' / " << endl;
    cout << "               `.-.        ,_.-'`'--'`'-._.` .' " << endl;
    cout << "                 `.`-.    /    .\"\".   _.'  / " <<"     Super Turtle"<< endl;
    cout << "                   `. '-.'_.._/0 \" 0\\/`    \\{" << endl;
    cout << "                     `.      |'-^Y^- |     //" << endl;
    cout << "                      (`\\     \\_.\"._/\\...-;..-." << endl;
    cout << "                      `._'._,'` ```    _.:---''`" << endl;
    cout << "                         ;-....----'''" << endl;
    cout << "                        /   (" << endl;
    cout << "                        |  (`" << endl;
    cout << "                        `.^'" << endl;
}

void Turtle::save() {
    ofstream file(name + ".txt");
    file << name << " " << hunger << " " << boredom << " " << happiness << " " << health << " " << shellHardness << endl;
    file.close();
}

void Turtle::load() {
    ifstream file(name + ".txt");
    if (file.is_open()) {
        file >> name >> hunger >> boredom >> happiness >> health >> shellHardness;
        file.close();
    }
}

void Turtle::hideInShell() {
    boredom -= 5;
    happiness += 5;
}

void Turtle::swim() {
    health += 10;
    happiness += 5;
}
void Turtle::play() {
    hideInShell();
    swim();
}