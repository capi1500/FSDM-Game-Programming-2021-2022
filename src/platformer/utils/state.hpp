#pragma once

class StateMachine;

class State{
	private:
		StateMachine& stateMachine;
		bool active = false;
	public:
		State(StateMachine& stateMachine);
		StateMachine& getStateMachine() const;
		
		bool isActive() const;
		void setActive(bool active);
		
		virtual ~State() = default;
};


