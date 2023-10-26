#ifndef MONKEY_H
#define MONKEY_H

#include "pet.h"

class Monkey : public Pet {
public:
    Monkey(string name = "Monkey", int hunger = 50, int boredom = 50, int happiness = 50, int health = 100, int intelligence = 50);
    virtual ~Monkey();
    virtual void draw();
    virtual void save();
    virtual void load();
    void swing();
    void throwBanana();
    void play();
private:
    int intelligence;
};

#endif // MONKEY_H
