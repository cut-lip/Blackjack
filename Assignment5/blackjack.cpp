/*
    Nicholas Cutlip
    CS 361
    Assignment #8
    blackjack.cpp
    Implements Blackjack gameplay logic.
*/

#include <iostream>
#include "card.h"
#include "deck.h"
#include "hand.h"

using namespace std;

// ******************************* HELPER FUNCTIONS **************************************
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

//Determine whether to use high or low hand value
int handValue(hand currHand) {
    int val;
    currHand.handValueHigh() > 21 ?
        val = currHand.handValueLow() : val = currHand.handValueHigh();
}

// Determine if current hand is a bust
bool isBust(hand currHand) {

    bool isBust;
    // Ternary expression to check if the hand's low value is greater than 21, or not
    (currHand.handValueLow() > 21) ? (isBust = true) : (isBust = false);

    return isBust;        // Return the result of the evaluation
}

// Deal another card to the given hand
// NOTE: MUST PASS BY REFERENCE HERE OR HAND ISN'T MODIFIED
void hit(hand& currHand, deck gameDeck) {
    currHand.addCardToHand(gameDeck.dealCard());
}

// ********************************** MAIN FUNCTION **************************************
// *************************************************************************************
// Implements Blackjack gameplay logic
int main() {

    // Name of player
    string playerName = "";
    // Unique pointer to deck of cards for use in the game
    auto gameDeck = make_unique<deck>();
    // Unique pointers to hands of cards for use in the game
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
    cout << "\n" + playerName + " is dealt another card." << endl;
    hit(*playerHand, *gameDeck);
    displayHand(*playerHand, "player");

    // Deal another card to dealer (don't display value)
    cout << "\nDealer is dealt another card.\n" << endl;
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

        // Check if the player's hand is a bust
        if (isBust(*playerHand)) {
            cout << "\nWith a hand value of " << playerHand->handValueLow()
                << " " << playerName << " has busted!" << endl;

            cout << "\n" << "Dealer is the winner!" << endl;
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
        displayHand(*dealerHand, "dealer");
    }

    // Check if the dealer's hand is a bust
    if (isBust(*dealerHand)) {
        cout << "\nWith a hand value of " << dealerHand->handValueLow()
            << " Dealer has busted!" << endl;

        cout << "\n" << playerName << " is the winner!" << endl;
        return 0;
    }
    // Otherwise, dealer stands

    // Determine whether player and dealer will use high or low hand values
    short playerFinalValue;
    short dealerFinalValue;

    playerHand->handValueHigh() > 21 ?
        playerFinalValue = playerHand->handValueLow() : playerFinalValue = playerHand->handValueHigh();

    dealerHand->handValueHigh() > 21 ?
        dealerFinalValue = dealerHand->handValueLow() : dealerFinalValue = dealerHand->handValueHigh();

    // Display the player's and dealer's highest values
    cout << "\n" << playerName << "'s highest value is " << playerFinalValue << endl;
    cout << "\nDealer's highest value is " << dealerFinalValue << endl;

    // Check for a tie
    if (playerFinalValue == dealerFinalValue) {
        cout << "The game is a push! " << playerName << " and Dealer tie! Woohoo!" << endl;
        return 0;
    }

    // Check if the player beat the dealer, or the other way around
    playerFinalValue > dealerFinalValue ?
        cout << "\n" << playerName << " is the winner!" << endl : cout << "\n" << "Dealer is the winner!" << endl;

    return 0;
}


