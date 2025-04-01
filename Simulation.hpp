#ifndef SIMULATION_HPP
#define SIMULATION_HPP
#include <map>
#include <array>
#include <SFML/Graphics.hpp>


class Simulation : public Game {
public:
    Simulation(int iterations, Deck deck, int place, sf::RenderWindow& window,
        sf::Text& playerText, sf::Text& dealerText, sf::Text& bestText, sf::Text& resultText,
    sf::Text& countText, sf::Text& recordText, sf::Text&winningsText, sf::Text& simRatioText,
    sf::Text& newShoeText);
    void simulate();
    void dealCards();
    void finishHand();
    void reset();

private:
    int iterations;
    int place;
    double ratio;
    std::string decision;
    bool dbl = false;
    std::map<std::string, int> results = {
        {"winnings", 0},
        {"losses", 0},
        {"pushes", 0},
        {"blackjacks", 0},
        {"surrenders", 0}
    };
};

/*class Simulation {
public:
    Simulation(int iterations, Deck deck, int place);

    void simulate();

    void dealCards();

    void finishHand();

    void reset();

private:
    int iterations;
    Deck deck;
    int place;
    Hand player;
    Hand dealer;

    double ratio;
    std::string decision;

    std::map<std::array<int, 2>, std::string> basic;
    std::map<std::array<int, 2>, std::string> split;
    std::map<std::array<int, 2>, std::string> soft;
    // {player total, dealer card}
    bool playerBJ = false;
    bool dealerBJ = false;
    bool playerBust = false;
    bool dealerBust = false;
    bool dbl = false;

    std::map<std::string, int> results = {
        {"winnings", 0},
        {"losses", 0},
        {"pushes", 0},
        {"blackjacks", 0},
        {"surrenders", 0}
    };

};*/

#endif // SIMULATION_HPP