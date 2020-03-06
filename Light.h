#ifndef LIGHT_H
#define LIGHT_H

#include "Warhorse.h"

class Light: public Warhorse {
public:
                                                                 
  Light();                        
  Light(string, Size, int, int);      
  int attack(string, int);       
  string toString();
};

#endif /* LIGHT_H */
