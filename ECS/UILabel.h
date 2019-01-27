#pragma once
#include "ECS.h"
#include "../AssetManager.h"
#include "../Game.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL.h"
#include <string>

class UILabel : public Component
{
public:
    UILabel(int xpos , int ypos , std::string text , std::string font , SDL_Color& color) : 
    labelText(text) , labelfont(font) , textColor(color)
    {
        position.x = xpos;
        position.y = ypos;
        SetLabelText(labelText , font);
    }
    ~UILabel(){}
    void SetLabelText(std::string text , std::string font){
        SDL_Surface* surface = TTF_RenderText_Blended(Game::assets->GetFont(font) , text.c_str() , textColor);
        labelTexture = SDL_CreateTextureFromSurface(Game::renderer , surface );
        SDL_FreeSurface(surface);
        SDL_QueryTexture(labelTexture , nullptr , nullptr , &position.w , &position.h);
    }
    void Draw() override{
        SDL_RenderCopy(Game::renderer , labelTexture , nullptr , &position);
    }

private:
SDL_Rect position;
std::string labelText;
std::string labelfont;
SDL_Color textColor;
SDL_Texture* labelTexture;

};
