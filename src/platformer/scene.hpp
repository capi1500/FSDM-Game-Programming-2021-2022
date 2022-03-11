#pragma once

#include <vector>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <platformer/utils/state.hpp>
#include <platformer/utils/listener.hpp>
#include <SFML/Graphics/View.hpp>
#include "platformer/entities/entity.hpp"
#include "level.hpp"

class Scene : public State, public Listener<sf::Event>{
	protected:
		std::vector<Entity*> entities;
		Level level;
		sf::View view;
	public:
		Scene(StateMachine& stateMachine);
		virtual ~Scene();

        virtual void update(const sf::Time& time);
		void draw();
		
		void activate() override;
		void deactivate() override;
};


