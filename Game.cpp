#include "Deck.cpp"
#include "Hand.cpp"
#include "Game.hpp"
#include "Simulation.cpp"
#include "graphics.hpp"

std::map<std::array<int, 2>, std::string> Game::basic = {
    { {5,2}, "hit"},
    { {5,3}, "hit"},
    { {5,4}, "hit"},
    { {5,5}, "hit"},
    { {5,6}, "hit"},
    { {5,7}, "hit"},
    { {5,8}, "hit"},
    { {5,9}, "hit"},
    { {5,10}, "hit"},
    { {5,11}, "hit"},
    { {6,2}, "hit"},
    { {6,3}, "hit"},
    { {6,4}, "hit"},
    { {6,5}, "hit"},
    { {6,6}, "hit"},
    { {6,7}, "hit"},
    { {6,8}, "hit"},
    { {6,9}, "hit"},
    { {6,10}, "hit"},
    { {6,11}, "hit"},
    { {7,2}, "hit"},
    { {7,3}, "hit"},
    { {7,4}, "hit"},
    { {7,5}, "hit"},
    { {7,6}, "hit"},
    { {7,7}, "hit"},
    { {7,8}, "hit"},
    { {7,9}, "hit"},
    { {7,10}, "hit"},
    { {7,11}, "hit"},
    { {8,2}, "hit"},
    { {8,3}, "hit"},
    { {8,4}, "hit"},
    { {8,5}, "hit"},
    { {8,6}, "hit"},
    { {8,7}, "hit"},
    { {8,8}, "hit"},
    { {8,9}, "hit"},
    { {8,10}, "hit"},
    { {8,11}, "hit"},
    { {9,2}, "hit"},
    { {9,3}, "double"},
    { {9,4}, "double"},
    { {9,5}, "double"},
    { {9,6}, "double"},
    { {9,7}, "hit"},
    { {9,8}, "hit"},
    { {9,9}, "hit"},
    { {9,10}, "hit"},
    { {9,11}, "hit"},
    { {10,2}, "double"},
    { {10,3}, "double"},
    { {10,4}, "double"},
    { {10,5}, "double"},
    { {10,6}, "double"},
    { {10,7}, "double"},
    { {10,8}, "double"},
    { {10,9}, "double"},
    { {10,10}, "hit"},
    { {10,11}, "hit"},
    { {11,2}, "double"},
    { {11,3}, "double"},
    { {11,4}, "double"},
    { {11,5}, "double"},
    { {11,6}, "double"},
    { {11,7}, "double"},
    { {11,8}, "double"},
    { {11,9}, "double"},
    { {11,10}, "double"},
    { {11,11}, "double"},
    { {12,2}, "hit"},
    { {12,3}, "hit"},
    { {12,4}, "stand"},
    { {12,5}, "stand"},
    { {12,6}, "stand"},
    { {12,7}, "hit"},
    { {12,8}, "hit"},
    { {12,9}, "hit"},
    { {12,10}, "hit"},
    { {12,11}, "hit"},
    { {13,2}, "stand"},
    { {13,3}, "stand"},
    { {13,4}, "stand"},
    { {13,5}, "stand"},
    { {13,6}, "stand"},
    { {13,7}, "hit"},
    { {13,8}, "hit"},
    { {13,9}, "hit"},
    { {13,10}, "hit"},
    { {13,11}, "hit"},
    { {14,2}, "stand"},
    { {14,3}, "stand"},
    { {14,4}, "stand"},
    { {14,5}, "stand"},
    { {14,6}, "stand"},
    { {14,7}, "hit"},
    { {14,8}, "hit"},
    { {14,9}, "hit"},
    { {14,10}, "hit"},
    { {14,11}, "hit"},
    { {15,2}, "stand"},
    { {15,3}, "stand"},
    { {15,4}, "stand"},
    { {15,5}, "stand"},
    { {15,6}, "stand"},
    { {15,7}, "hit"},
    { {15,8}, "hit"},
    { {15,9}, "hit"},
    { {15,10}, "surrender"},
    { {15,11}, "surrender"},
    { {16,2}, "stand"},
    { {16,3}, "stand"},
    { {16,4}, "stand"},
    { {16,5}, "stand"},
    { {16,6}, "stand"},
    { {16,7}, "hit"},
    { {16,8}, "hit"},
    { {16,9}, "surrender"},
    { {16,10}, "surrender"},
    { {16,11}, "surrender"},
    { {17,2}, "stand"},
    { {17,3}, "stand"},
    { {17,4}, "stand"},
    { {17,5}, "stand"},
    { {17,6}, "stand"},
    { {17,7}, "stand"},
    { {17,8}, "stand"},
    { {17,9}, "stand"},
    { {17,10}, "stand"},
    { {17,11}, "surrender"},
    { {18,2}, "stand"},
    { {18,3}, "stand"},
    { {18,4}, "stand"},
    { {18,5}, "stand"},
    { {18,6}, "stand"},
    { {18,7}, "stand"},
    { {18,8}, "stand"},
    { {18,9}, "stand"},
    { {18,10}, "stand"},
    { {18,11}, "stand"},
    { {19,2}, "stand"},
    { {19,3}, "stand"},
    { {19,4}, "stand"},
    { {19,5}, "stand"},
    { {19,6}, "stand"},
    { {19,7}, "stand"},
    { {19,8}, "stand"},
    { {19,9}, "stand"},
    { {19,10}, "stand"},
    { {19,11}, "stand"},
    { {20,2}, "stand"},
    { {20,3}, "stand"},
    { {20,4}, "stand"},
    { {20,5}, "stand"},
    { {20,6}, "stand"},
    { {20,7}, "stand"},
    { {20,8}, "stand"},
    { {20,9}, "stand"},
    { {20,10}, "stand"},
    { {20,11}, "stand"},
    { {21,2}, "stand"},
    { {21,3}, "stand"},
    { {21,4}, "stand"},
    { {21,5}, "stand"},
    { {21,6}, "stand"},
    { {21,7}, "stand"},
    { {21,8}, "stand"},
    { {21,9}, "stand"},
    { {21,10}, "stand"},
    { {21,11}, "stand"},
};

