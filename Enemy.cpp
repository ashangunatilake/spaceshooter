#include "Enemy.h"
#include <iostream>
using namespace std;

Enemy::Enemy(int startX, int startY) : x(startX), y(startY), symbol('O') {}

void Enemy::moveDown() {
    y++;
}

void Enemy::display() {
    cout << symbol;
}