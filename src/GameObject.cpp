#include <GameObject.h>

GameObject::GameObject(float xPos, float yPos, SDL_Texture *leftFacingText, SDL_Texture *rightFacingText, int mass)
        : Entity(xPos, yPos, rightFacingText, true) {
    orientation = FacingRight;
    this->leftFacingTexture = leftFacingText;
    this->rightFacingTexture = rightFacingText;
    this->mass = mass;
}

void GameObject::step(StepAction action) {
    switch (action) {
        case MoveLeft:
            orientation = FacingLeft;
            xPosition -= (1 * 8);
            break;
        case MoveRight:
            orientation = FacingRight;
            xPosition += (1 * 8);
            break;
    }
}

SDL_Texture *GameObject::getTexture() {
    if (getOrientation() == FacingLeft) {
        return leftFacingTexture;
    } else {
        return rightFacingTexture;
    }
}

Orientation GameObject::getOrientation() {
    return orientation;
}

int GameObject::getMass() const {
    return mass;
}