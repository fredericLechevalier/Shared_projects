/*
** EPITECH PROJECT, 2023
** B4-Object-Oriented_Programming
** File description:
** Ennemy
*/

#include "../../../includes/Games/Centipede.hpp"

//spawns an ennemy centipede of the length given
void Arcade::Game::Centipede::ennemySpawn(int length)
{
    int x = (length + 2) * _tile;
    unsigned int color = 0x00f0ffff;

    for (int z = 0; z < length; z++) {
        _ennemy.push_back(ennemy(color, std::make_pair(x, _playfield._y), _tile/4));
        _ennemy[z]._speed = _tile;//_tile / 2;
        x -= _tile;
        color -= 0x00150000;
    }
}
//Coding simplification for checking colision from ennemy to either an obstacle or the screen border
bool Arcade::Game::Centipede::ennemyColisionChecks(std::pair<int, int> pos, std::pair<int, int> hitbox, int speed, char direction)
{
    if (isColisionToObstacle(pos, hitbox, speed, direction))
        return true;
    if (isColisionToBorder(pos, hitbox, speed, direction))
        return true;
    return false;
}
//Updates the ennemy's direction before moving on the screen
void Arcade::Game::Centipede::ennemyDirection()
{
    for(int x = 0; x < _ennemy.size(); x++) {
        if (_ennemy[x]._goDown > 0)
            continue;
        if (ennemyColisionChecks(_ennemy[x]._pos, std::make_pair(_tile - 1, _tile - 1), _ennemy[x]._speed, _ennemy[x]._direction)) {
            if (_ennemy[x]._direction == 'r') {
                _ennemy[x]._direction = 'l';
            } else {
                _ennemy[x]._direction = 'r';
            }
            _ennemy[x]._goDown = _tile;
        }
    }
}
//Updates the ennemy's position on the screen
void Arcade::Game::Centipede::ennemyMove()
{
    for(int x = 0; x < _ennemy.size(); x++) {
        if (_ennemy[x]._goDown > 0) {
            _ennemy[x]._goDown -= _ennemy[x]._speed;
            _ennemy[x]._pos.second += _ennemy[x]._speed;
        } else if (_ennemy[x]._direction == 'r') {
            _ennemy[x]._pos.first += _ennemy[x]._speed;
        } else {
            _ennemy[x]._pos.first -= _ennemy[x]._speed;
        }
    }
}
//Says if the given coordonates collides with any of the ennemy's segments. <X, Y> pos, <wight, height> hitbox;
bool Arcade::Game::Centipede::isColisionToEnnemy(std::pair<int, int> pos, std::pair<int, int> hitbox, int speed)
{
    for(int x = 0; x < _ennemy.size(); x++) {
        if ((pos.first + hitbox.first) >= _ennemy[x]._pos.first && pos.first <= (_ennemy[x]._pos.first + _tile)) //X colision
            if ((pos.second + hitbox.second) >= _ennemy[x]._pos.second && pos.second <= (_ennemy[x]._pos.second + _tile)) //Y colision
                return true;
    }
    return false;
}
//Places the ennemy on the screen
void Arcade::Game::Centipede::ennemyDisplay()
{
    for(int x = 0; x < _ennemy.size(); x++) {
        addPixels(_ennemy[x]._pos, std::pair<int, int>(_tile, _tile), _ennemy[x]._color);
    }
}

void Arcade::Game::Centipede::ennemyManager()
{
    ennemyDirection();
    ennemyMove();
    ennemyDisplay();
}