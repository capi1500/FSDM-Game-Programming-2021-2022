#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <platformer/entities/world/textureInfo.hpp>

class Gui : public sf::Drawable{
	private:
		int health = 3;
		int max_health = 6;
		int keys = 1;
		int coins = 500;
		int diamonds = 2;
		
		sf::Sprite sprite;
		sf::RenderTexture texture;
		void updateTexture();
		
		TextureInfo textureInfo;
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		Gui();
		int getHealth() const;
		void setHealth(int health);
		int getKeys() const;
		void setKeys(int keys);
		int getCoins() const;
		void setCoins(int coins);
		int getDiamonds() const;
		void setDiamonds(int diamonds);
};


