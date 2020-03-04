#include <fstream>
#include "Element.h"
#include "Alchemist.h"
#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

/* Name: Game() Default Constructor                                             
// Desc - Builds a new game by:                                                 
// 1. Loads all Alchemy recipes into m_elements (by making elements)            
// 2. Asks user for their alchemist's name (store in m_myAlchemist as m_myNam   
e)                                                                             
// 3. Adds fire, water, air, and earth to m_myElements (in m_myAlchemist)       
// Preconditions - None                                                         
// Postconditions - m_elements is populated                                     
*/
Game::Game(){ //Default Constructor                                             
  GameTitle();
  LoadElements();

  char name[80];
  cout << "What is the name of the Alchemist?" << endl;
  cin.getline(name, 80);
  string name1 = name;
  m_myAlchemist.SetName(name1);

  //adding initial elements to m_myAlchemist's array                           
  m_myAlchemist.AddElement(m_elements[1]); //air                                
  m_myAlchemist.AddElement(m_elements[103]); //earth                            
  m_myAlchemist.AddElement(m_elements[120]); //fire                             
  m_myAlchemist.AddElement(m_elements[368]); //water                            

}
// Name: LoadElements                                                           
// Desc - Loads each element into m_elements from file                          
// Preconditions - Requires file with valid element data                        
// Postconditions - m_element is populated with element structs                 
void Game::LoadElements(){
  ifstream fileName(PROJ2_DATA);
  string one;
  string two;
  string three;

  if(fileName.is_open()){
    int counter = 0;
    while(counter < PROJ2_SIZE){

      getline(fileName, one, ',');
      getline(fileName, two, ',');
      getline(fileName, three, '\n');

      Element el1(one, two, three);
      m_elements[counter] = el1;
      counter+=1;
    }
    fileName.close();
    cout << counter << " elements loaded." << endl;

  }else
    cout << "Unable to open the file." << endl;                                                                        
}

// Name: StartGame()                                                            
// Desc - Manages the game itself including win conditions continually          
//         calling the main menu                                                
// Preconditions - Player is placed in game                                     
// Postconditions - Continually checks to see if player has entered 5           
void Game::StartGame(){
  int choice;
  while(choice != 4){
    choice = MainMenu();
    switch(choice){
    case 1:
      DisplayMyElements();
      break;
    case 2:
      CombineElements();
      break;
    case 3:
      CalcScore();
      break;
    case 4:
      cout << "Thanks for playing the Alchemist!" << endl;
    }
  }
}
// Name: DisplayMyElements()                                                    
// Desc - Displays the current elements                                         
// Preconditions - Player has elements                                          
// Postconditions - Displays a numbered list of elements                        
void Game::DisplayMyElements(){
  if(m_myAlchemist.GetNumElements() == 0)
    cout << "no elements to display" << endl;
  else
    for(int i = 0; i < m_myAlchemist.GetNumElements(); i++){
      cout << i+1 << ". ";
      cout << m_myAlchemist.GetElement(i).m_name << endl;
    }
}

// Name: MainMenu()                                                             
// Desc - Displays and manages menu                                             
// Preconditions - Player has an Alchemist                                      
// Postconditions - Returns number including exit                               
int Game::MainMenu(){
  cout << "" << endl;
  int choice;
  cout << "What would you like to do?" << endl;
  cout << "1. Display the Alchemist's Elements" << endl;
  cout << "2. Attempt to merge Elements" << endl;
  cout << "3. See Score" << endl;
  cout << "4. Quit" << endl;
  cin >> choice;

  while(choice < 1 or choice > 4){
    cout << "What would you like to do?" << endl;
    cout << "1. Display the Alchemist's Elements" << endl;
    cout << "2. Attempt to merge Elements" << endl;
    cout << "3. See Score" << endl;
    cout << "4. Quit" << endl;
    cin >> choice;
  }
  return choice;
}


