#pragma once
#include<SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace ASGames
{
	class GameOver : public State
	{
	public:
		GameOver(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		sf::Sprite _gameOverBackground;
		sf::Sprite _homeButton;
	};
}