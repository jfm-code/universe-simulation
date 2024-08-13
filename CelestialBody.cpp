// Copyright 2024 Jessica Vu

#include "CelestialBody.hpp"

std::istream& NB::operator>>(std::istream& in, CelestialBody& body_uni) {
    double temp1, temp2, temp3, temp4, temp5;
    std::string path = "nbody/";
    std::string temp6;
    in >> temp1 >> temp2 >> temp3 >> temp4 >> temp5 >> temp6;
    body_uni.set_xPostition(temp1);
    body_uni.set_yPostition(temp2);
    body_uni.set_xVelocity(temp3);
    body_uni.set_yVelocity(temp4);
    body_uni.set_mass(temp5);
    body_uni.set_filename(temp6);
    body_uni.set_planetSkin(path+temp6);
    return in;
}
std::ostream& NB::operator<<(std::ostream& out, CelestialBody body_uni) {
    out << body_uni.get_xPosition() << "    " << body_uni.get_yPosition() << "    "
        << body_uni.get_xVelocity() << "    " << body_uni.get_yVelocity() << "    "
        << body_uni.get_mass() << "    " << body_uni.get_filename() << std::endl;
    return out;
}

void NB::CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::Sprite display_img;
    display_img.scale({2, 2});
    display_img.setPosition(trans.transformPoint(x_position, y_position));
    display_img.setTexture(planet_skin);
    target.draw(display_img, states);
}

sf::Vector2f NB::CelestialBody::calculate_Force(double other_x, double other_y, double other_mass) {
    sf::Vector2f force_vect;  // return value
    double delta_x = other_x - x_position;
    double delta_y = other_y - y_position;
    double distance_square = pow(delta_x, 2) + pow(delta_y, 2);  // r
    double force = (gravitational * mass * other_mass) / distance_square;  // F
    force_vect.x = (force * delta_x) / sqrt(distance_square);  // Fx
    force_vect.y = (force * delta_y) / sqrt(distance_square);  // Fy
    return force_vect;
}

sf::Vector2f NB::CelestialBody::calculate_Velocity(sf::Vector2f force, double delta_time) {
    // Calculate acceleration
    double acceleration_x = force.x / mass;
    double acceleration_y = force.y / mass;

    // Use acceleration to calculate new velocity
    x_velocity += delta_time * acceleration_x;
    y_velocity += delta_time * acceleration_y;

    sf::Vector2f new_vel;
    new_vel.x = x_velocity;
    new_vel.y = y_velocity;
    return new_vel;
}

sf::Vector2f NB::CelestialBody::calculate_Position(sf::Vector2f velocity, double delta_time) {
    // Use velocity to calculate new position
    x_position += delta_time * x_velocity;
    y_position += delta_time * y_velocity;

    sf::Vector2f new_pos;
    new_pos.x = x_position;
    new_pos.y = y_position;
    return new_pos;
}
