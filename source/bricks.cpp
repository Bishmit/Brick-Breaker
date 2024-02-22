#include "../header/bricks.h"

bricks::bricks(): flag(false),store(0), score(0)
{
	if (!bricktexture.loadFromFile("Assets/Images/brick.png")) {
		std::cout << "Error loading brick" << "\n"; 
	}

    // defining the block properties
    int blockwidth = 50;
    int blockheight = 30;
    int startX = 80;
    int startY = 100;

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (MATRIX[row][col] == 1) {
                float positionX = static_cast<float>(startX) + static_cast<float>(col) * blockwidth;
                float positionY = static_cast<float>(startY) + static_cast<float>(row) * blockheight;
                sf::Vector2f position(positionX, positionY);
                blocks[row][col].setTexture(bricktexture);
                blocks[row][col].setPosition(position);
                blocks[row][col].setScale(sf::Vector2f(0.5f, 0.5f));
            }
        }
    }
    // font for score 
    if (!font.loadFromFile("Assets/Font/PixellettersFull.ttf")) {
        std::cout << "Error: Font could not be loaded!" << std::endl;
    }
    text.setFont(font);
    text.setString("Score: " + std::to_string(this->score));
    text.setCharacterSize(34);
    text.setFillColor(sf::Color::White);
    text.setPosition(370.f, 5.f);
}

void bricks::update(player& ba) {
    // Logic for brick collision detection
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (MATRIX[row][col] == 1) {
                // Check if the player's bounds intersect with the current brick's bounds
                if (ba.getbounds().intersects(blocks[row][col].getGlobalBounds())) {
                    ba.makedirectionchange();
                    MATRIX[row][col] = 0;
                    score++;
                    text.setString("Score: " + std::to_string(this->score));
                    if (score == (ROWS * COLS) - 10) std::cout << "Gameover" << "\n"; 
                    break;
                }
            }
        }
    }
}


void bricks::render(sf::RenderWindow* window, player& ba) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (MATRIX[row][col] == 1) {
                if (!ba.getbounds().intersects(blocks[row][col].getGlobalBounds())) {
                    window->draw(blocks[row][col]);
                }
            }
        }
    }
    window->draw(text); 
}
