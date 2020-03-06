#include "Untrained.h"

using namespace std;

// Default Constructor                                                                       
// Preconditions: None                                                                       
// Postconditions: None                                                                      
Untrained::Untrained():Horse(){}

// Overloaded Constructor                                                                    
// Preconditions: Valid inputs                                                               
// Postconditions: None                                                                      
Untrained::Untrained(string name, Size size, int health, int speed):Horse(name, size, health\
, speed){}

// breed() - if an horse successfully produces specializes it is replaced                    
//           by a corresponding warhorse                                                     
// Preconditions: all variables are set valid                                                
// Postconditions: returns an pointer to a new warhorse or NULL                              
Horse* Untrained::specialize(){
  Horse * newHorse;
  if(getSpeed() == 2)
    newHorse = new Light(getName(), SMALL, getHealth(), getSpeed());
  else if(getSpeed() == 3 or getSpeed() == 4){
    if(getHealth() <= 80)
      newHorse = new Medium(getName(), MEDIUM, getHealth(), getSpeed());
    else
      newHorse = new Heavy(getName(), LARGE, getHealth(), getSpeed());
  }else
    newHorse = new Heavy(getName(), LARGE, getHealth(), getSpeed());


  return newHorse;
}

// train() : attempts to train an untrained horse                                            
// Preconditions: all variables are set valid                                                
// Postconditions: says that horses cannot be trained                                        
bool Untrained::train(){
  cout << "Cannot train an untrained horse." << endl;
  return false;
}
// toString() - a string representation of the untrained horse                               
// Preconditions: all variables are set valid                                                
// Postconditions: returns an string describing the horse                                    
string Untrained::toString(){
  return "Untrained";
}

// attack(string, int) - only light, medium, and heavy can attack                            
// Preconditions: target passed and health of attacker                                       
// Postconditions: displays that untrained horses can't attack                               
int Untrained::attack(string name, int health){
  cout << "Untrained horses cannot attack" << endl;
  return 0;
}
