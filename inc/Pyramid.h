#pragma once

#include "Polygon.h"
#include "Obstacle.h"

const int SIDES = 4;

class Pyramid : public Obstacle {
private:
    std::array<Polygon<TRIANGLE>, SIDES> walls;
    Polygon<RECTANGLE> basis;

    void setupObstacle();
public:
    Pyramid() = default;

    Pyramid(double size, double height);

    void draw() override;

    void translation(Vector<STANDARD_SIZE> translationVector) override;

    void rotationMain(Vector<STANDARD_SIZE> rotations) override;

    void rotationLocal(Vector<STANDARD_SIZE> rotations) override;

    void setColor(std::string _color) override;

    Vector<STANDARD_SIZE> getCenterOfSymmetry() override;
};
