#include "Flat.h"
#include <bits/stdc++.h>

Flat::Flat(double _width, double _height, double _lenght) {
    cuboid = Cuboid(_width, _height, _lenght, DEFAULT_COLOR);
    centerOfSymmetry = cuboid.getCenterOfSymmetry();
    hitbox = Hitbox({0,0,0,0,0,0});
    setupHitbox();
}
void Flat::draw() {
    cuboid.draw();
}

void Flat::setColor(std::string _color) {
    color = _color;
    cuboid.setColor(_color);
}

void Flat::translation(Vector<STANDARD_SIZE> translationVector) {
    cuboid.translation(translationVector);
    setupHitbox();
}

void Flat::rotationMain(Vector<STANDARD_SIZE> rotations) {
    cuboid.rotationMain(rotations);
}

void Flat::rotationLocal(Vector<STANDARD_SIZE> rotations) {
    cuboid.rotationLocal(rotations);
}

Vector<STANDARD_SIZE> Flat::getCenterOfSymmetry() {
    return cuboid.getCenterOfSymmetry();
}

void Flat::setupHitbox() {
    double minX = INT_MIN;
    double maxX = INT_MAX;
    double minY = INT_MIN;
    double maxY = INT_MAX;
    double minZ = INT_MIN;
    double maxZ = INT_MAX;

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 4; ++j) {
            if(cuboid[i][j][0] < minX) minX = cuboid[i][j][0];
            if(cuboid[i][j][0] > maxX) maxX = cuboid[i][j][0];
            if(cuboid[i][j][1] < minY) minY = cuboid[i][j][1];
            if(cuboid[i][j][1] > maxY) maxY = cuboid[i][j][1];
            if(cuboid[i][j][2] < minZ) minZ = cuboid[i][j][2];
            if(cuboid[i][j][2] > maxZ) maxZ = cuboid[i][j][2];
        }
    }

    hitbox.setCuboid(minX, maxX, minY, maxY, minZ, maxZ);
}
