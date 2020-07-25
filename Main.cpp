#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Crops.h"

//Game Screen Variables
	//Assigns a value for each screen
const int GAME_MENU_SCREEN = 0; //Main game screen
const int INSTRUCTIONS_MENU_SCREEN = 1; //Instructions Menu screen
const int LEVEL_1_SCREEN = 2; // Level 1 of the game
const int GAME_OVER_SCREEN = 3; //Game Over screen
const int LEVEL_2_SCREEN = 4; // Level 2 of the game
int CURRENT_SCREEN = GAME_MENU_SCREEN; //Using current screen in order to switch to another screen

	
int main()
{
	sf::RenderWindow app(sf::VideoMode(800, 600), "Farm the land of StormVille");
	Player player;
	Crops crops;

	int riceHeld = 0;
	int potatoHeld = 0;
	int seedsHeld = 0;
	bool occupied = false;
	bool occupied1 = false;
	bool waterCanHeld = false;
	
	while (app.isOpen())
	{
		sf::Event event{};
		while (app.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				app.close();
		}

		if (player.player.getGlobalBounds().intersects(crops.Rice.getGlobalBounds()) && seedsHeld == 0)
		{
			crops.Rice.setFillColor(sf::Color::Transparent);
			crops.Rice.setOutlineColor(sf::Color::Transparent);
			riceHeld += 1;
			seedsHeld += 1;
			crops.Rice.setPosition(0,0);
		}
		else if (player.player.getGlobalBounds().intersects(crops.Potato.getGlobalBounds()) && seedsHeld == 0)
		{
			crops.Potato.setFillColor(sf::Color::Transparent);
			crops.Potato.setOutlineColor(sf::Color::Transparent);
			potatoHeld += 1;
			seedsHeld += 1;
			crops.Potato.setPosition(0, 0);
		}
		else if (player.player.getGlobalBounds().intersects(crops.WaterCan.getGlobalBounds()))
		{
			crops.WaterCan.setFillColor(sf::Color::Transparent);
			crops.WaterCan.setOutlineColor(sf::Color::Transparent);
			crops.WaterCan.setPosition(0, 0);
			waterCanHeld = true;
		}

		if (player.player.getGlobalBounds().intersects(crops.Plot1.getGlobalBounds()))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && riceHeld > 0 && !occupied)
			{
				riceHeld -= 1;
				seedsHeld -= 1;
				crops.cropType = 1;
				occupied = true;
				crops.Plot1.setFillColor((sf::Color::Green));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && potatoHeld > 0 && !occupied)
			{
				potatoHeld -= 1;
				seedsHeld -= 1;
				crops.cropType = 2;
				occupied = true;
				crops.Plot1.setFillColor((sf::Color::Green));
				crops.Plot1.setOutlineColor(sf::Color::White);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && waterCanHeld == true && (crops.cropType == 1 || crops.cropType == 2))
			{
				crops.Plot1.setOutlineColor(sf::Color::Black);
				crops.Plot1.setFillColor(sf::Color(210, 105, 50));
				occupied = false;
			}
		}
		else if (player.player.getGlobalBounds().intersects(crops.Plot2.getGlobalBounds()))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && riceHeld > 0 && !occupied1)
			{
				riceHeld -= 1;
				seedsHeld -= 1;
				crops.cropType = 1;
				occupied1 = true;
				crops.Plot2.setFillColor((sf::Color::Green));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && potatoHeld > 0 && !occupied1)
			{
				potatoHeld -= 1;
				seedsHeld -= 1;
				crops.cropType = 2;
				occupied1 = true;
				crops.Plot2.setFillColor((sf::Color::Green));
				crops.Plot2.setOutlineColor(sf::Color::White);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && waterCanHeld == true && (crops.cropType == 1 || crops.cropType == 2))
			{
				crops.Plot2.setOutlineColor(sf::Color::Black);
				crops.Plot2.setFillColor(sf::Color(210, 105, 50));
				occupied1 = false;
			}
		}

		//std::cout << "Seeds held: " << seedsHeld << std::endl;
		//std::cout << " Potatos held: " << potatoHeld << " Rice held: " << riceHeld << std::endl;
		//std::cout << "Crop type: " << crops.cropType << std::endl;

		app.clear(sf::Color::Magenta);
		player.Inputs();
		crops.Draw(app);
		player.Draw(app);
		app.display();
	}

	return 0;
}