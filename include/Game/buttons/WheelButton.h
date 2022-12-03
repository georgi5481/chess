#ifndef INCLUDE_GAME_BUTTONS_WHEELBUTTON_H_
#define INCLUDE_GAME_BUTTONS_WHEELBUTTON_H_

//C system includes

//C++ system includes

//3rd-party includes

//Own includes
#include "manager_utils/input/ButtonBase.h"
//Forward Declaration
class GameProxy;

class WheelButton : public ButtonBase {

public:
	int32_t init(GameProxy* gameProxy, int32_t buttonId);
	void handleEvent(const InputEvent &e) final;	//overiding the handle Event logic
													//no need to write virtual destructor. It will create one
private:
GameProxy* _gameProxy = nullptr;
int32_t _buttonId {0};


};
#endif /* INCLUDE_GAME_BUTTONS_WHEELBUTTON_H_ */
