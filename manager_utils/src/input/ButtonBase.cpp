//Coresponding Headerrectangle
#include "manager_utils/input/ButtonBase.h"

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes
#include"sdl_utils/InputEvent.h"

void ButtonBase::draw(){
	Image::draw();		//since we can't call draw() directly cuz we will have infinite loop, we have to manually call the Image::draw() or the Widget directly
}

void ButtonBase::lockInput(){

	_isInputUnlocked = false;
	Image::setFrame(DISABLED);
}

void ButtonBase::unlockInput(){
	_isInputUnlocked = true;

	Image::setFrame(UNCLICKED);
}

bool ButtonBase::isInputUnlocked() const{

	return  _isInputUnlocked;
}

bool ButtonBase::containsEvent(const InputEvent & e){

	return  Image::containsPoint(e.pos);
}


