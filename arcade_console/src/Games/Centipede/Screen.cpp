/*
** EPITECH PROJECT, 2023
** B4-Object-Oriented_Programming
** File description:
** Screen
*/

#include "../../../includes/Games/Centipede.hpp"

long Arcade::Game::Centipede::pair_to_long(int x, int y) {
    return static_cast<long>(x) << 32 | static_cast<long>(y);
}

std::pair<int, int> Arcade::Game::Centipede::long_to_pair(long nbr) {
    return {nbr >> 32, static_cast<int>(nbr)};
}

unsigned int Arcade::Game::Centipede::compresFromRgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a) //also in Core
{
    return r << 24 | g << 16 | b << 8 | a;
}

rgbaColors Arcade::Game::Centipede::decompressFromRgba(unsigned int color)
{
    unsigned char red   = (color & 0xff000000) >> 24; //0xFFA50000 orange ?
    unsigned char green = (color & 0x00ff0000) >> 16;
    unsigned char blue  = (color & 0x0000ff00) >> 8;
    unsigned char a     = (color & 0x000000ff);
    rgbaColors tupColors {red, green, blue, a};

    return tupColors;
}
//add a block of a color to the screen variable, in order for this block to be drawn for the next screen update
void Arcade::Game::Centipede::addPixels(std::pair<int, int> pos, std::pair<int, int> size, unsigned int color)
{
    for (int y = 0; y < size.second; y++)
        for (int x = 0; x < size.first; x++)
            this->_screen.insert({pair_to_long(pos.first + x, pos.second + y), color});
}
//cleans the screen
void Arcade::Game::Centipede::cleanPixel()
{
    this->_screen.clear();
}

bool Arcade::Game::Centipede::isColisionToBorder(std::pair<int, int> pos, std::pair<int, int> hitbox, int speed, char direction)
{
    if (direction == 'r' && pos.first + hitbox.first >= (_playfield._x + _playfield._width - _tile))
        return true;
    if (direction == 'l' && pos.first <= _playfield._x)
        return true;
    if (direction == 'd' && pos.second + hitbox.second >= (_playfield._y + _playfield._height - _tile))
        return true;
    if (direction == 'u' && pos.second <= _playfield._y)
        return true;
    return false;
}
//Creates the borders for the game, take the number of tiles for it's dimenssions as arguments
void Arcade::Game::Centipede::borderMake(int widthInTiles, int heightInTiles)
{
    _playfield = playfield(_tile * 4, _tile * 6, widthInTiles * _tile, heightInTiles * _tile);
    std::pair<int, int> pos = {0, _tile * 5};
    unsigned char value = 255;
    unsigned int color = compresFromRgba(value, value, value, 255);

    for (int x = 0; x <= widthInTiles; x++) {
        pos.first = (_playfield._x - _tile + (x * _tile));
        _borders.push_back(border(color, pos));
    }
    for (int y = 0; y <= heightInTiles - 1; y++) {
        value -= 10;
        color = compresFromRgba(value, value, value, 255);
        pos = {_playfield._x - _tile, _playfield._y + (y * _tile)};
        _borders.push_back(border(color, pos));
        pos = {_playfield._width + (_tile * 3) , _playfield._y + (y * _tile)};
        _borders.push_back(border(color, pos));
    }
    value -= 10;
    color = compresFromRgba(value, value, value, 255);
    pos.second = _playfield._width - _playfield._x;
    for (int x = 0; x <= widthInTiles; x++) {
        pos.first = (_playfield._x - _tile + (x * _tile));
        _borders.push_back(border(color, pos));
    }
}

void Arcade::Game::Centipede::bordersdisplay()
{
    for (int x = 0; x < _borders.size(); x++)
        addPixels(_borders[x]._pos, std::pair<int, int>(_tile, _tile), _borders[x]._color);
}
