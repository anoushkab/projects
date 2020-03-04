#include "Element.h"
#include "Alchemist.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

// Name: Alchemist() - Default Constructor                                      
// Desc: Used to build a new Alchemist                                          
// Preconditions - Requires default values                                      
// Postconditions - Creates a new Alchemist                                     
Alchemist::Alchemist(){}

// Name: Alchemist(name) - Overloaded constructor                               
// Desc - Used to build a new Alchemist                                         
// Preconditions - Requires name                                                
// Postconditions - Creates a new Alchemist                                     
Alchemist::Alchemist(string name){}

// Name: GetName()                                                              
// Desc - Getter for Alchemist name                                             
// Preconditions - Alchemist exists                                             
// Postconditions - Returns the name of the Alchemist                           
string Alchemist::GetName(){
  return m_myName;
}

// Name: SetName(string)                                                        
// Desc - Allows the user to change the name of the Alchemist                   
// Preconditions - Alchemist exists                                             
// Postconditions - Sets name of Alchemist                                      
void Alchemist::SetName(string name){
  m_myName = name;
}

// Name: DisplayElements()                                                      
// Desc - Displays a numbered list of all elements known by the Alchemist       
// Preconditions - Alchemist exist                                              
// Postconditions - None                                    
void Alchemist::DisplayElements(){
  for (int i = 0; i < m_numElements; i++){
    cout << i+1 << ". ";
    cout << m_myElements[i].m_name << endl;
  }
}

// Name: GetNumElements()                                                       
// Desc - Returns number of elements known by the Alchemist                     
// Preconditions - Alchemist exists                                             
// Postconditions - None                                                        
int Alchemist::GetNumElements(){
  return m_numElements;
}

// Name: CheckElement(Element)                                                  
// Desc - Checks to see if the Alchemist has an element                         
// Preconditions - Alchemist already has elements                               
// Postconditions - Returns true if Alchemist has element else false            
bool Alchemist::CheckElement(Element check){
  bool value = false;
  for(int i = 0; i < GetNumElements(); i++){
    if((check.m_name).compare(m_myElements[i].m_name) == 0){
      value = true;
      cout << "TRUE" << endl;
    }
  }
  return value;
}

// Name: AddElement(Element)                                                    
// Desc - Adds element to m_myElements if not known increases numElements       
// Preconditions - Alchemist exists and new element not already known           
// Postconditions - Adds element to m_myElements                                
void Alchemist::AddElement(Element add){
  m_numElements += 1;
  m_myElements[m_numElements-1] = add;
}

// Name: GetElement(int)                                                        
// Desc - Checks to see if the alchemist has an element                         
// Preconditions - Alchemist already has elements                               
// Postconditions - Returns element at index                                    
Element Alchemist::GetElement(int num){
  return m_myElements[num];
}
// Name: AddAttempt                                                             
// Desc - Increments attempts                                                   
// Preconditions - Alchemist attempts a merge                                   
// Postconditions - Increments every time a merge is attempted                  
void Alchemist::AddAttempt(){
  m_attempts += 1;
}

// Name: GetAttempts()                                                          
// Desc - Returns number of attempts for that Alchemist                         
// Preconditions - Alchemist exists                                             
// Postconditions - Returns total number of attempts                            
int Alchemist::GetAttempts(){
  return m_attempts;
}

// Name: AddRepeat()                                                            
// Desc - Increments repeats for every time an element has already been found   
// Preconditions - Alchemist attempts a merge                                   
// Postconditions - Increments every time a merge yields an element already fou\
nd                                                                              
void Alchemist::AddRepeat(){
  m_repeats += 1;
}

// Name: GetRepeats()                                                           
// Desc - Returns number of repeats for that Alchemist                          
// Preconditions - Alchemist exists                                             
// Postconditions - Returns total number of repeats                             
int Alchemist::GetRepeats(){
  return m_repeats;
}

