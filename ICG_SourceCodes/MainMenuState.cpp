#include <sstream>
#include<SFML\Audio.hpp>
#include "MainMenuState.h"
#include "Definitions.h"

#include <iostream>
#include "GameState.h"

namespace ASGames {
	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{

	}

	void MainMenuState::Init()
	{
		//loads textures
		this->_data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
		//this->_data->assets.LoadTexture("Title", MAIN_MENU_TITLE_PATH);
		this->_data->assets.LoadTexture("Play Button", MAIN_MENU_PLAY_BUTTON);
		this->_data->assets.LoadTexture("Play Button Clicked", MAIN_MENU_PLAY_BUTTON_CLICKED);
		this->_data->assets.LoadTexture("Credit Button", MAIN_MENU_CREDITS_BUTTON);
		this->_data->assets.LoadTexture("Credit Button Clicked", MAIN_MENU_CREDITS_BUTTON_CLICKED);
		this->_data->assets.LoadTexture("Exit Button", MAIN_MENU_EXIT_BUTTON);
		this->_data->assets.LoadTexture("Exit Button Clicked", MAIN_MENU_EXIT_BUTTON_CLICKED);

		//gets textures
		this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		//this->_title.setTexture(this->_data->assets.GetTexture("Title"));
		this->_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
		this->_playButtonClicked.setTexture(this->_data->assets.GetTexture("Play Button Clicked"));
		this->_creditsButton.setTexture(this->_data->assets.GetTexture("Credit Button"));
		this->_creditsButtonClicked.setTexture(this->_data->assets.GetTexture("Credit Button Clicked"));
		this->_exitButton.setTexture(this->_data->assets.GetTexture("Exit Button"));
		this->_exitButtonClicked.setTexture(this->_data->assets.GetTexture("Exit Button Clicked"));

		//positions on the screen
		this->_playButton.setPosition((SCREEN_WIDTH / 2) - (this->_playButton.getGlobalBounds().width/2), (SCREEN_HEIGHT/2) - (this ->_playButton.getGlobalBounds().height / 2) + 90);
		this->_playButtonClicked.setPosition((SCREEN_WIDTH / 2) - (this->_playButtonClicked.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_playButtonClicked.getGlobalBounds().height / 2) + 90);
		this->_creditsButton.setPosition((SCREEN_WIDTH / 2) - (this->_creditsButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_creditsButton.getGlobalBounds().height / 2) + 180);
		this->_creditsButtonClicked.setPosition((SCREEN_WIDTH / 2) - (this->_creditsButtonClicked.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_creditsButtonClicked.getGlobalBounds().height / 2) + 180);
		this->_exitButton.setPosition((SCREEN_WIDTH / 2) - (this->_exitButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT/ 2)- (this->_exitButton.getGlobalBounds().height/2) + 270);
		this->_exitButtonClicked.setPosition((SCREEN_WIDTH / 2) - (this->_exitButtonClicked.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_exitButtonClicked.getGlobalBounds().height / 2) + 270);
	}

	void MainMenuState::HandleInput()
	{
		sf::Event event;
		
		while (this->_data->window.pollEvent(event))
		{
		
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.isSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState( StateRef(new GameState(_data)), true);
			}

			if (this->_data->input.isSpriteClicked(this->_creditsButton, sf::Mouse::Left, this->_data->window))
			{
				cout << "Go to Game Screen" << endl;
			}

			if (this->_data->input.isSpriteClicked(this->_exitButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->window.close();
			}
		
		}
	}

	void MainMenuState::Update(float dt)
	{
	}

	void MainMenuState::Draw(float dt)
	{

		this->_data->window.clear();
		this->_data->window.draw(this->_background);
		//this->_data->window.draw(this->_title);
		this->_data->window.draw(this->_playButton);
		this->_data->window.draw(this->_creditsButton);
		this->_data->window.draw(this->_exitButton);
	

		if (this->_data->input.isMouseOver(this->_playButton, this->_data->window))
		{
			this->_data->window.draw(this->_playButtonClicked);
		}

		if (this->_data->input.isMouseOver(this->_creditsButton, this->_data->window))
		{
			this->_data->window.draw(this->_creditsButtonClicked);
		}

		if (this->_data->input.isMouseOver(this->_exitButton, this->_data->window))
		{
			this->_data->window.draw(this->_exitButtonClicked);
		}

		this->_data->window.display();
		
	}

}
