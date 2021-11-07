#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Globals.h"

class OverlayUI
{
    public:
        
        sf::RectangleShape createInverseButton();

        sf::Vector2f findFuncMin();
        sf::Vector2f findFuncMax();



        std::string setFunction(std::string input);

        std::string getFunction() {
            return function;
        };


    private:
        std::string function;

  
};

