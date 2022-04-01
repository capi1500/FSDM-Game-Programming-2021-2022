#pragma once


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <platformer/entities/world/textureInfo.hpp>

class Entity : public sf::Drawable, public sf::Transformable{
	protected:
		bool visible = true;
		
		sf::Sprite sprite;
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		Entity(const TextureInfo& textureInfo, const sf::Vector2u& textureFrame);
		Entity();
		virtual void update(const sf::Time& time) = 0;
		virtual ~Entity() = default;
		
		void hide();
		void show();
		
		virtual void activate();
		virtual void deactivate();
};


