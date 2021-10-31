#pragma once

#include "Camera.h"

#ifndef GLOBALS
#define GLOBALS

namespace Globals {
	sf::RenderWindow window(sf::VideoMode(1520, 980), "My window");
	Camera camera(window);
}

#endif