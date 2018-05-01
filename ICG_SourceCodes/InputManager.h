#pragma once

#include <SFML\Graphics.hpp>
namespace ASGames
{
	class InputManager
	{
	public:
		InputManager() {}
		~InputManager() {}

		bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
		bool isMouseOver(sf::Sprite object, sf::RenderWindow &window);
		bool isDragged(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
		
		sf::Vector2i GetMousePosition(sf::RenderWindow &window);

	};
}
