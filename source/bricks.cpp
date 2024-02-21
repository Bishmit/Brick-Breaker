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
                sf::Vector2f position(startX + col * blockwidth, startY + row * blockheight);
                blocks[row][col].setTexture(bricktexture);
                blocks[row][col].setPosition(position);
                blocks[row][col].setScale(sf::Vector2f(0.5f, 0.5f));
            }
        }
    }
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
}
