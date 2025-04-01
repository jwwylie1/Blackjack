#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

bool dealt = false;
std::vector<Card> dealtCards;
std::vector<sf::Texture> playerCards;
std::vector<sf::Texture> dealerCards;
std::string blackjackStatus;
int playerCount;
int dealerCount;

const sf::Vector2f CARD_SCALE(0.4f, 0.4f);
const sf::Vector2f BTN_SCALE(0.34f, 0.34f);

const double CARD_OFFSET = 200;

// Function to create a text box
sf::Text createTextBox(const std::string& content, const sf::Font& font, unsigned int size, sf::Color color, float x, float y) {
    sf::Text text;
    text.setFont(font);
    text.setString(content);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setPosition(x, y);
    return text;
}

// Function to create a button
sf::RectangleShape createRect(float x, float y, float width, float height, sf::Color color) {
    sf::RectangleShape button(sf::Vector2f(width, height));
    button.setPosition(x, y);
    button.setFillColor(color);
    return button;
}

sf::Texture createCardTexture(const std::string& imagePath) {
    sf::Texture texture;
    texture.loadFromFile("./images/" + imagePath + ".png");
    return texture;
}

sf::Sprite createButton(float x, float y, const std::string& imagePath) {
    sf::Texture btnTexture;
    btnTexture.loadFromFile("./images/" + imagePath + ".png");
    sf::Sprite button(btnTexture);
    button.setPosition(x, y);
    return button;
}

sf::Sprite createPlayerSprite(sf::Texture texture, int cardNum) {
    sf::Sprite spr(texture);
    spr.scale(CARD_SCALE);
    spr.setPosition((380 + cardNum*60),590);
    return spr;
}

sf::Sprite createDealerSprite(sf::Texture texture, int cardNum) {
    sf::Sprite spr(texture);
    spr.scale(CARD_SCALE);
    spr.setPosition((380 + cardNum*60),100);
    return spr;
}

//sf::RectangleShape statusCover(sf::Vector2f(350,30));
sf::RectangleShape statusCover = createRect(20, 100, 350, 30, sf::Color(17, 111, 55));

void updateArea(sf::RenderWindow &window, const sf::Text &area) {
    sf::RectangleShape cover(sf::Vector2f(area.getGlobalBounds().width+15, area.getGlobalBounds().height+15));
    cover.setPosition(area.getPosition());
    cover.setFillColor(sf::Color(17, 111, 55)); // Match window background
    window.draw(cover);
    window.draw(area);
    window.display();
}

void updateArea(sf::RenderWindow &window, const sf::Text &area, int width) {
    sf::RectangleShape cover(sf::Vector2f(width, area.getGlobalBounds().height+15));
    cover.setPosition(area.getPosition());
    cover.setFillColor(sf::Color(17, 111, 55)); // Match window background
    window.draw(cover);
    window.draw(area);
    window.display();
}

void updateArea(sf::RenderWindow &window, const sf::Text &area, int width, int height) {
    sf::RectangleShape cover(sf::Vector2f(width, height));
    cover.setPosition(area.getPosition());
    cover.setFillColor(sf::Color(17, 111, 55)); // Match window background
    window.draw(cover);
    window.draw(area);
    window.display();
}

void updateArea(sf::RenderWindow &window, const sf::RectangleShape &area) {
    sf::RectangleShape cover(sf::Vector2f(area.getGlobalBounds().width+10, area.getGlobalBounds().height+10));
    cover.setPosition(area.getPosition());
    cover.setFillColor(sf::Color(17, 111, 55)); // Match window background
    window.draw(cover);
    window.draw(area);
    window.display();
}

void updateArea(sf::RenderWindow &window, const sf::Sprite &area) {
    sf::RectangleShape cover(sf::Vector2f(area.getGlobalBounds().width+10, area.getGlobalBounds().height+10));
    cover.setPosition(area.getPosition());
    cover.setFillColor(sf::Color(17, 111, 55)); // Match window background
    window.draw(cover);
    window.draw(area);
    window.display();
}

void updateBet(sf::RenderWindow& window, sf::Text& betText, int currentBet) {
    betText.setString("Current Bet: $" + std::to_string(currentBet));
    updateArea(window, betText, 350);
}

void updateCounting(sf::RenderWindow &window, const sf::Text &countText,
                    const sf::Text &ratioText, bool showing) {

    sf::RectangleShape cover(sf::Vector2f(300, 100));
    cover.setPosition(countText.getPosition());
    cover.setFillColor(sf::Color(17, 111, 55)); // Match window background
    window.draw(cover);

    if (showing) {
        window.draw(countText);
        window.draw(ratioText);
    }
    window.display();
}