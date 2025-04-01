#include "Simulation.hpp"
#include <algorithm>
#include <random>
#include <SFML/Graphics.hpp>

Simulation::Simulation(int iterations, Deck deck, int place, sf::RenderWindow& window,
        sf::Text& playerText, sf::Text& dealerText, sf::Text& bestText, sf::Text& resultText,
        sf::Text& countText, sf::Text& recordTextm, sf::Text& winningsText, sf::Text& simRatioText,
        sf::Text& newShoeText)
    : Game(/* numDecks */ 4, /* firstBet */ 2, deck, window, playerText, dealerText, bestText,
        resultText, countText, recordText, winningsText, simRatioText, newShoeText),
    iterations(iterations), place(place) {
}

void Simulation::reset() {
    playerBust = false;
    dealerBust = false;
    playerBJ = false;
    dealerBJ = false;
    dbl = false;
    decision = "";
}

void Simulation::simulate() {
    for (int i=0; i<iterations; ++i) {
        // Random number
        reset();
        dealCards();

    }

    /* std::cout << results["blackjacks"] << " blackjacks, " << results["wins"] << " wins, " << results["pushes"] << " pushes, "
        << results["surrenders"] << " surrenders, " << results["losses"] << " losses.";  */

    ratio = (results["blackjacks"]*1.5 + results["wins"] - 0.5*results["surrenders"] - results["losses"]) / iterations;

    simRatioText.setString("Your edge: " + std::to_string(ratio));

}

void Simulation::dealCards() {
    std::random_device rd;  // Seed for the random number generator
    std::mt19937 g(rd());   // Mersenne Twister engine
    std::uniform_int_distribution<> rand(place, deck.size()-1);

    player.reset();
    dealer.reset();
    player[0] = deck[rand(g)];
    dealer[0] = deck[rand(g)];
    player[1] = deck[rand(g)];
    dealer[1] = deck[rand(g)];

    while (true) {
    
        if (player.total() > 21) { // player busts
            playerBust = true;
            decision = "stand";
        } else if (player.total() == 21 && player.size() == 2) { // player blackjack
            playerBJ = true;
            decision = "stand";
        } else if (dealer.total() == 21) { // dealer blackjack
            dealerBJ = true;
            decision = "stand";
        } /* else if (player[0] == player[1]) { // check split chart
            decision = split[{player[0], dealer[0]}];
        } */ else if (player.hasAce() && player.size() == 2) { // check ace chart
            decision = soft[{player.total()-11, dealer[0]}];
        } else { // check basic chart
            decision = basic[{player.total(), dealer[0]}];
        }
        
        if (decision == "hit") {
            player.addCard(deck[rand(g)]);
        } else if (decision == "double") {
            player.addCard(deck[rand(g)]);
            finishHand();
            break;
        } else {
            finishHand();
            break;
        }

    }
    
}

void Simulation::finishHand() {
    std::random_device rd;  // Seed for the random number generator
    std::mt19937 g(rd());   // Mersenne Twister engine
    std::uniform_int_distribution<> rand(place, deck.size()-1);

    while (dealer.total() < 17) {
        dealer.addCard(deck[rand(g)]);

        if (dealer.total() > 21) { // dealer busts
            dealerBust = true;
            break;
        } else if (dealer.total() >= 17 && dealer.total() <= 21) { // done, no bust
            break;
        }
    }

    if (playerBJ) { // player blackjack
        results["blackjacks"] += 1.5;
    } else if (dealerBJ) {
        results["losses"] += (1 + dbl);
    } else if (playerBust) {
        results["losses"] += (1 + dbl);
    } else if (dealerBust) {
        results["wins"] += (1 + dbl);
    } else if (decision == "split") {
        ++results["pushes"];
    } else if (decision == "surrender") {
        results["surrenders"] += 1;
    } else {
        if (player.total() > dealer.total()) {
            results["wins"] += (1 + dbl);
        } else if (player.total() < dealer.total()) {
            results["losses"] += (1 + dbl);
        } else {
            ++results["pushes"];
        }
    }
}