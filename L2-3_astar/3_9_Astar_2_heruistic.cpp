/*
This Exercise:

        Write an int Heuristic function which takes four ints as arguments. 
        The ints represent two pairs of 2D coordinates: (x1,y1,x2,y2)(x_1, y_1, x_2, y_2)(x1​,y1​,x2​,y2​). 
        The function should return an int which is the Manhattan Distance 
        from one coordinate to the other: ∣x2−x1∣+∣y2−y1∣|x_2- x_1| + |y_2 - y_1|∣x2​−x1​∣+∣y2​−y1​∣.

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

// TODO: Write the Heuristic function here.
// fucntion args 4 int as two node co ordinates 
// this will return manhatten distance
int Heuristic (int x1,int y1,int x2,int y2){
  int manhattan_distance = abs( x2 - x1 ) + abs( y2 - y1);
  return manhattan_distance;
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

// ===== For testing solution
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
  cout << "----------------------------------------------------------" << "\n";
}
//=====

int main() {
  int init[2]{0, 0};
  int goal[2]{4, 5};
  auto board = ReadBoardFile("1.board");
  auto solution = Search(board, init, goal);
  PrintBoard(solution);
  // Tests
  TestHeuristic();
}