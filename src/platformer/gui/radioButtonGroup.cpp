#include "radioButtonGroup.hpp"

void RadioButtonGroup::buttonPressed(RadioButton* button) const{
	for(auto& b : group){
		if(button != b)
			b->onButtonReleased();
	}
}
