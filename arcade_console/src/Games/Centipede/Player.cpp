/*
** EPITECH PROJECT, 2023
** B4-Object-Oriented_Programming
** File description:
** Player
*/

#include "../../../includes/Games/Centipede.hpp"

void Arcade::Game::Centipede::playerManager()
{
    playerHit();
    playerMove();
    playerDisplay();
}

void Arcade::Game::Centipede::playerMove()
{
    if (std::find(_events.begin(), _events.end(), Arcade::Graphics::IDisplayModule::Events::D) != _events.end()
     || std::find(_events.begin(), _events.end(), Arcade::Graphics::IDisplayModule::Events::keyRight) != _events.end())
        if (!isColisionToBorder(_player._pos, std::pair<int, int>(_tile, _tile), _player._speed, 'r')
        &&  !isColisionToObstacle(_player._pos, std::pair<int, int>(_tile, _tile), _player._speed, 'r'))
            _player._pos.first += _player._speed;
    if (std::find(_events.begin(), _events.end(), Arcade::Graphics::IDisplayModule::Events::Q) != _events.end()
     || std::find(_events.begin(), _events.end(), Arcade::Graphics::IDisplayModule::Events::keyLeft) != _events.end())
        if (!isColisionToBorder(_player._pos, std::pair<int, int>(_tile, _tile), _player._speed, 'l')
        &&  !isColisionToObstacle(_player._pos, std::pair<int, int>(_tile, _tile), _player._speed, 'l'))
            _player._pos.first -= _player._speed;
    if (std::find(_events.begin(), _events.end(), Arcade::Graphics::IDisplayModule::Events::Z) != _events.end()
     || std::find(_events.begin(), _events.end(), Arcade::Graphics::IDisplayModule::Events::keyUp) != _events.end())
        if (!isColisionToBorder(_player._pos, std::pair<int, int>(_tile, _tile), _player._speed, 'u')
        &&  !isColisionToObstacle(_player._pos, std::pair<int, int>(_tile, _tile), _player._speed, 'u'))
            _player._pos.second -= _player._speed;
    if (std::find(_events.begin(), _events.end(), Arcade::Graphics::IDisplayModule::Events::S) != _events.end()
     || std::find(_events.begin(), _events.end(), Arcade::Graphics::IDisplayModule::Events::keyDown) != _events.end())
        if (!isColisionToBorder(_player._pos, std::pair<int, int>(_tile, _tile), _player._speed, 'd')
        &&  !isColisionToObstacle(_player._pos, std::pair<int, int>(_tile, _tile), _player._speed, 'd'))
            _player._pos.second += _player._speed;
}

void Arcade::Game::Centipede::playerHit()
{

}

void Arcade::Game::Centipede::playerDisplay()
{
    addPixels(_player._pos, std::pair<int, int>(_tile, _tile), _player._color);
}
