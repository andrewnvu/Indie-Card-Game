#pragma once
#include<SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace ASGames
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		void initHand(vector<sf::Sprite> myHand);
		GameDataRef _data;
		sf::Sprite _background;
		sf::Sprite _pauseButton;
		sf::Sprite _attackCard;
		sf::Sprite _defendCard;
		sf::Sprite _hand[5];
		sf::Sprite _deckSprite;
		int turn;
		int gameState;
	};
}