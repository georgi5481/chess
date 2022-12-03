#ifndef INCLUDE_GAME_ENTITIES_WHEEL_H_
#define INCLUDE_GAME_ENTITIES_WHEEL_H_

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes
#include"manager_utils/drawing/Image.h"
#include"manager_utils/time/TimerClient.h"
//Forward Declaration
struct InputEvent;

class Wheel : public TimerClient{
public:

	~Wheel();
	int32_t init(int32_t wheelRsrcId, int32_t rotateAnimTimerId, int32_t scaleAnimationTimeId);
	//void deinit(); //no need to deinit cuz it will call the destructor of Image
	void draw();
	void handleEvent(const InputEvent& e);

	void startAnimation();
	void stopAnimation();


private:
	void onTimeout(int32_t timerId) final;
	void processRotAnim();
	void processScaleAnim();

	bool _isAnimationActive = false;
	Image _wheelImg;
	int32_t _rotateAnimTimerId = -1; //since we have 0 element timerIdMgr, we set it to -1
	int32_t _scaleAnimationTimeId = -1;

	int32_t scaleSteps = 50;
	bool isShrinking = true;
};


#endif /* INCLUDE_GAME_ENTITIES_WHEEL_H_ */


