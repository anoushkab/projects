#include "Horse.h"
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;

// Default Constructor                                                                       
// Preconditions: None                                                                       
// Postconditions: A horse is created                                                        
Horse::Horse(){

  string name;
  cout << "What would you like to name the horse?" << endl;
  cin >> name;
  m_name = name;

  int randomHealth = rand() % 20 + 0;
  int randomSpeed = rand() % 1 + 0;
  int randomSize = rand() % 9 + 0;

  //for light horse                                                                          
  if(randomSize < 3){
    m_size = SMALL;
    m_health = randomHealth + 60;
    m_speed = randomSpeed + 2;
  }//for medium horse                                                                        
    else if(randomSize < 6){
    m_size = MEDIUM;
    m_health = randomHealth + 70;
    m_speed = randomSpeed + 3;
  }//for heavy horse                                                                         
  else{
    m_size = LARGE;
    m_health = randomHealth + 80;
    m_speed = randomSpeed + 4;
    }
  m_training = Training(0);
}

// Overloaded Constructor                                                                    
// Preconditions: Valid inputs (name, align, size, health, speed)                            
//                Training always 0                                                          
// Postconditions: None                                                                      
Horse::Horse(string name, Size size, int health, int speed){
  m_name = name;
  m_size = size;
  m_health = health;
  m_speed = speed;
  m_training = Training(0);
}

// Destructor - virtual (implement in child classes)                                         
// Preconditions: Horse object in memory                                                     
// Postconditions: Deallocates horse object in memory                                        
Horse::~Horse(){
}

// getName() - returns the name of horse                                                     
// Preconditions: m_name is set                                                              
// Postconditions: returns a string name of the horse                                        
string Horse::getName(){
  return m_name;
}
// getSize() - returns the size of horse                                                     
// Preconditions: m_size is set                                                              
// Postconditions: returns an enum Size referring to the size of the horse                   
Size Horse::getSize(){
  return m_size;
}

// getHealth() - returns the health of horse                                                 
// Preconditions: m_health is set                                                            
// Postconditions: returns an int referring to health from (1 - MAX_HEALTH)                  
int Horse::getHealth(){
  return m_health;
}

// getSpeed() - returns the speed of the horse                                               
// Preconditions: m_speed is set                                                             
// Postconditions: returns an int referring to speed from (1 - MAX_SPEED)                    
int Horse::getSpeed(){
  return m_speed;
}

// getTraining() - returns the training level of horse                                       
// Preconditions: m_training is set                                                          
// Postconditions: returns an enum Training referring to training level of the horse         
Training Horse::getTraining(){
  return m_training;
}

// setHealth() - updates the health of the horse                                             
// Preconditions: m_health is set                                                            
// Postconditions: updates m_health                                                          
void Horse::setHealth(int hp){
  m_health = hp;
}

// increaseTraining() - increase training by one, up to max                                  
// Preconditions: all variables are set valid                                                
// Postconditions: returns an bool (true if increased, false if at max)                      
bool Horse::increaseTraining(){
  if(m_training == MAX_TRAINING){
    return false;
  }else{
    m_training = Training(m_training + 1);
    return true;
  }
}

// battle() - Sends a horse to battle another horse                                          
// Preconditions: all variables are set valid                                                
// Postconditions: returns an bool of whether horse won the battle or not                    
bool Horse::battle(Horse* horsey){
  return true;
}

// specialize() - Attempts to converts an Untrained horse to                                 
//                a war horse (light, medium, or heavy)                                      
//                Only Untrained type of horses can be specialized                           
// Preconditions: all variables are set valid                                                
// Postconditions: returns a pointer to a new warhorse or NULL                               
Horse* Horse::specialize(){
  Horse* horsey = NULL;
  return horsey;
}

// Overloaded << - Prints the details of a horse                                             
// Preconditions: all variables are set valid                                                
// Postconditions: returns an ostream with output of horse                                   
ostream& operator<<(ostream &output, Horse &myHorse){
  string size;
  if(myHorse.toString().compare("Untrained") == 0)
    size = "Unknown";
  else if(myHorse.getSize() == 0)
    size = "Light";
  else if(myHorse.getSize() == 1)
    size = "Medium";
  else
    size = "Heavy";


  output << "\t" << setw(18) << myHorse.getName()
         << "\t" << size
         << "\t\t" << myHorse.getHealth()
         << "\t" << myHorse.getSpeed()
         << "\t" << myHorse.trainingString(myHorse.getTraining());
  return output;
}

// randomPercentBased (Helper function)                                                      
// Precondition: Given int to "pass"                                                         
// Description: This function is used to see if a certain random event occurs                
//              A random number 1-100 is compared to the int passed                          
//              If the random number is less than the passed value, return true              
//              Else return false (30 = 30%, 70 = 70%)                                       
// Postcondition: Returns boolean                                                            
bool Horse::randomPercentBased(int myNum){
  int random = rand() % 100 + 1;
  if(random < myNum)
    return true;
  else
    return false;
}
// trainingString() - a string representation of a training level enum                       
// UNTRAINED = 0, SADDLE = 1, GREEN = 2, INTERMEDIATE = 3, EXPERT = 4, MASTER = 5            
// Preconditions: Pass a training level to the function                                      
// Postconditions: Returns the string of the enum                                            
string Horse::trainingString(Training level){
    string statement;
    if(level == 0)
      statement =       "Untrained";
    else if(level == 1)
      statement =       "Saddle";
    else if(level == 2)
      statement =       "Green";
    else if(level == 3)
      statement =       "Intermediate";
    else if(level == 4)
      statement =       "Expert";
    else if(level == 5)
      statement =       "Master";
    else
      cout << "Level does not exist" << endl;
    return statement;
  }

