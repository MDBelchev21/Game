//
// Created by Ivaylo on 23.5.2025 г..
//

#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"

class RenderObject {
public:
    virtual ~RenderObject() = default;

    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void move(sf::Vector2f offset) = 0;

protected:
    sf::Drawable* m_drawable = nullptr;
};

#endif //RENDEROBJECT_H
