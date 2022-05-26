#pragma once

#include "checkboxButton.hpp"

class InputButton : public CheckboxButton{
	private:
		std::string default_text;
		sf::String text;
	public:
		const sf::String& getText() const;
		const std::string& getDefaultText() const;
		
		InputButton(const sf::Vector2f& position, const std::string& default_text);
		
		void onNotify(const sf::Event& event) override;
};


