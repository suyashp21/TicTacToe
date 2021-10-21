/*
Author: Suyash Pandit
Date: October 21, 2021
This is a C++ implementation of the popular game Tic-Tac-Toe.
 */

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

bool checkwin(char board[][3], char player);
void printboard(char board[][3]);

int main() {
  char board[3][3];
  char replay = 'y';
  int moves = 0;
  int turn = 0;
  char space[3];
  int row = 0;
  int col = 0;
  int xwins = 0;
  int ties = 0;
  int owins = 0;
  cout << endl;

  while (replay == 'y' || replay == 'Y') {
    // clear board
    moves = 0;
    turn = 0;
    for (int i=0; i<3; i++) {
      for (int j=0; j<3; j++) {
	board[i][j] = ' ';
      }
    }
    
    printboard(board);

    while (moves < 9) {
      cout << endl;
      if (turn == 0) {
	cout << "X's turn. Make a move!" << endl;
      }
      if (turn == 1) {
	cout << "O's turn. Make a move!" << endl;
      }

      char space[3];
      while (true) {
	// check if move is legal, keep asking for moves until player makes legal move
        cin >> space;
	if (space[0] != 'a' && space[0] != 'A' && space[0] != 'b' && space[0] != 'B' && space[0] != 'c' && space[0] != 'C') {
	  // first char is invalid
	  cout << "First character must be A, B, or C" << endl;
	  continue;
	}
	else if (space[1] != '1' && space[1] != '2' && space[1] != '3') {
	  // second char is invalid
	  cout << "Second character must be 1, 2, or 3" << endl;
	  continue;
	}
      
	// determine correct row and column
        if (space[0] == 'a' || space[0] == 'A') {row = 0;}
        else if (space[0] == 'b' || space[0] == 'B') {row = 1;}
        else if (space[0] == 'c' || space[0] == 'C') {row = 2;}

        if (space[1] == '1') {col = 0;}
        else if (space[1] == '2') {col = 1;}
        else if (space[1] == '3') {col = 2;}

	if (board[row][col] != ' ') {
	  cout << "Must play on a vacant space!" << endl;
	  continue;
	}

	else {
	  break;
	}
      }

      if (turn == 0) {board[row][col] = 'X';}
      else if (turn == 1) {board[row][col] = 'O';}
	
      printboard(board);
      // see if player has won
      if (checkwin(board, 'X') && turn == 0) {
	cout << "\nX wins!" << endl;
	xwins++;
	break;
      }
      else if (checkwin(board, 'O') && turn == 1) {
	cout << "\nO wins!" << endl;
	owins++;
	break;
      }
      turn = 1 - turn;
      moves++;
      if (moves == 9) {
	//9 moves with no winner - game ends in a tie
	cout << "\nIt's a tie!" << endl;
	ties++;
      }
    }
    cout << "X wins: " << xwins << ", O wins: " << owins << ", Ties: " << ties << endl;
    // ask if player wants to play again
    cout << "Play again (y/n)" << endl;
    cin >> replay;
  }

  return 0;
}

bool checkwin(char board[][3], char player) {
  // check the eight "winning lines"
  if (board[0][0] == player && board[1][0] == player && board[2][0] == player) {return true;}
  else if (board[0][1] == player && board[1][1] == player && board[2][1] == player) {return true;}
  else if (board[0][2] == player && board[1][2] == player && board[2][2] == player) {return true;}
  else if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {return true;}
  else if (board[1][0] == player && board[1][1] == player && board[1][2] == player) {return true;}
  else if (board[2][0] == player && board[2][1] == player && board[2][2] == player) {return true;}
  else if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {return true;}
  else if (board[2][0] == player && board[1][1] == player && board[0][2] == player) {return true;}
  // no winner? return false
  else {return false;}
}

void printboard(char board[][3]) {
  // print out the game board in its current state
  cout << "\n  123" << endl;
  cout << "a " << board[0][0] << board[0][1] << board[0][2] << endl;
  cout << "b " << board[1][0] << board[1][1] << board[1][2] << endl;
  cout << "c " << board[2][0] << board[2][1] << board[2][2] << endl;
}
