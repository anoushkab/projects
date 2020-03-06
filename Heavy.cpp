#include "Heavy.h"
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;

// Default Constructor                                                                       
// Preconditions: None                                                                       
// Postconditions: None                                                                      
Heavy::Heavy():Warhorse(){}

  // Overloaded Constructor                                                                  
  // Preconditions: Valid inputs                                                             
  // Postconditions: None                                                                    
Heavy::Heavy(string name, Size size, int health, int speed):Warhorse(name, size, health, spe\
ed){}

// attack(string, int) - Returns amount of damage from attack                                
  // Damage is calculated as health/6 + training level (0-5)                                 
  // Also, displays actual attack                                                            
  // Finally, the heavy warhorse calls kick from attack (special attack for heavy)          \
                                                                                             
  // Preconditions: passed string name of target and attacker's health                       
  // Postconditions: returns damage as integer                                               
int Heavy::attack(string name, int health){
  int damage = (health/6) + (getTraining());
  cout << "The " << toString() << " warhorse " << getName() << " attacks "
       << name << endl;
  damage += kick();
  return damage;
}

// toString() - a string representation of the child class                                   
// Preconditions: all variables are set valid                                                
// Postconditions: returns a string of the name of the subclass (return "Heavy")             
string Heavy::toString(){
  return "Heavy";
}
// kick() - a special attack by heavy warhorses                                              
// Preconditions: all variables are set valid                                                
// Postconditions: returns an int between 1 and 3 of additional damage                       
int Heavy::kick(){
  cout << "The " << toString() << " warhorse spins and kicks the enemy!"
       << endl;
  int random = rand() % 3 + 1;
  return random;
}
