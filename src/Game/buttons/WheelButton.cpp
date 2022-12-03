//Coresponding Header
#include "include/Game/buttons/WheelButton.h"
//C system includes

//C++ system includes
#include<iostream>
//3rd-party includes

//Own includes
#include "sdl_utils/InputEvent.h"
#include "include/Game/proxies/GameProxy.h"

int32_t WheelButton::init(GameProxy* gameProxy, int32_t buttonId){

	if(gameProxy == nullptr){		//first we check the included pointer
		std::cerr << "nullptr provided for gameProxy for ButtonId: " << buttonId << std::endl;
		return EXIT_FAILURE;
	}
_gameProxy = gameProxy;
_buttonId = buttonId;

	return EXIT_SUCCESS;
}


void WheelButton::handleEvent(const InputEvent &e){		//overriding the method
	if(e.type == TouchEvent::TOUCH_PRESS){
		setFrame(CLICKED);
	}
	else if(e.type == TouchEvent::TOUCH_RELEASE){
		setFrame(UNCLICKED);
		_gameProxy->onButtonPressed(_buttonId);
	}
}
