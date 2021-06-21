#pragma once

#include "Polygon.h"
#include "Obstacle.h"

const int SIDES_W = 2;

class Slope : public Obstacle {
private:
    Polygon<RECTANGLE> basis;
    std::array<Polygon<TRIANGLE>, SIDES_W> triangles;
    std::array<Polygon<RECTANGLE>, SIDES_W> rectangles;

    void setupObstacle();
public:
    Slope() = default;
    Slope(double lenght,  double height, double width);

    void draw() override;

    void translation(Vector<STANDARD_SIZE> translationVector) override;

    void rotationMain(Vector<STANDARD_SIZE> rotations) override;

    void rotationLocal(Vector<STANDARD_SIZE> rotations) override;

    void setColor(std::string _color) override;

    Vector<STANDARD_SIZE> getCenterOfSymmetry() override;

};