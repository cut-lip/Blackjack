/*
	Nicholas Cutlip
	CS 361
	Assignment #7
	game.cpp
	Cpp file for the definitions of the game class.
*/

#include "game.h"

// Constructor to set initial game state
game::game() : gameDeck(), dealerHand(), playerHand(), currentRound(1)
{
	cout << "*~~ Welcome to Blackjack ~~*\n\n" << "What is your name, player ?" << endl;
	cin >> playerName;		// Seeks input for player's name

	mainLoop();
}

// (private) Main game loop (started by the class constructor)
// (note its not a loop yet in this simplified implementation
void game::mainLoop()
{
	// Player should initially be dealt two cards
	cout << "\n" + playerName + " is dealt two cards.\n" << endl;
	hit(playerHand);
	hit(playerHand);

	// Display player's initial hand
	cout << playerName << "'s hand:\n";
	playerHand.drawHand();
	cout << endl;

	// Determine if the player will hit or stand
	int hitOrStand;
	cout << "Enter (1) for Hit or (0) for Stand:" << endl;
	cin >> hitOrStand;

	// NOTE THAT YOU HAVE TO ACTUALLY CHECK THE VALUE OF THE PLAYER'S HAND AT SOME POINT
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!

	// While the player chooses to hit
	while (hitOrStand == 1) {
		hit(playerHand);

		cout << "Enter (1) for Hit or (0) for Stand:" << endl;
		cin >> hitOrStand;
	}

	// Increment currentRound by 1
	currentRound++;
}

// (private) A single player or dealer's turn
// (for future use, not implemented uet in this simple version)
void game::turn()
{

}

// Deal another card to the given hand
void game::hit(hand& currHand)		// NOTE: YOU HAD TO PASS BY REFERENCE HERE OR HAND ISN'T MODIFIED
{
	currHand.addCardToHand(gameDeck.dealCard());
}