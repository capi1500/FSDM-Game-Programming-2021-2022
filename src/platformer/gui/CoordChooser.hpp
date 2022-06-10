#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <platformer/utils/listener.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <functional>

class CoordChooser : public Listener<sf::Event>{
	public:
		void onNotify(const sf::Event& event) override;
		
		const sf::Vector2i& getChosen() const;
		void setChosen(const sf::Vector2i& chosen);
		
		const sf::FloatRect& getRect() const;
		void setRect(const sf::FloatRect& rect);
		
		const sf::Vector2f& getTileSize() const;
		void setTileSize(const sf::Vector2f& tileSize);
		
		void setOnChosenUpdate(const std::function<void(const sf::Vector2i&)>& onChosenUpdate);
		void setOnHoverUpdate(const std::function<void(const sf::Vector2i&)>& onHoverUpdate);
		
		sf::Vector2i getCoord(const sf::Vector2f& pixel);
		
		sf::View& getView();
		const sf::View& getView() const;
		void setView(const sf::View& view);
		float getScaleFactor() const;
		void setScaleFactor(float scale);
		
		bool coordInView(const sf::Vector2f& coord);
	private:
		sf::FloatRect rect;
		sf::Vector2f tile_size;
		
		sf::Vector2i chosen = {-1, -1};
		bool is_pressed = false;
		sf::Vector2i hover = {-1, -1};
		
		sf::View view;
		
		float scaleFactor = 1;

		std::function<void(const sf::Vector2i&)> onChosenUpdate = [](const sf::Vector2i& coord){};
		std::function<void(const sf::Vector2i&)> onHoverUpdate = [](const sf::Vector2i& coord){};
};


