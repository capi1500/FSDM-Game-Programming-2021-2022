#pragma once

#include <functional>
#include <SFML/Window/Event.hpp>
#include <platformer/utils/listener.hpp>
#include "image.hpp"

class Button : public Image, public Listener<sf::Event>{
	private:
		std::function<void()> onHoverStart;
		std::function<void()> onHoverEnd;
		std::function<void()> onButtonPressed;
		std::function<void()> onButtonReleased;
		
		bool pressed = false;
		bool hover = false;
	public:
		Button();
		~Button() override;
		void setOnHoverStart(const std::function<void()>& onHoverStart);
		void setOnHoverEnd(const std::function<void()>& onHoverEnd);
		void setOnButtonPressed(const std::function<void()>& onButtonPressed);
		void setOnButtonReleased(const std::function<void()>& onButtonReleased);
		void onNotify(const sf::Event& event) override;
};

class ButtonBuilder{
	private:
		std::function<void()> onHoverStart;
		std::function<void()> onHoverEnd;
		std::function<void()> onButtonPressed;
		std::function<void()> onButtonReleased;
	public:
		ButtonBuilder& setOnHoverStart(const std::function<void()>& onHoverStart);
		ButtonBuilder& setOnHoverEnd(const std::function<void()>& onHoverEnd);
		ButtonBuilder& setOnButtonPressed(const std::function<void()>& onButtonPressed);
		ButtonBuilder& setOnButtonReleased(const std::function<void()>& onButtonReleased);
		Button create();
		Button* createPtr();
};
