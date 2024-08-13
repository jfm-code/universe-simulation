// Copyright 2024 Jessica Vu

#include <iostream>
#include "Universe.hpp"
#include "CelestialBody.hpp"

int main(int argc, char* argv[]) {
    double time, delta_time, init_time;
    init_time = 0;
    std::string time_s = argv[1];
    time = stod(time_s);
    std::string delta_time_s = argv[2];
    delta_time = stod(delta_time_s);

    NB::Universe universe;
    std::cin >> universe;

    /* //debug
    std::cout << universe << std::endl;
    std::cout << "Initial universe" << std::endl;
    universe.step(delta_time);
    std::cout << universe << std::endl;
    std::cout << "Step 1 done" << std::endl;
    universe.step(delta_time);
    std::cout << universe;
    std::cout << "Step 2 done" << std::endl; */

    // Setting the sound
    sf::SoundBuffer gameBuffer;
    if (!gameBuffer.loadFromFile("nbody/2001.wav")) {
        std::cout << "error opening file";
        exit(1);
    }
    sf::Sound gameSound;
    gameSound.setBuffer(gameBuffer);
    gameSound.play();

    // Setting up the text
    sf::Font font;
    if (!font.loadFromFile("text-font.otf")) {
        std::cout << "Error loading font file";
        return 1;
    }
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, 10);

    sf::RenderWindow window(sf::VideoMode(810, 810), "Welcome to my universe!");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(universe);
        text.setString("Elapsed Time: " + std::to_string(init_time) + " seconds");
        window.draw(text);
        window.display();
        universe.step(delta_time);
        init_time+=delta_time;
        if (init_time >= time)
            break;
    }
    std::cout << "Final state of the universe:" << std::endl;
    std::cout << universe << std::endl;
    return 0;
}
