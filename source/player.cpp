#include "../header/player.h"

player::player(): movement_y(-5.f),movement_x(-5.f), ball_should_move(false), counter(0)
{
	if (!balltex.loadFromFile("Assets/Images/ball.png")) {
		std::cout << "Error loading texture for the ball" << "\n"; 
	}
	ballsprite.setTexture(balltex); 
	ballsprite.setPosition(500.f / 2.f, 600.f - 30.f); 
	ballsprite.setScale(sf::Vector2f(0.25f, 0.25f)); 
}

void player::update(paddle &pad)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		ball_should_move = true; 
	}
	if (ball_should_move) {
		ballsprite.move(movement_x, movement_y);
	}

	if (ballsprite.getGlobalBounds().intersects(pad.getbound())){
		movement_y = -movement_y;
	}
	manageballboundariescondition(); 

}

void player::makedirectionchange() {
	//this->movement_x = -this->movement_x;
	this->movement_y = -this->movement_y;
 }

void player::render(sf::RenderTarget* target)
{
	target->draw(ballsprite); 
}

sf::FloatRect player::getbounds()
{
	return ballsprite.getGlobalBounds(); 
}

sf::Vector2f player::getpos()
{
	return ballsprite.getPosition(); 
}

void player::setposition(float x, float y)
{
	ballsprite.setPosition(x, y); 
}


void player::manageballboundariescondition() {
	sf::Vector2f ballPosition = ballsprite.getPosition();
	sf::FloatRect ballBounds = ballsprite.getGlobalBounds();

	// Check left and right boundaries
	if (ballPosition.x <= 0.f || ballPosition.x + ballBounds.width >= 500.f) {
		movement_x = -movement_x;
	}

	// Check top and bottom boundaries
	if (ballPosition.y <= 0.f || ballPosition.y + ballBounds.height >= 600.f) {
		movement_y = -movement_y;
	}
}


