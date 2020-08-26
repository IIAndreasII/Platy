#include <iostream>

#include <SFML/Graphics.hpp>

#include "Platy.Game.Core/Postmaster/PostMaster.h"

constexpr const char* GAME_NAME = "Minesweeper";

int main()
{
    srand(time(NULL));

    sf::RenderWindow window;
    window.create(sf::VideoMode(200, 200), GAME_NAME);
    window.setVerticalSyncEnabled(false);

    bool isWindowInFocus;

    /// Init clock for delta time
    sf::Clock tempClock;
    float deltaTime;


    PostMaster::Init();










    while (window.isOpen())
    {
        sf::Event tempEvent;
        while (window.pollEvent(tempEvent))
        {
            if (tempEvent.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (tempEvent.type == sf::Event::GainedFocus)
            {
                isWindowInFocus = true;
            }
            else if (tempEvent.type == sf::Event::LostFocus)
            {
                isWindowInFocus = false;
            }
        }

        deltaTime = tempClock.restart().asSeconds();

        window.clear();

        //////////////////////////////////////////////////////////////////
        // Draw logic
        //////////////////////////////////////////////////////////////////






        window.display();

    }
}
