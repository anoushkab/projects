#ifndef ELEMENT_H //Include/Header Guard                                        
#define ELEMENT_H //Include/Header Guard                                        

#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

// Name: Element struct                                                         
// Desc - Used to store data about elements                                     
struct Element{
  string m_name; //Name of the element                                          
  string m_element1; //Required element 1 to create                             
  string m_element2; //Required element 2 to create                             
  Element(){} //Default constructor                                             
  Element(string name, string element1, string element2){
    m_name = name; //Name of this element                                       
    m_element1 = element1; //Name of first required element to create           
    m_element2 = element2; //Name of second required element to create          
  }
};

#endif
