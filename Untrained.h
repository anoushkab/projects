#ifndef UNTRAINED_H
#define UNTRAINED_H

#include "Horse.h"
#include "Heavy.h"
#include "Medium.h"
#include "Light.h"

class Untrained: public Horse {
public:
                                                             
  Untrained();
                                                                 
  Untrained(string, Size, int, int);

                         
  Horse* specialize();

                                 
  bool train();
                             
  string toString();
                        
  int attack(string, int );
};

#endif /* UNTRAINED_H */
