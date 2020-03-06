#include "Medium.h"
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
Medium::Medium():Warhorse(){}

// Overloaded Constructor                                                                    
// Preconditions: Valid inputs                                                               
// Postconditions: None                                                                      
Medium::Medium(string name, Size size, int health, int speed):Warhorse(name, size, health, s\
peed){}

// attack(string, int) - Returns amount of damage from attack                                
// Damage is calculated as health/6 + training level (0-5)                                   
// Also, displays actual attack                                                              
// Preconditions: passed string name of target and attacker's health                         
// Postconditions: returns damage as integer                                                 
int Medium::attack(string name, int health){
  int damage = health/6 + (getTraining());
  cout << "The " << toString() << " warhorse " << getName() << " attacks "
       << name << endl;
  return damage;
}
  // toString() - a string representation of the child class                                 
  // Preconditions: all variables are set valid                                              
  // Postconditions: returns a string of the name of the subclass (return "Medium")         \
                                                                                             
string Medium::toString(){
  return "Medium";
}
