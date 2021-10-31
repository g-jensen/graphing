#include <SFML/Graphics.hpp>
#include <vector>
#include "Camera.h"
#include "OverlayUI.h"
#include <iostream>

sf::RenderWindow window(sf::VideoMode(1520, 980), "My window");
Camera camera(window);


//sf::RectangleShape linear(float slope, float yintercept) {
//
//}

std::vector<sf::CircleShape> quadratic() {

    // (x^2-300) + 200

    std::vector<sf::CircleShape> output;
    for (float x = 0; x <= 600; x += 0.1) {
        sf::CircleShape circle(camera.zoomScale * 2);
        circle.setPosition(x,(window.getSize().y - (1.0f/20.0f * ((x-300.f)*(x-300.f))+200.f)));
        output.push_back(circle);
    }
    return output;
}

sf::RectangleShape xaxis() {
    sf::View view = window.getView();
    sf::RectangleShape output(sf::Vector2f(view.getSize().x, camera.zoomScale * 5));
    output.setPosition(view.getCenter().x - (view.getSize().x / 2.0f), 0);
    return output;
}

sf::RectangleShape yaxis() {
    sf::View view = window.getView();
    sf::RectangleShape output(sf::Vector2f(view.getSize().y, camera.zoomScale* 5));
    output.setPosition(0,view.getCenter().y + (view.getSize().y / 2.0));
    output.rotate(-90);
    return output;
}

int main()
{
    OverlayUI overlayUI;
    sf::RectangleShape inverseButton = overlayUI.createInverseButton();

    sf::RectangleShape v(sf::Vector2f(1000,5));
    v.setPosition(100, 700);
    v.setRotation(-45);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        window.setFramerateLimit(100);
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseWheelMoved) {
                if (event.mouseWheel.delta >= 1) {
                    camera.zoom(0.9);
                }
                else if (event.mouseWheel.delta <= -1) {
                    camera.zoom(1.1);
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    camera.move(camera.zoomScale * -camera.moveSpeed,0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    camera.move(camera.zoomScale * camera.moveSpeed, 0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    camera.move(0, camera.zoomScale * -camera.moveSpeed);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    camera.move(0, camera.zoomScale * camera.moveSpeed);
                }
            }
        }   

         std::cout << window.mapPixelToCoords(sf::Mouse::getPosition(window)).x << ", " << window.mapPixelToCoords(sf::Mouse::getPosition(window)).y << std::endl;
        // std::cout << camera.zoomScale << std::endl;

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(inverseButton);
        window.draw(xaxis());
        window.draw(yaxis());

        for (auto i : quadratic()) {
            window.draw(i);
        }


        // end the current frame
        window.display();

        window.setView(camera.view);
    }

    return 0;
}

