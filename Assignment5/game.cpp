/*
    Nicholas Cutlip
    CS 361
    Assignment #7
    game.cpp
    Cpp file for the definitions of the game class.
*/

#include "game.h"

// Constructor to set initial game state
game::game() : gameDeck(), dealerHand(), playerHand() {
    cout << "*~~ Welcome to Blackjack ~~*\n\n" << "What is your name, player?" << endl;
    cin >> playerName;        // Seeks input for player's name

    mainLoop();
}

// Main game loop (initiated by class constructor)
// (note it is not a loop yet in this simplified implementation)
void game::mainLoop() {

    // Deal one card to player and display on console
    cout << "\n" + playerName + " is dealt a card.\n" << endl;
    hit(playerHand);
    displayHand(playerHand, "player");
    
    // Deal one card to dealer and display on console
    cout << "\nDealer is dealt a card.\n" << endl;
    hit(dealerHand);
    displayHand(dealerHand, "dealer");

    // Deal another card to player and display player hand
    cout << "\n" + playerName + " is dealt a card.\n" << endl;
    hit(playerHand);
    displayHand(playerHand, "player");

    // Deal another card to dealer (don't display value)
    cout << "\nDealer is dealt a card.\n" << endl;
    hit(dealerHand);

    // Check if the player's hand is a blackjack
    if (playerHand.handValueHigh() == 21) {
        cout << "\n" << playerName << " has a blackjack. "
            << playerName << " wins!!!" << endl;
        return;
    }

    // PLAYERS TURN:
    // Determine if the player will hit or stand
    int hitOrStand;
    cout << "Enter (1) for Hit or (0) for Stand:" << endl;
    cin >> hitOrStand;

    // While the player chooses to hit
    while (hitOrStand == 1) {
        hit(playerHand);

        displayHand(playerHand, "player");

        if (isBust(playerHand)) {
            cout << "With a hand value of " << playerHand.handValueHigh() << " " << playerName << " has busted!" << endl;
            presentWinner("Dealer");
            return;
        }

        // Determine if player will hit or stand
        cout << "\nEnter (1) for Hit or (0) for Stand:" << endl;
        cin >> hitOrStand;
    }

    // DEALER'S TURN
    // Display the dealer's entire hand
    displayHand(dealerHand, "dealer");

    // Check if the dealer has a blackjack
    if (dealerHand.handValueHigh() == 21) {
        cout << "Dealer has a blackjack. Dealer wins... :(" << endl;
        return;
    }

    // Hit the dealer's hand until it reaches the specified range ( value > 16 )
    while (dealerHand.handValueHigh() < 17) {
        hit(dealerHand);
    }

    // Check if the dealer's hand is a bust
    if (isBust(dealerHand)) {
        cout << "With a hand value of " << dealerHand.handValueHigh() << " Dealer has busted!" << endl;
        presentWinner(playerName);
        return;
    }
    // Otherwise, dealer stands

    // Display the player and dealer's highest values
    cout << "\n" << playerName << "'s highest value is " << playerHand.handValueHigh() << endl;
    cout << "\nDealer's highest value is " << dealerHand.handValueHigh() << endl;

    // Check for a tie
    if (playerHand.handValueHigh() == dealerHand.handValueHigh()) {
        cout << "The game is a push! " << playerName << " and Dealer tie! Woohoo!" << endl;
        return;
    }

    // Check if the player beat the dealer, or the other way around
    (playerHand.handValueHigh() > dealerHand.handValueHigh()) ? (presentWinner(playerName)) : (presentWinner("Dealer"));
}

// Display given hand with identifying message
void game::displayHand(hand currHand, string who) {

    if (who == "player") {
        cout << playerName << "'s hand:\n";
        playerHand.drawHand();
        cout << endl;
    }
    else {
        cout <<"Dealer's hand:\n";
        dealerHand.drawHand();
        cout << endl;
    }
}

// Determine if current hand is a bust
bool game::isBust(hand currHand) {

    bool isBust;
    // Ternary expression to check if the hand's low value is greater than 21, or not
    (currHand.handValueLow() > 21) ? (isBust = true) : (isBust = false);

    return isBust;        // Return the result of the evaluation
}

// Present the winner
void game::presentWinner(string winner) {
    cout << "\n" << winner << " is the winner!" << endl;
}

/*
// A single player or dealer's turn
// (for future use, not implemented yet in this simple version)
void game::turn() {}
*/

// Deal another card to the given hand
void game::hit(hand& currHand) {       // NOTE: YOU HAD TO PASS BY REFERENCE HERE OR HAND ISN'T MODIFIED
    currHand.addCardToHand(gameDeck.dealCard());
}