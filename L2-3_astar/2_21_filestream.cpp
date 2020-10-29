/*
Reading the Board from a File
Until now, the board has been declared and initialized in the main() function. 
As discussed in the previous notebook, you will need a function to read 
the board in from another file in order to make the program a little 
more flexible and user-friendly.

The first step in this process will be to write a ReadBoardFile 
function that reads in the file and prints each line to cout. 
The output should look like the 1.board file, 
which can be opened in the editor below:

0,1,0,0,0,0,
0,1,0,0,0,0,
0,1,0,0,0,0,
0,1,0,0,0,0,
0,0,0,0,1,0,

This Exercise:
        Write a function void ReadBoardFile which reads lines from a file. Write each line to cout, followed by a newline character "\n". The function should accept a string argument, which represents the path to the file. For now, since ReadBoardFile does not need to return anything, you can use a void return type.
        Call ReadBoardFile from main using the argument "1.board".
Note: you will need to include the fstream class, 
and you may want to have using std::ifstream to use the ifstream 
object without having to write std:: in the rest of your code.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;
using std::ifstream;

// TODO: Add the ReadBoardFile function here.
void ReadBoard(string path){
    ifstream my_file; // init object 
    my_file.open(path);
    if (my_file){
    	cout << "file loaded." << "\n";
      	string newline;
      while (getline(my_file, newline)){
      	  cout << newline << "\n";
       }
    }
}

// PrintBoard not used in this exercise
void PrintBoard(const vector<vector<int>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
    }
    cout << "\n";
  }
}

int main() {
  // TODO: Call the ReadBoardFile function here.
  string path = "1.board";
  ReadBoard(path);
  // Leave the following line commented out.
  //PrintBoard(board);
}