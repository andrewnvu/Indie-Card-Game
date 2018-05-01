#pragma once
#include<SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace ASGames
{
	class MainMenuState : public State 
	{
	public:
		MainMenuState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		sf::Sprite _background;
		sf::Sprite _playButton;
		sf::Sprite _playButtonClicked;
		sf::Sprite _creditsButton;
		sf::Sprite _creditsButtonClicked;
		sf::Sprite _exitButton;
		sf::Sprite _exitButtonClicked;
		sf::Sprite _title;
	};
}