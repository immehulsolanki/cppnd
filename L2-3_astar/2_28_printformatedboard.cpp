/*
Store the Board Using the State Enum

0   ⛰️   0   0   0   0
0   ⛰️   0   0   0   0
0   ⛰️   0   0   0   0
0   ⛰️   0   0   0   0
0   0    0   0  ⛰️   0

Fantastic work! Now that you have a way to print the State enum values, 
you will be able to modify your program to use State values in the board exclusively. 
To do this, you will need to modify the return types and variable types in several places of the code. 
don't worry, as we have clearly marked these with a TODO in each part of the code.

After this exercise, you will have completed the first part of this lesson, 
and you will begin coding the main A* search algorithm!

This Exercise:

    Follow the TODO comments in the main file below, and update the program 
    to store a board of State variables. When you are done, the board should print as in the image above. 
    Note that you will need to call CellString on each object in the board 
    before printing: CellString(board[i][j]).

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

enum class State {kEmpty, kObstacle};

/* Idea:
We read file and store values as our enum state by checking and comparing condition.
Now after that once we store whole board as just enum state values
Print is as new type (enum class var. name) values.
Note: Vector function is just memory allocator, so it type independent, you can
also store your own type other than int or str. Here we use our type "State"
*/

// TODO: Change the return type to use auto or
// explicitly indicate vector<State>
vector<State> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    // TODO: Change the variable type for row
    // to be a vector<State>
    vector<State> row;
    while (sline >> n >> c && c == ',') {
      // TODO: Modify the line below to push_back
      // a State::kEmpty if n is 0, and push_back
      // a State::kObstacle otherwise.
      if ( n == 0 ){        
      	row.push_back(State::kEmpty);
      }else{
      	row.push_back(State::kObstacle);
      }
    }
    return row;
}

// TODO: Modify the return type here as well. Just
// as above, the board will contain State objects
// instead of ints.
vector<vector<State>> ReadBoardFile(string path) {
  ifstream myfile (path);
  // TODO: Modify the board declarationto store 
  // State objects instead of ints.
  vector<vector<State>> board{};
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      // TODO: Modify the row type to use State
      // objects instead of ints.
      vector<State> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}

// TODO: Modify the function signature below to accept
// cells with State type instead of int type.
string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "⛰️   ";
    default: return "0   "; 
  }
}

void PrintBoard(const vector<vector<State>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      // TODO: Modify the line below to call CellString
      // on each element of the board before streaming to cout.
      string newboard = CellString( State ( board[i][j] ) );
      cout << newboard; // for print purpuse only
    }
    cout << "\n";
  }
}

int main() {
  auto board = ReadBoardFile("input.txt");
  PrintBoard(board);
  
}