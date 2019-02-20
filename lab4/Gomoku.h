#pragma once
#include "Game.h"
enum { first_check_row =4};
class Gomoku: public Game
{
public:
	Gomoku::Gomoku();
	~Gomoku();
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	virtual void print();
	void Gomoku::setN(int goSize);
	friend ostream & operator<<(ostream&o, const Gomoku &go);
private:
	vector<vector<string>> board;
	// pieces are X or O 
	string player1 = "B";
	string player2 = "W";
	//vector<string> p1Moves;
	//vector<string> p2Moves;
	string turnChar = "B";
	//string winner = "";
	int longestName;

};
ostream & operator<< (ostream &, const Gomoku &);