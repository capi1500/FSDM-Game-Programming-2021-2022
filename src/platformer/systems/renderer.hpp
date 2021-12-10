#pragma once

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Renderer : public sf::RenderWindow{
	private:
		static const unsigned layersCount = 10;
		
		sf::RenderTexture layers[layersCount];
		sf::Sprite sprite;
	public:
		sf::RenderTarget& getLayer(unsigned layer);
		
		void clear();
		void display();
};


