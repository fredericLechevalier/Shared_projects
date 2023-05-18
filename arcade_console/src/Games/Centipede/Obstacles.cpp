/*
** EPITECH PROJECT, 2023
** B4-Object-Oriented_Programming
** File description:
** Obstacles
*/

#include "../../../includes/Games/Centipede.hpp"

//Needs obstaclesManager()

//spawns an obtacle at the coordonates given, retries lower of position occupied
void Arcade::Game::Centipede::obstaclesSpawn(int x, int y)
{
    // std::cout << "spawned OBSTCL at " << x << "." << y << "\n.";
    for (int x = 0; x < _obstacles.size(); x++)
        if (_obstacles[x]._pos.first == x && _obstacles[x]._pos.second == y) {
            y += _tile;
            obstaclesSpawn(x, y);
            return;
        }
        if (x == 960 && y == 1000)
            return; //cancels the spawn
    _obstacles.push_back(obstacle(std::make_pair(x, y)));
}
//Says if the given coordonates collides with any obtacles. <X, Y> pos, <wight, height> hitbox;
bool Arcade::Game::Centipede::isColisionToObstacle(std::pair<int, int> pos, std::pair<int, int> hitbox, int speed, char direction)
{
    for(int x = 0; x < _obstacles.size(); x++) {
        if ((pos.first + hitbox.first + _tile) >= _obstacles[x]._pos.first && pos.first <= (_obstacles[x]._pos.first + _tile)) //X colision
            if ((pos.second + hitbox.second) >= _obstacles[x]._pos.second && pos.second <= (_obstacles[x]._pos.second + _tile)) //Y colision
                return true;
    }
    return false; //NEED TO TAKE CARE OF DIRECTIONS !
}
//return a random position on the gameboard according to the '_tile' scalling
int Arcade::Game::Centipede::randomPostionGenerator(int max)
{
    int randomPos = 2;

    while (randomPos % _tile != 0)
        randomPos = rand() % max + 1;
    return randomPos;
}
//Places all the obstacles on the screen
void Arcade::Game::Centipede::obstaclesDisplay()
{
    for (int x = 0; x < _obstacles.size(); x++)
        addPixels(_obstacles[x]._pos, std::pair<int, int>(_tile, _tile), _obstacles[x]._color);
}

void Arcade::Game::Centipede::obstaclesManager()
{
    obstaclesDisplay();
}
