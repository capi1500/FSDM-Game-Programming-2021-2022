#pragma once

#include "checkboxButton.hpp"

class RadioButtonGroup;

class RadioButton : public CheckboxButton{
	public:
		RadioButton(const sf::Vector2f& position, const std::function<void()>& actionOnPressed, const std::function<void()>& actionOnReleased, bool defaultState, RadioButtonGroup& group);
		
		friend class RadioButtonGroup;
};


