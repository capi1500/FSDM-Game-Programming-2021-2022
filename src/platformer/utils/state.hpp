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
		virtual void activate();
		virtual void deactivate();
		
		virtual ~State() = default;
};


