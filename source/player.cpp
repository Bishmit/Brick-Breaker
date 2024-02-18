#include "../header/player.h"

player::player(): movement(-5.f), ball_should_move(false)
{
	if (!balltex.loadFromFile("Assets/Images/ball.png")) {
		std::cout << "Error loading texture for the ball" << "\n"; 
	}
	ballsprite.setTexture(balltex); 
	ballsprite.setPosition(500.f / 2.f, 600.f - 30.f); 
	ballsprite.setScale(sf::Vector2f(0.25f, 0.25f)); 
}

void player::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		ball_should_move = true; 
	}
	if (ball_should_move && !should_move_downward) {
		ballsprite.move(0.f, this->movement);
	}

	if (ball_should_move && should_move_downward) {
		ballsprite.move(0.f, -this->movement);
	}

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

float player::getmovement()
{
	return movement;
}

void player::manageballboundariescondition() {

}

