#pragma once

#include "Hitbox.h"

class Obstacle : public Figure{
protected:
    Hitbox hitbox;
public:
    Hitbox* getHitbox() {return &hitbox;}
};



