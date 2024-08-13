// Copyright 2024 Jessica Vu

#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

namespace NB {
class CelestialBody : public sf::Drawable  {
 public:
    CelestialBody():
    x_position(0.0), y_position(0.0),
    x_velocity(0.0), y_velocity(0.0), mass(0.0),
    trans(sf::Transform::Identity) {}

    void set_xPostition(double input_x) { x_position = input_x;}
    double get_xPosition() { return x_position;}

    void set_yPostition(double input_y) { y_position = input_y;}
    double get_yPosition() { return y_position;}

    void set_xVelocity(double input_x) { x_velocity = input_x;}
    double get_xVelocity() { return x_velocity;}

    void set_yVelocity(double input_y) { y_velocity = input_y;}
    double get_yVelocity() { return y_velocity;}

    void set_mass(double input_mass) { mass = input_mass;}
    double get_mass() { return mass;}

    void set_filename(std::string input_name) { filename = input_name;}
    std::string get_filename() { return filename;}

    void set_planetSkin(std::string input_file) { planet_skin.loadFromFile(input_file);}
    sf::Texture get_planetSkin() { return planet_skin;}

    void setTransform(sf::Transform input) const {trans = input;}

    sf::Vector2f calculate_Force(double other_x, double other_y, double other_mass);
    sf::Vector2f calculate_Velocity(sf::Vector2f force, double delta_time);
    sf::Vector2f calculate_Position(sf::Vector2f velocity, double delta_time);

 protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
    double x_position;
    double y_position;
    double x_velocity;
    double y_velocity;
    double mass;
    std::string filename;
    sf::Texture planet_skin;
    mutable sf::Transform trans;
    const double gravitational = 6.67 * pow(10, -11);
};

    std::istream& operator>>(std::istream& in, CelestialBody& body_uni);
    std::ostream& operator<<(std::ostream& out, CelestialBody body_uni);
}  // namespace NB
