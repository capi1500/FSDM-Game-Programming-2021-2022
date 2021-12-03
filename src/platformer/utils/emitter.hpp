#pragma once

#include <set>
#include <queue>
#include "listener.hpp"

template<class T>
class Emitter{
	private:
		std::queue<T> events;
		std::set<Listener<T>*> listeners;
	public:
		void send(const T& event){
			events.push(event);
		}
		
		void sendNow(const T& event){
			for(auto& l : listeners){
				l->onNotify(event);
			}
		}
		
		void processEvents(){
			while(!events.empty()){
				sendNow(events.front());
				events.pop();
			}
		}
		
		void subscribe(Listener<T>* listener){
			listeners.insert(listener);
		}
		
		void unsubscribe(Listener<T>* listener){
			listeners.erase(listener);
		}
};

/*
Scene a; wyślij event, zamień scenę na nową (b)
	usuwa scenę a i dodaje scenę b
 
 
*/