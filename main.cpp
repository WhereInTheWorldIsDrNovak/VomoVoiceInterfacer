
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>

// File Libs
#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    std::vector <sf::Vertex> lines;
    std::vector <sf::Vertex> linesSave;
    sf::Texture texture;
    sf::Sprite sprite;
    texture.create(800,600);

    int mousedown = 0;
    // run the program as long as the window is open
    window.setFramerateLimit(30);

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                // Get time
                auto end = std::chrono::system_clock::now();
                // Convert time to more readable
                std::time_t time = std::chrono::system_clock::to_time_t(end);
                std::string timeStr = std::string(std::ctime(&time));
                // Save File Creation + Opening
                std::ofstream saveFile(timeStr+".csv");
                saveFile.open(timeStr, std::ios::in);
                // Below we loop through lines, and puts in file
                for (int iterI = 0; iterI < linesSave.size(); iterI++)
                {
                    // X and Y are swapped due to coding fast, the interface has them swapped
                    // so I swapped here to avoid having to redo this demo
                    std::cout << linesSave[iterI].position.y << "." << linesSave[iterI].position.x << std::endl;
                    saveFile << linesSave[iterI].position.y << "." << linesSave[iterI].position.x;
                    saveFile << "\n";
                }

                if (saveFile.is_open())
                {
                    saveFile.close();
                }
                window.close();
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
        window.clear(sf::Color::Black);

         window.draw(sprite);

      window.draw(&lines[0], lines.size(), sf::LinesStrip);

      sprite.setTexture(texture);
        window.display();

    }

    return 0;
}
