#pragma once

#include <string>
#include <SFML/System/Vector2.hpp>

class TextureInfo{
    private:
        std::string name;
        sf::Vector2i size;
        sf::Vector2i margin;
    public:
        const std::string& getName() const;
        const sf::Vector2i& getSize() const;
        const sf::Vector2i& getMargin() const;
        TextureInfo(const std::string& name, const sf::Vector2i& size, const sf::Vector2i& margin);
};


