/*
Formatting the Printed Board

0   ⛰️   0   0   0   0
0   ⛰️   0   0   0   0
0   ⛰️   0   0   0   0
0   ⛰️   0   0   0   0
0   0    0   0  ⛰️   0

The board will eventually have more than two cell states as the program becomes more complicated, 
and it would be nice to add formatting to the printed output of 
the board to ensure readability as the number of board states increases.

To accommodate more board states and facilitate print formatting, 
we have provided the State enum with enumerator values kEmpty and kObstacle. 
In this exercise, you will write a CellString function 
which converts each State to an appropriate string. 
In the next exercise, we will update the program to use the enum values and CellString function.
This Exercise:
        Write a function CellString which accepts aState as input and returns the following string:
            "⛰️ " if the input equals a kObstacle
            "0 " otherwise.
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

vector<int> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<int> row;
    while (sline >> n >> c && c == ',') {
      row.push_back(n);
    }
    return row;
}

vector<vector<int>> ReadBoardFile(string path) {
  ifstream myfile (path);
  vector<vector<int>> board{};
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      vector<int> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}

// TODO: Create the CellString function here,
// using the following return strings:
// "⛰️   "
// "0   "
// takes input as State type from enum llist and outputs either delta or 0.
string CellString(State cell) { // declare out enum type var. (any data)
  switch(cell){
    case State::kObstacle: return "⛰️   "; // compare in enum class list as case. 
    default: return "0   ";  // only two condition so no new case statements.
  }
}


void PrintBoard(const vector<vector<int>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
    }
    cout << "\n";
  }
}

int main() {
  auto board = ReadBoardFile("input.txt");
  PrintBoard(board);
}