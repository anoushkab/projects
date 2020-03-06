#ifndef WARHORSE_H
#define WARHORSE_H

#include "Horse.h"

class Warhorse: public Horse {
public:
  // Default Constructor                                                                     
  // Preconditions: None                                                                     
  // Postconditions: None                                                                    
  Warhorse();
  // Overloaded Constructor                                                                  
  // Preconditions: Valid inputs                                                             
  // Postconditions: None                                                                    
  Warhorse(string, Size, int, int);
  // train() - Tests if animal successfully ate.                                             
  // - if the hunt was a success or they are age 1 then true                                 
  // otherwise they have a 50% chance                                                        
  // Preconditions: all variables are set valid                                              
  // Postconditions: returns an bool of whether animal ate or did not                        
  //                 in the course of the year                                               
  bool train();

protected:
  // toString() - purely virtual                                                             
  // Preconditions: all variables are set valid                                              
  // Postconditions: used for subclasses to return string of their type                      
  virtual string toString() = 0;

  // battle(Horse*) - passed enemy horse                                                     
  // turns are based on speed - counter starts at 0 and if counter % speed == 0 then         
  // that horse attacks counter%getSpeed()==0, attacks. If attack leaves at or below 0       
  // then that horse loses battle.                                                           
  // Preconditions: enemy horse has been defined                                             
  // Postconditions: returns a bool of who won battle between two horses                     
  bool battle(Horse*);

  // attack(string, int) - purely virtual (implemented in all child classes)                 
  // Preconditions: passed string name of target and health of attacker                      
  // Postconditions: returns damage as an integer                                            
  virtual int attack(string, int) = 0;
};

#endif /* WARHORSE_H */
