#include <SFML/Graphics.hpp>
#include <vector>

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

#include "PostFix.h"
#include "Camera.h"
#include "Globals.h"
#include "Nodes.h"
#include "Presets.h"

// returns length between two vectors
float length(sf::Vector2f v1, sf::Vector2f v2) {
    float dy = v2.y - v1.y;
    float dx = v2.x - v1.x;
    return sqrt((dy * dy) + (dx * dx));
}

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

// returns a rectangle that goes from pos1 to pos2 and has a width of thickness
sf::RectangleShape line(sf::Vector2f pos1, sf::Vector2f pos2, float thickness) {
    sf::RectangleShape line;
    float len = length(pos1, pos2);
    line.setPosition(pos1);
    line.setSize(sf::Vector2f(len,thickness));
    line.setRotation(atan((pos2.y - pos1.y) / (pos2.x - pos1.x)) * 180.0/M_PI);
    line.setFillColor(sf::Color::Green);
    return line;
}

// Returns the rectangles to draw of a function
std::vector<sf::RectangleShape> getGraph(exprNode* root) {
    std::vector<sf::RectangleShape> output;
    sf::View view = Globals::window->getView();

    float increment = 0.1 * (Globals::camera.zoomScale / 0.0171801f);

    for (
            float x = view.getCenter().x - (view.getSize().x / 2.0f);
            x <= view.getCenter().x + (view.getSize().x / 2.0f); 
            x += increment
        ) {

        sf::Vector2f pos1 = plot(sf::Vector2f(x,root->eval(x)));
        sf::Vector2f pos2 = plot(sf::Vector2f(x + increment, root->eval(x + increment)));

        if (pos1.y >= view.getCenter().y - view.getSize().y / 2.0 || pos1.y <= view.getCenter().y + view.getSize().y / 2.0) {
            output.push_back(line(pos1,pos2,Globals::camera.zoomScale * 2));
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
        zero.setScale(Globals::camera.zoomScale/2.0, Globals::camera.zoomScale/2.0);
        zero.setString("0");
        zero.setPosition(plot(sf::Vector2f(0, -0.1 * Globals::camera.zoomScale / 0.0171801f)));
        output.push_back(zero);
    }

    for (long double x = start; x <= end; x += increment) {
        sf::Text text;
        text.setFont(font);
        text.setScale(Globals::camera.zoomScale/2.0, Globals::camera.zoomScale/2.0);
        text.setString(trimZeros(std::to_string(x)));
        text.setPosition(plot(sf::Vector2f(x,-0.1 * Globals::camera.zoomScale / 0.0171801f)));
        output.push_back(text);
    }
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

// clone of xNumberLine() but for y values
std::vector<sf::Text> yNumberline() {
    font.loadFromFile("fonts/Ubuntu-Regular.ttf");
    std::vector<sf::Text> output;
    sf::View view = Globals::camera.view;

    int farLeftY = view.getCenter().y - (view.getSize().y / 2.0f);
    long double farRightY = view.getCenter().y + (view.getSize().y / 2.0f);

    long double increment = 5.f * Globals::camera.zoomScale / 0.0171801f;

    long double start = 0;
    while (start > farLeftY) {
        start -= increment;
    }
    if (start == 0) {
        while (start < farLeftY) {
            start += increment;
        }
        start -= increment;
    }

    long double end = 0;
    while (end < farRightY) {
        end += increment;
    }
    if (end == 0) {
        while (end > farRightY) {
            end -= increment;
        }
        end += increment;
    }

    for (long double x = -start; x >= -end; x -= increment) {
        if (x != 0) {
            sf::Text text;
            text.setFont(font);
            text.setScale(Globals::camera.zoomScale / 2.0, Globals::camera.zoomScale / 2.0);
            text.setString(trimZeros(std::to_string(x)));
            text.setPosition(plot(sf::Vector2f(0.1 * Globals::camera.zoomScale / 0.0171801f,x)));
            output.push_back(text);
        }
    }
    return output;
}

int main()
{
    exprNode* root = Presets::sine();

    std::vector<sf::CircleShape> points;
    std::vector<sf::RectangleShape> lines;
    sf::Vector2f start;
    bool hasClicked = false;

    Globals::camera.move(Globals::camera.view.getSize().x / -2, Globals::camera.view.getSize().y / -2);
    Globals::camera.zoom(0.0171801f);

    while (Globals::window->isOpen())
    {
        Globals::window->setView(Globals::camera.view);
        Globals::window->setFramerateLimit(100);
        sf::Event event;
        while (Globals::window->pollEvent(event))
        {
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
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                    points.clear();
                    lines.clear();
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    sf::CircleShape point(Globals::camera.zoomScale * 5);
                    sf::Vector2f mouse = Globals::window->mapPixelToCoords(sf::Mouse::getPosition(*Globals::window));
                    mouse.x -= point.getRadius();
                    mouse.y -= point.getRadius();
                    point.setPosition(mouse);
                    point.setFillColor(sf::Color::Red);
                    points.push_back(point);
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                    sf::Vector2f mouse = Globals::window->mapPixelToCoords(sf::Mouse::getPosition(*Globals::window));
                    for (int i = 0; i < points.size(); i++) {
                        if (points[i].getGlobalBounds().contains(mouse)) {
                            points.erase(points.begin() + i);
                            break;
                        }
                    }
                    for (int i = 0; i < lines.size(); i++) {
                        if (lines[i].getGlobalBounds().contains(mouse)) {
                            lines.erase(lines.begin() + i);
                            break;
                        }
                    }
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) {
                    sf::Vector2f mouse = Globals::window->mapPixelToCoords(sf::Mouse::getPosition(*Globals::window));
                    if (!hasClicked) {
                        start = mouse;
                        hasClicked = true;
                    }
                    else {
                        sf::RectangleShape r;
                        if (start.x < mouse.x) {
                            r = line(start, mouse, Globals::camera.zoomScale * 3);
                        }
                        else {
                            r = line(mouse, start, Globals::camera.zoomScale * 3);
                        }
                        r.setFillColor(sf::Color::Yellow);
                        lines.push_back(r);
                        hasClicked = false;
                    }
                }
            }
        }   



        Globals::window->clear(sf::Color::Black);

        

        Globals::window->draw(xaxis());
        Globals::window->draw(yaxis());

        std::vector<sf::RectangleShape> graph = getGraph(root);
        // std::cout << graph.size() << std::endl;
        for (auto i : graph) {
            Globals::window->draw(i);
        }
        
        std::vector<sf::Text> xNumbers = xNumberline();
        for (auto i : xNumbers) {
            Globals::window->draw(i);
        }

        std::vector<sf::Text> yNumbers = yNumberline();
        for (auto i : yNumbers) {
            Globals::window->draw(i);
        }

        for (auto& i : lines) {
            i.setSize(sf::Vector2f(i.getSize().x, Globals::camera.zoomScale * 3));
            Globals::window->draw(i);
        }

        for (auto& i : points) {
            i.setRadius(Globals::camera.zoomScale * 5);
            Globals::window->draw(i);
        }

        // end the current frame
        Globals::window->display();
    }

    delete Globals::window;

    //delete root;

    //std::cout << "\"" << PostFix::InfixToPostfix("51 * (9+2)") << "\"" << std::endl;

    std::string s = "51 * (9+2)";
    auto v = PostFix::TokenizeString(s, ' ');

    for (auto i : v) {
        std::cout << i << std::endl;
    }

    //std::cin.get();

    return 0;
}

