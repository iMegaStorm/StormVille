#include "Crops.h"

Crops::Crops()
{
	this->x = 100;
	this->y = 300;
	this->cropType = 0;

	Rice.setRadius(20);
	Rice.setOutlineColor(sf::Color::Black);
	Rice.setFillColor(sf::Color::Green);
	Rice.setOutlineThickness(5);
	Rice.setPosition(100, 300);

	Potato.setRadius(20);
	Potato.setOutlineColor(sf::Color::White);
	Potato.setFillColor(sf::Color::Green);
	Potato.setOutlineThickness(5);
	Potato.setPosition(100, 500);

	Plot1.setSize(sf::Vector2f(64, 64));
	Plot1.setOutlineColor(sf::Color::Black);
	Plot1.setFillColor(sf::Color(210,105,50));
	Plot1.setOutlineThickness(5);
	Plot1.setPosition(400, 400);

	Plot2.setSize(sf::Vector2f(64, 64));
	Plot2.setOutlineColor(sf::Color::Black);
	Plot2.setFillColor(sf::Color(210, 105, 50));
	Plot2.setOutlineThickness(5);
	Plot2.setPosition(300, 400);

	WaterCan.setSize(sf::Vector2f(32, 32));
	WaterCan.setOutlineColor(sf::Color::Black);
	WaterCan.setFillColor(sf::Color::Blue);
	WaterCan.setOutlineThickness(5);
	WaterCan.setPosition(500, 500);
}

Crops::~Crops()
{
}

void Crops::Seeds()
{
	
}

void Crops::Draw(sf::RenderWindow& app)
{
	app.draw(Rice);
	app.draw(Potato);
	app.draw(Plot1);
	app.draw(Plot2);
	app.draw(WaterCan);
	
}
