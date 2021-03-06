#pragma once

#include <memory>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <platformer/entities/world/textureInfo.hpp>
#include <platformer/utils/listener.hpp>
#include <platformer/scenes/events/sceneEvent.hpp>

class Gui : public sf::Drawable, Listener<std::shared_ptr<SceneEvent>>{
	private:
		int health = 2;
		int max_health = 6;
		int keys = 1;
		int coins = 500;
		int diamonds = 2;
		
		sf::Sprite sprite;
		sf::RenderTexture texture;
		void updateTexture();
		void updateTextureRect(const TileConfig& t);
		void drawNumber(sf::RenderStates& states, int value);
		
		TextureInfo textureInfo;
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		Gui();
		virtual ~Gui();
		int getHealth() const;
		void setHealth(int health);
		int getKeys() const;
		void setKeys(int keys);
		int getCoins() const;
		void setCoins(int coins);
		int getDiamonds() const;
		void setDiamonds(int diamonds);
	private:
		void onNotify(const std::shared_ptr<SceneEvent>& event) override;
};


