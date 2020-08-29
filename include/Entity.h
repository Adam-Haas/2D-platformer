#pragma once

#include <SDL.h>
#include <SDL_image.h>

enum EntityOrientation {
    Null,
    FacingLeft,
    FacingRight,
};

class Entity {
public:
    Entity(float xPos, float yPos, SDL_Texture* tex, bool solid);
    float getX();
    float getY();
    SDL_Texture* getTexture();
    SDL_Rect getCurrentFrame();
    bool isSolid();
private:
    bool solid;
    float xPosition, yPosition;
    SDL_Rect currentFrame;
    SDL_Texture* texture;
};