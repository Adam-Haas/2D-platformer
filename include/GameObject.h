#include <Entity.h>

enum StepAction {
    MoveLeft,
    MoveRight
};

enum Orientation {
    FacingLeft,
    FacingRight
};

class GameObject : public Entity {
public:
    GameObject(float xPos, float yPos, SDL_Texture* leftFacingText, SDL_Texture* rightFacingText, int mass);
    void step(StepAction action);
    SDL_Texture* getTexture() override;
    Orientation getOrientation();
    int getMass() const;
private:
    Orientation orientation;
    SDL_Texture* leftFacingTexture;
    SDL_Texture* rightFacingTexture;
    int mass;
};