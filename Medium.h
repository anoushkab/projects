#ifndef MEDIUM_H
#define MEDIUM_H

#include "Warhorse.h"

class Medium: public Warhorse {
public:
                                                               
  Medium();                                                                  
  Medium(string, Size, int, int);                                             
  int attack(string, int);     
  string toString();
};

#endif /* MEDIUM_H */
