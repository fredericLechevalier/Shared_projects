/*
** EPITECH PROJECT, 2022
** B-OOP-400-MLH-4-1-arcade-theotime.schmeltz
** File description:
** Ncurses.cpp
*/

#include "../../includes/Graphical/Ncurses.hpp"

Arcade::Graphics::Ncurses::Ncurses()
{
    initscr();
    start_color();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_BLACK, COLOR_YELLOW);
    init_pair(3, COLOR_BLACK, COLOR_GREEN);
    init_pair(4, COLOR_BLACK, COLOR_BLUE);
    init_pair(5, COLOR_BLACK, COLOR_WHITE);
    mousemask(BUTTON1_CLICKED , NULL);
    timeout(0);
    this->isOpen_ = true;
    getmaxyx(stdscr, this->winHeight, this->winLength);
    this->time_ = std::chrono::system_clock::now();

}

Arcade::Graphics::Ncurses::~Ncurses()
{
    endwin();
}

void Arcade::Graphics::Ncurses::setFrameRateLimit(int limit)
{
    this->limit_ = limit;
}

void Arcade::Graphics::Ncurses::putpixel(int x, int y, unsigned int color)
{
    short r = color >> 24;
    if (r > 200 && r <= 255) {
        attron(COLOR_PAIR(1));
    }
    else if (r > 150 && r < 200){
        attron(COLOR_PAIR(2));
    }
    else if (r > 100 && r < 150){
        attron(COLOR_PAIR(3));
    }
    else if (r > 50 && r < 100){
        attron(COLOR_PAIR(4));
    }
    else if (r >= 0 && r < 50){
        attron(COLOR_PAIR(5));
    }
    int newX = x / (1920 / this->winLength + 1);
    int newY = y / (1080 / this->winHeight + 1);
    if (newX > this->winLength)
        newX -= 5;
    if (newY > this->winHeight)
        newY -= 5;
    mvprintw(newY, newX, " ");
}

void Arcade::Graphics::Ncurses::puttext(int x, int y, unsigned int color, const std::string &str)
{
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    y /= 10;
    x /= 10;
    std::string copyStr;
    attron(COLOR_PAIR(3));
    getmaxyx(stdscr, this->winHeight, this->winLength);
    if (this->winLength < str.size()) {
        copyStr = str;
        copyStr.erase(this->winLength, str.size() - 1);
        mvprintw(y, x, copyStr.c_str());
    } else
        mvprintw(y, x, str.c_str());
    attroff(COLOR_PAIR(3));
}

std::vector<Arcade::Graphics::Ncurses::Events> Arcade::Graphics::Ncurses::getEvents()
{
    this->ch_ = getch();
    std::vector<Arcade::Graphics::IDisplayModule::Events> events;
    if (this->ch_ == KEY_BACKSPACE)
        events.push_back(Arcade::Graphics::IDisplayModule::Events::backSpace);
    if (this->ch_ == KEY_UP)
        events.push_back(Arcade::Graphics::IDisplayModule::Events::keyUp);
    if (this->ch_ == KEY_DOWN)
        events.push_back(Arcade::Graphics::IDisplayModule::Events::keyDown);
    if (this->ch_ == KEY_LEFT)
        events.push_back(Arcade::Graphics::IDisplayModule::Events::keyLeft);
    if (this->ch_ == KEY_RIGHT)
        events.push_back(Arcade::Graphics::IDisplayModule::Events::keyRight);
    if (this->ch_ == 32)
        events.push_back(Arcade::Graphics::IDisplayModule::Events::keySpace);
    if (this->ch_ == '0')
        events.push_back(Arcade::Graphics::IDisplayModule::Events::key0);
    if (this->ch_ == '1')
        events.push_back(Arcade::Graphics::IDisplayModule::Events::key1);
    if (this->ch_ == '2')
        events.push_back(Arcade::Graphics::IDisplayModule::Events::key2);
    if (this->ch_ == '3')
        events.push_back(Arcade::Graphics::IDisplayModule::Events::key3);
    if (this->ch_ == '4')
        events.push_back(Arcade::Graphics::IDisplayModule::Events::key4);
    if (this->ch_ == '5')
        events.push_back(Arcade::Graphics::IDisplayModule::Events::key5);
    if (this->ch_ == '6')
        events.push_back(Arcade::Graphics::IDisplayModule::Events::key6);
    if (this->ch_ == '7')
        events.push_back(Arcade::Graphics::IDisplayModule::Events::key7);
    if (this->ch_ == '8')
        events.push_back(Arcade::Graphics::IDisplayModule::Events::key8);
    if (this->ch_ == '9')
        events.push_back(Arcade::Graphics::IDisplayModule::Events::key9);
    if (this->ch_ == '\n')
        events.push_back(Arcade::Graphics::IDisplayModule::Events::keyEnter);
    if (this->ch_ == 27)
        events.push_back(Arcade::Graphics::IDisplayModule::Events::keyEscape);
    else
        events.push_back(static_cast<Arcade::Graphics::IDisplayModule::Events>(this->ch_ - 97));

    return (events);
}

std::pair<int, int> Arcade::Graphics::Ncurses::getMousePos()
{
    return (std::pair<int, int>(0, 0));
}

bool Arcade::Graphics::Ncurses::isOpen()
{
    return this->isOpen_;
}

void Arcade::Graphics::Ncurses::clearWin()
{
    std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - this->time_).count() >= (1000 / 60)) {
        clear();
        this->time_ = currentTime;
    }
}

void Arcade::Graphics::Ncurses::refreshWin()
{
    refresh();
}

extern "C" {
    std::unique_ptr<Arcade::Graphics::IDisplayModule> entryPoint(int width, int height)
    {
        return std::make_unique<Arcade::Graphics::Ncurses>();
    }
    bool isGraphic()
    {
        return true;
    }
}
