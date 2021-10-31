#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class OverlayUI
{
    public:


        sf::RectangleShape createInverseButton();

        sf::Vector2f findFuncMin();
        sf::Vector2f findFuncMax();



        void setFunction(std::string input) {
            function = input;
        };

        std::string getFunction() {
            return function;
        };


    private:
        std::string function;

  
};

