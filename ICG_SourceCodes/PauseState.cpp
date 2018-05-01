#include <sstream>
#include<SFML\Audio.hpp>
#include "PauseState.h"
#include "Definitions.h"
#include "GameState.h"
#include "MainMenuState.h"

#include <iostream>


namespace ASGames {
	PauseState::PauseState(GameDataRef data) : _data(data)
	{

	}

	void PauseState::Init()
	{
		//loads textures
		this->_data->assets.LoadTexture("Pause Background", PAUSE_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Resume Button", RESUME_BUTTON);
		this->_data->assets.LoadTexture("Home Button", HOME_BUTTON);

		this->_background.setTexture(this->_data->assets.GetTexture("Pause Background"));
		this->_resumeButton.setTexture(this->_data->assets.GetTexture("Resume Button"));
		this->_homeButton.setTexture(this->_data->assets.GetTexture("Home Button"));

		_resumeButton.setPosition(this->_data->window.getSize().x - _resumeButton.getLocalBounds().width,
			_resumeButton.getPosition().y);
		_homeButton.setPosition(_homeButton.getPosition().x, 
			_homeButton.getPosition().y);
	}

	void PauseState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{

			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.isSpriteClicked(this->_resumeButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.RemoveState(); 
			}

			if (this->_data->input.isSpriteClicked(this->_homeButton, sf::Mouse::Left, this->_data->window))
			{
				//REMOVES PAUSE SCREEN OFF OF STACK
				this->_data->machine.RemoveState();
				//ADDS THE MAIN MENU STATE AND REPLACES THE GAME STATE
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}

		}
	}

	void PauseState::Update(float dt)
	{
	}

	void PauseState::Draw(float dt)
	{

		this->_data->window.clear();
		this->_data->window.draw(this->_background);
		//this->_data->window.draw(this->_title);
		this->_data->window.draw(this->_resumeButton);
		this->_data->window.draw(this->_homeButton);
	
		this->_data->window.display();

	}

}
