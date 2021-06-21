#pragma once

#include "Moveable.h"
#include "Drawable.h"
#include "Colorable.h"

class Figure : public Drawable, public Moveable, public Colorable{};