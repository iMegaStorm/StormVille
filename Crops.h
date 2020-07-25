#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Crops
{

public:

	float x;
	float y;
	int cropType;

	Crops();
	~Crops();


	void Seeds();
	void Draw(sf::RenderWindow& app);

	sf::CircleShape Rice;
	sf::CircleShape Potato;
	sf::RectangleShape WaterCan;
	sf::RectangleShape Plot1;
	sf::RectangleShape Plot2;
};

