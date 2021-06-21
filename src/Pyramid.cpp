#include "Pyramid.h"
#include <bits/stdc++.h>

Pyramid::Pyramid(double size, double height) {
    hitbox = Hitbox({0,0,0,0,0,0});
    Vector v({size, 0, 0});
    Vector w({size / 2, height, size / 2});
    Vector r({0, 0, size});

    color = DEFAULT_COLOR;
    basis = Polygon(v, r, Vector(), color);
    walls[0] = Polygon<TRIANGLE>({basis[0], basis[1], w});
    walls[1] = Polygon<TRIANGLE>({basis[1], basis[2], w});
    walls[2] = Polygon<TRIANGLE>({basis[2], basis[3], w});
    walls[3] = Polygon<TRIANGLE>({basis[3], basis[0], w});

    translation(Vector({-size / 2, 0, -size / 2}));
    centerOfSymmetry = Vector();
    setupObstacle();
}

void Pyramid::draw() {
    basis.draw();
    for (int i = 0; i < SIDES; ++i) {
        walls[i].draw();
    }
}

void Pyramid::translation(Vector<STANDARD_SIZE> translationVector) {
    centerOfSymmetry = centerOfSymmetry + translationVector;
    basis.translation(translationVector);
    for (int i = 0; i < SIDES; ++i) {
        walls[i].translation(translationVector);
    }
    setupObstacle();
}

void Pyramid::rotationMain(Vector<STANDARD_SIZE> rotations) {
    centerOfSymmetry.rotateByEulerAngles(rotations[0], rotations[1], rotations[2]);
    basis.rotationMain(rotations);
    for (int i = 0; i < SIDES; ++i) {
        walls[i].rotationMain(rotations);
    }
}

void Pyramid::rotationLocal(Vector<STANDARD_SIZE> rotations) {
    Vector tmp = centerOfSymmetry * -1;
    translation(tmp);
    rotationMain(rotations);
    tmp = tmp * -1;
    translation(tmp);
    centerOfSymmetry = tmp;
}

void Pyramid::setColor(std::string _color) {
    color = _color;
    basis.setColor(color);
    for (int i = 0; i < SIDES; ++i) {
        walls[i].setColor(color);
    }
}

Vector<STANDARD_SIZE> Pyramid::getCenterOfSymmetry() {
    return centerOfSymmetry;
}

void Pyramid::setupObstacle() {
    double minX = INT_MAX;
    double maxX = INT_MIN;
    double minY = 0; // state
    double maxY = walls[0][2][1]; // state
    double minZ = INT_MAX;
    double maxZ = INT_MIN;

    for (int i = 0; i < RECTANGLE; ++i) {
        if(basis[i][0] < minX) minX = basis[i][0];
        if(basis[i][0] > maxX) maxX = basis[i][0];
        if(basis[i][2] < minZ) minZ = basis[i][2];
        if(basis[i][2] > maxZ) maxZ = basis[i][2];
    }
    hitbox.setCuboid(minX, maxX, minY, maxY, minZ, maxZ);
}
