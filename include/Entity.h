#pragma once

#include <SDL.h>
#include <SDL_image.h>

class Entity {
public:
    Entity(float xPos, float yPos, SDL_Texture* tex);
    void init();
    float getX();
    float getY();
    SDL_Texture* getTexture();
    SDL_Rect getCurrentFrame();
private:
    float xPosition, yPosition;
    SDL_Rect currentFrame;
    SDL_Texture* texture;
};