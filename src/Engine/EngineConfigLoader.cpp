//Corresponding header
#include "include/Engine/EngineConfigLoader.h"
//C++ headers
#include<cstdint>

//3rd-party includes


//Own includes
#include "include/common/commonDefines.h"

//constants
namespace{		//the anonymous namespace will work only on this .cpp file
constexpr auto WINDOW_WIDTH = 1024;
constexpr auto WINDOW_HEIGHT = 800;
constexpr auto WINDOW_NAME = "Animations";


constexpr auto BLACK_BGR_WIDTH = 1920;
constexpr auto BLACK_BGR_HEIGHT = 1080;

constexpr auto RUNNING_GIRL_FRAMES = 6;
constexpr auto RUNNING_GIRL_WIDTH = 256;			//here you can scale manually the pictures or better set the right dimensions
constexpr auto RUNNING_GIRL_HEIGHT = 220;

constexpr auto BUTTON_FRAMES = 3;
constexpr auto BUTTON_WIDTH = 150;
constexpr auto BUTTON_HEIGHT = 50;

constexpr auto WHEEL_IMG_WIDTH_HEIGHT = 695;

constexpr auto MAX_FRAMERATE = 30;

constexpr auto ANGELINE_VINTAGE_40_FONTSIZE = 80;	//we can load the same font with a different size аt the same time
}

static std::string getFilePath(const std::string& relativePath){
#ifdef RELEASE_BUILD
	return relativePath;
#else
	return /*"../" +*/ relativePath;
#endif
}

static void populateImageContainerConfig(ImageContainerCfg& cfg){

	ImageCfg imageCfg;
	imageCfg.location = getFilePath("resources/pictures/sprites/running_girl.png");
	for(auto i = 0; i < RUNNING_GIRL_FRAMES; ++i){
		imageCfg.frames.emplace_back(i * RUNNING_GIRL_WIDTH,	//x	of the rectangle to visualise
										0,						//y of the rectangle to visualise
										RUNNING_GIRL_WIDTH,		//width
										RUNNING_GIRL_HEIGHT);	//height
	}

	cfg.imageConfigs.emplace(TextureId::RUNNING_GIRL,imageCfg);	//we have to pair them first with the ID

	imageCfg.frames.clear();	//clear the config and start implementing it again for the next image


	constexpr auto buttonCount = 2;
	const std::string buttonsPath[buttonCount]{
		"resources/pictures/buttons/button_start.png",	//we intentionally do not call the getFilePath function. We call it down bellow
		"resources/pictures/buttons/button_stop.png"
	};

	constexpr int32_t buttonRsrcIds[buttonCount] = {
			TextureId::START_BUTTON, TextureId::STOP_BUTTON
	};
	for(int32_t i = 0; i < buttonCount; ++i){
		imageCfg.location = getFilePath(buttonsPath[i]);
		for(auto frameId = 0; frameId < BUTTON_FRAMES; ++frameId){
			imageCfg.frames.emplace_back(frameId * BUTTON_WIDTH,	//x	of the rectangle to visualise
											0,						//y of the rectangle to visualise
											BUTTON_WIDTH,		//width
											BUTTON_HEIGHT);	//height
		}

		cfg.imageConfigs.emplace(buttonRsrcIds[i],imageCfg);	//we have to pair them first with the ID

		imageCfg.frames.clear();	//clear the config and start implementing it again for the next image

	}



	imageCfg.location = getFilePath("resources/pictures/wheel.png");

	imageCfg.frames.emplace_back(	0,							//x of the rectangle to visualise
									0,							//y of the rectangle to visualise
									WHEEL_IMG_WIDTH_HEIGHT,		//width
									WHEEL_IMG_WIDTH_HEIGHT);	//height (same cuz its a circle)

	cfg.imageConfigs.emplace(TextureId::WHEEL,imageCfg);
	imageCfg.frames.clear();

	imageCfg.location = getFilePath("resources/pictures/blackBackground.png");

		imageCfg.frames.emplace_back(	0,						//x of the rectangle to visualise
										0,						//y of the rectangle to visualise
										BLACK_BGR_WIDTH,		//width
										BLACK_BGR_HEIGHT);		//height

		cfg.imageConfigs.emplace(TextureId::BLACK_BACKGROUND,imageCfg);
		imageCfg.frames.clear();
}


static void populateTextContainerConfig(TextContainerCfg& cfg){
	FontCfg fontCfg;
	fontCfg.location = getFilePath("resources/fonts/AngelineVintage.ttf");
	fontCfg.fontSize = ANGELINE_VINTAGE_40_FONTSIZE;

	cfg.fontConfigs.insert(std::make_pair(FontId::ANGELINE_VINTAGE_40,fontCfg));	//we have to pair them first with the ID

}


static void populateMonitorConfig(MonitorWindowCfg& cfg){
	cfg.windowName = WINDOW_NAME;
	cfg.windowWidth = WINDOW_WIDTH;
	cfg.windowHeight = WINDOW_HEIGHT;
	cfg.windowFlags = WINDOW_SHOWN;
}

static void populateRsrcMgrConfig(RsrcMgrCfg& cfg){		//for better reading when configuring cown bellow

	populateImageContainerConfig(cfg.imageContainerCfg);
	populateTextContainerConfig(cfg.textContainerCfg);
}


static void populateDrawMgrConfig(DrawMgrCfg& cfg){		//for better reading when configuring cown bellow

	populateMonitorConfig(cfg.windowCfg);

	cfg.maxFrameRate = MAX_FRAMERATE;
}


void populateManagerHandlerCfg(ManagerHandlerCfg& cfg){
	populateDrawMgrConfig(cfg.drawMgrCfg);
	populateRsrcMgrConfig(cfg.rsrcMgrCfg);
}

static void populateGameConfig(GameCfg& cfg){
	cfg.runningGirlRsrcId = TextureId::RUNNING_GIRL;
	cfg.wheelRsrcId = TextureId::WHEEL;
	cfg.blackBgrImage = TextureId::BLACK_BACKGROUND;

	cfg.startButtonRsrcId = TextureId::START_BUTTON;
	cfg.stopButtonRsrcId = TextureId::STOP_BUTTON;

	cfg.textFontId = FontId::ANGELINE_VINTAGE_40;	//place unique key for our flyweight design pattern

	cfg.wheelRotAnimTimerId = TimerId::WHEEL_ROT_ANIM_TIMER_ID;
	cfg.moveGirlTimerId = TimerId::MOVE_GIRL_TIMER_ID;
	cfg.wheelScaleAnimTimerId = TimerId:: SCALE_WHEEL_TIMER_ID;

}






EngineConfig EngineConfigLoader::loadConfig(){
	EngineConfig cfg;
	populateManagerHandlerCfg(cfg.managerHandlerCfg);

	populateGameConfig(cfg.gameCfg);

	return cfg;
}
