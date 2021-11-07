#include "OverlayUI.h"
#include "Camera.h"
#include <iostream>


	
sf::RectangleShape OverlayUI::createInverseButton()
{
	sf::RectangleShape output;
	
	output.setSize(sf::Vector2f(200, 200));
	output.setPosition(sf::Vector2f(150 /* Camera.zoomScale */, 125 /* Camera.zoomScale*/));


	return output;
}

sf::Vector2f OverlayUI::findFuncMin()
{
	sf::Vector2f lowestPoint;

	for (int i = sf::Window::getSize.x; i < sf::Window::getSize.x / 2, i++) {
		// figure out how each circle of the graph will be numbered
		// figure out how to algorithimically sort to lowest point of y figuire
	}

	return sf::Vector2f();
}





sf::Vector2f OverlayUI::findFuncMax()
{

	// figure out how each circle of the graph will be numbered
	// figure out how to algorithimically sort to highest point of y 

	return sf::Vector2f();
}




std::string OverlayUI::setFunction(std::string input)
{
	std::string function = input;
	

	return function;
}
