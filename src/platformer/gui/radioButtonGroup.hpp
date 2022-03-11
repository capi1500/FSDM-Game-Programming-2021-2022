#pragma once

#include <set>
#include "radioButton.hpp"

class RadioButtonGroup{
	private:
		std::set<RadioButton*> group;
		void buttonPressed(RadioButton* button) const;
		
		friend class RadioButton;
};


