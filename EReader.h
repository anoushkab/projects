#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Book.h"
#include "Lqueue.h"

using namespace std;
#ifndef EREADER_H
#define EREADER_H

class EReader{
 public:
  EReader();
  EReader(string filename);
  ~EReader();
  void LoadCatalog(string filename);
  void MainMenu();
  void DisplayBooks();
  void AddBook();
  void DisplayReadlist();
  void SortReadlist();
private:
  vector<Book*> m_bookCatalog; //Holds all books in file                                     
  Lqueue<Book> m_readList; //Holds all books in read list                                    
};

#endif
