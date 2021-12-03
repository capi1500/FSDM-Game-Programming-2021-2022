#pragma once

#include <vector>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <platformer/utils/state.hpp>
#include <platformer/utils/listener.hpp>
#include <platformer/entity.hpp>
#include "level.hpp"

class Scene : public State, public Listener<sf::Event>{
	private:
		std::vector<Entity*> entities;
		Level level;
	public:
		Scene(StateMachine& stateMachine);
		virtual ~Scene() = default;
		
		void update(const sf::Time& time);
		void draw();
		
		void activate() override;
		void deactivate() override;
};


