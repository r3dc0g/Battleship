#include "Board.h"
#include <string>
#include <iostream>

using namespace std;

Board::Board() {

	// Fills the layout with blank spaces
	for (unsigned int row = 0; row < 10; ++row) {

		for (unsigned int column = 0; column < 10; ++column) {

			this->layout[row][column] = ' ';

		}

	}

}

// Prints the layout within the labeled grid
void Board::PrintBoard() {


	cout << endl << "     A   B   C   D   E   F   G   H   I   J  " << endl;

	for (unsigned int r = 0; r < 10; ++r) {

		if (r < 9) {
			cout << r + 1 << "  | ";
		}
		else {
			cout << r + 1 << " | ";
		}

		for (unsigned int c = 0; c < 10; ++c) {

			cout << this->layout[r][c];
			cout << " | ";

		}

		cout << endl;

		if (r < 9) {
			cout << "   -----------------------------------------" << endl;
		}

	}

}

// Marks the board
void Board::MarkBoard(int row, int column, char marker) {
	this->layout[row][column] = marker;
}
