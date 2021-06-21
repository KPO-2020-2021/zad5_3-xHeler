#pragma once

#include "Vector.h"

class Moveable {
protected:
    Vector<STANDARD_SIZE> centerOfSymmetry;
public:
    virtual void translation(Vector<STANDARD_SIZE> translationVector){}

    virtual void rotationMain(Vector<STANDARD_SIZE> rotations){}

    virtual void rotationLocal(Vector<STANDARD_SIZE> rotations){}

    virtual Vector<STANDARD_SIZE> getCenterOfSymmetry() { return centerOfSymmetry;}
};