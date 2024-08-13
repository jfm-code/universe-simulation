// Copyright 2024 Jessica Vu

#include "Universe.hpp"
#include "CelestialBody.hpp"

std::istream& NB::operator>>(std::istream& in, NB::Universe& init_uni) {
    int temp1;
    double temp2;
    in >> temp1 >> temp2;
    init_uni.set_numOf_particles(temp1);
    init_uni.set_radius(temp2);
    NB::CelestialBody temp;
    for (int i=0; i < init_uni.get_numOf_particles(); i++) {
        init_uni.getBody().push_back(temp);  // Prevent empty vector when using init_uni.body[i]
        in >> init_uni.getBody()[i];
    }
    return in;
}

std::ostream& NB::operator<<(std::ostream& out, Universe init_uni) {
    out << init_uni.get_numOf_particles() << std::endl
        << init_uni.get_radius() << std::endl;
    for (int i=0; i < init_uni.get_numOf_particles(); i++) {
        out << init_uni.getBody()[i];
    }
    return out;
}

void NB::Universe::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::Texture background;
    background.loadFromFile("universe-background.png");
    float scaleX = static_cast<float>(810) / background.getSize().x;
    float scaleY = static_cast<float>(810) / background.getSize().y;
    sf::Sprite background_img;
    background_img.setTexture(background);
    background_img.setScale(scaleX, scaleY);
    target.draw(background_img, states);

    sf::Transform transform =
        sf::Transform()
        .translate(sf::Vector2f(400, 400))
        .scale(sf::Vector2f(400.0 / radius, -400.0 / radius));

    for (auto planet : body) {
        planet.setTransform(transform);
        target.draw(planet, states);
    }
}

void NB::Universe::step(double time) {
    sf::Vector2f new_force, new_vel, new_pos;
    for (auto &planet : body) {
        for (auto other_planet : body) {
            if (planet.get_filename() != other_planet.get_filename()) {
                new_force = planet.calculate_Force(other_planet.get_xPosition(),
                                                    other_planet.get_yPosition(),
                                                    other_planet.get_mass());
                new_vel = planet.calculate_Velocity(new_force, time);
                planet.set_xVelocity(new_vel.x);
                planet.set_yVelocity(new_vel.y);
            }
        }
        new_pos = planet.calculate_Position(new_vel, time);
        planet.set_xPostition(new_pos.x);
        planet.set_yPostition(new_pos.y);
    }
}