// Name: CombineElements()                                                      
// Desc - Attempts to combine known elements                                    
// Preconditions - Alchemist is populated with elements                         
// Postconditions - May add element to Alchemist's list of elements             
void Game::CombineElements(){
  //getting first element                                                       
  int one = -2;
  while(one < -1 or one == 0 or one > m_myAlchemist.GetNumElements()){
    cout << "Which elements would you like to merge?" << endl;
    cout << "To list known elements enter -1" << endl;
    cin >> one;
  }
  while(one <= -1 or one == 0 or one > m_myAlchemist.GetNumElements()){
    if(one == -1)
      DisplayMyElements();
    cout << "Which elements would you like to merge?" << endl;
    cout << "To list known elements enter -1" << endl;
    cin >> one;
  }


  //getting second element                                                      
  int two = -2;
  while(two < -1 or two == 0 or two > m_myAlchemist.GetNumElements()){
    cout << "Which elements would you like to merge?" << endl;
    cout << "To list known elements enter -1" << endl;
    cin >> two;
  }
  while(two <= -1 or two == 0 or two > m_myAlchemist.GetNumElements()){
    if(two == -1)
      DisplayMyElements();
    cout << "Which elements would you like to merge?" << endl;
    cout << "To list known elements enter -1" << endl;
    cin >> two;
  }

  //actually doing the thing                                                    
  one = one-1;
  two = two-1;
  string One = RequestElement(one);
  string Two = RequestElement(two);
  int num = SearchRecipes(One, Two);

  bool inMyElements = false;

  if(num == -1)
    cout << "Nothing happened when you tried to combine "
         << One << " and " << Two << endl;
  else{
    //checks to see if element is already in m_myElements                       
    for(int i = 0; i < m_myAlchemist.GetNumElements(); i++){
      if((m_elements[num].m_name).compare(RequestElement(i)) == 0){
        inMyElements = true;
      }
    }

    if(inMyElements == true){
      //if already in m_myElements                                              
      cout << "You already have this element." << endl;
      m_myAlchemist.AddRepeat();
    }else{
      //not in m_myElements                                                     
      m_myAlchemist.AddElement(m_elements[num]);
      int numLMNs = m_myAlchemist.GetNumElements() - 1;
      cout << One << " combined with " << Two << " to create ";
      cout << RequestElement(numLMNs) << "!" << endl;
      cout << "The Alchemist now knows " << RequestElement(numLMNs) << "." << e\
ndl;
    }
  }
  m_myAlchemist.AddAttempt();
}// Name: RequestElement()                                                       
// Desc - Requests element to use to merge                                      
// Preconditions - Alchemist has elements to try and merge                      
// Postconditions - Returns                                                     
string Game::RequestElement(int &choice){
  return m_myAlchemist.GetElement(choice).m_name;
}

// Name: SearchRecipes()                                                        
// Desc - Searches recipes for two strings                                      
// Preconditions - m_elements is populated                                      
// Postconditions - Returns int index of matching recipe                        
int Game::SearchRecipes(string one, string two){
  int num = 0;
  int choice = -1;

  while(num < PROJ2_SIZE){
    if((one.compare(m_elements[num].m_element1) == 0) and (two.compare(m_elemen\
ts[num].m_element2) == 0))
      choice = num;
    num+=1;
  }
  return choice;
}

// Name: CalcScore()                                                            
// Desc - Displays current score for Alchemist                                  
// Preconditions - Alchemist is populated with elements                         
// Postconditions - None                                                        
void Game::CalcScore(){
  double numLMNS = m_myAlchemist.GetNumElements();
  double sizee = PROJ2_SIZE;
  double comp = (numLMNS/sizee)*100;
  cout << "****The Alchemist****" << endl;
  cout << "The Great Alchemist " << m_myAlchemist.GetName() << endl;
  cout << "The Alchemist has tried to combine " << m_myAlchemist.GetAttempts()
       << " elements." << endl;
  cout << "The Alchemist has repeated attempts " << m_myAlchemist.GetRepeats()
       << " times." << endl;
  cout << "The Alchemist has found " << m_myAlchemist.GetNumElements()
       << " out of " << PROJ2_SIZE << " elements." << endl;
  if(comp < 10.0)
    cout.precision(3);
      else
    cout.precision(4);
  cout << "You have completed " << comp << "% of the elements." << endl;
}
