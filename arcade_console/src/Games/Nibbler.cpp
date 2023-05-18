/*
** EPITECH PROJECT, 2022
** B-OOP-400-MLH-4-1-arcade-theotime.schmeltz
** File description:
** Nibbler.cpp
*/

#include "../../includes/Games/Nibbler.hpp"

std::pair<int, int> long_to_coords(long nbr)
{
    return {nbr >> 32, static_cast<int>(nbr)};
}

long coords_to_long(int x, int y)
{
    return static_cast<long>(x) << 32 | static_cast<long>(y);
}

void Arcade::Game::Nibbler::getMapCoords()
{
    this->mapWalls = {
        {
            "wwwwwwwwwwwwwwwwwwwwwwwwwwwww",
            "w                           w",
            "w     w   w    f         f  w",
            "w     w   w          w      w",
            "w     w   w          w      w",
            "w     w   w          w      w",
            "w     wwwww    f     w      w",
            "w  f                 w      w",
            "w     wwwww          w      w",
            "w     w f w          w      w",
            "w     w   w    f     w      w",
            "w                        f  w",
            "w             ssss          w",
            "wwwwwwwwwwwwwwwwwwwwwwwwwwwww"
        },
        {
            "wwwwwwwwwwwwwwwwwwwwwwwwwwwww",
            "w  f                        w",
            "w    wwwwwww             f  w",
            "w    w f w w         w      w",
            "w    w   www       wwwww    w",
            "w                    w      w",
            "w    f         f     w      w",
            "w                           w",
            "w    ww   wwww       w      w",
            "w         w          w      w",
            "w     f   w   f      w      w",
            "w                           w",
            "w             ssss       f  w",
            "wwwwwwwwwwwwwwwwwwwwwwwwwwwww"
        },
        {
            "wwwwwwwwwwwwwwwwwwwwwwwwwwwww",
            "w                      w  f w",
            "w     w   ww   f       w    w",
            "w  f  w  fw            w    w",
            "w     w w w                 w",
            "w     w w w          f      w",
            "w     wwwwwwww              w",
            "w                   www   f w",
            "w  f  w              f      w",
            "w     w   w                 w",
            "w   f w   w    f    www     w",
            "w        w                  w",
            "w       ww    ssss      f   w",
            "wwwwwwwwwwwwwwwwwwwwwwwwwwwww"
        }
    };

    for (int i = 0; i < this->mapWalls.at(this->level).size(); ++i) {
        for (int j = 0; j < this->mapWalls.at(this->level).at(i).size(); ++j) {
            if (this->mapWalls.at(this->level).at(i).at(j) == 'f')
                this->fruit.push_back(coords_to_long(100 + (j * 20), 100 + (i * 20)));
            else if (this->mapWalls.at(this->level).at(i).at(j) == 's')
                this->nibbler.push_back(coords_to_long((100 + (j * 20)), (100 + (i * 20))));
            else if (this->mapWalls.at(this->level).at(i).at(j) == 'w')
                this->walls.push_back(coords_to_long((100 + (j * 20)), (100 + (i * 20))));
        }
    }

}

void Arcade::Game::Nibbler::initTime()
{
    this->time_ = std::chrono::system_clock::now();
}

Arcade::Game::Nibbler::Nibbler()
{
    this->isAlive = true;
    this->score = 0;
    this->nibblerLength = 4;
    this->direction = 'l';
    this->level = 0;
    getMapCoords();
    this->isMoving = true;
    this->initTime();
}

Arcade::Game::Nibbler::~Nibbler()
{
}

void Arcade::Game::Nibbler::convertMap()
{
    this->map.clear();
    int posx;
    int posy;

    for (int x = 0; x != this->walls.size(); ++x)
        for (int i = 0; i != 15; ++i)
            for (int j = 0; j != 15; ++j) {
                posx = long_to_coords(this->walls[x]).first + i;
                posy = long_to_coords(this->walls[x]).second + j;
                    this->map[coords_to_long(posx, posy)] = compresFromRgba(255, 255, 255, 255);
            }


    for (int x = 0; x != this->nibbler.size(); ++x)
        for (int i = 0; i != 20; ++i)
            for (int j = 0; j != 20; ++j) {
                posx = long_to_coords(this->nibbler[x]).first + i;
                posy = long_to_coords(this->nibbler[x]).second + j;
                x == 0 ? this->map[coords_to_long(posx, posy)] = compresFromRgba(255, 255, (x * 15) % 255, 255)
                : this->map[coords_to_long(posx, posy)] = compresFromRgba((x * 5) % 255, 255, (x * 15) % 255, 255);
            }
    for (int x = 0; x != this->fruit.size(); ++x) {
        for (int i = 0; i != 20; ++i)
            for (int j = 0; j != 20; ++j) {
                posx = long_to_coords(this->fruit[x]).first + i;
                posy = long_to_coords(this->fruit[x]).second + j;
                this->map[coords_to_long(posx, posy)] = compresFromRgba(255, 0, 0, 255);
            }
    }
    for (int x = 0; x != this->timeBar.size(); ++x) {
        for (int i = 0; i != 10; ++i) {
            for (int j = 0; j != 5; ++j) {
                this->map[coords_to_long(0 + 10 * x + i, 500 + j)] = compresFromRgba(255, 0, 0, 255);
            }
        }
    }
}

