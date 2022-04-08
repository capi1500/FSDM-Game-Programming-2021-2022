#include <platformer/framework.hpp>
#include <iostream>
#include "CoordChooser.hpp"

const sf::FloatRect& CoordChooser::getRect() const{
	return rect;
}

void CoordChooser::setRect(const sf::FloatRect& rect){
	CoordChooser::rect = rect;
}

const sf::Vector2f& CoordChooser::getTileSize() const{
	return tile_size;
}

void CoordChooser::setTileSize(const sf::Vector2f& tileSize){
	tile_size = tileSize;
}

const sf::Vector2i& CoordChooser::getChosen() const{
	return chosen;
}

sf::Vector2i CoordChooser::getCoord(const sf::Vector2f& pixel){
	return sf::Vector2i((pixel.x - rect.left) / tile_size.x, (pixel.y - rect.top) / tile_size.y);
}

void CoordChooser::onNotify(const sf::Event& event){
	if(event.type == sf::Event::MouseMoved){
		sf::Vector2f coord = Framework::getRenderer().mapPixelToCoords({event.mouseMove.x, event.mouseMove.y}, view);
		if(coordInView(coord) && rect.contains(coord)){
			if(hover != getCoord(coord)){
				hover = getCoord(coord);
				onHoverUpdate(hover);
			}
			if(is_pressed && chosen != getCoord(coord)){
				chosen = getCoord(coord);
				onChosenUpdate(chosen);
			}
		}
		else if(hover != getCoord(coord)){
			hover = {-1, -1};
			onHoverUpdate(hover);
		}
	}
	else if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
		sf::Vector2f coord = Framework::getRenderer().mapPixelToCoords({event.mouseButton.x, event.mouseButton.y}, view);
		
		if(coordInView(coord) && rect.contains(coord) && chosen != getCoord(coord)){
			chosen = getCoord(coord);
			onChosenUpdate(chosen);
			is_pressed = true;
		}
	}
	else if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){
		is_pressed = false;
	}
}

void CoordChooser::setOnChosenUpdate(const std::function<void(const sf::Vector2i&)>& onChosenUpdate){
	CoordChooser::onChosenUpdate = onChosenUpdate;
}

void CoordChooser::setOnHoverUpdate(const std::function<void(const sf::Vector2i&)>& onHoverUpdate){
	CoordChooser::onHoverUpdate = onHoverUpdate;
}

sf::View& CoordChooser::getView(){
	return view;
}

const sf::View& CoordChooser::getView() const{
	return view;
}

void CoordChooser::setView(const sf::View& view){
	CoordChooser::view = view;
}

bool CoordChooser::coordInView(const sf::Vector2f& coord){
	return view.getCenter().x - view.getSize().x / 2 <= coord.x && coord.x <= view.getCenter().x + view.getSize().x / 2 &&
			view.getCenter().y - view.getSize().y / 2 <= coord.y && coord.y <= view.getCenter().y + view.getSize().y / 2;
}

float CoordChooser::getScaleFactor() const{
	return scaleFactor;
}

void CoordChooser::setScaleFactor(float scale){
	CoordChooser::scaleFactor = scale;
}
