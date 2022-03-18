#pragma once

#include <vector>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <platformer/utils/state.hpp>
#include <platformer/utils/emitter.hpp>
#include <platformer/utils/listener.hpp>
#include <SFML/Graphics/View.hpp>
#include <platformer/scenes/events/sceneEvent.hpp>
#include <memory>
#include "platformer/entities/entity.hpp"
#include "level.hpp"

class Scene : public State, public Listener<sf::Event>, public Listener<std::shared_ptr<SceneEvent>>, public Emitter<std::shared_ptr<SceneEvent>>{
	protected:
		std::vector<Entity*> entities;
		Level level;
		sf::View view;
	public:
		Scene(StateMachine& stateMachine);
		virtual ~Scene();

        virtual void update(const sf::Time& time);
		void draw();
		void onNotify(const std::shared_ptr<SceneEvent>& event) override;
		
		void activate() override;
		void deactivate() override;
};

