#include "Player.h"
#include <iostream>
using namespace std;


Player::Player(int startX, int startY) : x(startX), y(startY), symbol('^') {}

void Player::moveLeft() {
    if (x > 1) {
        x--;
    }
}

void Player::moveRight() {
    if (x < 20) {
        x++;
    }
}

void Player::shoot(std::vector<Entity>& bullets) {
    bullets.push_back({ x, 19, '|' });
}

void Player::display() {
    cout << symbol;
}