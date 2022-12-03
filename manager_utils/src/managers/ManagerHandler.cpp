//Coresponding Header
#include "manager_utils/managers/ManagerHandler.h"

//C system includes
#include <cstdint>
#include<iostream>
//C++ system includes

//3rd-party includes

//Own includes
#include "manager_utils/config/ManagerHandlerCfg.h"
#include "manager_utils/managers/DrawMgr.h"
#include "manager_utils/managers/RsrcMgr.h"
#include "manager_utils/managers/TimerMgr.h"


int32_t ManagerHandler::init(const ManagerHandlerCfg& cfg){

		//DRAW MANAGER INITIALIZATION
	gDrawMgr = new DrawMgr();

	if(gDrawMgr == nullptr) {
		std::cerr << "Error, bad alloc for DrawMgr" << std::endl;
			return EXIT_FAILURE;
	}
	if (EXIT_SUCCESS != gDrawMgr->init(cfg.drawMgrCfg)){
			std::cerr << "gDrawMgr init() failed. Reason: " << std::endl;
			return EXIT_FAILURE;
	}


		//RESOURCE MANAGER INITIALIZATION
	gRsrcMgr = new RsrcMgr();

	if(gRsrcMgr == nullptr) {
		std::cerr << "Error, bad alloc for gRsrcMgr" << std::endl;
			return EXIT_FAILURE;
	}
	if (EXIT_SUCCESS != gRsrcMgr->init(cfg.rsrcMgrCfg)){
			std::cerr << "gRsrcMgr init() failed. Reason: " << std::endl;
			return EXIT_FAILURE;
	}


		//TIMER MANAGER INITIALIZATION
	gTimerMgr = new TimerMgr();

	if(gTimerMgr == nullptr) {
		std::cerr << "Error, bad alloc for TimerMgr" << std::endl;
			return EXIT_FAILURE;
	}
	if (EXIT_SUCCESS != gTimerMgr->init()){
			std::cerr << "gTimerMgr init() failed. Reason: " << std::endl;
			return EXIT_FAILURE;
	}




		//downcasting pointers to MgrBase so that later on when we call the virtual deinit method
		//it will call their base deinit methods
	_managers[DRAW_MGR_IDX] = static_cast<MgrBase*>(gDrawMgr);
	_managers[RSRC_MGR_IDX] = static_cast<MgrBase*>(gRsrcMgr);
	_managers[TIMER_MGR_IDX] = static_cast<MgrBase*>(gTimerMgr);
	return EXIT_SUCCESS;
}


void ManagerHandler::deinit(){

	//we use polymorpfic deinit methods
	for(int32_t i = MANAGERS_COUNT -1; i >= 0 ; i--){		//we have to deinitialise backwards
		_managers[i]->deinit();
		_managers[i] = nullptr;
	}
}

void ManagerHandler::process(){
	//we use polymorpfic process methods
	for(int32_t i = 0; i < MANAGERS_COUNT; ++i){		//caling the proces vitual function
		_managers[i]->process();						//that will override with the correct process method
	}

}

void ManagerHandler::nullifyGlobalMgr(int32_t mgrIdx){
	switch(mgrIdx){
	case DRAW_MGR_IDX:
		delete gDrawMgr;
		gDrawMgr = nullptr;
		break;
	case RSRC_MGR_IDX:
		delete gRsrcMgr;
		gRsrcMgr = nullptr;
		break;
	case TIMER_MGR_IDX:
		delete gRsrcMgr;
		gTimerMgr = nullptr;
		break;
	default:
		std::cerr << "Received invalid mgrIdx: " << mgrIdx << std::endl;
		break;
	}
}
