#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


int main(int argc, char **argv) {
    sf::VideoMode vid = sf::VideoMode(800, 600);
    sf::RenderWindow window(vid, L"SFML Drawing – C to clear, PageUp/PageDown to pick colors", sf::Style::Default);
    // Set a specific frame rate, since we don't want to
    // worry about vsync or the time between drawing iterations
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(60);

    gui::ProgressBar aBar(10,10,10,10,sf::Color(10,10,10), 10, vid);

    MappaMap map(&window);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            map.eventHandler(event);
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
                }
        }

        aBar.render(window);
        aBar.update(10,200);

        // Clear the window
        window.clear(sf::Color(64, 64, 64));

        // Draw our canvas
        map.draw(&window);

        // Show the window
        window.display();
    }
    return 0;
}
