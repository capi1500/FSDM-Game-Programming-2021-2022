#pragma once

#include "entity.hpp"

class Background : public Entity{
	public:
		enum Type{
			Sky,
			Desert,
			Snow,
			Grass
		};
		
		std::shared_ptr<sf::RenderTexture> texture;
		Background();
		Type getType() const;
		void setType(Type type);
		const sf::FloatRect& getDisplay() const;
		void setDisplay(const sf::FloatRect& display);
		void update(const sf::Time& time) override;
		const sf::Vector2f& getOffset() const;
		void setOffset(const sf::Vector2f& offset);
	private:
		void updateTexture();
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	private:
		Type type;
		sf::FloatRect display;
		sf::Vector2f offset;
};


