#pragma once

#include "Camera.h"
#include <SFML/Window/ContextSettings.hpp>

#ifndef GLOBALS
#define GLOBALS

class Globals {
public:
	static sf::RenderWindow* window;
	static sf::ContextSettings settings;
	static Camera camera;
	// static sf::Font font;
	// static bool fontHasBeenLoaded;
	// static void loadFont(std::string path);
};

//void Globals::loadFont(std::string path) {
//	if (!Globals::fontHasBeenLoaded) {
//		Globals::font.loadFromFile(path);
//		Globals::fontHasBeenLoaded = true;
//	}
//}

// bool Globals::fontHasBeenLoaded = false;
sf::ContextSettings Globals::settings = sf::ContextSettings(0,0,8);
sf::RenderWindow* Globals::window = new sf::RenderWindow(sf::VideoMode(1520, 980), "My window", sf::Style::Default,Globals::settings);
Camera Globals::camera(*Globals::window);


#endif