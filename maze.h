#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

// Vector to store neighbors of a cell.  Each cell has at most four                          
// neighbors (up, down, left, and right).                                                    
typedef std::vector<int> neighbor_t;

// Flag for empty neighbor entry                                                             
const int VACANT = -1;

// A struct to hold a single cell (square) of the maze                                       
struct MazeCell {
  int cellNum;              // Index of the cell                                             
  neighbor_t neighbors;     // Neighbors of the cell                                         

  // Default Constructor.  Accepts a cell number and list of                                 
  // neighbors as a neighbor_t (integer vector).                                             
  MazeCell( int cn = VACANT, neighbor_t nb = neighbor_t() ) {
    cellNum = cn;
    neighbors = nb;

    // Ensure neighbor list has four elements; any new elements are                          
    // initialized to VACANT.                                                                
    neighbors.resize(4, VACANT);
  }

  // Non-Default Constructor. Must provide cell number and *at least*                        
  // one neighbor.                                                                           
  MazeCell( int cn, int n1, int n2 = VACANT, int n3 = VACANT, int n4 = VACANT ) {
    cellNum = cn;
    neighbors.push_back(n1);
    neighbors.push_back(n2);
    neighbors.push_back(n3);
    neighbors.push_back(n4);
  }

  // Copy Constructor                                                                        
  MazeCell( const MazeCell& cell) {
    cellNum = cell.cellNum;
    neighbors = cell.neighbors;
  }
  // Overloaded not-equal operator                                                           
  bool operator!=(const MazeCell& rhs) {
    return (cellNum != rhs.cellNum) ||
      (neighbors != rhs.neighbors);
  }
};

typedef struct MazeCell cell_t;

// Overloaded insertion operator for maze cells. Prints cell number                          
// and four neighbors.                                                                       
inline std::ostream& operator<<(std::ostream& outStream, const cell_t &cell) {
  auto nbs = cell.neighbors;
  outStream << "[" << cell.cellNum << "] "
            << nbs[0] << " "
            << nbs[1] << " "
            << nbs[2] << " "
            << nbs[3];
  return outStream;
}

// Source-Destination pairs for stack. First element is "from" cell                          
// index, second element is "to" index.                                                      
typedef std::pair<int,int> src_dest_t;
// Struct for data items on the stack                                                        
struct StackEntry {
  src_dest_t src_dest;   // source-dest pair                                                 
  StackEntry *next;      // pointer to next entry                                            

  // Default Constructor                                                                     
  StackEntry( int src = VACANT, int dest = VACANT ) {
    src_dest = std::pair<int,int>(src, dest);
    next = nullptr;
  }

  // Non-Default Constructor                                                                 
  StackEntry( src_dest_t sd ) {
    src_dest = sd;
    next = nullptr;
  }
};

typedef struct StackEntry entry_t;


class Maze {
public:
  // Default Maze constructor                                                                
  Maze(int numCells = 1);

  // Destructor                                                                              
  ~Maze();

  // Read an encoded maze from a data file.  This method will clear                          
  // any existing data in the maze and replace it with the maze read                         
  // from a file.  Does minimal error checking.                                              
  void readFile(std::string fileName);

  // Get the number of cells in the Maze object                                              
  int getNcell() const;

  // Reset the Maze object.  Old data is destroyed and a new, empty                          
  // Maze with 'numCells' cells is created.                                                  
  void reset(int numCells);

  // Insert a cell into the Maze object                                                      
  void insert(cell_t cell);

  // Retrieve a cell from the Maze object                                                    
  cell_t retrieve(int cellNum) const;

  // Solve the maze.  Returns the solution path.                                             
  std::vector<int> solve() const;
  // Dump the cell data for the Maze object.                                                 
  void dump() const;

  // SolveStack nested class.  A stack for use with the solve()                              
  // function.                                                                               

  class SolveStack {
  public:
    SolveStack();
    ~SolveStack();
    bool empty() const;
    void push(src_dest_t src_dest);
    src_dest_t pop();
    src_dest_t read() const;
  private:
    entry_t *_stack;
  };

 private:
  cell_t *_maze;
  int _ncell;                                                                                      

};
