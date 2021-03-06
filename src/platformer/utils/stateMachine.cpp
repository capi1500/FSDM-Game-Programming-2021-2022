#include "stateMachine.hpp"

StateMachine::StateMachine(){
	emitter.subscribe(this);
}

StateMachine::~StateMachine(){
	clear();
	emitter.processEvents();
	emitter.unsubscribe(this);
}

State& StateMachine::getState(){
	emitter.processEvents();
	return *states.top();
}

void StateMachine::add(State* state){
	emitter.send([this, state]{
		if(!states.empty())
			states.top()->deactivate();
		states.push(state);
		states.top()->activate();
	});
}

void StateMachine::pop(){
	emitter.send([this]{
        states.top()->deactivate();
		delete states.top();
		states.pop();
		if(!states.empty())
			states.top()->activate();
	});
}

void StateMachine::replace(State* state){
	pop();
	add(state);
}

void StateMachine::clear(){
	emitter.send([this]{
		while(!states.empty()){
			delete states.top();
			states.pop();
		}
	});
}

void StateMachine::onNotify(const Runnable& t){
	t();
}
