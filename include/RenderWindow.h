#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <Entity.h>
class RenderWindow{
public:
    RenderWindow(const char* windowTitle, int windowWidth, int windowHeight);
    SDL_Texture* loadTexture(const char* filePath);
    void cleanUp();
    void clear();
    void render(Entity& entity);
    void display();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};