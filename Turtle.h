#ifndef TURTLE_H
#define TURTLE_H

#include "pet.h"

class Turtle : public Pet {
public:
    Turtle(string name = "Turtle", int hunger = 50, int boredom = 50, int happiness = 50, int health = 100, int shellHardness = 50);
    virtual ~Turtle();
    virtual void draw();
    virtual void save();
    virtual void load();
    void hideInShell();
    void swim();
    void play();
private:
    int shellHardness;
};

#endif // TURTLE_H
