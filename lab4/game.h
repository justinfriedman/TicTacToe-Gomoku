#pragma once


#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <iosfwd>
#include <ctype.h>
#include <ostream>

using namespace std;

//ostream & operator<< (ostream & o, const Game & game);

enum {
	ws_offset = 1,
	left_col_index = 1,
	mid_col_index = 2,
	right_col_index = 3,
	top_row_index = 1,
	mid_row_index = 2,
	bottom_row_index = 3,
	bottom_row_index_g = 19,
	user_quit = 101,
	comma_index = 1,
	comma_index_g = 2,
	success = 0,
	incorrect_input = 7,
	failed_to_read = 8,
	invalid_coords = 9,
	already_piece = 10,
	turn_error = 404,
	game_draw = 202,
	max_moves = 9,
	play_error = 171
};

class Game {


public:

	//constructor 
	Game();
	//destructor
	virtual ~Game();
	//public nonstatic done method no params returns bool true if 3 x or o are in a vertical or hoz or diag line, else false [
	virtual bool done() = 0;
	// insertion operator << takes reference & to an ostream and & to a const game obj as params
	//returns the ostream & 
	//prints out board and labeled axis 
	//friend ostream & operator<< (ostream &, const Game &);
	virtual bool draw() = 0;
	virtual int prompt(unsigned int&, unsigned int&);
	virtual int turn() = 0;
	virtual int play();
	virtual void print() = 0;
	static Game *commandArgs(int argc, char * argv[]);
	virtual void setN(int boardSize) = 0;
protected:
	//start state: 1,1 to 3,3 are empty, all 0,4 or and 4 or 0 cord squares are always empty
	//game board 5 wide and tall ll=0,0 and ur=4,4
	vector<vector<string>> board;
	// pieces are X or O 
	string player1;
	string player2;
	vector<string> p1Moves;
	vector<string> p2Moves;
	string turnChar;
	string winner = "";
	int longestName; // = longestPLength();
	int nSize;
	//int longestPLength() {
	//	//if both have content, find the longer name 
	//	if (Game::p1Moves.empty() && Game::p2Moves.empty()) {
	//		if (Game::player1.length() >= Game::player2.length()) {
	//			return Game::player1.length();
	//		}
	//		if (Game::player2.length() > Game::player1.length()) {
	//			return Game::player2.length();
	//		}
	//	}
	//	//if one or both do not have content
	//	//check one
	//	if (!Game::p1Moves.empty()) {
	//		return Game::player1.length();
	//	}
	//	//check two
	//	if (!Game::p2Moves.empty()) {
	//		return Game::player2.length();
	//	}
	//	else {
	//		return 0;
	//	}
	//}

};