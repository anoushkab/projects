#ifndef ALCHEMIST_H //Include/Header Guard                                      
#define ALCHEMIST_H //Include/Header Guard                                      

#include "Element.h" //Include for the element struct                           
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

//Constants (allowed to add more as needed)                                     
const int PROJ2_SIZE = 390;

// class - allowed to add HELPER functions only                                 
class Alchemist{
 public:
  Alchemist();
  Alchemist(string name);
  string GetName();
  void SetName(string name);
  void DisplayElements();
  int GetNumElements();
  bool CheckElement(Element check);
  void AddElement(Element);
  Element GetElement(int);
  void AddAttempt();
  int GetAttempts();
  void AddRepeat();
  int GetRepeats();
private:
  string m_myName; //Name of Alchemist                                          
  int m_attempts; //Total Combination Attempts                                  
  int m_repeats; //Combination Attempts Repeated                                
  int m_numElements; //Number of elements known to the Alchemist                
  Element m_myElements[PROJ2_SIZE] = {}; //List of elements known to the Alchem\
ist                                                                             
};

#endif //Exit Header Guard   
