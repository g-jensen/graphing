#include <SFML/Graphics.hpp>
#include <vector>
#include "Camera.h"
#include "Camera.cpp"
#include <iostream>


//sf::RectangleShape linear(float slope, float yintercept) {
//
//}

std::vector<sf::CircleShape> quadratic() {

    // (x^2-300) + 200

    std::vector<sf::CircleShape> output;
    for (float x = 0; x <= 600; x += 0.5) {
        sf::CircleShape circle(globals::camera.zoomScale * 2);
        circle.setPosition(x,(globals::window.getSize().y - (1.0f/20.0f * ((x-300.f)*(x-300.f))+200.f)));
        output.push_back(circle);
    }
    return output;
}

sf::RectangleShape xaxis() {
    sf::View view = globals::window.getView();
    sf::RectangleShape output(sf::Vector2f(view.getSize().x, globals::camera.zoomScale * 5));
    output.setPosition(view.getCenter().x - (view.getSize().x / 2.0f), 0);
    return output;
}

sf::RectangleShape yaxis() {
    sf::View view = globals::window.getView();
    sf::RectangleShape output(sf::Vector2f(view.getSize().y, globals::camera.zoomScale * 5));
    output.setPosition(0,view.getCenter().y + (view.getSize().y / 2.0));
    output.rotate(-90);
    return output;
}

int main()
{
    // run the program as long as the window is open
    while (globals::window.isOpen())
    {
        globals::window.setFramerateLimit(100);
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (globals::window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                globals::window.close();
            }
            if (event.type == sf::Event::MouseWheelMoved) {
                if (event.mouseWheel.delta >= 1) {
                    globals::camera.zoom(0.9);
                }
                else if (event.mouseWheel.delta <= -1) {
                    globals::camera.zoom(1.1);
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    globals::camera.move(globals::camera.zoomScale * -globals::camera.moveSpeed,0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    globals::camera.move(globals::camera.zoomScale * globals::camera.moveSpeed, 0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    globals::camera.move(0, globals::camera.zoomScale * -globals::camera.moveSpeed);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    globals::camera.move(0, globals::camera.zoomScale * globals::camera.moveSpeed);
                }
            }
        }

        std::cout << globals::window.mapPixelToCoords(sf::Mouse::getPosition(globals::window)).x << ", " << globals::window.mapPixelToCoords(sf::Mouse::getPosition(globals::window)).y << std::endl;
        // std::cout << camera.zoomScale << std::endl;

        // clear the window with black color
        globals::window.clear(sf::Color::Black);

        // draw everything here...
        globals::window.draw(xaxis());
        globals::window.draw(yaxis());

        for (auto i : quadratic()) {
            globals::window.draw(i);
        }

        // end the current frame
        globals::window.display();

        globals::window.setView(globals::camera.view);
    }

    return 0;
}

