#include "Player.h"

Player::Player()
{
	this->x = 50;
	this->y = 10;
	player.setSize(sf::Vector2f(64, 64));
	player.setOrigin(64/2, 64/2);
	player.setOutlineColor(sf::Color::Black);
	player.setOutlineThickness(5);
	player.setPosition(this->x,this->y);
	
}

Player::~Player()
{
	
}
void Player::Initialise()
{

}
void Player::Inputs()
{

	

	
}

void Player::Draw(sf::RenderWindow& app)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && player.getPosition().y > 42)
	{
		player.move(0,-0.2);
		//std::cout << "Y: " << y << "/" << player.getPosition().y << std::endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && player.getPosition().x > 42)
	{
		player.move(-0.2,0);
		//std::cout << "X: " << x << "/" << player.getPosition().x << std::endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && player.getPosition().y < 558)
	{
		player.move(0,0.2);
		//std::cout << "Y: " << y << "/" << player.getPosition().y << std::endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && player.getPosition().x < 758)
	{
		/*player.setPosition(+5,Y);*/
		player.move(0.2,0);
		//std::cout << "X: " << x << "/" << player.getPosition().x << std::endl;
	}
	app.draw(player);
}