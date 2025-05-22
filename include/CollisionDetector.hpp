#pragma once
#include <array>
#include <vector>
#include <cmath>
#include <optional>
#include <ranges>
#include <algorithm>

#include <SFML/Graphics.hpp>

class CollisionDetector {
public:
    CollisionDetector() = default;
    bool gjk(const std::vector<sf::Vector2f>& shape1, const std::vector<sf::Vector2f>& shape2);
private:
    float dot(const sf::Vector2f& a, const sf::Vector2f& b);
    sf::Vector2f tripleProduct(const sf::Vector2f& a, const sf::Vector2f& b, const sf::Vector2f& c);
    sf::Vector2f support(const std::vector<sf::Vector2f>& shape1, const std::vector<sf::Vector2f>& shape2, const sf::Vector2f& dir);
    bool handleSimplex(std::vector<sf::Vector2f>& simplex, sf::Vector2f& dir);
};
