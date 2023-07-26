
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>


canvas::canvas(sf::RenderWindow parent)
    {
        this->parent = parent;
    }
void canvas::eventHandler(sf::Event *eventPntr)
{
    switch (eventPntr)
    {
        case (sf::Event::MouseMoved):
            if (mousedown) lines.push_back(sf::Vertex(sf::Vector2f(sf::Mouse::getPosition(window))));
        case (sf::Event::MouseButtonPressed):
            mousedown = true;
        case (sf::Event::MouseButtonReleased):
            mousedown = false;
    }
    else if ((event.type == sf::Event::MouseMoved) && (mousedown == 1))
    {
       lines.push_back(sf::Vertex(sf::Vector2f(sf::Mouse::getPosition(window))));
    }
    else if (event.type == sf::Event::MouseButtonPressed)
    {
       mousedown = 1;
    }
    else if (event.type == sf::Event::MouseButtonReleased)
    {
       mousedown = 0;
       texture.update(window);
       linesSave.insert(linesSave.end(), lines.begin(), lines.end());
       lines.clear();
    }
}
