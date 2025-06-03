#pragma once

class State;

#include "precompile.hpp"
#include "Entity.hpp"

class Enemy : public Entity{
public:
  	virtual float getHealth() = 0;
    virtual float getMaxHealth() = 0;
    virtual void update(State& state) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

protected:
    virtual void attack() = 0;
    virtual void move() = 0;
    virtual void updateHealth(float damage) = 0;
  	sf::Sprite* m_sprite = nullptr;
    float* m_health = nullptr;
    float* m_maxHealth = nullptr;
};