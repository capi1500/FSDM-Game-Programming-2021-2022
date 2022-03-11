#include <platformer/gui/checkboxButton.hpp>
#include <platformer/framework.hpp>
#include <platformer/gui/longButton.hpp>
#include <platformer/utils/stateMachine.hpp>
#include <platformer/gui/radioButtonGroup.hpp>
#include "settings.hpp"

Settings::Settings(StateMachine& stateMachine) : Scene(stateMachine){
	float centerX = Framework::getRenderer().getSize().x / 2, centerY = Framework::getRenderer().getSize().y / 2;
	
	CheckboxButton* checkboxButton = new CheckboxButton({centerX, centerY},
														[]{},
														[]{},
														false);
	
	RadioButton* radioButton1 = new RadioButton({centerX - 50, centerY - 50},
												[]{},
												[]{},
												false,
												group);
	RadioButton* radioButton2 = new RadioButton({centerX, centerY - 50},
	                                            []{},
	                                            []{},
	                                            true,
	                                            group);
	RadioButton* radioButton3 = new RadioButton({centerX + 50, centerY - 50},
	                                            []{},
	                                            []{},
	                                            false,
	                                            group);
	
	LongButton* returnButton = new LongButton(
			{centerX, centerY + 184},
			"Back",
			[this]{
				getStateMachine().pop();
			});
	
	entities.push_back(radioButton1);
	entities.push_back(radioButton2);
	entities.push_back(radioButton3);
	entities.push_back(checkboxButton);
	entities.push_back(returnButton);
}

void Settings::onNotify(const sf::Event& event){

}
