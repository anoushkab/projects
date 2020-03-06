#include "War.h"
#include "Horse.h"
#include "Untrained.h"
#include "Warhorse.h"
#include "Light.h"
#include "Medium.h"
#include "Heavy.h"

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

// Default Constructor                                                                       
// Preconditions: None                                                                       
// Postconditions: Seeds srand only                                                          
War::War(){
  srand(time(NULL));
}

// Destructor                                                                                
// Preconditions: m_myStable and/or m_enemyStable is populated                               
// Postconditions: Deallocates horse objects in all vectors                                  
War::~War(){
  for(int i = 0; i < int(m_enemyStable.size()); i++){
    delete m_enemyStable[i];
    //    m_enemyStable[i] = nullptr;                                                        
  }
  for(int i = 0; i < int(m_myStable.size()); i++){
    delete m_myStable[i];
    //    m_myStable[i] = nullptr;                                                           
  }
}

// Name: loadHorses                                                                          
// Desc - Loads each horse into m_enemyStable from file                                      
// Preconditions - Requires file with valid horse data                                       
// Postconditions - m_enemyStable is populated with enemy horse pointers                     
void War::loadHorses(char* fileName){
  string name;
  int sizeInt;
  int health;
  int speed;
  Size size;
  Horse *newHorse;
  ifstream horseFile(fileName);
  horseFile.is_open();

  //getting data from file                                                                   
  while(getline(horseFile, name, '\t')){
    horseFile >> sizeInt >> health >> speed;
    if(horseFile.peek() == '\n')
      horseFile.ignore();

    if(sizeInt == 0)
      size = SMALL;
    else if(sizeInt == 1)
      size = MEDIUM;
    else
      size = LARGE;

    //adding to list and making horses                                                       
    switch(sizeInt){
    case 0:
      newHorse = new Light(name, size, health, speed);
      m_enemyStable.push_back(newHorse);
      break;
    case 1:
      newHorse = new Medium(name, size, health, speed);
      m_enemyStable.push_back(newHorse);
      break;
    case 2:
      newHorse = new Heavy(name, size, health, speed);
      m_enemyStable.push_back(newHorse);
      break;
      }

  }
  horseFile.close();
  cout << "Welcome to UMBC War\n" << endl;
}
// Name: MainMenu()                                                                          
// Desc - Displays and manages menu                                                          
// Preconditions - m_enemyStable has been populated from file                                
// Postconditions - exits if user entered 6                                                  
void War::mainMenu(){
  int choice = 0;
  while (choice!=6){
    cout << "What would you like to do?" << endl;
    cout << "1. Display Friendly Stable" << endl;
    cout << "2. Display Enemy Stable" << endl;
    cout << "3. Acquire Horse" << endl;
    cout << "4. Train Horse" << endl;
    cout << "5. Battle" << endl;
    cout << "6. Exit" << endl;

    cin >> choice;
    while(choice < 1 or choice > 6){
      cout << "What would you like to do?" << endl;
      cout << "1. Display Friendly Stable" << endl;
      cout << "2. Display Enemy Stable" << endl;
      cout << "3. Acquire Horse" << endl;
      cout << "4. Train Horse" << endl;
      cout << "5. Battle" << endl;
      cout << "6. Exit" << endl;
      cin >> choice;
    }
    switch(choice){
    case 1:
      displayMyHorses();
      break;
    case 2:
      displayEnemyHorses();
      break;
    case 3:
      acquireHorse();
      break;
    case 4:
      trainHorse();
      break;
    case 5:
      startBattle();
      break;
    case 6:
      cout << "Thanks for using this horse simulator" << endl;
    }
  }
}

// Name: acquireHorse()                                                                      
// Desc - user randomly acquires a new untrained horse (random size)                         
// Preconditions - none                                                                      
// Postconditions - new horse is added to m_myStable                                         
void War::acquireHorse(){
  Horse * newHorse = new Untrained;
  m_myStable.push_back(newHorse);
  cout << "You have acquired a new horse\n" << endl;
}

