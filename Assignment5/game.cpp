/*
	Nicholas Cutlip
	CS 361
	Assignment #7
	game.cpp
	Cpp file for the definitions of the game class.
*/

#include "game.h"

// Constructor to set initial game state
game::game() : gameDeck(), dealerHand(), playerHand()
{
	cout << "*~~ Welcome to Blackjack ~~*\n\n" << "What is your name, player?" << endl;
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
	displayHand(playerHand);

	// Determine if the player will hit or stand
	int hitOrStand;
	cout << "Enter (1) for Hit or (0) for Stand:" << endl;
	cin >> hitOrStand;

	// While the player chooses to hit
	while (hitOrStand == 1) {
		hit(playerHand);

		displayHand(playerHand);

		if (isBust(playerHand)) {
			presentWinner("Dealer");
			break;
		}

		// Determine if player will hit or stand
		cout << "Enter (1) for Hit or (0) for Stand:" << endl;
		cin >> hitOrStand;
	}

	// Perform dealer turn internally
	// Deal two cards to dealer
	hit(dealerHand);
	hit(dealerHand);


	// Hit the dealer's hand until it reaches the specified range ( value > 16 )
	while (dealerHand.handValueHigh() < 17) {
		hit(dealerHand);
	}

	// Check if the dealer's hand is a bust
	if (isBust(dealerHand)) {
		presentWinner(playerName);
	}
	// Otherwise, dealer stands

	// Compare dealer and player hand values
	//( !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!)
	// IS it okay for high values to be over 21 here?

	// Check if the player beat the dealer, or the other way around
	(playerHand.handValueHigh() > dealerHand.handValueHigh()) ? (presentWinner(playerName)) : (presentWinner("dealer"));
}

// Display player's hand
void game::displayHand(hand currHand)
{
	cout << playerName << "'s hand:\n";
	playerHand.drawHand();
	cout << endl;
}

// Determine if current hand is a bust
bool game::isBust(hand currHand)
{
	// If high vale is over 21, so is low value
	if (currHand.handValueLow() > 21) {
		// Return true, currHand is a bust
		return true;
	}
	
	// Return false, currHand is not a bust
	return false;
}

// Present the winner
void game::presentWinner(string winner) {
	cout << "\n" << winner << " is the winner!" << endl;
}

// A single player or dealer's turn
// (for future use, not implemented yet in this simple version)
void game::turn()
{

}

// Deal another card to the given hand
void game::hit(hand& currHand)		// NOTE: YOU HAD TO PASS BY REFERENCE HERE OR HAND ISN'T MODIFIED
{
	currHand.addCardToHand(gameDeck.dealCard());
}