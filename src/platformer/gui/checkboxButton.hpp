#pragma once

#include "button.hpp"

class CheckboxButton : public Widget, public Listener<sf::Event>{
	protected:
		std::function<void()> onButtonPressed = []{};
		std::function<void()> onButtonReleased = []{};
		bool state;
	private:
		bool pressed = false;
		bool hover = false;
	public:
		bool isPressed() const;
		CheckboxButton(const sf::Vector2f& position, const std::function<void()>& actionOnPressed, const std::function<void()>& actionOnReleased, bool defaultState);
		virtual ~CheckboxButton();
		void onNotify(const sf::Event& event) override;
		void activate() override;
		void deactivate() override;
		
		void press();
		void release();
};


