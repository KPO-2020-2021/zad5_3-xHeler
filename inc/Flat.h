#pragma once

#include "Cuboid.h"
#include "Obstacle.h"


class Flat : public Obstacle{
private:
    Cuboid cuboid;

    void setupHitbox();
public:
    Flat(double _width, double _height, double _lenght);

    void draw() override;

    void setColor(std::string _color) override;

    void translation(Vector<STANDARD_SIZE> translationVector) override;

    void rotationMain(Vector<STANDARD_SIZE> rotations) override;

    void rotationLocal(Vector<STANDARD_SIZE> rotations) override;

    Vector<STANDARD_SIZE> getCenterOfSymmetry() override;
};