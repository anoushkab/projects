#ifndef HEAVY_H
#define HEAVY_H

#include "Warhorse.h"

class Heavy: public Warhorse {
public:
  Heavy();
  Heavy(string, Size, int, int);
  int attack(string, int);
  string toString();
  int kick();
};

#endif /* HEAVY_H */
