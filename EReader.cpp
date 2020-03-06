#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Book.h"
#include "EReader.h"
using namespace std;

//Name: EReader - Default Constructor                                                        
//Precondition: None                                                                         
//Postcondition: Creates a new EReader                                                       
EReader::EReader(){}

//Name: EReader - Overloaded Constructor                                                     
//Precondition: None                                                                         
//Postcondition: Creates a new EReader and passes the book filename                          
EReader::EReader(string filename){
  LoadCatalog(filename);
}

//Name: ~EReader - Destructor                                                                
//Precondition: None                                                                         
//Postcondition: Creates a new EReader                                                       
EReader::~EReader(){
  for(int i = 0; i < int(m_bookCatalog.size()); i++){
    delete m_bookCatalog[i];
    m_bookCatalog[i] = nullptr;
  }
}

//Name: LoadCatalog(string filename)                                                         
//Precondition: Requires filename                                                            
//Postcondition: Loads the file into the m_bookCatalog (as books)                            
void EReader::LoadCatalog(string filename){
  string title;
  string author;
  string rank;
  string price;

  ifstream F(filename);
  F.is_open();
  while(getline(F, title, ',')){
    getline(F, author, ',');
    getline(F, rank, ',');
    getline(F, price);

    Book *book = new Book(title, author, stoi(rank), stod(price));
    m_bookCatalog.push_back(book);
  }
  F.close();
}

//Name: MainMenu                                                                             
//Precondition: None                                                                         
//Postcondition: Manages the application and the menu                                        
void EReader::MainMenu(){
  int choice = 0;
  while(choice != 5){
    cout << "What would you like to do?" << endl;
    cout << "1. Display All Books" << endl;
    cout << "2. Add Book to Readlist" << endl;
    cout << "3. Display Readlist" << endl;
    cout << "4. Sort Readlist by Price" << endl;
    cout << "5. Exit" << endl;
    cin >> choice;

    while (choice < 1 or choice > 5){
      cout << "What would you like to do?" << endl;
      cout << "1. Display All Books" << endl;
      cout << "2. Add Book to Readlist" << endl;
      cout << "3. Display Readlist" << endl;
      cout << "4. Sort Readlist by Price" << endl;
      cout << "5. Exit" << endl;
      cin >> choice;
    }
    switch(choice){
    case 1:
      DisplayBooks();
      break;
    case 2:
      AddBook();
      break;
    case 3:
      DisplayReadlist();
      break;
    case 4:
      SortReadlist();
    break;
    case 5:
      cout << "Thanks for using the EReader!" << endl;
    }
  }
}
//Name: DisplayBooks                                                                         
//Precondition: Displays all 150 books                                                       
//Postcondition: Lists all books (numbered)                                                  
void EReader::DisplayBooks(){
  for(int i = 0; i < int(m_bookCatalog.size()); i++){
    cout << i+1 << "."<< *m_bookCatalog[i] << endl;
  }
}

//Name: AddBook                                                                              
//Precondition: m_bookCatalog is populated                                                   
//Postcondition: Displays the current list and adds a book                                   
//               to the m_readList                                                           
void EReader::AddBook(){
  cout << "Choose the book you would like to add to your reading list." << endl;
  DisplayBooks();
  int num;
  cout << "Enter the number of the book you would like to add." << endl;
  cin >> num;
  while(num < 1 or num >int(m_bookCatalog.size())){
    cout << "Enter the number of the book you would like to add." << endl;
    cin >> num;
  }
  num--;
  m_readList.Push(*m_bookCatalog[num], true);
}
//Name: DisplayReadlist                                                                      
//Precondition: None (can be empty)                                                          
//Postcondition: Displays the readlist                                                       
void EReader::DisplayReadlist(){
  if(int(m_readList.GetSize()) == 0)
    cout << "Your reading list is empty." << endl;
  else{
    for(int i = 0; i < int(m_readList.GetSize()); i++){
      cout << i+1 << "." << m_readList[i] << endl;
    }
  }
}

//Name: SortReadlist()                                                                       
//Precondition: Requires Readlist                                                            
//Postcondition: Uses the overloaded < operator in Book to sort                              
//               the prices from high to low in the m_readList                               
void EReader::SortReadlist(){
  if(m_readList.GetSize() == 0)
    cout << "Your reading list is empty." << endl;
  else{
    bool inOrder = false;
    do{
      //running through the list and swapping                                                
      for(int i = 0; i < m_readList.GetSize() - 1; i++){
        if(m_readList[i] < m_readList[i+1]){
          m_readList.Swap(i+1);
        }
      }
      //increments counter if need more sorts                                                
      int numToSort = 0;
      for(int j = 0; j < m_readList.GetSize() - 1; j++){
        if(m_readList[j] < m_readList[j+1])
          numToSort++;
      }

      //if it's in order, updates the bool                                                   
      if(numToSort == 0)
        inOrder = true;

    } while(inOrder == false);
  }
}
