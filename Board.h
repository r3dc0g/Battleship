using namespace std;

#ifndef BOARD_H
#define BOARD_H

class Board {
	public:
		Board();						// Constructor
		void MarkBoard(int row, int column, char marker);	// Marks the board
		void PrintBoard();					// Prints the board


	protected:
		char layout[10][10];					// Char array that stores the markers and ships


};

#endif
