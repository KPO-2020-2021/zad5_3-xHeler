#include "Hitbox.h"


void Hitbox::setCuboid(double minX, double maxX, double minY, double maxY, double minZ, double maxZ) {
    if (points.empty()) { fillZero(6); }
    points[0] = minX;
    points[1] = maxX;
    points[2] = minY;
    points[3] = maxY;
    points[4] = minZ;
    points[5] = maxZ;

}

void Hitbox::setSphere(Vector<STANDARD_SIZE> centerOfSymmetry, double radius) {
    if (points.empty()) { fillZero(4); }
    points[0] = centerOfSymmetry[0];
    points[1] = centerOfSymmetry[1];
    points[2] = centerOfSymmetry[2];
    points[3] = radius;
}

void Hitbox::translation(double x, double y, double z) {
    if (points.size() == 4) {
        points[0] = points[0] + x;
        points[1] = points[1] + y;
        points[2] = points[2] + z;

    } else if (points.size() == 6) {
        points[0] = points[0] + x;
        points[1] = points[1] + x;
        points[2] = points[2] + y;
        points[3] = points[3] + y;
        points[4] = points[4] + z;
        points[5] = points[5] + z;
    }
}

void Hitbox::translation(Vector<STANDARD_SIZE> translationVector) {
    translation(translationVector[0], translationVector[1], translationVector[2]);
}

void Hitbox::fillZero(int number) {
    for (int i = 0; i < number; ++i) {
        points.push_back(0);
    }
}

Hitbox::Hitbox(const std::vector<double> &points) : points(points) {}

bool isCollisonSphereBox(Hitbox _sphere, Hitbox _box) {
    if (_box.getSize() != 6 || _sphere.getSize() != 4) throw std::invalid_argument("isCollisionSphereBox error!\n");
    double x = std::max(_box[0], std::min(_sphere[0], _box[1]));
    double y = std::max(_box[2], std::min(_sphere[1], _box[3]));
    double z = std::max(_box[4], std::min(_sphere[2], _box[5]));

    double distance = sqrt((x - _sphere[0]) * (x - _sphere[0]) +
                           (y - _sphere[1]) * (y - _sphere[1]) +
                           (z - _sphere[2]) * (z - _sphere[2]));
    return distance < _sphere[3];
}

bool isCollisonSphereSphere(Hitbox _sphere1, Hitbox _sphere2) {
    double distance = sqrt((_sphere1[0] - _sphere2[0]) * (_sphere1[0] - _sphere2[0]) +
                           (_sphere1[1] - _sphere2[1]) * (_sphere1[1] - _sphere2[1]) +
                           (_sphere1[2] - _sphere2[2]) * (_sphere1[2] - _sphere2[2]));
    return distance < (_sphere1[3] + _sphere2[3]);
}
