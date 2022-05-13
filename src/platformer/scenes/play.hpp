#pragma once

#include <platformer/scene.hpp>
#include <platformer/utils/tileset.hpp>
#include <box2d/b2_world.h>
#include <platformer/entities/player.hpp>
#include <platformer/systems/contactListener.hpp>
#include <platformer/scenes/play/playerMonsterCollision.hpp>
#include <platformer/scenes/play/groundCollision.hpp>
#include <platformer/scenes/play/collectibleCollision.hpp>

class Play : public Scene{
	private:
		Level level;
		std::string levelBackup;
		
		PlayerMonsterCollision playerMonsterCollision;
		GroundCollision groundCollision;
		CollectibleCollision collectibleCollision;
	public:
		void onNotify(const sf::Event &event) override;
		void update(const sf::Time &time) override;
		
		const Level& getLevel() const;
		const std::string& getLevelBackup() const;
		Play(StateMachine& stateMachine, const std::string& level);
		void activate() override;
		void deactivate() override;
		void draw() override;
		enum SceneEventID{
			CollisionEvent
		};
};


