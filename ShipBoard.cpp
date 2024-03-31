#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include "ShipBoard.h"
#include "Ship.h"

using namespace std;

ShipBoard::ShipBoard(string playerType) {

	char marker = ' ';
	string startPos;
	string shipType;
	string direction;
	int position = 0;
	int column = 0;
	int row = 0;

	// If the player object being loaded it a player, we load a layout according the the ship_placement.csv file
	if (playerType == "human") {

		ifstream shipPlacement("ship_placement.csv");

		if (!shipPlacement) {
			cout << "No csv file for human player!" << endl;
		}
		else {

			// Loads in each ship and creates ship object pointers for each
			getline(shipPlacement, shipType, ',');
			getline(shipPlacement, startPos, ',');
			getline(shipPlacement, direction);
			direction.pop_back();
			Ship *ship1 = new Ship(shipType, startPos, direction);
			this->boats.push_back(ship1);

			getline(shipPlacement, shipType, ',');
			getline(shipPlacement, startPos, ',');
			getline(shipPlacement, direction);
			direction.pop_back();
			Ship *ship2 = new Ship(shipType, startPos, direction);
			this->boats.push_back(ship2);

			getline(shipPlacement, shipType, ',');
			getline(shipPlacement, startPos, ',');
			getline(shipPlacement, direction);
			direction.pop_back();
			Ship *ship3 = new Ship(shipType, startPos, direction);
			this->boats.push_back(ship3);

			getline(shipPlacement, shipType, ',');
			getline(shipPlacement, startPos, ',');
			getline(shipPlacement, direction);
			direction.pop_back();
			Ship *ship4 = new Ship(shipType, startPos, direction);
			this->boats.push_back(ship4);

			getline(shipPlacement, shipType, ',');
			getline(shipPlacement, startPos, ',');
			getline(shipPlacement, direction);
			direction.pop_back();
			Ship *ship5 = new Ship(shipType, startPos, direction);
			this->boats.push_back(ship5);

		}

		// For each ship, we then mark the board with where they are at with the appropriate numbered marker

		for (Ship *currentShip : this->boats) {

			if (currentShip->GetName() == "Battleship") {
				marker = '4';
			}
			else if (currentShip->GetName() == "Cruiser") {
				marker = '3';
			}
			else if (currentShip->GetName() == "Carrier") {
				marker = '5';
			}
			else if (currentShip->GetName() == "Submarine") {
				marker = '3';
			}
			else if (currentShip->GetName() == "Destroyer") {
				marker = '2';
			}


			for (int i = 0; i < currentShip->GetSize(); ++i) {

				position = currentShip->GetSpace(i);
				column = position % 10;
				row = (position - column) / 10;
				this->layout[row][column] = marker;

			}

		}

	}
	else if (playerType == "computer") {

		int randomNum = 0;

		srand(time(0));

		randomNum = rand() % 1000;

		ifstream shipPlacement;


		// if the player type is a computer we randomly select 1 of 10 different layouts to load the ships from
		switch(randomNum) {

			case 0 ... 99:
				shipPlacement.open("template_1.csv");
				break;

			case 100 ... 199:
				shipPlacement.open("template_2.csv");
				break;

			case 200 ... 299:
				shipPlacement.open("template_3.csv");
				break;

			case 300 ... 399:
				shipPlacement.open("template_4.csv");
				break;

			case 400 ... 499:
				shipPlacement.open("template_5.csv");
				break;

			case 500 ... 599:
				shipPlacement.open("template_6.csv");
				break;

			case 600 ... 699:
				shipPlacement.open("template_7.csv");
				break;

			case 700 ... 799:
				shipPlacement.open("template_8.csv");
				break;

			case 800 ... 899:
				shipPlacement.open("template_9.csv");
				break;

			case 900 ... 999:
				shipPlacement.open("template_10.csv");
				break;

		}

		if (!shipPlacement) {
			cout << "No csv file for human player!" << endl;
		}
		else {

			getline(shipPlacement, shipType, ',');
			getline(shipPlacement, startPos, ',');
			getline(shipPlacement, direction);
			Ship *ship1 = new Ship(shipType, startPos, direction);
			this->boats.push_back(ship1);

			getline(shipPlacement, shipType, ',');
			getline(shipPlacement, startPos, ',');
			getline(shipPlacement, direction);
			Ship *ship2 = new Ship(shipType, startPos, direction);
			this->boats.push_back(ship2);

			getline(shipPlacement, shipType, ',');
			getline(shipPlacement, startPos, ',');
			getline(shipPlacement, direction);
			Ship *ship3 = new Ship(shipType, startPos, direction);
			this->boats.push_back(ship3);

			getline(shipPlacement, shipType, ',');
			getline(shipPlacement, startPos, ',');
			getline(shipPlacement, direction);
			Ship *ship4 = new Ship(shipType, startPos, direction);
			this->boats.push_back(ship4);

			getline(shipPlacement, shipType, ',');
			getline(shipPlacement, startPos, ',');
			getline(shipPlacement, direction);
			Ship *ship5 = new Ship(shipType, startPos, direction);
			this->boats.push_back(ship5);

		}

		for (Ship *currentShip : this->boats) {

			if (currentShip->GetName() == "Battleship") {
				marker = '4';
			}
			else if (currentShip->GetName() == "Cruiser") {
				marker = '3';
			}
			else if (currentShip->GetName() == "Carrier") {
				marker = '5';
			}
			else if (currentShip->GetName() == "Submarine") {
				marker = '3';
			}
			else if (currentShip->GetName() == "Destroyer") {
				marker = '2';
			}


			for (int i = 0; i < currentShip->GetSize(); ++i) {

				position = currentShip->GetSpace(i);
				column = position % 10;
				row = (position - column) / 10;
				this->layout[row][column] = marker;

			}

		}
	}

}

// The coordinate converter again
int ShipBoard::SpaceConverter(string space) {

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

// The function returns which ship got hit
Ship* ShipBoard::HitShip(string space) {

	int spaceValue = this->SpaceConverter(space);

	// We create an error ship pointer to give if something goes wrong
	Ship* error = new Ship("error","A0","null");
	bool hitResult = false;

	for (Ship *currentShip : boats) {

		for (int i = 0; i < currentShip->GetSize(); ++i) {
			if (spaceValue == currentShip->GetSpace(i)) {
				hitResult = true;
			}

			if (hitResult) {
				delete error;
				return currentShip;
			}
		}

	}

	return error;

}

// This function queries if with the given space, a ship is hit
bool ShipBoard::QueryHit(string space) {

	int spaceValue = this->SpaceConverter(space);
	int currentSpace = 0;
	int row = 0;
	int column = 0;
	bool hitResult = false;
	char marker = ' ';

	// We go through each ship to see if the given space matches with their stored coord values
	for (Ship *currentShip : boats) {

		for (int i = 0; i < currentShip->GetSize(); ++i) {
			if (spaceValue == currentShip->GetSpace(i)) {
				hitResult = true;
			}

			if (hitResult) {

				// If we do find a ship with matching values we mark that the ship has been hit
				for (int i = 0; i < currentShip->GetSize(); ++i) {
					marker = 'x';
					currentSpace = currentShip->GetSpace(i);
					column = currentSpace % 10;
					row = (currentSpace - column) / 10;
					this->layout[row][column] = marker;

				}

				return hitResult;
			}
			else {
				// If nothing has been hit, we mark a miss
				marker = 'o';
				column = spaceValue % 10;
				row = (spaceValue - column) / 10;
				this->layout[row][column] = marker;
			}
		}
	}

	return hitResult;

}
