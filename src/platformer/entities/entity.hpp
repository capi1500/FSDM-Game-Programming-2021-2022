#pragma once


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <platformer/entities/world/textureInfo.hpp>
#include <json.hpp>

using json = nlohmann::json;

class Entity : public sf::Drawable, public sf::Transformable{
	private:
		TextureInfo textureInfo;
		sf::Vector2u textureCoord;
	protected:
		bool visible = true;
		
		sf::Sprite sprite;
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		virtual void update(const sf::Time& time) = 0;
		
		void updateTexture(const sf::Vector2u& textureCoord);
		
		void hide();
		void show();
		const TextureInfo& getTextureInfo() const;
		void setTextureInfo(const TextureInfo& textureInfo);
		virtual void activate();
		virtual void deactivate();
		
		friend void to_json(json& j, const Entity& e);
		friend void from_json(const json& j, Entity& e);
};


