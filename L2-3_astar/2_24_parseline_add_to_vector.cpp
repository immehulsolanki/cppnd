/*
Parse Lines from the File
This Exercise:

    Write a vector<int> ParseLine function which accepts a string as an argument. 
    Use std::istringstream to parse the line by comma chars, and store the ints in a vector<int>. 
    ParseLine should return the vector after parsing.

Note: you will need to #include <sstream> to use istringstream. Additionally, 
you may want to add using std::istringstream; to your program. 
Finally, remember that each line of the board will look something like: 1,0,0,0,0,, 
so you may want to stream an int and a char with each pass through a while loop.
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


// TODO: Add the ParseLine function here.
vector <int> ParseLine (string line){
  istringstream board_line(line);
  char c;
  int n;
  vector <int> v = {};  
  while (board_line >> n >> c){
   v.push_back(n);
  }
  return v;

}

void ReadBoardFile(string path) {
  ifstream myfile (path);
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      cout << line << "\n";
    }
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

// for testing
void PrintVector(vector<int> v) {
  cout << "{ ";
  for (auto item : v) {
    cout << item << " ";
  }
  cout << "}" << "\n";
}

// automatic tester
void TestParseLine() {
  cout << "----------------------------------------------------------" << "\n";
  cout << "TestParseLine: ";
  string line = "0,1,0,0,0,0,";
  vector<int> solution_vect{0,1,0,0,0,0};
  vector<int> test_vect;
  test_vect = ParseLine(line);
  if (test_vect != solution_vect) {
    cout << "failed" << "\n";
    cout << "\n" << "Test input string: " << line << "\n";
    cout << "Your parsed line: ";
    PrintVector(test_vect);
    cout << "\n";
  } else {
    cout << "passed" << "\n";
  }
  cout << "----------------------------------------------------------" << "\n";
  return;
}

int main() {
  ReadBoardFile("input.txt");
  TestParseLine(); // For testing.
  // Leave commented out.
  // PrintBoard(board);
}