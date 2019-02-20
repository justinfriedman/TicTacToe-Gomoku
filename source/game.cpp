#include "stdafx.h"
#include "game.h"
#include <iostream>
#include <ostream>
#include "header.h"
#include "TicTacToe.h"
#include "Gomoku.h"
// these are the include statments 





int Game::prompt(unsigned int & col, unsigned int & row) {
	cout << "Enter coordinates of your move like x,y or the word 'quit'" << endl;
	//get user
	string input = "";
	getline(cin, input);

	//remove any spaces from input
	string cleanInput = "";
	cleanInput = removeSpace(input);
	if (cleanInput.empty()) {
		cout << "No input detected" << endl;
		return incorrect_input;
	}
	//test for quit command
	if (cleanInput == "quit") {
		return user_quit;
	}
	//if comma is not second recall function
	if (nSize == 3)
	{
		if (cleanInput[comma_index] != ',') {
			cout << "incorrect input" << endl;
			//prompt(col, row);
			return incorrect_input;
		}
	}
	else if (nSize == 19)
	{
		if ((cleanInput[comma_index] != ',')&& (cleanInput[comma_index_g] != ',')) 
		{
			cout << "incorrect input" << endl;
			//prompt(col, row);
			return incorrect_input;
		}
	}
	
	//else replace comma with space
	if(cleanInput[comma_index] == ',') 
	{ 
		cleanInput[comma_index] = ' '; 
	}
	else if (cleanInput[comma_index_g] == ',')
	{
		cleanInput[comma_index_g] = ' ';
	}
	
	//put input in stream and extract into values

	istringstream iss(cleanInput);
	if (!(iss >> col)) {
		cout << "failed to read input" << endl;
		//prompt(col, row);
		return failed_to_read;
	}
	if (!(iss >> row)) {
		cout << "failed to read input" << endl;
		//prompt(col, row);
		return failed_to_read;
	}

	//ensure valid coords
	if ((col < top_row_index) || (col > nSize) || (row < top_row_index) || (row > nSize)) {
		cout << "invalid coords" << endl;
		//prompt(col, row);
		return invalid_coords;
	}
	//swap cords to map to label indexies
	if (nSize == bottom_row_index)
	{
		if (row == top_row_index) {
			row = bottom_row_index;
			return success;
		}
		if (row == bottom_row_index) {
			row = top_row_index;
			return success;
		}
		else {
			return success;
		}
	}
	return success;
}
int Game::play() {
	//print game board
	(*this).print();
	//repeatedly call turn() and done() and draw() methods 
	while ((!done()) && (!draw())) {
		//3: user quits then print how many turns were played and that user quit and a non 0 code
		if (turn() == user_quit) {
			cout << "User has quit" << endl;
			cout << to_string(Game::p1Moves.size() + Game::p2Moves.size()) << " moves were played" << endl;
			return user_quit;
		}
	}
	//until
	//1: done returns true and program prints the winner, returns sucess
	if (done()) {
		cout << Game::winner << " is the winner!" << endl;
		return success;
	}
	//2: draw method trurns true prints out how many turns were plaued and says that game is draw, return non 0
	if (draw()) {
		cout << "Game is draw" << endl;
		cout << to_string(Game::p1Moves.size() + Game::p2Moves.size()) << " moves were played" << endl;
		return game_draw;
	}
	//if here there is an issue
	return play_error;
}



Game::Game()
{
	cout << "Game()" << endl;
}
Game::~Game()
{
	cout << "~Game()" << endl;
	
}

Game * Game::commandArgs(int argc, char * argv[]) {
	Game * p = 0;
	//check that only one additional arg was passed
	if (argc != 2) {
		return p;
	}
	//string must TicTacToe
	string str(argv[arg]);
	if (str != "TicTacToe") {
		if (str != "Gomoku")
		{
			return p;

		}
	}
	if (str == "TicTacToe")
	{
		//use new to dymically construct new object 
		TicTacToe * gP = new TicTacToe();
		(*gP).setN(bottom_row_index);
		//return obj address 
		return gP;
	}
	if (str == "Gomoku")
	{
		Gomoku * g = new Gomoku();
		(*g).setN(bottom_row_index_g);
		return g;
	}
	//If it gets here theres a problem
	return p;
}