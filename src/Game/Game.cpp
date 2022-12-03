//Corresponding header
#include "include/Game/Game.h"
//C system includes

//C++ system includes
#include<cstdint>
#include<iostream>
//3rd-party includes


//Own components includes
//#include "sdl_utils/config/MonitorWindowCfg.h"
#include "sdl_utils/InputEvent.h"

int32_t Game::init(const GameCfg& cfg){

	if(EXIT_SUCCESS != _hero.init(cfg.runningGirlRsrcId, cfg.moveGirlTimerId)){
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != _wheel.init(cfg.wheelRsrcId, cfg.wheelRotAnimTimerId, cfg.wheelScaleAnimTimerId)){
		return EXIT_FAILURE;
	}


	const int32_t buttonRsrcIds[WHEEL_BTNS_COUNT] = {
			cfg.startButtonRsrcId, cfg.stopButtonRsrcId
	};
	const Point buttonStartPos[WHEEL_BTNS_COUNT] = {
			Point(650, 100), Point(830,100)
	};

	for(int32_t i = 0;  i < WHEEL_BTNS_COUNT; i++){

		//in init method down bellow-
		//since our first argument is and instance of gameProxy object, but we inherrit it on Game class
		//we will use 'this' pointer and it will downcast it to gameProxy
		if(EXIT_SUCCESS != _wheelBtns[i].init(this, i)){
			std::cerr << "_wheelBtns[" << i << "].init() failed." << std::endl;
			return EXIT_FAILURE;
		}
		_wheelBtns[i].create(buttonRsrcIds[i], buttonStartPos[i]);
	}

	_blackBgrImage.create(cfg.blackBgrImage);
	_blackBgrImage.activateAlphaModulation();
	_blackBgrImage.setOpacity(ZERO_OPACITY);


	_wheelBtns[WHEEL_STOP_BTN_IDX].lockInput();

	return EXIT_SUCCESS;
}

void Game::deinit(){
	_hero.deinit();
}

void Game::draw(){

	_wheel.draw();
	_hero.draw();

	for(int32_t i = 0;  i < WHEEL_BTNS_COUNT; i++){
		_wheelBtns[i].draw();
	}

	_blackBgrImage.draw();	//want to draw it lastly
}

void Game::handleEvent(const InputEvent& e){

	for(int32_t i = 0;  i < WHEEL_BTNS_COUNT; ++i){

		//first we check if the button is unlocked for pressing and does the click happened inside the area
		if(_wheelBtns[i].isInputUnlocked() && _wheelBtns[i].containsEvent(e)){
			_wheelBtns[i].handleEvent(e);
			return;
		}


	}

	_hero.handleEvent(e);
	_wheel.handleEvent(e);


	if(TouchEvent::KEYBOARD_RELEASE != e.type){	//if we don't touch with the mouse - do nothing
			if(Keyboard::KEY_NUMPAD_1 == e.key){
			_blackBgrImage.setOpacity(_blackBgrImage.getOpacity() + 10);
		}
		else if(Keyboard::KEY_NUMPAD_2 == e.key){
			_blackBgrImage.setOpacity(_blackBgrImage.getOpacity() - 10);
		}
	}

}



void Game::onButtonPressed(int32_t buttonId){

	switch(buttonId){
	case WHEEL_START_BTN_IDX:
		_wheelBtns[WHEEL_START_BTN_IDX].lockInput();	//if we pressed the button we lock it to do something.
		_wheelBtns[WHEEL_STOP_BTN_IDX].unlockInput();
		_wheel.startAnimation();
		_hero.startMoveAnim();
		break;
	case WHEEL_STOP_BTN_IDX:
		_wheelBtns[WHEEL_START_BTN_IDX].unlockInput();	//the same logic(backwards) for the stop button on the display
		_wheelBtns[WHEEL_STOP_BTN_IDX].lockInput();
		_wheel.stopAnimation();
		break;
	default:
		std::cerr << "Received unsuported buttonId: " << buttonId << std::endl;
		break;
}
}





