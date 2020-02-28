#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

//constants                                                                     
const int ARRAY_SIZE = 75;

//function prototypes                                                           
int mainMenu();
void inputArt(char artArray[][ARRAY_SIZE], int size);
void createArt(char artArray[][ARRAY_SIZE], int size);
void displayArt(char artArray[][ARRAY_SIZE], int size);
void rotateArt(char artArray[][ARRAY_SIZE], int size);
void invertArt(char artArray[][ARRAY_SIZE], int size);

//main function                                                                 
int main(){

  char artArray[ARRAY_SIZE][ARRAY_SIZE];
  for(int i = 0; i < ARRAY_SIZE; i++){
    for(int j = 0; j< ARRAY_SIZE; j++){
      artArray[i][j] = ' ';
    }
  }
  cout << "Welcome to the ASCII Art Tool" << endl;
  int choice;
  while(choice != 6){
    choice = mainMenu();
    //switch statement                                                          
    switch(choice)
      {
      case 1:
        inputArt(artArray, ARRAY_SIZE);
        cout << "" << endl;
        break;
      case 2:
        createArt(artArray, ARRAY_SIZE);
        cout << "" << endl;
        break;
      case 3:
        displayArt(artArray, ARRAY_SIZE);
        break;
      case 4:
        rotateArt(artArray, ARRAY_SIZE);
        cout << "" << endl;
        break;
      case 5:
        invertArt(artArray, ARRAY_SIZE);
        cout << "" << endl;
        break;
      case 6:
        cout << "Thank you for using the ASCII Art Tool!" << endl;
        break;
      }
  }
  return 0;
}

//main menu function                                                            
int mainMenu(){
  int choice;
  cout << "What would you like to do?" << endl;
  cout << "1. Load ASCII Art from File" << endl;
  cout << "2. Create ASCII Art Manually" << endl;
  cout << "3. Display Art" << endl;
  cout << "4. Rotate Art" << endl;
  cout << "5. Invert Art" << endl;
  cout << "6. Exit" << endl;
  cin >> choice;

  //just error checking                                                         
  while(choice < 1 or choice > 6){
    cout << "Please choose again." << endl;
    cout << "1. Load ASCII Art from File" << endl;
    cout << "2. Create ASCII Art Manually" << endl;
    cout << "3. Display Art" << endl;
    cout << "4. Rotate Art" << endl;
    cout << "5. Invert Art" << endl;
    cout << "6. Exit" << endl;
    cin >> choice;
  }

  return choice;
}

//function for loading the file and uploading it to the table                   
void inputArt(char artArray[][ARRAY_SIZE], int size){

  for(int i = 0; i < ARRAY_SIZE; i++){
    for(int j = 0; j< ARRAY_SIZE; j++){
      artArray[i][j] = ' ';
    }
  }

  char fileName [80];
  int num1;
  int num2;
  char art;
  cout << "What is the name of the data file to import?" << endl;
  cin >> fileName;

  ifstream artFile(fileName);

  if(artFile.is_open()){
    while(artFile >> num1 >> num2 >> art){
      //gets info from the file and places it in the table                      
      artArray[num1][num2] = art;
    }
    cout << "File uploaded" << endl;
    artFile.close();
  }else
    cout <<"File could not be opened."<< endl;
}

//takes in user input and modifies the table                                    
void createArt(char artArray[][ARRAY_SIZE], int size){
  int x;
  int y;
  char art;
  cout << "This will modify the current art." << endl;
  cout << "Enter the x coordinate between 0 and 74:" << endl;
  cin >> x;
  while(x < 0 or x > 74){
    cout<<"Please try again. Enter the x coordinate between 0 and 74:" << endl;
    cin >> x;
  }
  cout << "Enter the y coordinate between 0 and 74:" << endl;
  cin >> y;
  while(y < 0 or y > 74){
    cout<<"Please try again. Enter the y coordinate between 0 and 74:" << endl;
    cin >> y;
  }
  cout << "Enter the character for that location:" << endl;
  cin >> art;

  artArray[x][y] = art;
}

//displays the table                                                            
void displayArt(char artArray[][ARRAY_SIZE], int size){
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      cout << artArray[i][j];
    }
    cout<<""<< endl;
  }

}

//rotates the art                                                               
void rotateArt(char artArray[][ARRAY_SIZE], int size){
  //initializing copy array                                                     
  char copyArray[ARRAY_SIZE][ARRAY_SIZE];
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      copyArray[j][size-1-i] = artArray[i][j];
    }
  }
  //putting copy array back into main array                                     
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      artArray[i][j] = copyArray[i][j];
    }
  }
}

//inverts the art                                                               
void invertArt(char artArray[][ARRAY_SIZE], int size){

  int choice;
  cout << "Would you like to invert it horizontally or vertically? " << endl;
  cout << "1. Vertical \n2. Horizontal" << endl;
  cin >> choice;

  while(choice < 1 or choice > 2){
    cout << "Please try again. " << endl;
    cout << "Would you like to invert it horizontally or verically? " << endl;
    cout << "1. Vertical \n2. Horizontal" << endl;
    cin >> choice;
  }
  //vertical                                                                    
  if(choice == 1){
    for(int i = 0; i < size/2; i++){
      for(int j = 0; j < size; j++){
        swap(artArray[i][j], artArray[size-1-i][j]);
      }
    }
  }
  //horizontal                                                                  
  else{
    for(int i = 0; i < size; i++){
      for(int j = 0; j < size/2; j++){
        swap(artArray[i][j], artArray[i][size-1-j]);
      }
    }
  }
}
