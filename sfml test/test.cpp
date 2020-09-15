#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!", sf::Style::Close | sf::Style::Default);
	sf::RectangleShape player(sf::Vector2f(200.0f, 300.0f));
	player.setPosition(206.0f, 206.0f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("runleft.png");
	player.setTexture(&playerTexture);

	Animation animation(&playerTexture, sf::Vector2u(4, 3), 0.3f);

	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		
		deltaTime = clock.restart().asSeconds();

		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
			    window.close();
					break;
			case sf::Event::TextEntered:
				if (evnt.text.unicode < 128)
				{
					printf("%c", evnt.text.unicode);
				}

			}
			if (evnt.type == evnt.Closed)
			{
				window.close();
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			player.move(-1.0f ,0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player.move(1.0f ,0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player.move(0.0f ,-1.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player.move(0.0f ,1.0f);
		}
		
		animation.Update(1, deltaTime);
		player.setTextureRect(animation.uvRect);
		
		window.clear();
		window.draw(player);
		window.display();
	}

	return 0;
}