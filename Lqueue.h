  #include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

template <class T>
class Node {
public:
  Node( const T& data ); //Node Constructor                                                  
  T& GetData(); //Node Data Getter                                                           
  void SetData( const T& data ); //Node Data Setter                                          
  Node<T>* GetNext(); //Node m_next getter                                                   
  void SetNext( Node<T>* next ); //Node m_next setter                                        
private:
  T m_data; //Holds templated data                                                           
  Node<T>* m_next; //Pointer to next node                                                    
};

template <class T>
Node<T>::Node( const T& data ) {
   m_data = data;
   m_next = nullptr;
}

template <class T>
T& Node<T>::GetData() {
   return m_data;
}

template <class T>
void Node<T>::SetData( const T& data ) {
   m_data = data;
}

template <class T>
Node<T>* Node<T>::GetNext() {
   return m_next;
}

template <class T>
void Node<T>::SetNext( Node<T>* next ) {
   m_next = next;
}
template <class T>
class Lqueue {
 public:
  // Name: Lqueue() (Linked List Queue) - Default Constructor                                
  // Desc: Used to build a new linked queue (as a linked list)                               
  // Preconditions: None                                                                     
  // Postconditions: Creates a new lqueue where m_head and m_tail point to nullptr           
  Lqueue();
  // Name: ~Lqueue() - Destructor                                                            
  // Desc: Used to destruct a Lqueue                                                         
  // Preconditions: There is an existing lqueue with at least one node                       
  // Postconditions: An lqueue is deallocated (including dynamically allocated nodes)        
  //                 to have no memory leaks!                                                
 ~Lqueue();
  // Name: Lqueue (Copy Constructor)                                                         
  // Preconditions: Creates a copy of existing LQueue                                        
  //                Requires a Lqueue                                                        
  // Postconditions: Copy of existing Lqueue                                                 
  Lqueue(const Lqueue&);
  // Name: operator= (Overloaded Assignment Operator)                                        
  // Preconditions: Copies an Lqueue into an existing Lqueue                                 
  //                Requires a Lqueue                                                        
  // Postconditions: Copy of existing Lqueue                  
   Lqueue<T>& operator= (const Lqueue&);
  // Name: Push                                                                              
  // Preconditions: Takes in data. Creates new node.                                         
  //                Requires a Lqueue                                                        
  // Postconditions: If the bool = true, adds to front else adds a new node to the           
  //                 end of the lqueue.                                                      
  void Push(const T&, bool);
  // Name: Pop                                                                               
  // Preconditions: Lqueue with at least one node.                                           
  // Postconditions: Removes first node in the lqueue, returns data from first node.         
  T Pop();
  // Name: Display                                                                           
  // Preconditions: Outputs the lqueue.                                                      
  // Postconditions: Displays the data in each node of lqueue                                
  void Display();
  // Name: Front                                                                             
  // Preconditions: Requires a populated lqueue                                              
  // Postconditions: Returns whatever data is in front                                       
  T Front();
  // Name: IsEmpty                                                                           
  // Preconditions: Requires a lqueue                                                        
  // Postconditions: Returns if the lqueue is empty.                                         
  bool IsEmpty();
 // Name: GetSize                                                                           
  // Preconditions: Requires a lqueue                                                        
  // Postconditions: Returns m_size                                                          
  int GetSize();
  // Name: Swap(int)                                                                         
  // Preconditions: Requires a lqueue                                                        
  // Postconditions: Swaps the nodes at the index with the node prior to it.                 
  void Swap(int);
  // Name: Clear                                                                             
  // Preconditions: Requires a lqueue                                                        
  // Postconditions: Removes all nodes in a lqueue                                           
  void Clear();
  // Name: TestHeadTail() (Optional test function)                                           
  // Preconditions: Requires a lqueue                                                        
  // Postconditions: Returns the value of the head and the tail (used for main below)        
  void TestHeadTail();
  // Name: operator<< (Overloaded << operator)                                               
  // Preconditions: Requires a lqueue                                                        
  // Postconditions: Returns an ostream with the data from each node on different line       
  template <class U>
  friend ostream& operator<<(ostream& output, const Lqueue<U>&);
    //Name: Overloaded [] operator                                                             
  //Precondition: Existing Lqueue                                                            
  //Postcondition: Returns object from Lqueue using []                                       
  T& operator[] (int x);//Overloaded [] operator to pull data from Lqueue                    
private:
  Node <T> *m_head; //Node pointer for the head                                              
  Node <T> *m_tail; //Node pointer for the tail                                              
  int m_size = 0; //Number of nodes in queue                                                 
};
//*****************************************************************                          
//Implement Lqueue here                                                                      

// Name: Lqueue() (Linked List Queue) - Default Constructor                                  
template <class T>
Lqueue<T>::Lqueue(){
  m_head = nullptr;
  m_tail = nullptr;
}
// Name: ~Lqueue() - Destructor                                                              
template <class T>
Lqueue<T>::~Lqueue(){
  Node<T> *curr = m_head;
  Node<T> *temp = curr;
  while(temp != NULL){
    curr = temp->GetNext();
    delete temp;
    temp = curr;
    m_size--;
  }
  delete curr;
}