std::pair<int, int> Arcade::Game::Nibbler::getResolution() const
{
    return (std::make_pair(1920, 1080));
}

void Arcade::Game::Nibbler::moveNibbler()
{
    std::vector<long> tmp = this->nibbler;
    int headX = long_to_coords(this->nibbler[0]).first;
    int headY = long_to_coords(this->nibbler[0]).second;

    if (this->isMoving != false) {
        if (this->direction == 'l')
            this->nibbler[0] = coords_to_long(headX - 20, headY);
        else if (this->direction == 'd')
            this->nibbler[0] = coords_to_long(headX, headY + 20);
        else if (this->direction == 'u')
            this->nibbler[0] = coords_to_long(headX, headY - 20);
        else if (this->direction == 'r')
            this->nibbler[0] = coords_to_long(headX + 20, headY);
        for (int i = 1; i != this->nibbler.size() && this->isMoving; ++i)
            this->nibbler[i] = tmp[i - 1];
    }
}

void Arcade::Game::Nibbler::eventHandling()
{
    if (this->events.size() > 0) {
        if ((this->events.at(0) == Arcade::Graphics::IDisplayModule::Events::keyDown
        || this->events.at(0) == Arcade::Graphics::IDisplayModule::Events::S) && this->direction != 'u') {
            this->direction = 'd';
            this->isMoving = true;
        }
        if ((this->events.at(0) == Arcade::Graphics::IDisplayModule::Events::keyRight
        || this->events.at(0) == Arcade::Graphics::IDisplayModule::Events::D) && this->direction != 'l') {
            this->direction = 'r';
            this->isMoving = true;
        }
        if ((this->events.at(0) == Arcade::Graphics::IDisplayModule::Events::keyLeft
        || this->events.at(0) == Arcade::Graphics::IDisplayModule::Events::Q) && this->direction != 'r') {
            this->direction = 'l';
            this->isMoving = true;
        }
        if ((this->events.at(0) == Arcade::Graphics::IDisplayModule::Events::keyUp
        || this->events.at(0) == Arcade::Graphics::IDisplayModule::Events::Z) && this->direction != 'd') {
            this->direction = 'u';
            this->isMoving = true;
        }
    }
}

void Arcade::Game::Nibbler::checkFruit()
{
    for (int i = 0; i < this->fruit.size(); ++i) {
        if (this->nibbler[0] == this->fruit[i]) {
            this->nibblerLength += 1;
            if (this->direction == 'l')
                this->nibbler.push_back(coords_to_long(long_to_coords(this->nibbler[this->nibblerLength - 2]).first + 20,
                long_to_coords(this->nibbler[this->nibblerLength - 2]).second));
            if (this->direction == 'r')
                this->nibbler.push_back(coords_to_long(long_to_coords(this->nibbler[this->nibblerLength - 2]).first - 20,
                long_to_coords(this->nibbler[this->nibblerLength - 2]).second));
            if (this->direction == 'u')
                this->nibbler.push_back(coords_to_long(long_to_coords(this->nibbler[this->nibblerLength - 2]).first,
                long_to_coords(this->nibbler[this->nibblerLength - 2]).second + 20));
            if (this->direction == 'd')
                this->nibbler.push_back(coords_to_long(long_to_coords(this->nibbler[this->nibblerLength - 2]).first,
                long_to_coords(this->nibbler[this->nibblerLength - 2]).second - 20));
            fruit.erase(fruit.begin() + i);
            ++this->score;
        }
    }
}

