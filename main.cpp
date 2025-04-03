// library
#include <SFML/Graphics.hpp>


// main program
int main()
{
    // create window
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Title", sf::State::Windowed, settings);

    // create circle
    sf::CircleShape circle(200.f, 60);
    circle.setFillColor(sf::Color(128, 213, 255));
    circle.setOutlineColor(sf::Color(0, 170, 255));
    circle.setOutlineThickness(20.f);
    circle.setOrigin({200.f, 200.f});
    circle.setPosition({400.f, 300.f});
    // circle.setScale({1.5f, 1.f});
    // circle.setRotation(sf::degrees(30.f));


    // while window is still open
    while (window.isOpen())
    {
        // handle events
        while (std::optional event = window.pollEvent())
        {
            // when close button is clicked
            if (event->is<sf::Event::Closed>())
            {
                // close window
                window.close();
            }
            // when window is resized
            else if (event->is<sf::Event::Resized>())
            {
                // update view
                sf::View view(sf::FloatRect({0.f, 0.f}, sf::Vector2f(window.getSize())));
                window.setView(view);
            }
        }

        // fill window with color
        window.clear(sf::Color(64, 64, 64));

        // draw
        window.draw(circle);
        
        // display
        window.display();
    }

    
    // program end successfully
    return 0;
}