#pragma once

#include <platformer/scene.hpp>
#include <platformer/utils/tileset.hpp>
#include <box2d/b2_world.h>
#include <platformer/entities/player.hpp>
#include <platformer/systems/contactListener.hpp>

class Play : public Scene{
	private:
		Tileset tiles;
		Tileset background;
		Tileset characters;
		Tileset ui;
		
		b2World b2World;
		ContactListener contactListener;
		
		Player* p;
	public:
		void onNotify(const sf::Event &event) override;
		void update(const sf::Time &time) override;
		
		Play(StateMachine& stateMachine);
};


