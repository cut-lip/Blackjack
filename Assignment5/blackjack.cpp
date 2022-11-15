/*
    Nicholas Cutlip
    CS 361
    Assignment #8
    main.cpp
    Implements Blackjack gameplay logic.
*/

#include <iostream>
#include "card.h"
#include "deck.h"
#include "hand.h"

using namespace std;

// ******************************* HELPER METHODS **************************************
// *************************************************************************************

// Display given hand with identifying message
void displayHand(hand currHand, string who) {

    if (who == "player") {
        cout << "\nPlayer's hand:\n";
        currHand.drawHand();
    }
    else {
        cout << "\nDealer's hand:\n";
        currHand.drawHand();
    }
}

// Determine if current hand is a bust
bool isBust(hand currHand) {

    bool isBust;
    // Ternary expression to check if the hand's low value is greater than 21, or not
    (currHand.handValueLow() > 21) ? (isBust = true) : (isBust = false);

    return isBust;        // Return the result of the evaluation
}

// Present the winner
void presentWinner(string winner) {
    cout << "\n" << winner << " is the winner!" << endl;
}

// Deal another card to the given hand
// NOTE: MUST PASS BY REFERENCE HERE OR HAND ISN'T MODIFIED
void hit(hand& currHand, deck gameDeck) {
    currHand.addCardToHand(gameDeck.dealCard());
}

int main()
{
    // Name of player
    string playerName = "";
    // Deck of cards for use in the game
    auto gameDeck = make_unique<deck>();
    // Hands of cards for use in the game
    auto playerHand = make_unique<hand>();
    auto dealerHand = make_unique<hand>();

    cout << "*~~ Welcome to Blackjack ~~*\n\n" << "What is your name, player?" << endl;
    cin >> playerName;        // Seeks input for player's name

    // Deal one card to player and display on console
    cout << "\n" + playerName + " is dealt a card." << endl;
    hit(*playerHand, *gameDeck);
    displayHand(*playerHand, "player");

    // Deal one card to dealer and display on console
    cout << "\nDealer is dealt a card." << endl;
    hit(*dealerHand, *gameDeck);
    displayHand(*dealerHand, "dealer");

    // Deal another card to player and display player hand
    cout << "\n" + playerName + " is dealt a card." << endl;
    hit(*playerHand, *gameDeck);
    displayHand(*playerHand, "player");

    // Deal another card to dealer (don't display value)
    cout << "\nDealer is dealt a card.\n" << endl;
    hit(*dealerHand, *gameDeck);

    // Check if the player's hand is a blackjack
    if (playerHand->handValueHigh() == 21) {
        cout << "\n" << playerName << " has a blackjack. "
            << playerName << " wins!!!" << endl;
        return 0;
    }

    // PLAYERS TURN:
    // Determine if the player will hit or stand
    int hitOrStand;
    cout << "Enter (1) for Hit or (0) for Stand:" << endl;
    cin >> hitOrStand;

    // While the player chooses to hit
    while (hitOrStand == 1) {
        hit(*playerHand, *gameDeck);

        displayHand(*playerHand, "player");

        if (isBust(*playerHand)) {
            cout << "\nWith a hand value of " << playerHand->handValueLow()
                << " " << playerName << " has busted!" << endl;

            presentWinner("Dealer");
            return 0;
        }

        // Determine if player will hit or stand
        cout << "\nEnter (1) for Hit or (0) for Stand:" << endl;
        cin >> hitOrStand;
    }

    // DEALER'S TURN:
    // Display the dealer's entire hand
    displayHand(*dealerHand, "dealer");

    // Check if the dealer has a blackjack
    if (dealerHand->handValueHigh() == 21) {
        cout << "\nDealer has a blackjack. Dealer wins... :(" << endl;
        return 0;
    }

    // Hit the dealer's hand until it reaches the specified range ( value > 16 )
    while (dealerHand->handValueLow() < 17) {
        hit(*dealerHand, *gameDeck);
    }

    // Check if the dealer's hand is a bust
    if (isBust(*dealerHand)) {
        cout << "\nWith a hand value of " << dealerHand->handValueLow()
            << " Dealer has busted!" << endl;

        presentWinner(playerName);
        return 0;
    }
    // Otherwise, dealer stands

    // Display the player and dealer's highest values
    cout << "\n" << playerName << "'s highest value is " << playerHand->handValueHigh() << endl;
    cout << "\nDealer's highest value is " << dealerHand->handValueHigh() << endl;

    // Check for a tie
    if (playerHand->handValueHigh() == dealerHand->handValueHigh()) {
        cout << "The game is a push! " << playerName << " and Dealer tie! Woohoo!" << endl;
        return 0;
    }

    // Check if the player beat the dealer, or the other way around
    (playerHand->handValueHigh() > dealerHand->handValueHigh())
        ? (presentWinner(playerName)) : (presentWinner("Dealer"));

    return 0;
}


