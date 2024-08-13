// Copyright 2024 Jessica Vu

#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "CelestialBody.hpp"

namespace NB {
class Universe : public sf::Drawable {
 public:
    Universe(): numOf_particles(0), radius(0.0) {}

    void set_numOf_particles(int input_num) { numOf_particles = input_num;}
    int get_numOf_particles() { return numOf_particles;}

    void set_radius(double input_radius) { radius = input_radius;}
    double get_radius() { return radius;}

    std::vector<CelestialBody>& getBody() { return body;}
    void step(double time);

 protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
    int numOf_particles;
    double radius;
    std::vector <CelestialBody> body;
};
    std::istream& operator>>(std::istream& in, Universe& init_uni);
    std::ostream& operator<<(std::ostream& out, Universe init_uni);
}  // namespace NB
