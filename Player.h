#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
public:
	float x;
	float y;

public:
	void Initialise();
	void Inputs();
	void Draw(sf::RenderWindow& app);

	Player();
	~Player();

	sf::RectangleShape player;
};