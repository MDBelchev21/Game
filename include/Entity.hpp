#pragma once

#include "precompile.hpp"

enum MovableType{
  Movable = 0,
  Immovable = 1
};

class Entity {
public:
  Entity() = default;
  ~Entity() = default;
  virtual sf::Transform getTransform() = 0;
  virtual sf::Sprite getSprite() = 0;
  virtual MovableType getMovableType() = 0;
protected:
  sf::ConvexShape* m_shape = nullptr;
  MovableType* m_movableType = nullptr;
};