// Name: trainHorse()                                                                        
// Desc - user randomly acquires a horse                                                     
// Preconditions - none                                                                      
// Postconditions - new horse is added to m_stable                                           
void War::trainHorse(){

  int chosen = chooseHorse();
  if(chosen == -1)
    cout << "You must acquire horses before you can train\n" << endl;
  else{

    if(m_myStable[chosen]->toString().compare("Untrained") == 0){
      Horse* newHorse = m_myStable[chosen]->specialize();
      delete m_myStable[chosen];
      m_myStable[chosen] = NULL;
      m_myStable[chosen] = newHorse;
      cout << "Your horse is now a " << m_myStable[chosen]->toString()
           << " warhorse\n"<< endl;
    }
    else{
      bool trainer = false;
      if(m_myStable[chosen]->getTraining() == MASTER)
        cout << "Your horse has trained to the highest level!" << endl;
      else
        trainer = m_myStable[chosen]->train();

      if(trainer == true)
        cout << "Your horse's training level increased" << endl;
      else
        cout << "Your horse's training level didn't change" << endl;
    }
  }
}
// Name: startBattle()                                                                       
// Desc - user selects a horse to battle with and fights first horse in enemy                
// m_enemyStable. Horse that loses is removed from their respective stable forever           
// User must have at least ONE specialized horse at least training level 2 or higher         
// Preconditions - Use has at least one horse and horse is specialized trained               
// Postconditions - m_myStable or m_enemyStable has loser removed                            
void War::startBattle(){
  int choice = chooseHorse();
  if(choice == -1)
    cout << "You must acquire and train horses before you can battle" << endl;
  else if(m_myStable[choice]->getTraining() < SADDLE)
    cout << "This horse is not ready for battle yet" << endl;
  else{
    bool winner;
    winner = m_myStable[choice]->battle(m_enemyStable[0]);

    if(winner == true){
      cout << "Congrats you won!" << endl;
      //for(int i = 0; i < int(m_enemyStable.size()) - 1; i++){                              
      //m_enemyStable[i] = m_enemyStable[i+1];                                               
      //}                                                                                    

      //      m_enemyStable.pop_back();                                                      
      delete m_enemyStable[0];
      m_enemyStable.erase(m_enemyStable.begin());

    }else{
      cout << "Your horse perished in battle." << endl;
      //for(int i = 0; i < int(m_myStable.size()) - 1; i++){                                 
      //m_myStable[i] = m_myStable[i+1];                                                     
      //}                                                                                    
      // m_myStable.pop_back();                                                              
      delete m_myStable[choice];
      m_myStable.erase(m_myStable.begin()+choice);
    }
  }
  cout << "" << endl;
}
// Name: displayMyHorses()                                                                   
// Desc - Displays all horses in m_myStable or empty message if no horses                    
// Preconditions - m_myStable is populated                                                   
// Postconditions - None                                                                     
void War::displayMyHorses(){
  if(int(m_myStable.size()) == 0)
    cout << "Your stable is currently empty" << endl;
  else{
    cout << "My Horses" << endl;
    cout << "Num\t" << setw(18) << "Horse\t" << "Size\t\t" << "Health\t"
         << "Speed\t" << "Training"<< endl;
    for(int i = 0; i < int(m_myStable.size()); i++)
      cout << i+1 << *m_myStable[i] << endl;
    cout << "" << endl;
  }

}
// Name: displayEnemyHorses()                                                                
// Desc - Displays all horses in m_enemyStable or win message if empty                       
// Preconditions - m_enemyStable is populated                                                
// Postconditions - None                                                                     
void War::displayEnemyHorses(){
  if(int(m_enemyStable.size()) == 0)
    cout << "Enemy stable is empty."
         << "\nCongratulations! You've beaten all the enemy horses!" << endl;
  else{
    cout << "Enemy Horses" << endl;
    cout << "Num\t" << setw(18) << "Horse\t" << "Size\t\t" << "Health\t"
         << "Speed\t" << "Training"<< endl;
    for(int i = 0; i < int(m_enemyStable.size()); i++)
      cout << i+1 << *m_enemyStable[i] << endl;
    cout << "" << endl;
  }
}
// Name: chooseHorse                                                                         
// Desc  Helper that either displays that m_myStable is empty or allows user to              
//        choose a horse to use for training or battle. Returns index + 1                    
// Preconditions - None                                                                      
// Postconditions - None                                                                     
int War::chooseHorse(){
  if(int(m_myStable.size()) == 0){
    return -1;
  }
  else{
    int horse;
    cout << "Which horse would you like to work with?" << endl;
    cin >> horse;

    while(horse > int(m_myStable.size()) or horse < 0){
      cout << "Which horse would you like to work with?" << endl;
      cin >> horse;
    }

    return horse-1;
  }
}
