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

	return sf::Vector2f();
}





sf::Vector2f OverlayUI::findFuncMax()
{
	return sf::Vector2f();
}
