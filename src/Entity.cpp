#include <Entity.h>
#include <SDL.h>
#include <SDL_image.h>

Entity::Entity(float xPos, float yPos, SDL_Texture *tex, bool solid): xPosition(xPos), yPosition(yPos), texture(tex) {
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32 * 4;
    currentFrame.h = 32 * 4;
    this->solid = solid;
}

float Entity::getX() {
    return xPosition;
}

float Entity::getY() {
    return yPosition;
}

SDL_Texture* Entity::getTexture() {
    return texture;
}

SDL_Rect Entity::getCurrentFrame() {
    return currentFrame;
}

bool Entity::isSolid() {
    return solid;
}