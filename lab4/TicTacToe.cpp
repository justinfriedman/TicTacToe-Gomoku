#include "stdafx.h"
#include "game.h"
#include <sstream>
#include <iostream>
#include <iomanip>
#include <ostream>
#include "TicTacToe.h"
#include "game.h"
#include "header.h"

//tic tac toe  game class with private member variables 
//game board 5 wide and tall ll=0,0 and ur=4,4
// pieces are X or O 
// insertion operator << takes reference & to an ostream and & to a const game obj as params
//insertion operator is friend 
//Game::Game() {};
ostream & operator<< (ostream & o, const TicTacToe & game) {
	int w = game.longestName + 1;
	vector<vector<string>> board2Print = game.TicTacToe::board;
	for (unsigned int i = 0; i < board2Print.size();++i) {
		int line_num = board2Print.size() - 1 - i;
		o << line_num;
		for (unsigned int j = 0; j < board2Print[i].size();++j) {
			//set width to the width of the longest name
			o << setw(w) << board2Print[i][j];
		}
		o << endl;
	};
	o << " " << setw(w) << "0";
	o << setw(w) << "1";
	o << setw(w) << "2";
	o << setw(w) << "3";
	o << setw(w) << "4" << endl;
	return o;
}
TicTacToe::TicTacToe(){
	cout << "TicTacToe()" << endl;
	
	if (player2.length() > player1.length()) {
		longestName = player2.length();
	}
	else {
		longestName = player1.length();
	}
}
TicTacToe::~TicTacToe() {
	cout << "~TicTacToe" << endl;
	
}
void TicTacToe::print()
{
	cout << (*this) ;
}

//done()
bool TicTacToe::done() {


	// row is all non space same
	for (unsigned int i = 1; i < (board.size() - ws_offset);++i) {

		if ((board[i][left_col_index] == board[i][right_col_index]) && (board[i][left_col_index] == board[i][mid_col_index]) && (board[i][left_col_index] != " ")) {
			TicTacToe::winner = board[i][left_col_index];
			return true;
		}
	};

	//col is all non space same
	for (unsigned int i = 1; i < (board[top_row_index].size() - ws_offset);++i) {

		if ((board[top_row_index][i] == board[mid_row_index][i]) && (board[top_row_index][i] == board[bottom_row_index][i]) && (board[top_row_index][i] != " ")) {
			TicTacToe::winner = board[top_row_index][i];
			return true;
		}
	};
	//hardcoded \ diag
	if ((board[top_row_index][left_col_index] == board[mid_row_index][mid_col_index]) && (board[top_row_index][left_col_index] == board[bottom_row_index][right_col_index]) && (board[top_row_index][left_col_index] != " ")) {
		TicTacToe::winner = board[top_row_index][left_col_index];
		return true;
	}

	//hardcoded / diag
	if ((board[top_row_index][right_col_index] == board[mid_row_index][mid_col_index]) && (board[top_row_index][right_col_index] == board[bottom_row_index][left_col_index]) && (board[top_row_index][right_col_index] != " ")) {
		TicTacToe::winner = board[top_row_index][right_col_index];
		return true;
	}
	else {
		return false;
	}
}

//draw()

bool TicTacToe::draw() {
	//return false if moves remaining or if done is true
	//TODO moves remaining logic
	if ((TicTacToe::p1Moves.size() + TicTacToe::p2Moves.size()) < max_moves) {
		return false;
	}
	if (done()) {
		return false;
	}

	//else true
	else {
		return true;
	}
}
//prompt()

//turn()

void TicTacToe::setN(int boardSize)
{
	nSize = boardSize;
}
int TicTacToe::turn() {
	cout << "It is player " << turnChar << "'s turn" << endl;
	unsigned int col;
	unsigned int row;

	int promptReturn = prompt(col, row);
	//cout << "prompt return" << promptReturn << endl;
	if (promptReturn == user_quit) {
		return user_quit;
	}
	if (promptReturn != success) {

		return turn();
	}
	//below is for valid moves only
	//test is if space is already taken 
	if (TicTacToe::board[row][col] != " ") {
		cout << "Already Piece at entered location" << endl;
		return turn();
	}

	//replace vector index value with peice 
	TicTacToe::board[row][col] = turnChar;
	//swap index values to match moves to keys
	bool swapped = false;
	if (row == top_row_index) {
		row = bottom_row_index;
		swapped = true;
	}
	if ((row == bottom_row_index) && (!swapped)) {
		row = top_row_index;

	}
	//swap turn 
	if (TicTacToe::turnChar == TicTacToe::player1) {

		//add move to list of player moves

		TicTacToe::p1Moves.push_back(to_string(col) + "," + to_string(row));
		//print out board
		(*this).print();
		cout << endl;
		cout << "Player "<< player1 <<" Moves: ";
		for (unsigned int i = 0; i < TicTacToe::p1Moves.size(); ++i) {
			cout << TicTacToe::p1Moves[i];
			if (i != (TicTacToe::p1Moves.size() - 1)) {
				cout << ";";
			}
		}
		cout << endl;
		cout << endl;
		TicTacToe::turnChar = TicTacToe::player2;
		return success;
	}
	if (TicTacToe::turnChar == TicTacToe::player2) {
		//add moves to vector of player moves
		TicTacToe::p2Moves.push_back(to_string(col) + "," + to_string(row));

		//print out board
		(*this).print();
		cout << endl;
		cout << "Player " << player2 << " Moves: ";
		for (unsigned int i = 0; i < TicTacToe::p2Moves.size(); ++i) {
			cout << TicTacToe::p2Moves[i];
			if (i != (TicTacToe::p2Moves.size() - 1)) {
				cout << ";";
			}
		}
		cout << endl;
		cout << endl;
		TicTacToe::turnChar = TicTacToe::player1;
		return success;
	}

	//if it gets here there is an issue
	return turn_error;

}