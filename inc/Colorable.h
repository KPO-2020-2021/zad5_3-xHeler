#pragma once

const std::string DEFAULT_COLOR = "#000000";
const std::string RED = "#FF0000";
const std::string GREEN = "#00FF00";
const std::string BLUE = "#0000FF";
const std::string DBLUE = "#191970";

class Colorable {
protected:
    std::string color;
public:
    virtual void setColor(std::string _color){color = _color;}
};
