#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML works!", sf::Style::Close | sf::Style::Default);
	sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f));
	player.setPosition(206.0f, 206.0f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("test111.png");
	player.setTexture(&playerTexture);

	sf::Vector2u textureSize = playerTexture.getSize();
	textureSize.x /= 3;
	textureSize.y /= 9;

	player.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * 2, textureSize.x, textureSize.y));
	
	while (window.isOpen())
	{
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
			player.move(-0.1f ,0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player.move(0.1f ,0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player.move(0.0f ,-0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player.move(0.0f ,0.1f);
		}
		window.clear();
		window.draw(player);
		window.display();
	}

	return 0;
}