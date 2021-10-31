#pragma once

#include "Camera.h"
#include <SFML/Window/ContextSettings.hpp>

#ifndef GLOBALS
#define GLOBALS

namespace Globals {
	sf::ContextSettings settings(0,0,8);
	sf::RenderWindow window(sf::VideoMode(1520, 980), "My window", sf::Style::Default,settings);
	Camera camera(window);
}

#endif