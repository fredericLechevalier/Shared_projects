/*
** EPITECH PROJECT, 2022
** B-OOP-400-MLH-4-1-arcade-theotime.schmeltz
** File description:
** Centipede.cpp
*/

#include "../../../includes/Games/Centipede.hpp"
//Maybe could create values ? but that dosen't seem neccessary
Arcade::Game::Centipede::Centipede()
{
    _score = 0;
}

Arcade::Game::Centipede::~Centipede()
{
}
//Starts a new game
void Arcade::Game::Centipede::start()
{
    _score = 0;
    borderMake(30, 20);
    _laser._speed = _tile;//_tile / 2;
    _player._speed = _tile;//_tile / 2;
    _resolution = {1920, 1080};
    for (int x = 0; x <= 10; x++) //generates 30 random obstacles for the begining of the game
        obstaclesSpawn(randomPostionGenerator(_playfield._width - (_tile * 2)) + _playfield._x, randomPostionGenerator(_playfield._height - _tile) + _playfield._y);
    ennemySpawn(5);
}
//Closes the game
void Arcade::Game::Centipede::end()
{
    _obstacles.clear();
    _ennemy.clear();
    _borders.clear();
}
//Updates the Input vectors by replacing it for a new one, for the game to read
void Arcade::Game::Centipede::setInputs(std::vector<Arcade::Graphics::IDisplayModule::Events> inputs)
{
    _events.clear();
    _events = inputs;
}
//Getter of said container that simulates the whole screen with
const std::unordered_map<long, unsigned int> &Arcade::Game::Centipede::getPixels() const
{
    return _screen;
}
//Updates the game
void Arcade::Game::Centipede::refresh()
{
    cleanPixel();
    if (_player._lives == 0)
        end();
    playerManager();
    //laserManager();
    ennemyManager();
    obstaclesManager();
    bordersdisplay();
}
//Restarts to a new game
void Arcade::Game::Centipede::reset()
{
    end();
    start();
    //end() then start() ? Will depend on memory and variables allocations, but will be probably cleaner to be sure to get new values
}

extern "C" {
    std::unique_ptr<Arcade::Game::IGameModule> entryPoint(int width, int height)
    {
        return std::make_unique<Arcade::Game::Centipede>();
    }
    bool isGraphic()
    {
        return false;
    }
}