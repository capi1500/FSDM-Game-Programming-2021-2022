#pragma once

#include <platformer/scene.hpp>
#include <platformer/utils/tileset.hpp>
#include <box2d/b2_world.h>
#include <platformer/entities/player.hpp>
#include <platformer/systems/contactListener.hpp>
#include <platformer/scenes/play/playerMonsterCollision.hpp>
#include <platformer/scenes/play/groundCollision.hpp>
#include <platformer/scenes/play/collectibleCollision.hpp>
#include <platformer/gui.hpp>
#include <platformer/entities/background.hpp>

class Play : public Scene{
	private:
		Level level;
		Gui gui;
		std::string levelBackup;
		
		sf::View gui_view;
		
		Background background;
		
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
		void draw(sf::RenderStates renderStates = sf::RenderStates()) override;
		enum SceneEventID{
			CollisionEvent,
			CoinCollected,
			DiamondCollected,
			LevelStarted
		};
};