std::map<std::array<int, 2>, std::string> Game::split = {
    {{2,2}, "split"},
    {{2,3}, "split"},
    {{2,4}, "split"},
    {{2,5}, "split"},
    {{2,6}, "split"},
    {{2,7}, "split"},
    {{2,8}, "hit"},
    {{2,9}, "hit"},
    {{2,10}, "hit"},
    {{2,11}, "hit"},
    {{3,2}, "split"},
    {{3,3}, "split"},
    {{3,4}, "split"},
    {{3,5}, "split"},
    {{3,6}, "split"},
    {{3,7}, "split"},
    {{3,8}, "hit"},
    {{3,9}, "hit"},
    {{3,10}, "hit"},
    {{3,11}, "hit"},
    {{4,2}, "hit"},
    {{4,3}, "hit"},
    {{4,4}, "hit"},
    {{4,5}, "split"},
    {{4,6}, "split"},
    {{4,7}, "hit"},
    {{4,8}, "hit"},
    {{4,9}, "hit"},
    {{4,10}, "hit"},
    {{4,11}, "hit"},
    {{5,2}, "double"},
    {{5,3}, "double"},
    {{5,4}, "double"},
    {{5,5}, "double"},
    {{5,6}, "double"},
    {{5,7}, "double"},
    {{5,8}, "double"},
    {{5,9}, "double"},
    {{5,10}, "hit"},
    {{5,11}, "hit"},
    {{6,2}, "split"},
    {{6,3}, "split"},
    {{6,4}, "split"},
    {{6,5}, "split"},
    {{6,6}, "split"},
    {{6,7}, "hit"},
    {{6,8}, "hit"},
    {{6,9}, "hit"},
    {{6,10}, "hit"},
    {{6,11}, "hit"},
    {{7,2}, "split"},
    {{7,3}, "split"},
    {{7,4}, "split"},
    {{7,5}, "split"},
    {{7,6}, "split"},
    {{7,7}, "split"},
    {{7,8}, "hit"},
    {{7,9}, "hit"},
    {{7,10}, "hit"},
    {{7,11}, "hit"},
    {{8,2}, "split"},
    {{8,3}, "split"},
    {{8,4}, "split"},
    {{8,5}, "split"},
    {{8,6}, "split"},
    {{8,7}, "split"},
    {{8,8}, "split"},
    {{8,9}, "split"},
    {{8,10}, "split"},
    {{8,11}, "surrender"},
    {{9,2}, "split"},
    {{9,3}, "split"},
    {{9,4}, "split"},
    {{9,5}, "split"},
    {{9,6}, "split"},
    {{9,7}, "stand"},
    {{9,8}, "split"},
    {{9,9}, "split"},
    {{9,10}, "stand"},
    {{9,11}, "stand"},
    {{10,2}, "stand"},
    {{10,3}, "stand"},
    {{10,4}, "stand"},
    {{10,5}, "stand"},
    {{10,6}, "stand"},
    {{10,7}, "stand"},
    {{10,8}, "stand"},
    {{10,9}, "stand"},
    {{10,10}, "stand"},
    {{10,11}, "stand"},
    {{11,2}, "split"},
    {{11,3}, "split"},
    {{11,4}, "split"},
    {{11,5}, "split"},
    {{11,6}, "split"},
    {{11,7}, "split"},
    {{11,8}, "split"},
    {{11,9}, "split"},
    {{11,10}, "split"},
    {{11,11}, "split"},
};

