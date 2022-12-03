#ifndef INCLUDE_GAME_ENTITIES_HERO_H_
#define INCLUDE_GAME_ENTITIES_HERO_H_

//C system includes

//C++ system includes

//3rd-party includes

//Own includes
#include"manager_utils/drawing/Image.h"
#include"manager_utils/time/TimerClient.h"

//Forward Declaration

struct InputEvent;

class Hero : public TimerClient{

public:
	int32_t init(int32_t heroRsrcId, int32_t moveTimerId);
	void deinit();	//no need cuz it will call the destructor of Image
	void draw();
	void handleEvent(const InputEvent& e);
	void processMoveAnim();

	void startMoveAnim();
private:

	void onTimeout(int32_t timerId) final;

	Image _heroImg;
	int32_t _moveTimerId = -1;	//we set it to -1 cuz we have an element equal to 0
	int32_t moveSteps = 50;
};




#endif /* INCLUDE_GAME_ENTITIES_HERO_H_ */
