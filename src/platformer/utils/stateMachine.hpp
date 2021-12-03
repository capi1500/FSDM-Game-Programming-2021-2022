#pragma once

#include <stack>
#include "state.hpp"
#include "emitter.hpp"
#include <functional>

using Runnable = std::function<void()>;

class StateMachine : Listener<Runnable>{
	private:
		Emitter<Runnable> emitter;
		std::stack<State*> states;
	public:
		State& getState();
		
		void add(State* state);
		void pop();
		void replace(State* state);
		void clear();
		StateMachine();
		virtual ~StateMachine();
};