std::map<std::array<int, 2>, std::string> Game::soft = {
    {{2,2}, "hit"},
    {{2,3}, "hit"},
    {{2,4}, "hit"},
    {{2,5}, "double"},
    {{2,6}, "double"},
    {{2,7}, "hit"},
    {{2,8}, "hit"},
    {{2,9}, "hit"},
    {{2,10}, "hit"},
    {{2,11}, "hit"},
    {{3,2}, "hit"},
    {{3,3}, "hit"},
    {{3,4}, "hit"},
    {{3,5}, "double"},
    {{3,6}, "double"},
    {{3,7}, "hit"},
    {{3,8}, "hit"},
    {{3,9}, "hit"},
    {{3,10}, "hit"},
    {{3,11}, "hit"},
    {{4,2}, "hit"},
    {{4,3}, "hit"},
    {{4,4}, "double"},
    {{4,5}, "double"},
    {{4,6}, "double"},
    {{4,7}, "hit"},
    {{4,8}, "hit"},
    {{4,9}, "hit"},
    {{4,10}, "hit"},
    {{4,11}, "hit"},
    {{5,2}, "hit"},
    {{5,3}, "hit"},
    {{5,4}, "double"},
    {{5,5}, "double"},
    {{5,6}, "double"},
    {{5,7}, "hit"},
    {{5,8}, "hit"},
    {{5,9}, "hit"},
    {{5,10}, "hit"},
    {{5,11}, "hit"},
    {{6,2}, "hit"},
    {{6,3}, "double"},
    {{6,4}, "double"},
    {{6,5}, "double"},
    {{6,6}, "double"},
    {{6,7}, "hit"},
    {{6,8}, "hit"},
    {{6,9}, "hit"},
    {{6,10}, "hit"},
    {{6,11}, "hit"},
    {{7,2}, "double"},
    {{7,3}, "double"},
    {{7,4}, "double"},
    {{7,5}, "double"},
    {{7,6}, "double"},
    {{7,7}, "stand"},
    {{7,8}, "stand"},
    {{7,9}, "hit"},
    {{7,10}, "hit"},
    {{7,11}, "hit"},
    {{8,2}, "stand"},
    {{8,3}, "stand"},
    {{8,4}, "stand"},
    {{8,5}, "stand"},
    {{8,6}, "double"},
    {{8,7}, "stand"},
    {{8,8}, "stand"},
    {{8,9}, "stand"},
    {{8,10}, "stand"},
    {{8,11}, "stand"},
    {{9,2}, "stand"},
    {{9,3}, "stand"},
    {{9,4}, "stand"},
    {{9,5}, "stand"},
    {{9,6}, "stand"},
    {{9,7}, "stand"},
    {{9,8}, "stand"},
    {{9,9}, "stand"},
    {{9,10}, "stand"},
    {{9,11}, "stand"},
};

