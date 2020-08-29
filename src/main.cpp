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
    SDL_Texture *minerTextureRight = window.loadTexture("res/gfx/miner_right_32.png");
    SDL_Texture *minerTextureLeft = window.loadTexture("res/gfx/miner_left_32.png");

    Entity mainCharacter = Entity(50, windowHeight-(32 * 8), minerTextureRight, true);
    bool gameRunning = true;
    SDL_Event gameEvent;
    while (gameRunning) {
        while (SDL_PollEvent(&gameEvent)) {
            switch (gameEvent.type) {
                case SDL_QUIT:
                    gameRunning = false;
                    break;
                case SDL_KEYDOWN:
                    switch (gameEvent.key.keysym.sym) {
                        case SDLK_LEFT:
                            mainCharacter = Entity(mainCharacter.getX()-8, mainCharacter.getY(), minerTextureLeft, true);
                            break;
                        case SDLK_RIGHT:
                            mainCharacter = Entity(mainCharacter.getX()+8, mainCharacter.getY(), minerTextureRight, true);
                            break;
                        case SDLK_SPACE:
                            mainCharacter = Entity(mainCharacter.getX(), mainCharacter.getY() - 64, minerTextureRight, true);
                            break;
                    }
            }
        }

        window.clear();

        //Draw the floor
        for (int i = 0; i < windowWidth; i+=(32*4)) {
            Entity entity = Entity(i, windowHeight-(32 * 4), grassTexture, true);
            window.render(entity);
        }

        //Draw the character
        window.render(mainCharacter);

        window.display();
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}
