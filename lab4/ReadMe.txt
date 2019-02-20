Micah Rounds, Justin Friedman 
========================================================================
    CONSOLE APPLICATION : LAB4 Project Overview
========================================================================

AppWizard has created this lab4 application for you.

This file contains a summary of what you will find in each of the files that
make up your lab4 application.


lab4.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

lab4.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

lab4.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named lab4.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
Errors Before QA:

Problem: String index out of bounds whenever enter was pressed during the game 
Fix: added a stub to catch empty input and break execution 

Problem: / win case did not fire done
Fix: start stepping through windows at the south east corner moving northeast by col and row 

Problem: Name of winning player and number of moves played displaying incorrectly
Fix: Removed redeclaration of base class variables in derived classes

Problem: game returns invalid move for double digit entries in gomoku
Fix: add conditional dependent on game name to adjust coordinate entry restraints

Problem: single digit coordinates return invalid move in gomoku
Fix: add separate conditionals in game.cpp to handle out of bounds coordinates separately for each game 

/////////////////////////////////////////////////////////////////////////////
Testing:

Command: lab3src.exe TicTacToe
Result: Game is played and coord moves are printed correctly, moving to the space coord twice is not allowed 

Command: lab3src.exe 
Result: returns usage message and exits 

Command: lab3src.exe TicTacToe ++ quiting during game 
Result: functional 

Command: lab3src.exe TicTacToe ++ quiting during first move 
Result: exits and prints correct output 


Command: lab3src.exe TicTacToe ++ spaces in coords 
Result: spaces are removed properly 


Command: lab3src.exe TicTacToe ++ out of bounds coords 
Result: functional

Command: lab3src.exe TicTacToe ++ non integer coords 
Result: functional

Command: lab3src.exe TicTacToe ++ coords are words 
Result: functional


Command: lab3src.exe TicTacToe ++ someone plays winning move 
Result: functional


Command: lab3src.exe TicTacToe ++ no moves are left  
Result: functional


Command: lab3src.exe Gomoku
Result: Game is played and coord moves are printed correctly, moving to the space coord twice is not allowed 

Command: lab3src.exe 
Result: returns usage message and exits 

Command: lab3src.exe Gomoku ++ quiting during game 
Result: functional 

Command: lab3src.exe Gomoku ++ quiting during first move 
Result: exits and prints correct output 


Command: lab3src.exe Gomoku ++ spaces in coords 
Result: spaces are removed properly 


Command: lab3src.exe Gomoku ++ out of bounds coords 
Result: functional

Command: lab3src.exe Gomoku ++ non integer coords 
Result: functional

Command: lab3src.exe Gomoku ++ coords are words 
Result: functional


Command: lab3src.exe Gomoku ++ someone plays winning move 
Result: functional


Command: lab3src.exe Gomoku ++ no moves are left  
Result: functional but very hard to test many cases 
