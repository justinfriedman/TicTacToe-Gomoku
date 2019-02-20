#include "stdafx.h"
#include "game.h"
#include <iostream>
#include <ostream>
#include <iomanip>
#include "Gomoku.h"
#include "game.h"
void Gomoku::print()
{
	cout << (*this);
}

Gomoku::Gomoku()
{
	for (int i = 0; i <= bottom_row_index_g; ++i)
	{
		board.push_back(std::vector<string>());
		for (int j = 0; j <= bottom_row_index_g; ++j)
		{
			board[i].push_back(" ");
		}
	}
	if (player2.length() > player1.length()) {
		longestName = player2.length();
	}
	else {
		longestName = player1.length();
	}
	//cout << board.size() << endl;
	cout << "Gomoku()" << endl;
}
Gomoku::~Gomoku()
{
	cout << "~Gomoku()" << endl;
}

ostream & operator<< (ostream & o, const Gomoku & go)
{
	int w = go.longestName + 1;
	vector<vector<string>> goBoard = go.Gomoku::board;
	for (unsigned int i = 0; i < goBoard.size();++i)
	{
		int line_num = goBoard.size() - 1 - i;
		o << line_num;
		for (unsigned int j = 0; j < goBoard[i].size();++j)
		{
			o << setw(w) << goBoard[i][j];
		}
		o << endl;
	};
	o << " " << setw(w) << "0" << setw(w) << "1" << setw(w) << "2" << setw(w) << "3" << setw(w) << "4" << setw(w) << "5" << setw(w) << "6" << setw(w) << "7" << setw(w) << "8" << setw(w) << "9" << setw(w) << "10" << setw(w) << "11" << setw(w) << "12" << setw(w) << "13" << setw(w) << "14" << setw(w) << "15" << setw(w) << "16" << setw(w) << "17" << setw(w) << "18" << setw(w) << "19" << endl;
	return o;
}
bool Gomoku::draw()
{

	//cols
	//for each col
	for (unsigned int col = ws_offset; col <= bottom_row_index_g; ++col) {
		//for each row in col
		for (unsigned int row = first_check_row; row <= (bottom_row_index_g - first_check_row); ++row) {
			string piece = board[row][col];

			int counter = 0;
			for (unsigned int i = 0; i < 5; ++i) {
				if ((board[row + i][col] == piece) || (board[row + i][col] == " ")) {
					counter += 1;
				}

				if (counter == 5) {
					return false;
				}
			}

		}
	}

	//rows
	for (unsigned int row = ws_offset; row <= bottom_row_index_g; ++row) {
		for (unsigned int col = ws_offset; col <= (bottom_row_index_g - first_check_row); ++col) {
			string piece = board[row][col];

			int counter = 0;
			for (unsigned int i = 0; i < 5; ++i) {
				if ((board[row][col + i] == piece) || (board[row][col + i] == " ")) {
					counter += 1;
				}
			}
			if (counter == 5) {
				return false;
			}


		}
	}

	//diags /

	for (unsigned int row = (bottom_row_index_g - first_check_row); row >0; --row) {
		for (unsigned int col = bottom_row_index_g; col > first_check_row; --col) {
			string piece = board[row][col];

			int counter = 0;
			for (unsigned int i = 0; i < 5; ++i) {
				if ((board[row + i][col - i] == piece) || (board[row + i][col - i] == " ")) {
					counter += 1;
				}
			}
			if (counter == 5) {
				return false;
			}


		}
	}

	//diags \

	for (unsigned int col = ws_offset; col <= (bottom_row_index_g - first_check_row); ++col) {
		for (unsigned int row = ws_offset; row <= (bottom_row_index_g - first_check_row); ++row) {
			string piece = board[row][col];

			int counter = 0;
			for (unsigned int i = 0; i < 5; ++i) {
				if ((board[row + i][col + i] == piece) || (board[row + i][col + i] == " ")) {
					counter += 1;
				}
			}
			if (counter == 5) {
				return false;
			}


		}
	}
	//if it gets here there are no possible ways for a player to win the game
	//aka there are no windows of 5 spaces with only " " or a single piece type in them
	return true;
}
void Gomoku::setN(int goSize)
{
	nSize = goSize;
}
bool Gomoku::done()
{
	//cols
	//for each col
	for (unsigned int col = ws_offset; col <= bottom_row_index_g; ++col) {
		//for each row in col
		for (unsigned int row = first_check_row; row <= (bottom_row_index_g - first_check_row); ++row) {
			string piece = board[row][col];
			if (piece != " ") {
				bool won = true;
				for (unsigned int i = 0; i < 5; ++i) {
					if (board[row + i][col] != piece) {
						won = false;
					}
				}
				if (won) {
					if (piece == player1)
					{
						winner = player1;
					}
					else if (piece == player2)
					{
						winner = player2;
					}
					return true;
				}
			}

		}
	}

	//rows
	for (unsigned int row = ws_offset; row <= bottom_row_index_g; ++row) {
		for (unsigned int col = ws_offset; col <= (bottom_row_index_g - first_check_row); ++col) {
			string piece = board[row][col];
			if (piece != " ") {
				bool won = true;
				for (unsigned int i = 0; i < 5; ++i) {
					if (board[row][col + i] != piece) {
						won = false;
					}
				}
				if (won) {
					if (piece == player1)
					{
						winner = player1;
					}
					else if (piece == player2)
					{
						winner = player2;
					}
					return true;
				}
			}

		}
	}

	//diags /

	for (unsigned int row = (bottom_row_index_g - first_check_row); row >0; --row) {
		for (unsigned int col = bottom_row_index_g; col > first_check_row; --col) {
			string piece = board[row][col];
			if (piece != " ") {
				bool won = true;
				for (unsigned int i = 0; i < 5; ++i) {
					if (board[row + i][col - i] != piece) {
						won = false;
					}
				}
				if (won) {
					if (piece == player1)
					{
						winner = player1;
					}
					else if (piece == player2)
					{
						winner = player2;
					}
					return true;
				}
			}

		}
	}

	//diags \

	for (unsigned int col = ws_offset; col <= (bottom_row_index_g - first_check_row); ++col) {
		for (unsigned int row = ws_offset; row <= (bottom_row_index_g - first_check_row); ++row) {
			string piece = board[row][col];
			if (piece != " ") {
				bool won = true;
				for (unsigned int i = 0; i < 5; ++i) {
					if (board[row + i][col + i] != piece) {
						won = false;
					}
				}
				if (won) {
					if (piece == player1)
					{
						winner = player1;
					}
					else if (piece == player2)
					{
						winner = player2;
					}
					return true;
				}
			}

		}
	}
	return false;
}
int Gomoku::turn() {
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
	if (Gomoku::board[bottom_row_index_g-row][col] != " ") {
		cout << "Already Piece at entered location" << endl;
		return turn();
	}

	//replace vector index value with peice 
	Gomoku::board[bottom_row_index_g -row][col] = turnChar;
	//swap index values to match moves to keys
	//TODO redo swapping for Gomoku confirm with Micah that top_row_index=1 and bottom = 15
	/*bool swapped = false;
	if (row == top_row_index) {
		row = bottom_row_index_g;
		swapped = true;
	}
	if ((row == bottom_row_index_g) && (!swapped)) {
		row = top_row_index;

	}*/
	//swap turn 
	if (Gomoku::turnChar == Gomoku::player1) {

		//add move to list of player moves

		Gomoku::p1Moves.push_back(to_string(col) + "," + to_string(row));
		//print out board
		(*this).print();
		cout << endl;
		cout << "Player " << player1 << " Moves: ";
		for (unsigned int i = 0; i < Gomoku::p1Moves.size(); ++i) {
			cout << Gomoku::p1Moves[i];
			if (i != (Gomoku::p1Moves.size() - 1)) {
				cout << ";";
			}
		}
		cout << endl;
		cout << endl;
		Gomoku::turnChar = Gomoku::player2;
		return success;
	}
	if (Gomoku::turnChar == Gomoku::player2) {
		//add moves to vector of player moves
		Gomoku::p2Moves.push_back(to_string(col) + "," + to_string(row));
		

		//print out board
		(*this).print();
		cout << endl;
		cout << "Player " << player2 << " Moves: ";
		for (unsigned int i = 0; i < Gomoku::p2Moves.size(); ++i) {
			cout << Gomoku::p2Moves[i];
			if (i != (Gomoku::p2Moves.size() - 1)) {
				cout << ";";
			}
		}
		cout << endl;
		cout << endl;
		Gomoku::turnChar = Gomoku::player1;
		return success;
	}

	//if it gets here there is an issue
	return turn_error;


}




