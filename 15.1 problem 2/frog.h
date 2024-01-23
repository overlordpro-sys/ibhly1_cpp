#ifndef FROG_H
#define FROG_H

#include "dice.h"

class frog {
 public:
   frog();
   int getPos() const { return myPos; };
   int getSteps() const { return mySteps; };
   void move();

 private:
   dice myDice;
   int myPos, mySteps;
};

frog::frog() : myDice(2), myPos(0), mySteps(0) {
   // initialized with initializer list
}

void frog::move() {
   if (myDice.roll() == 1)
      myPos--;
   else
      myPos++;
   mySteps++;
}
#endif
