#pragma once

#include <SDL.h>
#include <SDL_image.h>

class Entity {
public:
    Entity(float xPos, float yPos, SDL_Texture* tex, bool solid);
    float getX();
    float getY();
    virtual SDL_Texture* getTexture();
    SDL_Rect getCurrentFrame();
    bool isSolid();
private:
    SDL_Rect currentFrame;
    SDL_Texture* texture;
    bool solid;
protected:
    float xPosition, yPosition;
};