// Name: Lqueue (Copy Constructor)                                                           
template <class T>
Lqueue<T>::Lqueue(const Lqueue& queue){
  m_head = nullptr;
  m_tail = nullptr;

  for(Node<T> *cur =    queue.m_head;cur!=NULL;cur=cur->GetNext()){
    Push(cur->GetData(),true);
  }
}

// Name: operator= (Overloaded Assignment Operator)                                          
template <class T>
Lqueue<T>&Lqueue<T>:: operator= (const Lqueue& queue){
  Clear();
  m_head = nullptr;
  m_tail = nullptr;

  for(Node<T> *cur = queue.m_head;cur!=NULL;cur=cur->GetNext()){
    Push(cur->GetData(),true);
  }
  return *this;
}
// Name: Push                                                                                
// Preconditions: Takes in data. Creates new node.                                           
//                Requires a Lqueue                                                          
// Postconditions: If the bool = true, adds to front else adds a new node @ the              
//                 end of the lqueue.                                                        
template <class T>
void Lqueue<T>::Push(const T& data1, bool booly){
  //inserting at the end                                                                     
  if(booly == true){
    //    cout << "in the end" << endl;                                                      
    Node<T> *temp = new Node<T>(data1);
    temp->SetNext(nullptr);
    if (m_head == nullptr){
      m_head = temp;
      m_tail = temp;
      temp->SetNext(nullptr);
    }else{
      m_tail->SetNext(temp);
      m_tail = temp;
    }
  }
  //inserting at the beginning                                                               
  else{
    //    cout << "in the beginning" << endl;                                                
    Node<T> *temp = new Node<T>(data1);

    if(m_head == nullptr){
      m_head = temp;
      temp->SetNext(nullptr);
    }
    else{
      Node<T> *ptr;
      ptr = m_head;
      temp->SetNext(ptr);
      m_head = temp;
    }
  }
  m_size++;
}
// Name: Pop                                                                                 
template <class T>
T Lqueue<T>::Pop(){
  m_size--;
  Node<T> *front = m_head->GetNext();
  delete m_head;
  m_head = NULL;
  m_head = front;
  T popped = front->GetData();
  return popped;
}

// Name: Display                                                                             
template <class T>
void Lqueue<T>::Display(){
  if(IsEmpty() == true)
    cout << "" << endl;
  else{

    Node<T> *curr = m_head;
    for(int numNodes = 0; numNodes< m_size; numNodes++){
      cout << curr->GetData()<< " -> ";
      curr = curr->GetNext();
    }cout << "END" << endl;
  }
}

// Name: Front                                                                               
template <class T>
T Lqueue<T>::Front(){
  T front = m_head->GetData();
  return front;
}
  
// Name: IsEmpty                                                                             
template <class T>
bool Lqueue<T>::IsEmpty(){
  if(m_size == 0){
    cout << "The linked list is empty" << endl;
    return true;
  }else{
    return false;
  }
}

// Name: GetSize                                                                             
template <class T>
int Lqueue<T>::GetSize(){
  return m_size;
}

// Name: Swap(int)                                                                           
template <class T>
void Lqueue<T>::Swap(int swapper){

  if(IsEmpty() == true or GetSize() == 1)
    cout << "This is empty or has only 1 item. Nothing to swap" << endl;
  else if(swapper <= 0){
    cout << "no node before the 0th node. cannot swap";
  }
  else if(swapper == 1){
    Node<T> *prev = (m_head);
    Node<T> *curr = (prev->GetNext());
    prev->SetNext(curr->GetNext());

    curr->SetNext(prev);

    m_head = curr;
  }
  else if(swapper < GetSize()){
    Node<T> *prev2 = (m_head);
    Node<T> *prev1 = (prev2->GetNext());
    Node<T> *curr = (prev1->GetNext());

    int count = 2;

    while(swapper > count){
      prev2 = prev2->GetNext();
      prev1 = prev1->GetNext();
      curr = curr->GetNext();
      count++;
    }
    prev2->SetNext(curr);
    prev1->SetNext(curr->GetNext());
    curr->SetNext(prev1);

    if(swapper+1 == GetSize())
      m_tail = prev1;
  }
}

// Name: Clear                                                                               
template <class T>
void Lqueue<T>::Clear(){
  if (IsEmpty() == false){
    Node<T> *curr = m_head;
    while(m_head != NULL){
      curr = m_head->GetNext();
      curr = NULL;
      m_head = curr;
    }
  }
  m_size = 0;
}
// Name: TestHeadTail() (Optional test function)                                             
template <class T>
void Lqueue<T>::TestHeadTail(){
  cout << m_head->GetData() << " " << m_tail->GetData() << endl;
}

// Name: operator<< (Overloaded << operator)                                                 
template <class U>
ostream& operator<<(ostream& output, const Lqueue<U>& queue){
  if(queue.m_head){
    Node<U> *temp = queue.m_head;
    while(temp != NULL){
      output << temp->GetData() << " -> ";
      temp = temp->GetNext();
    }output << "END" << endl;
  }else
    output << "This is empty" << endl;
  return output;
}

//Name: Overloaded [] operator                                                               
template <class T>
T& Lqueue<T>::operator[] (int x){
  Node<T> *curr = m_head;
  T now1 = curr->GetData();
  for(int i = 0; i < GetSize(); i++){
    if(i == x)
      return curr->GetData();
    curr = curr->GetNext();
  }
  return curr->GetData();
}
