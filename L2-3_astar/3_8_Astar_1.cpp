/*
Lesson Code Structure:
Below are the steps from the while loop in the A* pseudocode you saw previously:

    1.while the list of open nodes is nonempty:

        2.Sort the open list by f-value
        3.Pop the optimal cell (called the current cell).
        4.Mark the cell's coordinates in the grid as part of the path.
        5.if the current cell is the goal cell:
            return the grid.
        6.else, expand the search to the current node's neighbors. This includes the following steps:
            Check each neighbor cell in the grid to ensure that the cell is empty: it hasn't been closed and is not an obstacle.
            If the cell is empty, compute the cost (g value) and the heuristic, and add to the list of open nodes.
            Mark the cell as closed.

This Exercise:

        1.Write a std::vector<vector<State>> Search function stub which takes a board grid and two length 2 int arrays as arguments. The int arrays will represent the start and goal coordinates for the search. The function should print ""No path found!" and return an empty std::vector<vector<State>>. The function will later return the board with a path from the start to the goal.
        2.In main(), call Search with a start of {0, 0} and a goal of {4, 5}. Store the results in the variable solution.
        3.Pass solution to PrintBoard.
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

enum class State {kEmpty, kObstacle};

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

// TODO: Write the Search function stub here.
// create a vector type search or board type so it it will final reurn same type 
// for printing.
// arguments: main board or greed as State type vector formate.
// one initial point of board (greed start co ordinate (0,0)).
// goal co ordinate (max location co ordinate (max,max)).
vector<vector<State>> Search (vector<vector<State>> board, int start[2], int goal[2] ) {
 
  cout << "No path found ";
  return vector<vector<State>> {}; // return empty if nothing processed.
}


string CellString(State cell) { // only used for print board.
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

int main() {
  // TODO: Declare "init" and "goal" arrays with values {0, 0} and {4, 5} respectively.
  int init [2] = { 0, 0 };
  int goal [2] = { 4, 5 };
  auto board = ReadBoardFile("1.board");
  // TODO: Call Search with "board", "init", and "goal". Store the results in the variable "solution".
  vector<vector<State>> solution = Search(board, init, goal);
  
  // TODO: Change the following line to pass "solution" to PrintBoard.
  PrintBoard(solution);
}
