#include "Game.h"
#include "Definitions.h"
#include "SplashState.h"

namespace ASGames
{
	Game::Game(int width, int height, string title)
	{
		_data->window.create(sf::VideoMode(width, height), "ASGames", sf::Style::Close | sf::Style::Titlebar);

		_data->machine.AddState(StateRef(new SplashState(this->_data)));
		
		this->Run();
	}

	void Game::Run()
	{
		sf::Music music;
		music.openFromFile(BACKGROUND_MUSIC);
		music.setVolume(50);
		music.play();
	
		float newTime, frameTime, interpolation;

		float currentTime = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->_data->window.isOpen())
		{
			this->_data->machine.ProcessStateChanges();
			
			newTime = this->_clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;

			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				this->_data->machine.GetActiveState()->HandleInput();
				this->_data->machine.GetActiveState()->Update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			this->_data->machine.GetActiveState()->Draw(interpolation);
		}
	}
}