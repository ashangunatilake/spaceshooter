#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>  
using namespace std;

Game::Game() : player(11, 20), score(0) {
    srand(time(0)); // Seed for random generation
}

void Game::spawnEnemy() {
    int x = rand() % 20 + 1;
    enemies.push_back(Enemy(x, 0));
}

void Game::moveEnemies() {
    for (auto& enemy : enemies) {
        enemy.moveDown();
    }
}

void Game::detectCollisions() {
    for (int i = 0; i < bullets.size(); i++) {
        for (int j = 0; j < enemies.size(); j++) {
            if (bullets[i].x == enemies[j].x && (bullets[i].y == enemies[j].y || bullets[i].y == (enemies[j].y - 1))) {
                // Bullet hits enemy
                cout << "hit" << endl;
                score += 10;
                enemies.erase(enemies.begin() + j);
                bullets.erase(bullets.begin() + i);
                return;
            }
        }
    }

    // Check if player collides with any enemy
    for (auto& enemy : enemies) {
        if (player.x == enemy.x && player.y == enemy.y) {
            cout << "Game Over! Final Score: " << score << endl;
            exit(0); // End game
        }
    }
}

void Game::moveBullets() {
    for (auto& bullet : bullets) {
        bullet.y--; // Move bullets
    }
    // Remove bullets that go off screen
    bullets.erase(remove_if(bullets.begin(), bullets.end(), [](Entity& bullet) { return bullet.y < 0; }), bullets.end());
}

void Game::display() {
    system("cls");  
    for (int y = 0; y < 22; ++y) {
        for (int x = 0; x < 22; ++x) {
            bool printed = false;

            //Display borders
            if (x == 0 || x == 21) {
                cout << "|";
                continue;
            }

            if (y == 0 || y == 21) {
                cout << "_";
                continue;
            }
            // Display player
            if (x == player.x && y == player.y) {
                player.display();
                printed = true;
            }

            // Display bullets
            for (auto& bullet : bullets) {
                if (bullet.x == x && bullet.y == y) {
                    cout << bullet.symbol;
                    printed = true;
                }
            }

            // Display enemies
            for (auto& enemy : enemies) {
                if (enemy.x == x && enemy.y == y) {
                    enemy.display();
                    printed = true;
                }
            }

            // Empty space
            if (!printed) std::cout << ' ';
        }
        cout << endl;
    }
    cout << "Score: " << score << endl;
}

void Game::handleInput() {
    char input;
    cout << "a (Move left)\nd (Move right)\ns (Stay still) \nj (Shoot)" << endl;
    cout << "Select command: ";
    cin >> input;

    if (input == 'a') {
        player.moveLeft();
        cout << "Moved left" << endl;
    }
    else if (input == 'd') {
        player.moveRight();
        cout << "Moved right" << endl;
    }
    else if (input == 's') {
        cout << "Stayed still" << endl;
    }
    else if (input == 'j') {
        cout << "Bullet shot" << endl;
        player.shoot(bullets);
    }
}

void Game::run() {
    while (true) {
        if (rand() % 10 == 0) {
            spawnEnemy(); // Spawn enemy randomly
        }
        moveEnemies();
        moveBullets();
        detectCollisions();
        display();
        handleInput();
        Sleep(200); 
    }
}
