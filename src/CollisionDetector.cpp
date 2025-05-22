#include "../include/CollisionDetector.hpp"

bool CollisionDetector::gjk(const std::vector<sf::Vector2f>& shape1, const std::vector<sf::Vector2f>& shape2) {
    sf::Vector2f dir = shape1[0] - shape2[0];
    std::vector<sf::Vector2f> simplex = { support(shape1, shape2, dir) };
    dir = -simplex[0];

    while (true) {
        sf::Vector2f a = support(shape1, shape2, dir);
        if (dot(a, dir) < 0) return false;
        simplex.push_back(a);
        if (handleSimplex(simplex, dir)) return true;
    }
}

float CollisionDetector::dot(const sf::Vector2f& a, const sf::Vector2f& b) {
    return a.x * b.x + a.y * b.y;
}

sf::Vector2f CollisionDetector::tripleProduct(const sf::Vector2f& a, const sf::Vector2f& b, const sf::Vector2f& c) {
    float ac = dot(a, c);
    float bc = dot(b, c);
    return { b.x * ac - a.x * bc, b.y * ac - a.y * bc };
}

sf::Vector2f CollisionDetector::support(const std::vector<sf::Vector2f>& shape1, const std::vector<sf::Vector2f>& shape2, const sf::Vector2f& dir) {
    auto furthest = [this](const std::vector<sf::Vector2f>& shape, const sf::Vector2f& d) {
        return *std::ranges::max_element(shape, {}, [&](const sf::Vector2f& v) {
            return dot(v, d);
        });
    };

    sf::Vector2f p1 = furthest(shape1, dir);
    sf::Vector2f p2 = furthest(shape2, -dir);
    return p1 - p2;
}

bool CollisionDetector::handleSimplex(std::vector<sf::Vector2f>& simplex, sf::Vector2f& dir) {
    if (simplex.size() == 2) {
        sf::Vector2f a = simplex[1], b = simplex[0];
        sf::Vector2f ab = b - a;
        sf::Vector2f ao = -a;
        dir = tripleProduct(ab, ao, ab);
    } else if (simplex.size() == 3) {
        sf::Vector2f a = simplex[2], b = simplex[1], c = simplex[0];
        sf::Vector2f ab = b - a, ac = c - a, ao = -a;
        sf::Vector2f abPerp = tripleProduct(ac, ab, ab);
        sf::Vector2f acPerp = tripleProduct(ab, ac, ac);

        if (dot(abPerp, ao) > 0) {
            simplex.erase(simplex.begin());
            dir = abPerp;
        } else if (dot(acPerp, ao) > 0) {
            simplex.erase(simplex.begin() + 1);
            dir = acPerp;
        } else {
            return true;
        }
    }
    return false;
}