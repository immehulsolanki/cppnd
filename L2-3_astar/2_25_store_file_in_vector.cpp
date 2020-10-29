/*
Use the ParseLine Function
Great! With the ParseLine function complete, 
you can now use it in the ReadBoardFile to process each line of the incoming file. 
In this exercise, you will do just that: follow the TODOs in the code below, 
updating both ReadBoardFile and the main function to finish the processing of an external board file.
This Exercise:
        Update ReadBoardFile to use ParseLine and return the board as a vector<vector<int>>. 
        You can read the TODO comments in the code for step by step instructions.
        Update the main function to pass the results of ReadBoardFile to the PrintBoard function.
*/
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream; // For file stream
using std::istringstream; // For string stream
using std::string;
using std::vector;

vector<int> ParseLine(string line) {
  // Will get one line at a time and we will extrach num and char
  // Then store as 1d vector.
    istringstream sline(line); // Init. sring stream with var.
    // declare two iterator vars.
    int n;
    char c;
    vector<int> row;
    while (sline >> n >> c && c == ',') {
      row.push_back(n); // Store in 1d vec. as num. only c is not used.
    }
    // return 1D vec.
    return row;
}

// To get 2d vec. in return, We must declare fun. type 2d vec.
// Read oneline at a time from input file.
vector<vector<int>> ReadBoardFile(string path) {
  ifstream myfile (path); // Init stream with var.
  vector<vector<int>> board{}; // declare one var for storage.
  if (myfile) {
    string line; // line iterator var.
    while (getline(myfile, line)) {
      // parseline will return 1d vec.
      // line var. hold one string line from input file.
      vector<int> row = ParseLine(line); // call func and get 1d vec.
      board.push_back(row); // store 1d vec. in 2d vec.
      // push_back will always stores to back or end of vec.
    }
  }
  return board; // return 2d vec.
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
  //call and save in to 2d vec. varialbe.
  auto board = ReadBoardFile("input.txt"); // return 2d vec. (file to vec convert)
  PrintBoard(board); // print the vector contents.
}