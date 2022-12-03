#ifndef GAME_GAME_H_
#define GAME_GAME_H_		//the game class should be the one that holds the game specific logic

//C system includes

//C++ system includes
#include <cstdint>
#include <string>

//3rd-party includes

//Own includes
#include "include/Game/config/GameCfg.h"
#include "manager_utils/drawing/Image.h"
#include "entities/Hero.h"
#include "entities/Wheel.h"
#include "proxies/GameProxy.h"
#include "include/Game/buttons/WheelButton.h"

//Forward Declaration
struct InputEvent;

class Game : public GameProxy{
public:

	int32_t init(const GameCfg& cfg);
	void deinit();
	void draw();
	void handleEvent(const InputEvent& e);

	void process();
private:

	void onButtonPressed(int32_t buttonId) final;	//this is the final override of the function we inherited from GameProxy

	enum Internals {
		WHEEL_START_BTN_IDX,
		WHEEL_STOP_BTN_IDX,
		WHEEL_BTNS_COUNT
	};

	Hero _hero;
	Wheel _wheel;
	Image _blackBgrImage;
	WheelButton _wheelBtns[WHEEL_BTNS_COUNT];
};

#endif /* GAME_GAME_H_ */
