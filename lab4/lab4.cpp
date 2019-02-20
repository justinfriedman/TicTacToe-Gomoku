// lab4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <ctype.h>
#include "TicTacToe.h"
#include "Gomoku.h"
#include <ostream>
#include <memory>
#include "header.h"
#include "game.h"

using namespace std;

int main(int argc, char * argv[])
{
	
	//cout << "begin main" << endl;
	// member function that checks for count and value of args then makes a game object 
	shared_ptr<Game> gP(Game::commandArgs(argc, argv));
	
	//comment

	//if ^ resulting value is dereferenced to 0, call usage message 
	if (gP == 0) {
		string usageStr = " TicTacToe |or| Gomoku";
		return usageMessage(argv[prgm_name], usageStr);
	}
	//if obj was created, call play and return the result 
	int playReturn = gP->play();

	//destroy dynamically allocated object
	//we do this by initilizing a shared_ptr with return of static method so that 
	//destruction is handled for us
	
	
	cout << "end main" << endl;
	return playReturn;
	/*string firstArg(argv[arg]);
	if ((firstArg != "TicTacToe")&&(firstArg != "Gomoku")) {
		cout << firstArg << endl;
		string usageStr = " TicTacToe or Gomoku";
		return usageMessage(argv[prgm_name], usageStr);
	}*/
	//int playResult;
	//declare game object 
	/*if (firstArg == "TicTacToe")
	{
		TicTacToe * tGame = new TicTacToe();
		shared_ptr<TicTacToe> tptr = make_shared<TicTacToe>();
		playResult = (*tGame).play();
		cout << "delete tptr" << endl;
		delete &tptr;
	}
	else if (firstArg == "Gomoku")
	{
		Gomoku * gGame = new Gomoku();
		shared_ptr<Gomoku> gptr = make_shared<Gomoku>();
		playResult = (*gGame).play();
		cout << "delete gptr" << endl;
		delete &gptr;
	}*/
	
	//return playResult;
}

string removeSpace(string str) {
	string final_string;
	for (unsigned int i = 0; i < str.length(); ++i) {
		if (isspace(str[i]) == 0) {
			final_string += str[i];
		}
	}

	return final_string;
}

int usageMessage(char* str, string message) {
	string program_name(str);
	string usageInstructions = "usage: " + program_name + message;
	cout << usageInstructions;
	return wrong_num_cmd_arg;
}