Game::Game(int numDecks, int firstBet, Deck deck_in, sf::RenderWindow& window,
    sf::Text& playerText, sf::Text& dealerText, sf::Text& bestText, sf::Text& resultText,
    sf::Text& countText, sf::Text& recordText, sf::Text& winningsText, sf::Text& simRatioText,
    sf::Text& newShoeText)
        : window(window), playerText(playerText), dealerText(dealerText), bestText(bestText),
        resultText(resultText), countText(countText), recordText(recordText), winningsText(winningsText),
        simRatioText(simRatioText), newShoeText(newShoeText),
        player(ACE, ACE, window, playerText, dealerText),
        dealer(ACE, ACE, window, playerText, dealerText) {
    bet = firstBet;
    numCards = numDecks*52;
    deck = deck_in;
    deck.shuffle();
}

void Game::setBet(int newBet) {
    bet = newBet;
}

void Game::reset() {
    playerDone = false;
    dealerDone = false;
    playerBust = false;
    dealerBust = false;
    playerBJ = false;
    dealerBJ = false;
    sf::RectangleShape dealerCover = createRect(360, 90, 700, 315, sf::Color(17, 111, 55));
    sf::RectangleShape playerCover = createRect(360, 580, 700, 315, sf::Color(17, 111, 55));
    resultText.setString("");
    updateArea(window, resultText, 500, 100);
    window.draw(dealerCover);
    window.draw(playerCover);
}

void Game::dealCards() {
    if (!dealt) {
        dealt = true;
        reset();
        player.reset();
        dealer.reset();
        player[0] = deck.next();
        dealer[0] = deck.next();
        player[1] = deck.next();
        dealer[1] = deck.next();

        std::vector<Card> dealtCards = {
            player[0], player[1], dealer[0], dealer[1]
        };
    }

}

void Game::showCards(std::string blackjackStatus) {
    player.printPlayer(blackjackStatus);
    dealer.printDealer(false, blackjackStatus);

    if (blackjackStatus != "none") {
        finishHand();
    }
}

    /* if (player.total() != 21 && dealer.total() != 21) { // no blackjacks
        dealer.printDealer(false);
        promptUser();
    } else if (player.total() == 21) { // player has blackjack
        playerBJ = true;
        finishHand();
    } else { // dealer has blackjack
        dealerBJ = true;
        dealer.printDealer(true);
        finishHand();
    } */


std::string Game::checkBlackjack() {
    if (dealer.total() == 21 && dealer.size() == 2) {
        dealerBJ = true;
        if (player.total() == 21 && player.size() == 2) {
            playerBJ = true;
            return "both";
        }
        else return "dealer";
    }
    else if (player.total() == 21 && player.size() == 2) {
        playerBJ = true;
        return "player";
    }
    else return "none";
}

void Game::hit(bool doubled) {
    if (doubled) {
        bet *= 2;
        showBestPlay("Double");
    } else {
        showBestPlay("Hit");
    }

    player.addCard(deck.next());
    
    int cardNum = player.size()-1;
    Card cardRank = player[cardNum];

    sf::Texture cardTexture = createCardTexture(std::to_string(cardRank) + "_of_" + randomSuit());
    window.draw(createPlayerSprite(cardTexture, cardNum));
    
    playerText.setString(std::to_string(player.total()));

    updateArea(window, playerText, 250);

    if (player.total() == 21) { // player hits 21
        playerDone = true;
        finishHand();
    } else if (player.total() > 21) {// player goes over (busts)
        playerDone = true;
        playerBust = true;
        playerText.setString(std::to_string(player.total()) + " - BUST"); // change player text
        finishHand();
    } else if (doubled) {finishHand();}
}

void Game::stand() {
    showBestPlay("Stand");
    finishHand();
}

void Game::surrender() {
    showBestPlay("Surrender");
    bet /= 2;
    playerBust = true;
    finishHand();
}

