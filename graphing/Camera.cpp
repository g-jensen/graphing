
#include "Camera.h"

Camera::Camera(sf::View& view)
{
	this->maxZoom = 256.f;
	this->minZoom = 0.0001f;
	this->zoomScale = 1;
	this->moveSpeed = 50.f;
	this->zoomAmount = 1.5f;
	this->view = view;
}

Camera::Camera(sf::RenderWindow& window)
{
	this->maxZoom = 256.f;
	this->minZoom = 0.0001f;
	this->zoomScale = 1;
	this->moveSpeed = 50.f;
	this->zoomAmount = 1.5f;
	this->view = sf::View(sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f((float)window.getSize().x, (float)window.getSize().y)));
}

void Camera::move(float x, float y)
{
	this->view.move(x, y);
}

void Camera::zoom(float magnitude)
{
	if (zoomScale*magnitude > minZoom && zoomScale*magnitude < maxZoom) {
		this->zoomScale *= magnitude;
		this->view.zoom(magnitude);
	}
}

void Camera::cameraUp(Camera &camera)
{
	camera.move(0, -camera.moveSpeed);
}

void Camera::cameraDown(Camera &camera)
{
	camera.move(0, camera.moveSpeed);
}

void Camera::cameraLeft(Camera &camera)
{
	camera.move(-camera.moveSpeed, 0);
}

void Camera::cameraRight(Camera& camera)
{
	camera.move(camera.moveSpeed, 0);
}