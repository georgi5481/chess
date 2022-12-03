//Coresponding Header
#include "include/Game/entities/Hero.h"
//C system includes

//C++ system includes
#include<cstdint>
#include<stdlib.h>
#include<iostream>
//3rd-party includes

//Own includes
#include "sdl_utils/InputEvent.h"


int32_t Hero::init(int32_t heroRsrcId, int32_t moveTimerId)
{
	_heroImg.create(heroRsrcId, Point(0,0));


	_moveTimerId = moveTimerId;
return EXIT_SUCCESS;
}

void Hero::deinit(){	//no need for implementation. It will call the destructor of image

}


void Hero::draw(){
_heroImg.draw();
}


void Hero::startMoveAnim(){
	startTimer(50, _moveTimerId, TimerType::PULSE);
}


void Hero::handleEvent(const InputEvent& e){

	if(TouchEvent::KEYBOARD_PRESS != e.type){
		return;
	}

	switch(e.key){
	case Keyboard::KEY_RIGHT:
		_heroImg.setFlipType(WidgetFlip::NONE);
		_heroImg.setNextFrame();
		_heroImg.moveRight(10);
		break;
	case Keyboard::KEY_LEFT:
		_heroImg.setFlipType(WidgetFlip::HORIZONTAL);
		_heroImg.setPrevFrame();
		_heroImg.moveLeft(10);
		break;

	case Keyboard::KEY_DOWN:
		_heroImg.setNextFrame();
		_heroImg.moveDown(10);
		break;
	case Keyboard::KEY_UP:
		_heroImg.setPrevFrame();
		_heroImg.moveUp(10);
		break;
		//rotation
	case Keyboard::KEY_E:
		_heroImg.rotateRight(10);
		break;
	case Keyboard::KEY_Q:
		_heroImg.rotateLeft(10);
		break;

	default:
		break;
	}
}

void Hero::onTimeout(int32_t timerId) {
	if(timerId == _moveTimerId){
		processMoveAnim();
	}
	else{
			std::cerr << "Received id unsuported timerId: " << timerId << std::endl;
	}
}


void Hero::processMoveAnim(){	//we want our hero to move
	--moveSteps;

	_heroImg.moveRight(5);
	_heroImg.setNextFrame();

	if(moveSteps == 0){
		stopTimer(_moveTimerId);
	}
}


