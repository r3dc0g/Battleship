#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include "Ship.h"

using namespace std;

// The same converter, I probably could've found a solution to only have to have typed this once
int Ship::SpaceConverter(string space) {

	string letters = "ABCDEFGHIJ";
	int spaceValue = 0;
	string rowNumString;
	int rowNum = 0;

	if (space.size() > 2) {
		rowNumString = space.substr(1,2);
	}
	else {
		rowNumString = space.substr(1,1);
	}

	stringstream intRow(rowNumString);

	intRow >> rowNum;

	spaceValue = ((rowNum - 1) * 10 + letters.find(space.substr(0,1)));

	return spaceValue;
}

// Ship constructor
Ship::Ship(string shipType, string startPos, string direction) {

	int length = 0;
	int startValue = this->SpaceConverter(startPos);
	this->name = shipType;
	this->startString = startPos;
	this->start = startValue;
	this->direction = direction;

	if (shipType == "Carrier") {
		length = 5;
	}
	else if (shipType == "Battleship") {
		length = 4;
	}
	else if (shipType == "Cruiser") {
		length = 3;
	}
	else if (shipType == "Submarine") {
		length = 3;
	}
	else if (shipType == "Destroyer") {
		length = 2;
	}

	this->spaces.push_back(startValue);

	for (int s = 0; s < length - 1; ++s) {
		if (direction == "VD") {
			this->spaces.push_back(startValue + (10 * (s + 1)));
		}
		else if (direction == "VU") {
			this->spaces.push_back(startValue - (10 * (s + 1)));
		}
		else if (direction == "HR") {
			this->spaces.push_back(startValue + (s + 1));
		}
		else if (direction == "HL") {
			this->spaces.push_back(startValue - (s + 1));
		}
	}

}

// Prints the spaces it lies on
void Ship::PrintSpaces() {

	for (int spaceNum : this->spaces) {
		cout << spaceNum << endl;
	}

}

// Get one space it lies on
int Ship::GetSpace(int position) {

	return this->spaces.at(position);

}

// Returns the ship size
int Ship::GetSize() {
	return this->spaces.size();
}

// Returns the ship type
string Ship::GetName() {
	return this->name;
}

// Returns the starting position as an int
int Ship::GetStart() {
	return this->start;
}

// Returns the Direction
string Ship::GetDirection() {
	return this->direction;
}

// Returns the starting position as a string
string Ship::GetStartString() {
	return this->startString;
}
