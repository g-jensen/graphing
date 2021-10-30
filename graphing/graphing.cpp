#include <SFML/Graphics.hpp>
#include <vector>
#include "Camera.h"

sf::RenderWindow window(sf::VideoMode(1520, 980), "My window");
Camera camera(window);

std::vector<sf::CircleShape> quadratic() {\

    // (x^2-300) + 200

    std::vector<sf::CircleShape> output;
    for (float x = 0; x <= 600; x += 0.1) {
        sf::CircleShape circle(2);
        circle.setPosition(x,(window.getSize().y - (1.0f/20.0f * ((x-300.f)*(x-300.f))+200.f)));
        output.push_back(circle);
    }
    return output;
}


int main()
{
    // create the window

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
        }

        sf::CircleShape circle(10);
        circle.setPosition(200, 200);

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        for (auto i : quadratic()) {
            window.draw(i);
        }

        // end the current frame
        window.display();

        window.setView(camera.view);
    }

    return 0;
}