void Game::finishHand() {

    dealer.printDealer(true, "none");
    updateArea(window, resultText, 500, 100);

    if (!playerBust) { // only do if player has real score, otherwise dealer wins
        while (dealer.total() < 17) {
            // add card and update it on screen
            dealer.addCard(deck.next());
            int cardNum = dealer.size()-1;
            Card cardRank = dealer[cardNum];
            sf::Texture cardTexture = createCardTexture(std::to_string(cardRank) + "_of_" + randomSuit());
            window.draw(createDealerSprite(cardTexture, cardNum));
            dealerText.setString(std::to_string(dealer.total()));
            updateArea(window, dealerText, 250);

            if (dealer.total() > 21) { // dealer busts
                dealerText.setString(std::to_string(dealer.total()) + " - BUST");
                updateArea(window, dealerText, 250);
                dealerBust = true;
                break;
            } else if (dealer.total() >= 17 && dealer.total() <= 21) { // done, no bust
                break;
            }
        }
    }

    if (playerBJ && dealerBJ) {
        resultText.setString("Push");
        results["pushes"] += bet;
    } else if (playerBJ) {
        resultText.setString("Blackjack");
        results["blackjacks"] += bet;
        winnings += bet*1.5;
    } else if (dealerBJ) {
        resultText.setString("Loss");
        results["losses"] += bet;
        winnings -= bet;
    } else if (playerBust) {
        resultText.setString("Loss");
        results["losses"] += bet;
        winnings -= bet;
    } else if (dealerBust) {
        resultText.setString("Win");
        results["wins"] += bet;
        winnings += bet;
    } else {
        if (player.total() > dealer.total()) {
            resultText.setString("Win");
            results["wins"] += bet;
            winnings += bet;
        } else if (player.total() < dealer.total()) {
            resultText.setString("Loss");
            results["losses"] += bet;
            winnings -= bet;
        } else {
            resultText.setString("Push");
            results["pushes"] += bet;
        }
    }

    window.draw(resultText);
    window.display();

    ++handsPlayed;
    dealt=false;

    showStats();

}

void Game::showStats() {
    for (int i=0; i<player.size(); ++i) {
        if (player[i] <= 6)
            ++runningCount;
        if (player[i] >= 10)
            --runningCount;
        ++cardsUsed;
    }
    for (int i=0; i<dealer.size(); ++i) {
        if (dealer[i] <= 6)
            ++runningCount;
        if (dealer[i] >= 10)
            --runningCount;
        ++cardsUsed;
    }

    double decksLeft = static_cast<double>(numCards-cardsUsed) / 52.0;
    trueCount = static_cast<double>(runningCount)/decksLeft;

    Simulation sim(100000, deck, cardsUsed, window, playerText, dealerText, bestText,
                    resultText, countText, recordText, winningsText, simRatioText,
                    newShoeText);
    sim.simulate();
    /* sim.simulate();
    sim.simulate();
    sim.simulate(); */

    if (winnings < 0) // for formatting
        winningsText.setString("Winnings: -$" + std::to_string(winnings*-1));
    else
        winningsText.setString("Winnings: $" + std::to_string(winnings));
    updateArea(window, winningsText, 350);

    int roundedTrueCount = std::round(trueCount);
    countText.setString("Running count: " + std::to_string(runningCount) + "\nTrue count: " + std::to_string(roundedTrueCount));
    updateCounting(window, countText, simRatioText, showingHelp);

    if (numCards-cardsUsed < 10) {
        cardsUsed = 0;
        deck.shuffle();
        newShoeText.setString("New Shoe!");
        window.draw(newShoeText);
        window.display();
    } else {
        sf::RectangleShape cover = createRect(600, 10, 400, 80, sf::Color(17, 111, 55));
        window.draw(cover);
        window.display();
    }
}

int Game::getPlayerTotal() {
    return player.total();
}

int Game::getDealerTotal() {
    return dealer.total();
}

void Game::showBestPlay(std::string playerDecision) {
    std::string decision;
    if (player.hasAce() && player.size() == 2) { // check ace chart
        decision = soft[{player.total()-11, dealer[0]}];
    } else { // check basic chart
        decision = basic[{player.total(), dealer[0]}];
    }
    decision[0] = std::toupper(decision[0]); // capitalize first letter

    if (decision == playerDecision) // improve record if right
        ++decisions[0];
    ++decisions[1];

    bestText.setString("Best choice: " + decision);
    recordText.setString("Your Score: " + std::to_string(decisions[0])
                        + "/" + std::to_string(decisions[1]) + " (" +
                        std::to_string(100*decisions[0]/decisions[1])
                        + "%)");
    updateArea(window, bestText, 350);
    updateArea(window, recordText, 350);
}

std::string Game::randomSuit() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);
    int rand = dis(gen);
    
    if (rand==0) {return "spades";}
    else if (rand==1) {return "hearts";}
    else if (rand==2) {return "clubs";}
    else {return "diamonds";}
}

void Game::switchHelp() {
    showingHelp = !showingHelp;
}

bool Game::helpStatus() { return showingHelp; }