#include "Entity.h"
#include <vector>

class Player {
public:
    int x, y;
    char symbol;

    Player(int startX, int startY);

    void moveLeft();
    void moveRight();
    void shoot(std::vector<Entity>& bullets);
    void display();
};
