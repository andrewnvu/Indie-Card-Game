#pragma once



class State
{
public:

	//initialize state
	virtual void Init() = 0;

	//handle all inputs on the state
	virtual void HandleInput() = 0;

	//update all variables and input from the user
	//ex. if arrow is pressed updates the computer to move along the arrow
	virtual void Update(float dt) = 0;

	//draws the change
	//float dt = time difference, frame dependency
	virtual void Draw(float dt) = 0;

	virtual void Pause() {}
	virtual void Resume() {}

private:
	
};

