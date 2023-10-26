#ifndef PET_H
#define PET_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Pet {
protected:
    string name;
    int hunger;
    int boredom;
    int happiness;
    int health;
public:
    Pet(string name = "Pet", int hunger = 50, int boredom = 50, int happiness = 50, int health = 100);
    virtual ~Pet();
    string getName();
    int getHunger();
    int getBoredom();
    int getHappiness();
    int getHealth();
    void setName(string name);
    void setHunger(int hunger);
    void setBoredom(int boredom);
    void setHappiness(int happiness);
    void setHealth(int health);
    void play();
    void feed();
    void sleep();
    void nextHour();
    virtual void draw();
    virtual void save();
    virtual void load();
};

#endif // PET_H