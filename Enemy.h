#include "Entity.h"

class Enemy {
public:
    int x, y;
    char symbol;

    Enemy(int startX, int startY);

    void moveDown();
    void display();
};
