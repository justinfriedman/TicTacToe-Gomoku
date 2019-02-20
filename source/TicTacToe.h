#pragma once
#include "game.h"
class TicTacToe: public Game
{
	//updated
	public:
		//contructor
		TicTacToe::TicTacToe();
		//destructor
		virtual TicTacToe::~TicTacToe();
		virtual bool done();
		virtual bool  draw();
		void TicTacToe::setN(int boardSize);
		virtual int turn();
		void print();
		friend ostream & operator<< (ostream &, const TicTacToe &);
	private:
		vector<vector<string>>board{ { " "," ", " ", " ", " " },
									{ " "," ", " ", " ", " " },
									{ " "," ", " ", " ", " " },
									{ " "," ", " ", " ", " " },
									{ " "," ", " ", " ", " " } };
		// pieces are X or O 
		string player1 = "X";
		string player2 = "O";
		//vector<string> p1Moves;
		//vector<string> p2Moves;
		string turnChar = "X";
		//string winner = "";
		int longestName; // = longestPLength();
};