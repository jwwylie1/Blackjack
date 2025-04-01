#pragma once

#include <map>
#include <string>
#include <SFML/Graphics.hpp>


class Game {
public:
    Game(int numDecks, int firstBet, Deck deck_in, sf::RenderWindow& window,
        sf::Text& playerText, sf::Text& dealerText, sf::Text& bestText,
        sf::Text& resultText, sf::Text& countText, sf::Text& recordText,
        sf::Text& winningsText, sf::Text& simRatioText, sf::Text& newShoeText);
    Game(int numDecks, int firstBet, Deck deck_in);

    void reset();
    void setBet(int newBet);
    void dealCards();
    void showCards(std::string blackjackStatus);
    std::string checkBlackjack();
    void promptUser();
    void hit(bool doubled);
    void stand();
    void surrender();
    void finishHand();
    void showStats();
    int getPlayerTotal();
    int getDealerTotal();
    void showBestPlay(std::string playerDecision);
    std::string randomSuit();
    void switchHelp();
    bool helpStatus();

    static std::map<std::array<int, 2>, std::string> basic;
    static std::map<std::array<int, 2>, std::string> split;
    static std::map<std::array<int, 2>, std::string> soft;


protected:
    Deck deck;
    Hand player;
    Hand dealer;
    std::map<std::string, int> results = {
        {"winnings", 0},
        {"losses", 0},
        {"pushes", 0},
        {"blackjacks", 0}
    };
    int handsPlayed = 0;
    double ratio;
    int winnings = 0;
    int bet = 0;
    int runningCount = 0;
    double trueCount;
    int numCards = 0;
    int cardsUsed = 0;
    bool dealt = false;
    int decisions[2] = {0,0};

    bool playerDone = false;
    bool dealerDone = false;
    bool playerBust = false;
    bool dealerBust = false;
    bool playerBJ = false;
    bool dealerBJ = false;
    bool showingHelp = true;
    
    sf::RenderWindow& window;
    sf::Text& playerText;
    sf::Text& dealerText;
    sf::Text& bestText;
    sf::Text& resultText;
    sf::Text& countText;
    sf::Text& recordText;
    sf::Text& winningsText;
    sf::Text& simRatioText;
    sf::Text& newShoeText;
};