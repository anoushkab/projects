#ifndef HORSE_H
#define HORSE_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//enumerated type for size                                                                   
enum Size { SMALL, MEDIUM, LARGE};

//enumerated type for horse training level                                                   
enum Training {UNTRAINED, SADDLE, GREEN, INTERMEDIATE, EXPERT, MASTER};

//Constants                                                                                  
const int MAX_TRAINING = 5;
const int MAX_SIZE = 2;

class Horse {
public:                                                   
  Horse();                                                                 
  Horse(string name, Size, int health, int speed);                                
  virtual ~Horse();                        
  string getName();              
  Size getSize();           
  int getHealth();       
  int getSpeed();
  Training getTraining();                                                   
  void setHealth(int);             
  bool increaseTraining();                       
  virtual Horse* specialize();              
  virtual int attack(string, int)=0;                        
  virtual bool train() = 0;               
  virtual bool battle(Horse* horsey);                               
  friend ostream& operator<<(ostream&, Horse&);                                                         
  static bool randomPercentBased(int);                               
  virtual string toString() = 0;
protected:                                       
  string trainingString(Training );

private:
  string m_name;        //Horse's name                                                       
  Size m_size;          //SMALL, MEDIUM, LARGE, HUGE                                         
  int m_health;         //MIN_HEALTH to MAX_HEALTH - Higher is better and 0 is dead          
  int m_speed;          //MIN_SPEED to MAX_SPEED - Lower is better (1 would be best)         
  Training m_training;  //UNTRAINED, SADDLE, GREEN, INTERMEDIATE, EXPERT, MASTER             
};

#endif /* HORSE_H */
