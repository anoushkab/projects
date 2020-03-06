#include <iostream>
#include <string>
#include <iomanip>
#include "Book.h"
using namespace std;

//Name: Book - Default Constructor                                                           
//Precondition: None                                                                         
//Postcondition: Creates a default book                                                      
Book::Book(){}

//Name: Book - Overloaded Constructor                                                        
//Precondition: Requires title, author, rank and price (in dollars)                          
//Postcondition: Creates a book based on passed parameters                                   
Book::Book(string title, string author, int rank,  double price){
  setTitle(title);
  setAuthor(author);
  setRank(rank);
  setPrice(price);
}

//Name: Mutators and Accessors                                                               
//Precondition: None                                                                         
//Postcondition: Sets and Gets private member variables                                      
string Book::getTitle()const{
  return m_title;
} // return title                                                                            

string Book::getAuthor()const{
  return m_author;
} // return author                                                                           

int Book::getRank()const{
  return m_rank;
} // return rank (1-150)                                                                     

double Book::getPrice()const{
  return m_price;
} // return price                                                                            

void Book::setTitle(string title){
  m_title = title;
}
void Book::setAuthor(string author){
  m_author = author;
}

void Book::setRank(int rank){
  m_rank = rank;
}

void Book::setPrice(double price){
  m_price = price;
}

// Overloaded << - Prints the details of a book                                              
// Preconditions: all variables are set valid                                                
// Postconditions: returns an ostream with details of a book                                 
ostream& operator<<(ostream& output, Book& book){
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  output << "\t" << setw(35) <<  book.getTitle()
         << setw(27) << book.getAuthor()
         << setw(6) << "($" << book.getPrice() <<  ")";
  return output;
}

// Overloaded < - compares the price of the book                                             
// Preconditions: all variables are set valid                                                
// Postconditions: returns true if lhs price is less than rhs price                          
bool operator< (Book const & lhs, Book const & rhs){
  if(lhs.getPrice() < rhs.getPrice())
    return true;
  else
    return false;
}
