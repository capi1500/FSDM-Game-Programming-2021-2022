#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <list>
#include "board.hpp"

class Player : public sf::Drawable{
	private:
		enum Direction{
			Up,
			Right,
			Down,
			Left
		};
		
		static int dx[4];
		static int dy[4];
		
		Direction dir = Right;
		sf::Time timeFromLastMove = sf::Time::Zero;
		sf::Time timeToNextChange = sf::milliseconds(1000);
		
		sf::Vector2i pos;
		int points;
		sf::CircleShape circle;
		sf::CircleShape tail;
		std::list<sf::Vector2i> tailPos;
		Board& board;
		
		sf::Vector2f getCenter(const sf::Vector2i& p) const;
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		void handleEvent(const sf::Event& event);
		bool update(const sf::Time& time);
		
		sf::Vector2f getCenter() const;
		const sf::Vector2i& getPos() const;
		void pointGet();
		
		bool isOnTail(const sf::Vector2i& pos) const;
		
		Player(Board& b, int x, int y);
};
