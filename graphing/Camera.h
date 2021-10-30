#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Camera
{
public:
	float zoomScale;
	float zoomAmount;
	float moveSpeed;
	sf::View view;
	Camera(sf::View& view);
	Camera(sf::RenderWindow& window);
	void move(float x, float y);
	void zoom(float magnitude);
	static void cameraUp(Camera &camera);
	static void cameraDown(Camera &camera);
	static void cameraLeft(Camera &camera);
	static void cameraRight(Camera &camera);
private:
	float maxZoom;
	float minZoom;
};

