
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>


class canvas {
    sf::Texture aTexture;
    sf::Sprite aSprite;
    std::vector <st::Vertex> lines;
    std::vector <st::Vertex> linesSave;
    sf::RenderWindow *parent;
    bool mousedown;
    // funcs 
public:
    canvas(sf::RenderWindow parent);
    void eventHandler(sf::Event *eventPntr);
}
