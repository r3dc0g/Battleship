#include "Board.h"
#include "ShipBoard.h"
#include <string>
#include <vector>
using namespace std;

#ifndef PLAYER_H
#define	PLAYER_H

class Player {
	public:
		Player(string player);					// We construct the player object with the known type of the player, whether human or computer
		void MakeAttack(string space, ShipBoard &enemyShips); 	// Function that makes the attack, taking in what space to attack and the enemy ship board so it can compare the two
		Board GetHitBoard();					// Returns the hit board, aka the board with only markers on them
		void PrintBoards();					// Prints both boards, the board with ships and the board only with markers
		int SpaceConverter(string space);			// Function to convert a string space like "A7" to a meaningful number value
		ShipBoard shipBoard;					// The Ship board object is made public because of how much the other player needs access to it
		bool CheckGame();					// Function that check whether the player has won
		string GenerateMove();					// Generates a move is the player is a computer
		bool CheckInput(string space);				// Checks the input if its valid


	private:
		vector<int> doNotPick;					// Vector of spaces that can't be picked because they've aready been pick or are part of a sunk ship
		string playerType;					// Player type, either human or computer
		Board hitBoard;						// The board with only markers
		int score = 0;						// The Score. If the player hits 5, they win



};

#endif
