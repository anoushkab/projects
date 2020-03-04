#ifndef GAME_H //Header Guard                                                   
#define GAME_H //Header Guard                                                   
#include <fstream>
#include "Element.h"
#include "Alchemist.h"

//Constants (additional constants allowed)                                      
const string PROJ2_DATA = "proj2_data.txt"; //File constant                     

//Additional HELPER functions allowed to be added as needed                     

class Game{
public:
  Game(); //Default Constructor                                                 
  void LoadElements();
  void StartGame();
  void DisplayMyElements();
  int MainMenu();
  void CombineElements();
  string RequestElement(int &choice);
  int SearchRecipes(string, string);
  void CalcScore();
  void GameTitle(){
    cout << "**************************************************************" <<\
 endl;
    cout << "    AAA   L     CCCCC  H   H  EEEEE  M   M  I  SSSSS  TTTTT   " <<\
 endl;
    cout << "   A   A  L     C      H   H  E      MM MM  I  S        T     " <<\
 endl;
    cout << "   AAAAA  L     C      HHHHH  EEEEE  M M M  I  SSSSS    T     " <<\
 endl;
    cout << "   A   A  L     C      H   H  E      M   M  I      S    T     " <<\
 endl;
    cout << "   A   A  LLLLL CCCCC  H   H  EEEEE  M   M  I  SSSSS    T     " <<\
 endl;
    cout << "**************************************************************" <<\
 endl;
  }
private:
  Alchemist m_myAlchemist; //Player's Alchemist for the game                    
  Element m_elements[PROJ2_SIZE]; //All elements in the game (loaded from file)
};

#endif //Exit Header Guard  
