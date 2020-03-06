include "Warhorse.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

// Default Constructor                                                                       
// Preconditions: None                                                                       
// Postconditions: None                                                                      
Warhorse::Warhorse():Horse(){}

// Overloaded Constructor                                                                    
// Preconditions: Valid inputs                                                               
// Postconditions: None                                                                      
Warhorse::Warhorse(string name, Size size, int health, int speed):Horse(name, size, health, \
speed){}

// train() - Gives a 50% of increasing training up to maximum.                               
// Preconditions: all variables are set valid                                                
// Postconditions: returns true if successfully trained                                      
bool Warhorse::train(){
  int randomNum = rand() % 100 + 1;
  if(randomNum < 50){
    increaseTraining();
    return true;
  }else
    return false;
}

// battle(Horse*) - passed enemy horse                                                       
// turns are based on speed - counter starts at 0 and if counter % speed == 0 then           
// that horse attacks counter%getSpeed()==0, attacks. If attack leaves at or below 0         
// then that horse loses battle.                                                             
// Preconditions: enemy horse has been defined                                               
// Postconditions: returns a bool of who won battle between two horses                       
bool Warhorse::battle(Horse* enemy){
  bool winner = false;
  int myDamage;
  int enemyDamage;
  int counter = 0;
  while(getHealth() > 0 and enemy->getHealth() > 0){
    //my horse attacks enemy horse, then adjusts health stats                                
    if(counter % getSpeed() == 0){
      if(enemy->getHealth() > 0){
        enemyDamage = attack(enemy->getName(), getHealth());
        //      cout << "enemy damage = " << enemyDamage << endl;                            
        enemy->setHealth(enemy->getHealth() - enemyDamage);
        //      cout << "enemy health = " << enemy->getHealth() << endl;                     
        if(enemy->getHealth() <= 0)
          winner = true;
      }
    }
    //enemy horse attacks my horse, then adjusts health stats                                
    if(counter % enemy->getSpeed() == 0){
      if(getHealth() > 0 and winner == false){
        myDamage = enemy->attack(getName(), enemy->getHealth());
        //      cout << "my damage = " << myDamage << endl;                                  
        setHealth(getHealth() - myDamage);
        //      cout << "my health = " << getHealth() << endl;                               
      }
    }
  }
  return winner;
}
