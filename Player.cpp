#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "Player.h"

using namespace std;

Player::Player(string player) : shipBoard(player) {

	playerType = player;

}

void Player::PrintBoards() {

	this->hitBoard.PrintBoard();
	cout << endl;
	this->shipBoard.PrintBoard();
	cout << endl;
}

int Player::SpaceConverter(string space) {

	// This function takes in the battleship
	// coordinate and then make it a number
	// where 0 is A1 and 99 is J10.

	string letters = "ABCDEFGHIJ";
	int spaceValue = 0;
	string rowNumString;
	int rowNum = 0;

	// First we determine if the coordinate has 10 in it
	// then seperate the number from the letter
	if (space.size() > 2) {
		rowNumString = space.substr(1,2);
	}
	else {
		rowNumString = space.substr(1,1);
	}

	// Then we use stringstream to convert the number as a string into an integer

	stringstream intRow(rowNumString);

	intRow >> rowNum;

	// Then we make the number by making the
	// row number into the tens place and then
	// add column value by determining the index
	// of the letter in the above letter string
	spaceValue = ((rowNum - 1) * 10 + letters.find(space.substr(0,1)));

	return spaceValue;
}




void Player::MakeAttack(string space, ShipBoard &enemyShips) {

	// First we set up all the variables needed

	char marker = ' ';

	// Convert the coord to num value
	int spaceValue = SpaceConverter(space);
	int position = 0;
	int row = 0;
	int column = 0;

	// Make a ship pointer for later use
	Ship* hitShip = nullptr;

	// We see if the space chosen hits a ship
	if (enemyShips.QueryHit(space)) {

		// If it does we get the ship that it hit
		hitShip = enemyShips.HitShip(space);

		// Then we add a point to the score
		++this->score;

		// This marks that the ship was hit and adds its coords to the vector of spaces not to pick
		for (int i = 0; i < hitShip->GetSize(); ++i) {
			marker = 'x';

			position = hitShip->GetSpace(i);
			this->doNotPick.push_back(position);
			column = position % 10;
			row = (position - column) / 10;
			this->hitBoard.MarkBoard(row,column,marker);
		}
	}
	else {

		// Marks the misses
		marker = 'o';

		column = spaceValue % 10;
		row = (spaceValue - column) / 10;
		this->hitBoard.MarkBoard(row, column, marker);

	}

	// Adds the chosem space to the list to know that the player has already chosen this space
	this->doNotPick.push_back(spaceValue);


}

bool Player::CheckGame() {
	bool endOfGame = false;

	if (this->score == 5) {
		endOfGame = true;
	}

	return endOfGame;
}

// Generates a coord to give to the computer
string Player::GenerateMove() {

	int randNum = 0;
	string validMoves[] = {"A1","A2","A3","A4","A5","A6","A7","A8","A9","A10",
			       "B1","B2","B3","B4","B5","B6","B7","B8","B9","B10",
			       "C1","C2","C3","C4","C5","C6","C7","C8","C9","C10",
			       "D1","D2","D3","D4","D5","D6","D7","D8","D9","D10",
			       "E1","E2","E3","E4","E5","E6","E7","E8","E9","E10",
			       "F1","F2","F3","F4","F5","F6","F7","F8","F9","F10",
			       "G1","G2","G3","G4","G5","G6","G7","G8","G9","G10",
			       "H1","H2","H3","H4","H5","H6","H7","H8","H9","H10",
			       "I1","I2","I3","I4","I5","I6","I7","I8","I9","I10",
			       "J1","J2","J3","J4","J5","J6","J7","J8","J9","J10"};

	srand(time(0));

	randNum = rand() % 100;

	return validMoves[randNum];

}

// Checks if the chosen space is either a valid coord, a space that hasn't been chosen before, or the STOP flag
bool Player::CheckInput(string space) {

	int spaceValue = this->SpaceConverter(space);
	int validCounter = 0;

	for (int value : this->doNotPick) {
		if (spaceValue == value) {
			return false;
		}
	}

	string validMoves[] = {"A1","A2","A3","A4","A5","A6","A7","A8","A9","A10",
			       "B1","B2","B3","B4","B5","B6","B7","B8","B9","B10",
			       "C1","C2","C3","C4","C5","C6","C7","C8","C9","C10",
			       "D1","D2","D3","D4","D5","D6","D7","D8","D9","D10",
			       "E1","E2","E3","E4","E5","E6","E7","E8","E9","E10",
			       "F1","F2","F3","F4","F5","F6","F7","F8","F9","F10",
			       "G1","G2","G3","G4","G5","G6","G7","G8","G9","G10",
			       "H1","H2","H3","H4","H5","H6","H7","H8","H9","H10",
			       "I1","I2","I3","I4","I5","I6","I7","I8","I9","I10",
			       "J1","J2","J3","J4","J5","J6","J7","J8","J9","J10"};

	for (string move : validMoves) {
		if (space == move) {
			++validCounter;
		}
	}

	if (validCounter > 0) {
		return true;
	}
	else if (space == "STOP") {
		return true;
	}
	else {
		return false;
	}

}
