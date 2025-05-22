//
// Created by Ivaylo on 23.5.2025 г..
//

#ifndef CIRCLE_H
#define CIRCLE_H
#include "RenderObject.h"
#include "SFML/Graphics/CircleShape.hpp"

class Circle final : public RenderObject {
public:
    explicit Circle(const float radius) {
        this->m_drawable = new sf::CircleShape(radius);
    }

    void draw(sf::RenderWindow &window) override {
        window.draw(*this->m_drawable);
    }

    void move(sf::Vector2f offset) override {
        auto circle = dynamic_cast<sf::CircleShape*>(this->m_drawable);
        circle->move(offset);
    }
};

#endif //CIRCLE_H
