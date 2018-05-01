#pragma once
#include <memory>
#include <stack>
#include "State.h"

using namespace std;


typedef std::unique_ptr<State> StateRef;

class StateMachine 
{
public:
	StateMachine(){}
	~StateMachine(){}

	void AddState(StateRef newSate, bool isReplacing = true);
	void RemoveState();

	void ProcessStateChanges();

	//returns a reference to the top level state, handles game logic
	StateRef &GetActiveState();

private:
	//creates a stack of StateRef. Creates a ptr to all of our states present our stack
	stack<StateRef> _states;
	
	//Adds a new state to our stack
	StateRef _newState;

	bool _isRemoving;
	bool _isAdding;
	bool _isReplacing;
};

