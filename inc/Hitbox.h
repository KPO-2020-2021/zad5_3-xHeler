#pragma once

#include <vector>
#include "Vector.h"

class Hitbox {
protected:
    std::vector<double> points;
    void fillZero(int number);
public:
    Hitbox() = default;

    Hitbox(const std::vector<double> &points);

    void setCuboid(double minX, double maxX, double minY, double maxY, double minZ, double maxZ);

    void setSphere(Vector<STANDARD_SIZE> centerOfSymmetry, double radius);

    void translation(Vector<STANDARD_SIZE> translationVector);

    void translation(double x, double y, double z);

    int getSize() { return points.size(); }

    const double &operator[](int index) const { return points[index]; }

    double &operator[](int index) { return points[index]; }

};

bool isCollisonSphereBox(Hitbox _sphere, Hitbox _box);
bool isCollisonSphereSphere(Hitbox _sphere1, Hitbox _sphere2);