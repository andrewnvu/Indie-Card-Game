#include <sstream>
#include<SFML\Audio.hpp>
#include "GameOver.h"
#include "Definitions.h"

#include <iostream>
#include "GameState.h"
#include "MainMenuState.h"

namespace ASGames {
	GameOver::GameOver(GameDataRef data) : _data(data)
	{
		
	}

	void GameOver::Init()
	{
		//loads textures
		
		this->_homeButton.setTexture(this->_data->assets.GetTexture("Home Button"));

		//positions on the screen
		
		this->_homeButton.setPosition((SCREEN_WIDTH / 2) - (this->_homeButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_homeButton.getGlobalBounds().height / 2) + 270);
	}

	void GameOver::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{

			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.isSpriteClicked(this->_homeButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}


		}
	}

	void GameOver::Update(float dt)
	{
	}

	void GameOver::Draw(float dt)
	{

		this->_data->window.clear();
		this->_data->window.draw(this->_gameOverBackground);
		this->_data->window.draw(this->_homeButton);
		

		this->_data->window.display();

	}

}
