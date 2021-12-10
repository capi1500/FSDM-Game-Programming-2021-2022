#include "renderer.hpp"

sf::RenderTarget& Renderer::getLayer(unsigned int layer){
	return layers[layer];
}

void Renderer::clear(){
	sf::RenderWindow::clear();
	for(int i = 0; i < layersCount; i++)
		layers[i].clear();
}

void Renderer::display(){
	for(int i = 0; i < layersCount; i++){
		layers[i].display();
		sprite.setTexture(layers[i].getTexture(), true);
		draw(sprite);
	}
	sf::RenderWindow::display();
}
