#include <SFML/Graphics/RenderTarget.hpp>
#include "image.hpp"

void Image::update(const sf::Time& time){

}

void Image::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(sprite, states.transform.combine(getTransform()));
}

void Image::setTexture(const sf::Texture& texture){
	sprite.setTexture(texture, true);
}

sf::FloatRect Image::getGlobalBounds() const{
	return getTransform().transformRect(sprite.getGlobalBounds());
}
