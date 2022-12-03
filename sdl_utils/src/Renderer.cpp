//Corresponding header
#include "sdl_utils/Renderer.h"

//C system includes

//C++ system includes
#include<iostream>

//3rd-party includes
#include <SDL_render.h>
#include <SDL_hints.h>

//Own includes
#include"sdl_utils/Texture.h"



int32_t Renderer::init(SDL_Window * window){
	//first we have to hint what we want to fix and then we have to render the image we want.
	if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")){	//1 means it will use linear algorithm
		std::cerr << "Warning: Linear texture filtering not enabled ! "
				"SDL_SetHint() failed. SDL Error:" << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}


	/*giving the SDL_CreateRenderer function:
	 * 1 the window(pointer) where rendering is displayed,
	 * 2 setting -1 for using default driver(DiretX in this case)
	 * 3 A flag for using the hardware acceleration instead of CPU.*/

	constexpr auto unspecifiedDriverId = -1;
	_sdlRenderer = SDL_CreateRenderer(window, unspecifiedDriverId, SDL_RENDERER_ACCELERATED);
	if(_sdlRenderer == nullptr)
	{
		std::cerr << "SDL_CreateRenderer failed. Reason:" << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	//SDL_SetRenderDrawColor will place a color on every pixel on the buffer we are clearing
	if(EXIT_SUCCESS != SDL_SetRenderDrawColor(_sdlRenderer, 0, 0, 200, SDL_ALPHA_OPAQUE)){
		std::cerr << "SDL_SetRenderDrawColor failed. Reason:" << SDL_GetError() << std::endl;
		return EXIT_FAILURE;

	}


	Texture::setRenderer(_sdlRenderer);//will basically set another pointer for the renderer outside the class

	return EXIT_SUCCESS;
}

void Renderer::deinit(){
	if(_sdlRenderer){
	SDL_DestroyRenderer(_sdlRenderer);
	_sdlRenderer = nullptr;
	}
}


void Renderer::clearScreen(){
	if(EXIT_SUCCESS != SDL_RenderClear(_sdlRenderer)){
		std::cerr << "SDL_RenderClear() failed. Reason:" << SDL_GetError() << std::endl;
	}

}

void Renderer::finishFrame(){
	SDL_RenderPresent(_sdlRenderer);	//will swap the pointers to visualise the updated frame
}

void Renderer::renderTexture(SDL_Texture* texture, const DrawParams& drawParams){//SDL_Texture is a primitive we are drawing
	if(WidgetType::IMAGE == drawParams.widgetType){
		drawImage(drawParams, texture);
	}
	else if(WidgetType::TEXT == drawParams.widgetType){
		drawText(drawParams,texture);
	}
	else{
		std::cerr << "Error unknown widgetType : " << static_cast<int>(drawParams.widgetType)
				<< " for rsrcId : " << drawParams.rsrcId << std::endl;
	}
}


void Renderer::setWidgetBledMode(SDL_Texture* texture, BlendMode blendMode){
	//temporary enable alpha blending for all existing textures
	if(EXIT_SUCCESS != Texture::setBlendModeTexture(texture, blendMode)){
			std::cerr << "setBlendModeTexture failed " << std::endl;
		}
}

void Renderer::setWidgetOpacity(SDL_Texture* texture, int32_t opacity){


	if(EXIT_SUCCESS != Texture::setAlphaTexture(texture, opacity)){
		std::cerr << "setAlphaTexture failed " << std::endl;

	}
}



void Renderer::drawText(const DrawParams& drawParams, SDL_Texture* texture){
	drawTextureInternal(drawParams, texture);
}

void Renderer::drawImage(const DrawParams& drawParams, SDL_Texture* texture){

	if(FULL_OPACITY == drawParams.opacity) {
		drawTextureInternal(drawParams, texture);
	}
	else{
		if(EXIT_SUCCESS != Texture::setAlphaTexture(texture, drawParams.opacity)){
			std::cerr << "Texture::setAlphaTexture failed for rsrcId : " << drawParams.rsrcId << std::endl;
		}
		drawTextureInternal(drawParams, texture); //will set the alpha and then draw the image
	}
}

void Renderer::drawTextureInternal(const DrawParams& drawParams, SDL_Texture* texture){
	const SDL_Rect destRect = {.x = drawParams.pos.x, .y = drawParams.pos.y,		//destination rectangle basically sets to place the texture on the left corner with full lenght
								.w = drawParams.width, .h = drawParams.height };

	const SDL_Rect* sourceRect = reinterpret_cast<const SDL_Rect*>(&drawParams.frameRect);
	//reinterpret_cast the memory so that it will treat the same way as the defined
	const SDL_Point* center = reinterpret_cast<const SDL_Point*>(&drawParams.rotationCenter);

	/*first argument - The renderer which should copy parts of a texture
		 * second - The source texture
		 * third - NULL for the entire texture to be displayed, or the dimensions of the window you would like to show
		 * fourth - NULL for the entire rendering target
		 * fifth -an angle in degrees that indicates the rotation of destRect(clockwise)
		 * six - the point of center rotation position
		 * seven - enum mask for a flipping effect*/
	const int32_t err = SDL_RenderCopyEx(_sdlRenderer, texture,sourceRect, &destRect,
			drawParams.rotationAngle , center, static_cast<SDL_RendererFlip>(drawParams.flipType));
	if(EXIT_SUCCESS != err) {
		std::cerr << "RenderCopy() failed for rsrcId():" << drawParams.rsrcId << " Reason : " << SDL_GetError() << std::endl;
	}
}


