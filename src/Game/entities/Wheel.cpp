//Coresponding Header
#include "include/Game/entities/Wheel.h"
//C system includes

//C++ system includes
#include<cstdint>
#include<iostream>
#include<stdlib.h>
//3rd-party includes

//Own includes
#include "sdl_utils/InputEvent.h"


Wheel::~Wheel(){
	if(isActiveTimerId(_rotateAnimTimerId)) {
		stopTimer(_rotateAnimTimerId);
	}
}

int32_t Wheel::init(int32_t wheelRsrcId, int32_t rotateAnimTimerId, int32_t scaleAnimationTimeId){

	_wheelImg.create(wheelRsrcId);

	Point rotCenter(_wheelImg.getWidth(), _wheelImg.getHeight());
	rotCenter.x /=2;
	rotCenter.y /=2;

	_wheelImg.setRotationPoint(rotCenter);

	_rotateAnimTimerId = rotateAnimTimerId;

	_scaleAnimationTimeId = scaleAnimationTimeId;
	return EXIT_SUCCESS;

}
void Wheel::draw(){
	_wheelImg.draw();
}
void Wheel::handleEvent(const InputEvent& e){

	if(TouchEvent::KEYBOARD_PRESS != e.type){
		return;
	}

	switch(e.key){		//rotation for the wheel
	case Keyboard::KEY_E:
		_wheelImg.rotateRight(10);
		break;
	case Keyboard::KEY_Q:
		_wheelImg.rotateLeft(10);
		break;

	case Keyboard::KEY_P:
		_wheelImg.setRotationPoint(Point::ZERO);
		break;
	case Keyboard::KEY_O:{
		Point rotCenter(_wheelImg.getWidth(), _wheelImg.getHeight());
		rotCenter.x /=2;
		rotCenter.y /=2;

		_wheelImg.setRotationPoint(rotCenter);


		}
		break;


	default:
		break;
	}
}

void Wheel::startAnimation(){
	if(_isAnimationActive){
		std::cerr << "Wheel animation is already active " << std::endl;
		return;
	}
	_isAnimationActive = true;
	startTimer(20, _rotateAnimTimerId, TimerType::PULSE);

	startTimer(100, _scaleAnimationTimeId, TimerType::PULSE);
}

void Wheel::stopAnimation(){
	if(!_isAnimationActive){
		std::cerr << "Wheel animation was not active in the first place. " << std::endl;
		return;
	}

	_isAnimationActive = false;

	stopTimer(_rotateAnimTimerId);
}

void Wheel::processRotAnim(){

	_wheelImg.rotateRight(5);
}

void Wheel::processScaleAnim(){
	--scaleSteps;
	if(0 == scaleSteps){
		isShrinking = !isShrinking;
		scaleSteps = 50;
	}

	if(isShrinking){
		_wheelImg.setHeight(_wheelImg.getHeight() -5);
		_wheelImg.setWidth(_wheelImg.getWidth() -5);
	}
	else{
		_wheelImg.setHeight(_wheelImg.getHeight() + 5);
		_wheelImg.setWidth(_wheelImg.getWidth() +5);
	}
}

void Wheel::onTimeout(int32_t timerId){
	if(timerId == _rotateAnimTimerId){
		processRotAnim();
	}
	else if(timerId == _scaleAnimationTimeId){
		processScaleAnim();
	}
	else{
			std::cerr << "Received id unsuported timerId: " << timerId << std::endl;
	}

}


