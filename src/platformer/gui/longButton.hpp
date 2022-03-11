#pragma once

#include "button.hpp"

class LongButton : public Button{
	public:
		LongButton(const sf::Vector2f& position, const std::string& text, const std::function<void()>& action);
};