void Arcade::Game::Nibbler::checkWalls(int x, int y)
{
    long coordsA;
    long coordsB;

    if (this->direction == 'l') {
        if (std::find(this->walls.begin(), this->walls.end(), coords_to_long(x - 20, y)) != this->walls.end()) {
            coordsA = coords_to_long(x, y - 20);
            coordsB = coords_to_long(x, y + 20);
            if (std::find(this->walls.begin(), this->walls.end(), coordsA) == this->walls.end() &&
                std::find(this->walls.begin(), this->walls.end(), coordsB) == this->walls.end()) {
                this->isMoving = false;
            }
            else if (std::find(this->walls.begin(), this->walls.end(), coordsB) != this->walls.end()) {
                this->direction = 'u';
                this->isMoving = true;
            }
            else if (std::find(this->walls.begin(), this->walls.end(), coordsA) != this->walls.end()) {
                this->direction = 'd';
                this->isMoving = true;
            }
        }
    }
    else if (this->direction == 'r') {
        if (std::find(this->walls.begin(), this->walls.end(), coords_to_long(x + 20, y)) != this->walls.end()) {
            coordsA = coords_to_long(x, y - 20);
            coordsB = coords_to_long(x, y + 20);
            if (std::find(this->walls.begin(), this->walls.end(), coordsA) == this->walls.end() &&
                std::find(this->walls.begin(), this->walls.end(), coordsB) == this->walls.end()) {
                this->isMoving = false;
            }
            else if (std::find(this->walls.begin(), this->walls.end(), coordsB) == this->walls.end()) {
                this->direction = 'd';
                this->isMoving = true;
            }
            else if (std::find(this->walls.begin(), this->walls.end(), coordsA) == this->walls.end()) {
                this->direction = 'u';
                this->isMoving = true;
            }
        }
    }

    else if (this->direction == 'd') {
        if (std::find(this->walls.begin(), this->walls.end(), coords_to_long(x, y + 20)) != this->walls.end()) {
            coordsA = coords_to_long(x + 20, y);
            coordsB = coords_to_long(x - 20, y);

            if (std::find(this->walls.begin(), this->walls.end(), coordsA) == this->walls.end() &&
                std::find(this->walls.begin(), this->walls.end(), coordsB) == this->walls.end()) {
                this->isMoving = false;
            }
            else if (std::find(this->walls.begin(), this->walls.end(), coordsB) == this->walls.end()) {
                this->direction = 'l';
                this->isMoving = true;
            }
            else if (std::find(this->walls.begin(), this->walls.end(), coordsA) == this->walls.end()) {
                this->direction = 'r';
                this->isMoving = true;
            }
        }
    }

    else if (this->direction == 'u') {
        if (std::find(this->walls.begin(), this->walls.end(), coords_to_long(x, y - 20)) != this->walls.end()) {
            coordsA = coords_to_long(x + 20, y);
            coordsB = coords_to_long(x - 20, y);
            if (std::find(this->walls.begin(), this->walls.end(), coordsA) == this->walls.end() &&
                std::find(this->walls.begin(), this->walls.end(), coordsB) == this->walls.end()) {
                this->isMoving = false;
            }
            else if (std::find(this->walls.begin(), this->walls.end(), coordsB) == this->walls.end()) {
                this->direction = 'l';
                this->isMoving = true;
            }
            else if (std::find(this->walls.begin(), this->walls.end(), coordsA) == this->walls.end()) {
                this->direction = 'r';
                this->isMoving = true;
            }
        }
    }
}

void Arcade::Game::Nibbler::checkWin()
{
    if (this->fruit.size() == 0) {
        if (this->level < 2) {
            ++this->level;
            this->getNextLevel();
        }
        else {
            this->level = 0;
            this->getNextLevel();
        }
    }
}

void Arcade::Game::Nibbler::checkDeath()
{
    for (int i = 1; i < this->nibbler.size(); ++i)
        if (this->nibbler[0] == this->nibbler[i])
            this->isAlive = false;
}

void Arcade::Game::Nibbler::start()
{

}

void Arcade::Game::Nibbler::end()
{
    if (this->events.size() != 0)
        this->reset();
}

const size_t &Arcade::Game::Nibbler::getScore() const
{
    return (this->score);
}

void Arcade::Game::Nibbler::setInputs(std::vector<Arcade::Graphics::IDisplayModule::Events> e)
{
    this->events.clear();
    this->events = e;
}

const std::unordered_map<long, unsigned int> &Arcade::Game::Nibbler::getPixels() const
{
    return (this->map);
}


void Arcade::Game::Nibbler::checkTime()
{
    std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();
    if (this->timeBar.size() > 192) {
        this->isAlive = false;
    }
    else if (std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - this->time_).count() >= (1000)) {
        this->timeBar.push_back('s');
    }
}

void Arcade::Game::Nibbler::refresh()
{
    if (this->isAlive) {
        this->eventHandling();
        this->checkWalls(long_to_coords(this->nibbler[0]).first, long_to_coords(this->nibbler[0]).second);
        this->moveNibbler();
        this->convertMap();
        this->checkFruit();
        this->checkDeath();
        this->checkWin();
        this->checkTime();
    } else
        this->end();
}

void Arcade::Game::Nibbler::getNextLevel()
{
    this->map.clear();
    this->nibbler.clear();
    this->events.clear();
    this->walls.clear();
    this->fruit.clear();
    this->timeBar.clear();
    this->isAlive = true;
    this->nibblerLength = 4;
    this->direction = 'l';
    this->isMoving = true;
    getMapCoords();
    this->initTime();

}

void Arcade::Game::Nibbler::reset()
{
    this->map.clear();
    this->nibbler.clear();
    this->events.clear();
    this->walls.clear();
    this->fruit.clear();
    this->timeBar.clear();
    this->isAlive = true;
    this->score = 0;
    this->nibblerLength = 4;
    this->direction = 'l';
    this->isMoving = true;
    this->level = 0;
    getMapCoords();
    this->initTime();

}

unsigned int Arcade::Game::Nibbler::compresFromRgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    return r << 24 | g << 16 | b << 8 | a;
}

extern "C" {
    std::unique_ptr<Arcade::Game::IGameModule> entryPoint(int width, int height)
    {
        return std::make_unique<Arcade::Game::Nibbler>();
    }
    bool isGraphic()
    {
        return false;
    }
}
