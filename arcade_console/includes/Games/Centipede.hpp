/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-arcade-theotime.schmeltz
** File description:
** Centipede
*/

#pragma once
#include "IGameModule.hpp"
#include <memory>
#include <cstdlib>
#include <ctime>

struct rgbaColors {
    unsigned char _R;
    unsigned char _G;
    unsigned char _B;
    unsigned char _A;
};

struct obstacle {
    std::pair<int, int> _pos = {0, 100};
    unsigned int _hp = 5;
    unsigned int _color = 0x00ff00ff;//Green by default

    obstacle(std::pair<int, int> pos) : _pos(pos) {}
};

struct player {
    std::pair<int, int> _pos = {400, 400};
    unsigned int _lives = 5;
    int _speed; //_tile / 2
    unsigned int _color = 0xFFA500ff; //Orange by default
};

struct laser {
    std::pair<int, int> _pos = {0, 0};
    bool _alive = false;
    int _speed; //_tile / 2 OR
    unsigned int _color = 0xff0000ff;// Red by default
};

struct ennemy {
    std::pair<int, int> _pos;
    unsigned int _color;
    char _direction = 'r';
    int _goDown = 0;
    int _speed; //_tile / 4

    ennemy(unsigned int color, std::pair<int, int> pos, int speed) : _color(color), _pos(pos), _speed(speed) {}
};

struct border {
    std::pair<int, int> _pos;
    unsigned int _color;

    border(unsigned int color, std::pair<int, int> pos) : _color(color), _pos(pos) {}
};

struct playfield {
    int _x;
    int _y;
    int _width;
    int _height;

    playfield() {}
    playfield(int x, int y, int width, int height) : _x(x), _y(y), _width(width), _height(height) {}
};

namespace Arcade {
    namespace Game {
        class Centipede : public IGameModule
        {
        public:
            Centipede();
            ~Centipede();
            std::pair<int, int> getResolution() const {return _resolution;}
            void start();
            void end();
            const size_t &getScore() const {return _score;}
            void setInputs(std::vector<Arcade::Graphics::IDisplayModule::Events>);
            void refresh();
            void reset();
            //calls all the fonctions about the player
            void playerManager();
            void playerMove();
            void playerHit();
            void playerDisplay();
            //calls all the fonctions about the laser that the player can shoot*
            void laserManager();
            void laserMove();
            void laserFire();
            void laserDisplay();
            //calls all the fonctions about the ennemy centipede
            void ennemyManager();
            void ennemyDirection();
            void ennemyMove();
            void ennemySpawn(int lenght);
            bool isColisionToEnnemy(std::pair<int, int> pos, std::pair<int, int> hitbox, int speed);
            void ennemyDisplay();
            bool ennemyColisionChecks(std::pair<int, int> pos, std::pair<int, int> hitbox, int speed, char direction);
            //calls all the fonctions about the obstacles
            void obstaclesManager();
            void obstaclesSpawn(int x, int y);
            bool isColisionToObstacle(std::pair<int, int> pos, std::pair<int, int> hitbox, int speed, char direction);
            int randomPostionGenerator(int max);
            void obstaclesDisplay();
            //Screen related foncions

            const std::unordered_map<long, unsigned int> &getPixels() const;
            unsigned int compresFromRgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
            rgbaColors decompressFromRgba(unsigned int color);
            long pair_to_long(int x, int y);
            std::pair<int, int> long_to_pair(long nbr);
            void cleanPixel();
            void addPixels(std::pair<int, int> pos, std::pair<int, int> size, unsigned int color);
            bool isColisionToBorder(std::pair<int, int> pos, std::pair<int, int> hitbox, int speed, char direction);
            void borderMake(int widthInTiles, int heightInTiles);
            void bordersdisplay();

        protected:
            std::pair<int, int> _resolution;
            size_t _score;
            std::vector<struct obstacle> _obstacles;
            std::vector<struct ennemy> _ennemy;
            struct laser _laser;
            struct player _player;
            struct playfield _playfield;
            std::vector<Arcade::Graphics::IDisplayModule::Events> _events;
            std::unordered_map<long, unsigned int> _screen;
            int _tile = 20; //universal square size of most object, also universal height of every hitboxs
            std::vector<struct border> _borders;
        };
    }
}