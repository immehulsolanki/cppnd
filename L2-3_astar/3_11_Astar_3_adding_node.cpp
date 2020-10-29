/*
Adding Nodes to the Open Vector
The search algorithm keeps a list of potential board cells to search through. 
In this implementation of A*, we will refer to a board cell along with 
it's g and h values as a node. In other words, each node will consist of 
the following values which are needed for the A* algorithm:

    an x coordinate,
    a y coordinate,
    the g value (or cost) that has accumulated up to that cell,
    the h value for the cell, given by the heuristic function.

In the code, nodes will be implemented with the type vector<int>, 
and should have the form {x, y, g, h} for ints x, y, g, and h. Also, 
the open list will be implemented as a C++ vector (of type vector<vector<int>>). 
The goal in this exercise is for you to write a helper function for your A* Search 
which will add nodes to the open vector and mark them as visited in the grid.

This Exercise:

        1.Write a void AddToOpen function which accepts the following arguments:
            Four ints, one for each of the x, y, g, and h values.
            References to one vector<vector<int>> for the vector of open nodes.
            Reference to one vector<vector<State>> for the grid.
        2.The AddToOpen function should do two things:
            Create a vector<int> node with the form {x, y, g, h} and push the node to 
            the back of the open vector.
            Set the grid value for the x and y coordinates to the enum value kClosed. 
            We have added kClosed to the set of enum values.


*/
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::abs;

enum class State {kEmpty, kObstacle, kClosed};

vector<State> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;
    while (sline >> n >> c && c == ',') {
      if (n == 0) {
        row.push_back(State::kEmpty);
      } else {
        row.push_back(State::kObstacle);
      }
    }
    return row;
}

vector<vector<State>> ReadBoardFile(string path) {
  ifstream myfile (path);
  vector<vector<State>> board{};
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      vector<State> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}


// Calculate the manhattan distance
int Heuristic(int x1, int y1, int x2, int y2) {
  return abs(x2 - x1) + abs(y2 - y1);
}

// TODO: Write the AddToOpen function here.
// before we add data to open list we need a vector first.
// to add data to openlist vector we also need a other 1dvector to apend main 2dvector.
// Get any vector<vector<int>> &openlist
// Get any vector<vector<State>> &grid
int AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openlist, vector<vector<State>> &grid){
  
  vector <int> node = { x, y, g, h}; // create a node vactor with four values
  openlist.push_back(node); // send that node to end of the open list.
  grid[x][y] = State::kClosed; // change that  origional grid value to closed.
  // because we used pass by reference this state will direct change value in main grid.

  return 0; // temp just to get rid of warning.
 }

/** 
 * Implementation of A* search algorithm
 */
vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]) {


  cout << "No path found!" << "\n";
  return std::vector<vector<State>> {};
}


string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "⛰️   ";
    default: return "0   "; 
  }
}


void PrintBoard(const vector<vector<State>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << CellString(board[i][j]);
    }
    cout << "\n";
  }
}

// ===== Test function not part of code =====
void PrintVectorOfVectors(vector<vector<int>> v) {
  for (auto row : v) {
    cout << "{ ";
    for (auto col : row) {
      cout << col << " ";
    }
    cout << "}" << "\n";
  }
}

void PrintVectorOfVectors(vector<vector<State>> v) {
  for (auto row : v) {
    cout << "{ ";
    for (auto col : row) {
      cout << CellString(col) << " ";
    }
    cout << "}" << "\n";
  }
}

void TestHeuristic() {
  cout << "----------------------------------------------------------" << "\n";
  cout << "Heuristic Function Test: ";
  if (Heuristic(1, 2, 3, 4) != 4) {
    cout << "failed" << "\n";
    cout << "\n" << "Heuristic(1, 2, 3, 4) = " << Heuristic(1, 2, 3, 4) << "\n";
    cout << "Correct result: 4" << "\n";
    cout << "\n";
  } else if (Heuristic(2, -1, 4, -7) != 8) {
    cout << "TestHeuristic Failed" << "\n";
    cout << "\n" << "Heuristic(2, -1, 4, -7) = " << Heuristic(2, -1, 4, -7) << "\n";
    cout << "Correct result: 8" << "\n";
    cout << "\n";
  } else {
    cout << "passed" << "\n";
  }
  return;
}

void TestAddToOpen() {
  cout << "----------------------------------------------------------" << "\n";
  cout << "AddToOpen Function Test: ";
  int x = 3;
  int y = 0;
  int g = 5;
  int h = 7;
  vector<vector<int>> open{{0, 0, 2, 9}, {1, 0, 2, 2}, {2, 0, 2, 4}};
  vector<vector<int>> solution_open = open; 
  solution_open.push_back(vector<int>{3, 0, 5, 7});
  vector<vector<State>> grid{{State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                            {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                            {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                            {State::kEmpty, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                            {State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty, State::kObstacle, State::kEmpty}};
  vector<vector<State>> solution_grid = grid;
  solution_grid[3][0] = State::kClosed;
  AddToOpen(x, y, g, h, open, grid);
  if (open != solution_open) {
    cout << "failed" << "\n";
    cout << "\n";
    cout << "Your open list is: " << "\n";
    PrintVectorOfVectors(open);
    cout << "Solution open list is: " << "\n";
    PrintVectorOfVectors(solution_open);
    cout << "\n";
  } else if (grid != solution_grid) {
    cout << "failed" << "\n";
    cout << "\n";
    cout << "Your grid is: " << "\n";
    PrintVectorOfVectors(grid);
    cout << "\n";
    cout << "Solution grid is: " << "\n";
    PrintVectorOfVectors(solution_grid);
    cout << "\n";
  } else {
    cout << "passed" << "\n";
  }
  cout << "----------------------------------------------------------" << "\n";
  return;
}
// ===== Test fucntion =====

int main() {
  int init[2]{0, 0};
  int goal[2]{4, 5};
  auto board = ReadBoardFile("input.txt");
  auto solution = Search(board, init, goal);
  PrintBoard(solution);
  // Tests
  TestHeuristic();
  TestAddToOpen();
}