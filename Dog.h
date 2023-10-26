#ifndef DOG_H
#define DOG_H

#include "pet.h"

class Dog : public Pet {
public:
  Dog(string name = "Dog", int hunger = 50, int boredom = 50,
      int happiness = 50, int health = 100, int loyalty = 50);
  virtual ~Dog();
  virtual void draw();
  virtual void save();
  virtual void load();
  void bark();
  void wagTail();
  void play();

private:
  int loyalty;
};

#endif // DOG_H
