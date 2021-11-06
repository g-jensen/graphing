#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "Camera.h"
#include "Globals.h"
#include "addNode.h"
#include "numNode.h"
#include "multNode.h"
#include "divideNode.h"
#include "variableNode.h"

// removes the trailing zeros of a number
// ex: 15.430000 -> 15.43
std::string trimZeros(std::string input) {
    int i = input.length() - 1;
    while (input[i] == '0') {
        input.pop_back();
        i--;
    }
    if (input[input.length() - 1] == '.') {
        input.pop_back();
    }
    return input;
}

// Takes in normal coordinates and returns the coordinates to plot that in SFML
sf::Vector2f plot(sf::Vector2f v) {
    return sf::Vector2f(v.x,-v.y);
}

// Returns the circles to draw of a function
std::vector<sf::CircleShape> getGraph(exprNode* root) {
    std::vector<sf::CircleShape> output;
    sf::View view = Globals::window->getView();

    for (
            float x = view.getCenter().x - (view.getSize().x / 2.0f);
            x <= view.getCenter().x + (view.getSize().x / 2.0f); 
            x += 0.1 * (Globals::camera.zoomScale / 0.0171801f)
        ) {
        sf::CircleShape circle;
        //circle.setSize(sf::Vector2f(Globals::camera.zoomScale * 2, Globals::camera.zoomScale * 2));
        circle.setRadius(Globals::camera.zoomScale * 2);



        circle.setPosition(
            plot(
                sf::Vector2f(x,root->eval(x))
            )
        );



        if (circle.getPosition().y >= view.getCenter().y - view.getSize().y / 2.0 && circle.getPosition().y <= view.getCenter().y + view.getSize().y / 2.0) {
            output.push_back(circle);
        }
    }

    return output;
}

// returns rectangle to draw the x-axis
sf::RectangleShape xaxis() {
    sf::View view = Globals::window->getView();
    sf::RectangleShape output(sf::Vector2f(view.getSize().x, Globals::camera.zoomScale * 2));
    output.setPosition(view.getCenter().x - (view.getSize().x / 2.0f), 0);
    return output;
}

sf::Font font;
// returns a list of texts that are the numbers on the numberline that are visible in the view
std::vector<sf::Text> xNumberline() {
    font.loadFromFile("fonts/Ubuntu-Regular.ttf");
    std::vector<sf::Text> output;
    sf::View view = Globals::camera.view;

    int farLeftX = view.getCenter().x - (view.getSize().x / 2.0f);
    long double farRightX = view.getCenter().x + (view.getSize().x / 2.0f);

    long double increment = 5.f * Globals::camera.zoomScale / 0.0171801f;

    long double start = 0;
    while (start > farLeftX) {
        start -= increment;
    }
    if (start == 0) {
        while (start < farLeftX) {
            start += increment;
        }
        start -= increment;
    }

    long double end = 0;
    while (end < farRightX) {
        end += increment;
    }
    if (end == 0) {
        while (end > farRightX) {
            end -= increment;
        }
        end += increment;
    }
    

    if (0 >= start && 0 <= farRightX) {
        sf::Text zero;
        zero.setFont(font);
        zero.setScale(Globals::camera.zoomScale, Globals::camera.zoomScale);
        zero.setString("0");
        zero.setPosition(plot(sf::Vector2f(0, -0.1 * Globals::camera.zoomScale / 0.0171801f)));
        output.push_back(zero);
    }

    for (long double x = start; x <= end; x += increment) {
        sf::Text text;
        text.setFont(font);
        text.setScale(Globals::camera.zoomScale, Globals::camera.zoomScale);
        text.setString(trimZeros(std::to_string(x)));
        text.setPosition(plot(sf::Vector2f(x,-0.1 * Globals::camera.zoomScale / 0.0171801f)));
        output.push_back(text);
    }
    // std::cout << output.size() << std::endl;
    return output;
}

// returns rectangle to draw the y-axis
sf::RectangleShape yaxis() {
    sf::View view = Globals::window->getView();
    sf::RectangleShape output(sf::Vector2f(view.getSize().y, Globals::camera.zoomScale * 2));
    output.setPosition(0,view.getCenter().y + (view.getSize().y / 2.0));
    output.rotate(-90);
    return output;
}

int main()
{
    exprNode* v = new variableNode();
    exprNode* n1 = new multNode(v,v);
    exprNode* n2 = new multNode(n1,n1);
    exprNode* n3 = new multNode(n2, v);
    exprNode* root = n3;/*new multNode(n1, v);*/


    Globals::camera.move(Globals::camera.view.getSize().x / -2, Globals::camera.view.getSize().y / -2);
    Globals::camera.zoom(0.0171801f);
    // run the program as long as the window is open
    while (Globals::window->isOpen())
    {
        Globals::window->setFramerateLimit(100);
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (Globals::window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                Globals::window->close();
            }
            if (event.type == sf::Event::MouseWheelMoved) {
                if (event.mouseWheel.delta >= 1) {
                    Globals::camera.zoom(0.9);
                }
                else if (event.mouseWheel.delta <= -1) {
                    Globals::camera.zoom(1.1);
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    Globals::camera.move(Globals::camera.zoomScale * -Globals::camera.moveSpeed,0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    Globals::camera.move(Globals::camera.zoomScale * Globals::camera.moveSpeed, 0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    Globals::camera.move(0, Globals::camera.zoomScale * -Globals::camera.moveSpeed);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    Globals::camera.move(0, Globals::camera.zoomScale * Globals::camera.moveSpeed);
                }
            }
        }

        // std::cout << Globals::window.mapPixelToCoords(sf::Mouse::getPosition(Globals::window)).x << ", " << Globals::window.mapPixelToCoords(sf::Mouse::getPosition(Globals::window)).y << std::endl;
        // std::cout << Globals::camera.zoomScale << std::endl;

        // clear the window with black color
        Globals::window->clear(sf::Color::Black);

        // draw everything here...
        Globals::window->draw(xaxis());
        Globals::window->draw(yaxis());

        

        std::vector<sf::CircleShape> graph = getGraph(root);
        // std::cout << graph.size() << std::endl;
        for (auto i : graph) {
            Globals::window->draw(i);
        }
        
        std::vector<sf::Text> xNumbers = xNumberline();
        for (auto i : xNumbers) {
            Globals::window->draw(i);
        }

        // end the current frame
        Globals::window->display();

        Globals::window->setView(Globals::camera.view);
    }

    delete Globals::window;

    delete root;

    return 0;
}

