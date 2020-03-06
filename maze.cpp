#include <stdexcept>
#include "maze.h"

Maze::Maze(int ncell) {
  if (ncell < 1) {
    throw std::invalid_argument("Maze::Maze(): ncell must be >= 1");
  }

  _ncell = ncell;
  _maze = new cell_t[_ncell];
}

Maze::~Maze() {
  // IMPLEMENT DESTRUCTOR                                                                    
  delete [] _maze;
  _maze = nullptr;
}

void Maze::readFile(std::string fileName) {
  int numCells;
  int cell, n1, n2, n3, n4;
  std::ifstream dataFile;

  dataFile.open(fileName);

  if (dataFile.is_open()) {
    dataFile >> numCells;
    this->reset(numCells);

    for (int i = 0; i < numCells; i++) {
      dataFile >> cell >> n1 >> n2 >> n3 >> n4;
      this->insert(cell_t(cell, n1, n2, n3, n4));
    }
  }
}

int Maze::getNcell() const {
  return _ncell;
}

void Maze::reset(int ncell) {
  if (ncell < 1) {
    throw std::invalid_argument("Maze::reset(): ncell must be >= 1");
  }

  if (_maze != nullptr) {
    delete [] _maze;
  }

  _ncell = ncell;
  _maze = new cell_t[_ncell];
}

void Maze::insert(cell_t cell) {
  if (_maze == nullptr) {
    throw std::domain_error("Maze::insert(): attempt to insert into uninitialized Maze objec\
t");
  }
  if (cell.cellNum < 0 || cell.cellNum >= _ncell) {
    throw std::invalid_argument("Maze:insert(): invalid cell number");
  }
  _maze[cell.cellNum] = cell;
}

cell_t Maze::retrieve(int nc) const {
  if (_maze == nullptr) {
    throw std::domain_error("Maze::retrieve(): attempt to retrieve from an uninitialized Maz\
e object");
  }
  if (nc < 0 || nc >= _ncell) {
    throw std::invalid_argument("Maze:retrieve(): invalid cell index");
  }

  return _maze[nc];
}
void Maze::dump() const {

  std::cout << "[*] Dumping the maze cells..." << std::endl;

  for (int i = 0; i < _ncell; i++) {
    int nc = _maze[i].cellNum;
    if (nc != i) {
      std::cerr << "Warning: maze cell at index " << i
                <<" has cellNum of " << nc << std::endl;
    }
    std::cout << "Cell " << i << " has neighbor cells: ";
    neighbor_t nbs = _maze[i].neighbors;
    int n0, n1, n2, n3;
    if ( nbs[0] >= 0 ) std::cout << nbs[0] << " ";
    if ( nbs[1] >= 0 ) std::cout << nbs[1] << " ";
    if ( nbs[2] >= 0 ) std::cout << nbs[2] << " ";
    if ( nbs[3] >= 0 ) std::cout << nbs[3] << " ";
    std::cout << std::endl;
  }
}

std::vector<int> Maze::solve() const {
  std::cout << "[*] Start of call to solve()..."  << std::endl;
  //initializing variables and vectors and stuff.                                            
  SolveStack stacker;
  std::pair<int, int> adder(-1, 0);
  std::vector<int> solver;

  solver.clear();
  stacker.push(adder);
  solver.push_back(0);

  std::vector<cell_t> mazeCopy;
  for(int i = 0; i < _ncell; i++){
    mazeCopy.push_back(_maze[i]);
  }
  int curr = 0;
  //the actual loop that does the thing                                                      
  //exits if stack is empty or if we get the solution                                        
  while(stacker.empty() != true and curr != _ncell -1 ){
    bool solved = false;
    bool nflag = false;

    for(int j = 0; j < 4; j++){
      int n = mazeCopy[curr].neighbors[j];
      //checks to make sure its something we can actually use                                
      if(n != -1 and n != stacker.read().first){
        adder.first = curr;
        adder.second = n;
        //      std::cout<< "push" << std::endl;                                             
        //updating                                                                           
        stacker.push(adder);
        solver.push_back(n);
        nflag = true;
        //      std::cout << n << std::endl;                                                 
        curr = n;
        break;
      }
    }//if there are no neighbors                                                             
    if(nflag == false){

      //      std::cout << "pop" << std::endl;                                               
      //pops (yeets) stuff out of here                                                       
       for(int i = 0; i < 4; i++){
        if (stacker.read().first == -1) {
          stacker.pop();
          curr = -1;
          break;
        }//if the dest = maze(first) at i, then we pop                                       
        if(stacker.read().second == mazeCopy[stacker.read().first].neighbors.at(i)){
          mazeCopy[stacker.read().first].neighbors[i] = -1;
          stacker.pop();
          solver.pop_back();
          curr = stacker.read().second;
          break;
        }
      }

    }
  }
  //end part!!                                                                               
  if(stacker.empty())
    std::cout << "[-] No Solution Found. :(" << std::endl;
  else
    std::cout << "[+] Solution Found! :)" << std::endl;

  return solver;
}
Maze::SolveStack::SolveStack() {
  _stack = nullptr;
}

Maze::SolveStack::~SolveStack() {

  while(_stack != 0)
    pop();
}

bool Maze::SolveStack::empty() const {
  if(_stack == nullptr)
    return true;
  else
    return false;
}

void Maze::SolveStack::push(src_dest_t src_dest) {
  // IMPLEMENT PUSH METHOD                                                                   
  entry_t *pusher = new entry_t(src_dest);
  pusher->next = _stack;
  _stack = pusher;
}
src_dest_t Maze::SolveStack::pop() {
// IMPLEMENT POP METHOD                                                                      

  if(empty() == true)
    throw std::domain_error("Maze::SolveStack::pop(): Cannot pop on an empty stack.");

  entry_t *temp = _stack;
  src_dest_t data = temp->src_dest;
  _stack = temp->next;
  delete temp;
  return data;

}

src_dest_t Maze::SolveStack::read() const {
  // IMPLEMENT READ METHOD                                                                   
  if(empty() == true)
    throw std::domain_error("Maze::SolveStack::read(): Cannot read an empty stack.");

  src_dest_t data = _stack->src_dest;
  return data;
}
