#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Game.cpp"

// g++ main.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

int main(int argc, char* argv[]) {

    int num_decks_in = 6;
    int initial_bet = 1000;

    if (argc > 3) {
        std::cout << "RUN FAILED: ./sfml-app [NUMBER OF DECKS] [INITIAL BET]";
        return 1;
    }

    if (argc > 1) {
        if (std::stoi(argv[1]) > 10 || std::stoi(argv[1]) < 1) {
            std::cout << "RUN FAILED: Number of decks must be between 1 and 10";
            return 1;
        }
        num_decks_in = std::stoi(argv[1]);
    }

    if (argc == 3) {
        if (std::stoi(argv[2]) > 10000 || std::stoi(argv[2]) < 100) {
            std::cout << "RUN FAILED: Initial bet must be between 100 and 10,000";
            return 1;
        }
        initial_bet = std::stoi(argv[2]);
    }

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1500, 900), "Card Counting Simulator");

    // Load a font
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
        return -1;
    }

    // Initialize game variables
    int winnings = 0;
    int currentBet = 0;
    std::string playerChoice = "";
    std::string bestChoice = "";

    // Create text boxes for stats
    sf::Text winningsText = createTextBox("Winnings: $" + std::to_string(winnings), font, 24, sf::Color::White, 20, 20);
    sf::Text betText = createTextBox("Current Bet: $" + std::to_string(initial_bet), font, 24, sf::Color::White, 20, 60);
    sf::Text playerChoiceText = createTextBox("Player choice: " + playerChoice, font, 24, sf::Color::White, 20, 100);
    sf::Text bestChoiceText = createTextBox("Best choice:   " + bestChoice, font, 24, sf::Color::White, 20, 140);
    sf::Text decisionPercentageText = createTextBox("Your Score: 0/0 (0%)", font, 24, sf::Color::White, 20, 180);

    sf::Text countsText = createTextBox("Running count: 0\nTrue count: 0", font, 24, sf::Color::White, 20, 240);
    sf::Text simRatioText = createTextBox("Your edge: -", font, 24, sf::Color::White, 20, 310);
    sf::Text newShoeText = createTextBox("", font, 60, sf::Color::White, 600, 10);

    sf::Texture hitTexture;
    hitTexture.loadFromFile("./images/hitbtn.png");
    sf::Sprite hitBtn(hitTexture);
    hitBtn.setPosition(50, 590);
    hitBtn.scale(BTN_SCALE);

    sf::Texture standTexture;
    standTexture.loadFromFile("./images/standbtn.png");
    sf::Sprite standButton(standTexture);
    standButton.setPosition(210, 590);
    standButton.scale(BTN_SCALE);

    sf::Texture dblTexture;
    dblTexture.loadFromFile("./images/dblbtn.png");
    sf::Sprite doubleButton(dblTexture);
    doubleButton.setPosition(50, 750);
    doubleButton.scale(BTN_SCALE);

    sf::Texture surrTexture;
    surrTexture.loadFromFile("./images/surrenderbtn.png");
    sf::Sprite surrenderButton(surrTexture);
    surrenderButton.setPosition(210, 750);
    surrenderButton.scale(BTN_SCALE);

    sf::Texture nhTexture;
    nhTexture.loadFromFile("./images/nexthandbtn.png");
    sf::Sprite nextHandButton(nhTexture);
    nextHandButton.setPosition(71, 470);
    nextHandButton.scale(sf::Vector2f(0.25f, 0.25f));

    sf::Texture scTexture;
    scTexture.loadFromFile("./images/chButton.png");
    sf::Sprite showCountingButton(scTexture);
    showCountingButton.setPosition(71, 360);
    showCountingButton.scale(sf::Vector2f(0.25f, 0.25f));

    sf::Texture texture100;
    texture100.loadFromFile("./images/chip100.png");
    sf::Sprite chip100(texture100);
    chip100.setPosition(1270,30);
    chip100.scale(sf::Vector2f(0.39f,0.39f));

    sf::Texture texture500;
    texture500.loadFromFile("./images/chip500.png");
    sf::Sprite chip500(texture500);
    chip500.setPosition(1270,200);
    chip500.scale(sf::Vector2f(0.39f,0.39f));

    sf::Texture texture1000;
    texture1000.loadFromFile("./images/chip1000.png");
    sf::Sprite chip1000(texture1000);
    chip1000.setPosition(1270,370);
    chip1000.scale(sf::Vector2f(0.39f,0.39f));

    sf::Texture texture2500;
    texture2500.loadFromFile("./images/chip2500.png");
    sf::Sprite chip2500(texture2500);
    chip2500.setPosition(1270,540);
    chip2500.scale(sf::Vector2f(0.39f,0.39f));

    sf::Texture texture10000;
    texture10000.loadFromFile("./images/chip10000.png");
    sf::Sprite chip10000(texture10000);
    chip10000.setPosition(1270,710);
    chip10000.scale(sf::Vector2f(0.39f,0.39f));


    sf::Text dealerCountText = createTextBox("", font, 50, sf::Color::White, 480, 410);
    sf::Text playerCountText = createTextBox("", font, 50, sf::Color::White, 480, 490);
    sf::Text handResultText = createTextBox("", font, 70, sf::Color::White, 720, 430);

    sf::Texture cardBack = createCardTexture("back");

    // Clear the window
    window.clear(sf::Color(17, 111, 55));

    //window.draw(createCardSprite(card1, 0));

    // Draw stats
    window.draw(winningsText);
    window.draw(betText);
    window.draw(playerChoiceText);
    window.draw(bestChoiceText);
    window.draw(decisionPercentageText);
    window.draw(countsText);
    window.draw(simRatioText);
    window.draw(handResultText);
    window.draw(newShoeText);

    // Draw buttons
    //window.draw(hitButton);
    window.draw(hitBtn);
    window.draw(standButton);
    window.draw(doubleButton);
    window.draw(surrenderButton);
    //window.draw(newGameButton);
    //window.draw(hitText);
    //window.draw(standText);
    //window.draw(doubleText);
    //window.draw(surrenderText);
    window.draw(nextHandButton);
    window.draw(showCountingButton);
    window.draw(chip100);
    window.draw(chip500);
    window.draw(chip1000);
    window.draw(chip2500);
    window.draw(chip10000);
    //window.draw(nextHandText);

    Deck newDeck(num_decks_in);
        Game game(num_decks_in, initial_bet, newDeck, window, playerCountText, dealerCountText, bestChoiceText,
        handResultText, countsText, decisionPercentageText, winningsText, simRatioText, newShoeText);

        //playerCards.reserve(10);
        //dealerCards.reserve(10);

        game.dealCards();
        blackjackStatus = game.checkBlackjack();
        game.showCards(blackjackStatus);

    window.display();

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Handle mouse clicks
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                // Check if the "Hit" button is clicked
                if (hitBtn.getGlobalBounds().contains(mousePos)) {
                    playerChoice = "Hit";
                    playerChoiceText.setString("Player choice: " + playerChoice);
                    updateArea(window, playerChoiceText, 350);
                    dealt = true;
                    game.hit(false);
                }

                // Check if the "Stand" button is clicked
                if (standButton.getGlobalBounds().contains(mousePos)) {
                    playerChoice = "Stand";
                    playerChoiceText.setString("Player choice: " + playerChoice);
                    updateArea(window, playerChoiceText, 350);
                    game.stand();
                }

                // Check if the "Double" button is clicked
                if (doubleButton.getGlobalBounds().contains(mousePos)) {
                    playerChoice = "Double";
                    playerChoiceText.setString("Player choice: " + playerChoice);
                    updateArea(window, playerChoiceText, 350);
                    game.hit(true);
                }

                // Check if the "Surrender" button is clicked
                if (surrenderButton.getGlobalBounds().contains(mousePos)) {
                    playerChoice = "Surrender";
                    playerChoiceText.setString("Player choice: " + playerChoice);
                    updateArea(window, playerChoiceText, 350);
                    game.surrender();
                }

                // Check if the "New Game" button is clicked
                if (nextHandButton.getGlobalBounds().contains(mousePos)) {
                    currentBet += 1;
                    game.dealCards();
                    blackjackStatus = game.checkBlackjack();
                    game.showCards(blackjackStatus);
                }

                if (showCountingButton.getGlobalBounds().contains(mousePos)) {
                    game.switchHelp();
                    updateCounting(window, countsText, simRatioText, game.helpStatus());
                }

                // bets
                if (chip100.getGlobalBounds().contains(mousePos)) {
                    currentBet = 100;
                    updateBet(window, betText, currentBet);
                    game.setBet(currentBet);
                }
                if (chip500.getGlobalBounds().contains(mousePos)) {
                    currentBet = 500;
                    updateBet(window, betText, currentBet);
                    game.setBet(currentBet);
                }
                if (chip1000.getGlobalBounds().contains(mousePos)) {
                    currentBet = 1000;
                    updateBet(window, betText, currentBet);
                    game.setBet(currentBet);
                }
                if (chip2500.getGlobalBounds().contains(mousePos)) {
                    currentBet = 2500;
                    updateBet(window, betText, currentBet);
                    game.setBet(currentBet);
                }
                if (chip10000.getGlobalBounds().contains(mousePos)) {
                    currentBet = 10000;
                    updateBet(window, betText, currentBet);
                    game.setBet(currentBet);
                }
            }
        }
    }

    return 0;
}