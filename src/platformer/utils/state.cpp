#include "state.hpp"
#include "stateMachine.hpp"

State::State(StateMachine& stateMachine)
   : stateMachine(stateMachine){}

StateMachine& State::getStateMachine() const{
	return stateMachine;
}

bool State::isActive() const{
	return active;
}

void State::activate(){
	active = true;
}

void State::deactivate(){
	active = false;
}
