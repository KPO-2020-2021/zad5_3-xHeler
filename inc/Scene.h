#pragma once

#include <vector>
#include "Slope.h"
#include "Pyramid.h"
#include "Drone.h"
#include "Command.h"
#include "Obstacle.h"
#include "Flat.h"

const double ALTITUDE = 200;
const int AMOUNT_OF_LINES = 3;

class Scene {
private:
    std::vector<Drone> drons;
    std::vector<Command> commands;
    std::vector<Figure*> terrainElements;
    std::vector<Hitbox*> obstacles;
    std::array<Polygon<LINE>, AMOUNT_OF_LINES> lines;
    int droneNumber;

    void droneCommandCenter();
    bool isTranslationDone();
    bool isRotationDone();
    void setPath();
    void clearPath();
public:
    Scene(double scale = 0.5);

    void draw();

    void activateDrone();
    void startDrone();
    void landDrone();
    void rotateDrone();
    void flyForwardDrone();
    void addTerrainElement();
    void deleteTerrainElement();
};