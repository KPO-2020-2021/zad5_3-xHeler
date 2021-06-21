#include "Slope.h"
#include <bits/stdc++.h>

Slope::Slope(double lenght, double height, double width) {
    hitbox = Hitbox({0,0,0,0,0,0});
    Vector v({lenght, 0, 0});
    Vector r({0, 0, width});
    centerOfSymmetry = Vector();

    color = DEFAULT_COLOR;
    basis = Polygon(v, r, Vector(), color);
    basis.translation(-lenght / 2, 0, -width / 2);

    triangles[0] = Polygon<TRIANGLE>({basis[0], basis[1], basis[1] + Vector({0, height, 0})});
    triangles[1] = Polygon<TRIANGLE>({basis[2], basis[3], basis[2] + Vector({0, height, 0})});

    rectangles[0] = Polygon<RECTANGLE>({basis[0], basis[1] + Vector({0, height, 0}),
                                        basis[2] + Vector({0, height, 0}), basis[3]});
    rectangles[1] = Polygon<RECTANGLE>({basis[1], basis[1] + Vector({0, height, 0}),
                                        basis[2] + Vector({0, height, 0}), basis[2]});
    setupObstacle();
}

void Slope::draw() {
    basis.draw();
    for (int i = 0; i < SIDES_W; ++i) {
        triangles[i].draw();
        rectangles[i].draw();
    }
}

void Slope::translation(Vector<STANDARD_SIZE> translationVector) {
    centerOfSymmetry = centerOfSymmetry + translationVector;
    basis.translation(translationVector);
    for (int i = 0; i < SIDES_W; ++i) {
        triangles[i].translation(translationVector);
        rectangles[i].translation(translationVector);
    }
    setupObstacle();
}

void Slope::rotationMain(Vector<STANDARD_SIZE> rotations) {
    centerOfSymmetry.rotateByEulerAngles(rotations[0], rotations[1], rotations[2]);
    basis.rotationMain(rotations);
    for (int i = 0; i < SIDES_W; ++i) {
        triangles[i].rotationMain(rotations);
        rectangles[i].rotationMain(rotations);
    }
}

void Slope::rotationLocal(Vector<STANDARD_SIZE> rotations) {
    Vector tmp = centerOfSymmetry * -1;
    translation(tmp);
    rotationMain(rotations);
    tmp = tmp * -1;
    translation(tmp);
    centerOfSymmetry = tmp;
}

void Slope::setColor(std::string _color) {
    color = _color;
    basis.setColor(color);
    for (int i = 0; i < SIDES_W; ++i) {
        triangles[i].setColor(color);
        rectangles[i].setColor(color);
    }
}

Vector<STANDARD_SIZE> Slope::getCenterOfSymmetry() {
    return centerOfSymmetry;
}

void Slope::setupObstacle() {
    double minX = INT_MAX;
    double maxX = INT_MIN;
    double minY = 0; // state
    double maxY = triangles[0][2][1]; // state
    double minZ = INT_MAX;
    double maxZ = INT_MIN;

    for (int i = 0; i < RECTANGLE; ++i) {
        if (basis[i][0] < minX) minX = basis[i][0];
        if (basis[i][0] > maxX) maxX = basis[i][0];
        if (basis[i][2] < minZ) minZ = basis[i][2];
        if (basis[i][2] > maxZ) maxZ = basis[i][2];
    }
    hitbox.setCuboid(minX, maxX, minY, maxY, minZ, maxZ);
}