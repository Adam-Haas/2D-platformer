#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <RenderWindow.h>
#include <Entity.h>

const int windowWidth = 1280;
const int windowHeight = 720;

int main(int argc, char *args[]) {
    if (SDL_Init(SDL_INIT_VIDEO) > 0) {
        std::cout << "SDL_Init failure: " << SDL_GetError() << std::endl;
        return 1;
    }

    if (!IMG_Init(IMG_INIT_PNG)) {
        std::cout << "IMG_Init failure: " << SDL_GetError() << std::endl;
        return 1;
    }

    RenderWindow window("GAME v1.0", windowWidth, windowHeight);
    SDL_Texture *grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");

    std::vector<Entity> entities = {Entity(0, 0, grassTexture),
                                    Entity(30, 0, grassTexture),
                                    Entity(30, 30, grassTexture),
                                    Entity(30, 60, grassTexture)};
    bool gameRunning = true;
    SDL_Event gameEvent;
    while (gameRunning) {
        while (SDL_PollEvent(&gameEvent)) {
            if (gameEvent.type == SDL_QUIT)
                gameRunning = false;
        }

        window.clear();
        for (Entity& entity : entities) {
            window.render(entity);
        }

        window.display();
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}
