/*
** EPITECH PROJECT, 2022
** B-OOP-400-MLH-4-1-arcade-theotime.schmeltz
** File description:
** Snake.cpp
*/

#include "../../includes/Games/Snake.hpp"

std::pair<int, int> long_to_coords(long nbr)
{
    return {nbr >> 32, static_cast<int>(nbr)};
}

long coords_to_long(int x, int y)
{
    return static_cast<long>(x) << 32 | static_cast<long>(y);
}

Arcade::Game::Snake::Snake()
{
    this->alive = true;
    this->score = 0;
    this->snakeLength = 4;
    this->direction = 'l';
    int fruitY = (rand() % (1080 / 20)) * 20;
    while (fruitY <= 20)
        fruitY = (rand() % (1080 / 20)) * 20;
    this->fruit = coords_to_long((rand() % (1920 / 20)) * 20, fruitY);
    this->snake.push_back(coords_to_long(940, 520));
    this->snake.push_back(coords_to_long(960, 520));
    this->snake.push_back(coords_to_long(980, 520));
    this->snake.push_back(coords_to_long(1000, 520));
}

void Arcade::Game::Snake::convertMap()
{
    this->map.clear();
    int posx;
    int posy;
    for (int x = 0; x != this->snake.size(); ++x)
        for (int i = 0; i != 20; ++i)
            for (int j = 0; j != 20; ++j) {
                posx = long_to_coords(this->snake[x]).first + i;
                posy = long_to_coords(this->snake[x]).second + j;
                x == 0 ? this->map[coords_to_long(posx, posy)] = compresFromRgba(255, 255, (x * 15) % 255, 255)
                : this->map[coords_to_long(posx, posy)] = compresFromRgba((x * 5) % 255, 255, (x * 15) % 255, 255);
            }
    for (int i = 0; i != 20; ++i)
        for (int j = 0; j != 20; ++j) {
            posx = long_to_coords(this->fruit).first + i;
            posy = long_to_coords(this->fruit).second + j;
            this->map[coords_to_long(posx, posy)] = compresFromRgba(255, 0, 0, 255);
        }
}

std::pair<int, int> Arcade::Game::Snake::getResolution() const
{
    return (std::make_pair(1920, 1080));
}

void Arcade::Game::Snake::moveSnake()
{
    std::vector<long> tmp = this->snake;
    int headX = long_to_coords(this->snake[0]).first;
    int headY = long_to_coords(this->snake[0]).second;
    if (this->direction == 'l')
        this->snake[0] = coords_to_long(headX - 20, headY);
    if (this->direction == 'd')
        this->snake[0] = coords_to_long(headX, headY + 20);
    if (this->direction == 'u')
        this->snake[0] = coords_to_long(headX, headY - 20);
    if (this->direction == 'r')
        this->snake[0] = coords_to_long(headX + 20, headY);
    for (int i = 1; i != this->snake.size(); ++i)
        this->snake[i] = tmp[i - 1];
}

void Arcade::Game::Snake::eventHandling()
{
    if (this->events.size() > 0) {
        if ((this->events.at(0) == Arcade::Graphics::IDisplayModule::Events::keyDown
        || this->events.at(0) == Arcade::Graphics::IDisplayModule::Events::S) && this->direction != 'u')
            this->direction = 'd';
        if ((this->events.at(0) == Arcade::Graphics::IDisplayModule::Events::keyRight
        || this->events.at(0) == Arcade::Graphics::IDisplayModule::Events::D) && this->direction != 'l')
            this->direction = 'r';
        if ((this->events.at(0) == Arcade::Graphics::IDisplayModule::Events::keyLeft
        || this->events.at(0) == Arcade::Graphics::IDisplayModule::Events::Q) && this->direction != 'r')
            this->direction = 'l';
        if ((this->events.at(0) == Arcade::Graphics::IDisplayModule::Events::keyUp
        || this->events.at(0) == Arcade::Graphics::IDisplayModule::Events::Z) && this->direction != 'd')
            this->direction = 'u';
    }
}

void Arcade::Game::Snake::checkFruit()
{
    if (this->snake[0] == this->fruit) {
        this->snakeLength += 1;
        if (this->direction == 'l')
            this->snake.push_back(coords_to_long(long_to_coords(this->snake[this->snakeLength - 2]).first + 20,
            long_to_coords(this->snake[this->snakeLength - 2]).second));
        if (this->direction == 'r')
            this->snake.push_back(coords_to_long(long_to_coords(this->snake[this->snakeLength - 2]).first - 20,
            long_to_coords(this->snake[this->snakeLength - 2]).second));
        if (this->direction == 'u')
            this->snake.push_back(coords_to_long(long_to_coords(this->snake[this->snakeLength - 2]).first,
            long_to_coords(this->snake[this->snakeLength - 2]).second + 20));
        if (this->direction == 'd')
            this->snake.push_back(coords_to_long(long_to_coords(this->snake[this->snakeLength - 2]).first,
            long_to_coords(this->snake[this->snakeLength - 2]).second - 20));
        int fruitY = (rand() % (1080 / 20)) * 20;
        while (fruitY <= 20)
            fruitY = (rand() % (1080 / 20)) * 20;
        this->fruit = coords_to_long((rand() % (1920 / 20)) * 20, fruitY);
        ++this->score;
    }
}

void Arcade::Game::Snake::checkDeath()
{
    for (int i = 1; i != this->snake.size(); ++i)
        if (this->snake[0] == this->snake[i])
            this->alive = false;
    if (long_to_coords(this->snake[0]).first < 0 || long_to_coords(this->snake[0]).first >= 1920
    || long_to_coords(this->snake[0]).second < 0 || long_to_coords(this->snake[0]).second >= 1080)
        this->alive = false;
}

void Arcade::Game::Snake::start()
{
}

void Arcade::Game::Snake::end()
{
    if (this->events.size() != 0)
        this->reset();
}

const size_t &Arcade::Game::Snake::getScore() const
{
    return (this->score);
}

void Arcade::Game::Snake::setInputs(std::vector<Arcade::Graphics::IDisplayModule::Events> e)
{
    this->events.clear();
    this->events = e;
}

const std::unordered_map<long, unsigned int> &Arcade::Game::Snake::getPixels() const
{
    return (this->map);
}

void Arcade::Game::Snake::refresh()
{
    if (this->alive) {
        this->eventHandling();
        this->moveSnake();
        this->convertMap();
        this->checkFruit();
        this->checkDeath();
    } else
        this->end();
}

void Arcade::Game::Snake::reset()
{
    this->map.clear();
    this->snake.clear();
    this->events.clear();
    this->alive = true;
    this->score = 0;
    this->snakeLength = 4;
    this->direction = 'l';
    int fruitY = (rand() % (1080 / 20)) * 20;
    while (fruitY <= 20)
        fruitY = (rand() % (1080 / 20)) * 20;
    this->fruit = coords_to_long((rand() % (1920 / 20)) * 20, fruitY);
    this->snake.push_back(coords_to_long(940, 520));
    this->snake.push_back(coords_to_long(960, 520));
    this->snake.push_back(coords_to_long(980, 520));
    this->snake.push_back(coords_to_long(1000, 520));
}

unsigned int Arcade::Game::Snake::compresFromRgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

extern "C" {
    std::unique_ptr<Arcade::Game::IGameModule> entryPoint(int width, int height)
    {
        return std::make_unique<Arcade::Game::Snake>();
    }
    bool isGraphic()
    {
        return false;
    }
}
