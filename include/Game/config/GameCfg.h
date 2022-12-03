#ifndef GAME_CONFIG_GAMECFG_H_
#define GAME_CONFIG_GAMECFG_H_

//C system includes

//C++ system includes
#include<cstdint>
#include<unordered_map>
//3rd-party includes

//Own includes

//Forward Declaration

struct GameCfg {
	int32_t runningGirlRsrcId;
	int32_t wheelRsrcId;
	int32_t blackBgrImage;

	int32_t startButtonRsrcId;
	int32_t stopButtonRsrcId;

	int32_t textFontId;

	int32_t wheelRotAnimTimerId;
	int32_t wheelScaleAnimTimerId;

	int32_t moveGirlTimerId;
};


#endif /* GAME_CONFIG_GAMECFG_H_ */
