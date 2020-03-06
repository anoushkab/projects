#ifndef WAR_H
#define WAR_H

#include "Horse.h"
#include "Untrained.h"
#include "Warhorse.h"
#include "Light.h"
#include "Medium.h"
#include "Heavy.h"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>

//light = 60-80 and 8-10                                                                     
//medium = 70-90 and 6-8                                                                     
//heavy = 80-100 and 4-6                                                                     
const int LT_MIN_HEALTH = 60; //Light minimum health                                         
const int LT_MAX_HEALTH = 80; //Light maximum health                                         
const int LT_MIN_SPEED = 2; //Light minimum speed (lower is better)                          
const int LT_MAX_SPEED = 3; //Light maximum speed                                            
const int MD_MIN_HEALTH = 70; //Medium minimum health                                        
const int MD_MAX_HEALTH = 90; //Medium maximum health                                        
const int MD_MIN_SPEED = 3; //Medium minimum speed (lower is better)                         
const int MD_MAX_SPEED = 4; //Medium maximum speed                                           
const int HV_MIN_HEALTH = 80; //Heavy minimum health                                         
const int HV_MAX_HEALTH = 100; //Heavy maximum health                                        
const int HV_MIN_SPEED = 4; //Heavy minimum speed (lower is better)                          
const int HV_MAX_SPEED = 5; //Heavy maximum speed                                            

class War {
public:
  // Default Constructor                                                                     
  // Preconditions: None                                                                     
  // Postconditions: Seeds srand only                                                        
  War();

  // Destructor                                                                              
  // Preconditions: m_myStable and/or m_enemyStable is populated                             
  // Postconditions: Deallocates horse objects in all vectors                                
  virtual  ~War();
  
  // Name: loadHorses                                                                        
  // Desc - Loads each horse into m_enemyStable from file                                    
  // Preconditions - Requires file with valid horse data                                     
  // Postconditions - m_enemyStable is populated with enemy horse pointers                   
  void loadHorses(char*);

  // Name: MainMenu()                                                                        
  // Desc - Displays and manages menu                                                        
  // Preconditions - m_enemyStable has been populated from file                              
  // Postconditions - exits if user entered 6                                                
  void mainMenu();

  // Name: acquireHorse()                                                                    
  // Desc - user randomly acquires a new untrained horse (random size)                       
  // Preconditions - none                                                                    
  // Postconditions - new horse is added to m_myStable                                       
  void acquireHorse();

  // Name: trainHorse()                                                                      
  // Desc - user randomly acquires a horse                                                   
  // Preconditions - none                                                                    
  // Postconditions - new horse is added to m_stable                                         
  void trainHorse();

  // Name: startBattle()                                                                     
  // Desc - user selects a horse to battle with and fights first horse in enemy              
  // m_enemyStable. Horse that loses is removed from their respective stable forever         
  // User must have at least ONE specialized horse at least training level 2 or higher       
  // Preconditions - Use has at least one horse and horse is specialized trained             
  // Postconditions - m_myStable or m_enemyStable has loser removed                          
  void startBattle();

  // Name: displayMyHorses()                                                                 
  // Desc - Displays all horses in m_myStable or empty message if no horses                  
  // Preconditions - m_myStable is populated                                                 
  // Postconditions - None                                                                   
  void displayMyHorses();

  // Name: displayEnemyHorses()                                                              
  // Desc - Displays all horses in m_enemyStable or win message if empty                     
  // Preconditions - m_enemyStable is populated                                              
  // Postconditions - None                                                                   
  void displayEnemyHorses();

  // Name: chooseHorse                                                                       
  // Desc - Helper that either displays that m_myStable is empty or allows user to           
  //        choose a horse to use for training or battle. Returns index + 1                  
  // Preconditions - None                                                                    
  // Postconditions - None                                                                   
  int chooseHorse();
private:
  vector<Horse*> m_myStable; // all user horses in our simulation                            
  vector<Horse*> m_enemyStable; // all enemy horses in our simulation                        
};

#endif /* WAR_H */
