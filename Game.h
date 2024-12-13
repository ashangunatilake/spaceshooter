#include "Player.h"
#include "Enemy.h"
#include "Entity.h"
#include <vector>

class Game {
private:
    Player player;
    std::vector<Entity> bullets;
    std::vector<Enemy> enemies;
    int score;

public:
    Game();

    void spawnEnemy();
    void moveEnemies();
    void detectCollisions();
    void moveBullets();
    void display();
    void handleInput();
    void run();
};
