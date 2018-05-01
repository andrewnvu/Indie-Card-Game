#include <sstream>
#include<SFML\Audio.hpp>
#include "GameState.h"
#include "Definitions.h"
#include <stack>
#include <iostream>
#include "PauseState.h"


namespace ASGames {
	GameState::GameState(GameDataRef data) : _data(data)
	{

	}

	void GameState::Init()
	{
		gameState = STATE_PLAYING;
		turn = PLAYERS_TURN;
		this->_data->assets.LoadTexture("Pause Button", PAUSE_BUTTON);
		this->_data->assets.LoadTexture("Play Background", GAME_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Attack Card", ATTACK_CARD);
		this->_data->assets.LoadTexture("Defend Card", DEFEND_CARD);
		this->_data->assets.LoadTexture("Deck", DECK);
		//loads textures

		//gets textures
		_background.setTexture(this->_data->assets.GetTexture("Play Background"));
		_pauseButton.setTexture(this->_data->assets.GetTexture("Pause Button"));
		/*_attackCard.setTexture(this->_data->assets.GetTexture("Attack Card"));
		_defendCard.setTexture(this->_data->assets.GetTexture("Defend Card"));*/
		_deckSprite.setTexture(this->_data->assets.GetTexture("Deck"));


		//positions on the screen
		_pauseButton.setPosition(this->_data->window.getSize().x - _pauseButton.getLocalBounds().width,
			_pauseButton.getPosition().y);

		/*for (int i = 0; i < 10; ++i) {
			_hand[i].setTexture(this->_data->assets.GetTexture("Defend Card"));
		}*/
		_deckSprite.setPosition(20, 520);

		for (int i = 0; i < 5; ++i) {
			if (i % 2 == 0) {
				_hand[i].setTexture(this->_data->assets.GetTexture("Attack Card"));
				_hand[i].setPosition(190 + i * 180, 470);
			}
			else if (i % 2 == 1) {
				_hand[i].setTexture(this->_data->assets.GetTexture("Defend Card"));
				_hand[i].setPosition(190 + i * 180, 470);
			}
		}
		

	}

	//this is where the program recognizes user input
	void GameState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{

			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.isSpriteClicked(this->_pauseButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(new PauseState(_data)), false);
			}

			if (this->_data->input.isDragged(this->_hand[4], sf::Mouse::Left, this->_data->window))
			{
				cout << "Hello";
			}

		}
	}

	void GameState::Update(float dt)
	{
	}

	void GameState::Draw(float dt)
	{

		this->_data->window.clear();
		this->_data->window.draw(this->_background);
		//this->_data->window.draw(this->_title);
		/*for (size_t i = 0; i < Cards.size(); ++i) {
			this->_data->window.draw(Cards[i]);
		}*/
		for (int i = 0; i < 5; ++i) {
			this->_data->window.draw(this->_hand[i]);
		}
		this->_data->window.draw(this->_deckSprite);
		this->_data->window.draw(this->_pauseButton);
		this->_data->window.display();
	}


}
