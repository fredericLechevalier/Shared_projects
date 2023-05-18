/*
** EPITECH PROJECT, 2022
** B-OOP-400-MLH-4-1-arcade-theotime.schmeltz
** File description:
** SFML.cpp
*/

#include "../../includes/Graphical/SFML.hpp"

Arcade::Graphics::SFML::SFML(int width, int height)
{
    _window = std::make_unique<sf::RenderWindow>(sf::VideoMode::getDesktopMode(), "Arcade SFML", sf::Style::Fullscreen);
    if (!_font.loadFromFile("./doc/two_p_font.ttf"))
        std::cout << "Font loadFromFile by SFML failed.\n";
    this->_isOpen = true;
}

void Arcade::Graphics::SFML::setFrameRateLimit(int limit)
{
    _window->setFramerateLimit(limit);
}

void Arcade::Graphics::SFML::putpixel(int x, int y, unsigned int color)
{
    sf::RectangleShape pixel(sf::Vector2f(1, 1));
    sf::Color myColor;

    myColor.r = color >> 24;
    myColor.g = color >> 16;
    myColor.b = color >> 8;
    myColor.a = color;
    pixel.setFillColor(myColor);
    pixel.setPosition(x, y);
    _window->draw(pixel);
}

void Arcade::Graphics::SFML::puttext(int x, int y, unsigned int color, const std::string &str)
{
    sf::Text text;
    sf::Color myColor;
    myColor.r = color >> 24;
    myColor.g = color >> 16;
    myColor.b = color >> 8;
    myColor.a = color;

    text.setFont(_font);
    text.setString(str);
    text.setCharacterSize(26);
    text.setFillColor(myColor);
    text.setPosition(x, y);
    _window->draw(text);
}

std::vector<Arcade::Graphics::SFML::Events> Arcade::Graphics::SFML::getEvents()
{
    std::vector<Arcade::Graphics::SFML::Events> events;
    sf::Event sfevent;

    while(_window->pollEvent(sfevent)) {
        switch (sfevent.type)
        {
        case sf::Event::Closed:
            events.push_back(Events::close);
            this->_isOpen = false;
            break;
        case sf::Event::MouseButtonPressed:
            events = getEventsMouse(events, sfevent);
            break;
        case sf::Event::KeyPressed:
            events = getEventsKeys(events, sfevent);
            break;
        }
    }
    return (events);
}

std::pair<int, int> Arcade::Graphics::SFML::getMousePos()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition();

    return std::make_pair(mousePos.x, mousePos.y);
}

bool Arcade::Graphics::SFML::isOpen()
{
    return (this->_isOpen);
}

void Arcade::Graphics::SFML::clearWin()
{
    _window->clear();
}

void Arcade::Graphics::SFML::refreshWin()
{
    _window->display();
}

std::vector<Arcade::Graphics::SFML::Events> Arcade::Graphics::SFML::getEventsMouse(std::vector<Arcade::Graphics::SFML::Events> events, sf::Event sfevent)
{
    if (sfevent.mouseButton.button == sf::Mouse::Left)
        events.push_back(Events::leftClic);
    if (sfevent.mouseButton.button == sf::Mouse::Right)
        events.push_back(Events::rightClic);
    return events;
}

std::vector<Arcade::Graphics::SFML::Events> Arcade::Graphics::SFML::getEventsKeys(std::vector<Arcade::Graphics::SFML::Events> events, sf::Event sfevent)
{
    switch (sfevent.key.code) {
        case sf::Keyboard::A:
            events.push_back(Events::A);
            break;
        case sf::Keyboard::B:
            events.push_back(Events::B);
            break;
        case sf::Keyboard::C:
            events.push_back(Events::C);
            break;
        case sf::Keyboard::D:
            events.push_back(Events::D);
            break;
        case sf::Keyboard::E:
            events.push_back(Events::E);
            break;
        case sf::Keyboard::F:
            events.push_back(Events::F);
            break;
        case sf::Keyboard::G:
            events.push_back(Events::G);
            break;
        case sf::Keyboard::H:
            events.push_back(Events::H);
            break;
        case sf::Keyboard::I:
            events.push_back(Events::I);
            break;
        case sf::Keyboard::J:
            events.push_back(Events::J);
            break;
        case sf::Keyboard::K:
            events.push_back(Events::K);
            break;
        case sf::Keyboard::L:
            events.push_back(Events::L);
            break;
        case sf::Keyboard::M:
            events.push_back(Events::M);
            break;
        case sf::Keyboard::N:
            events.push_back(Events::N);
            break;
        case sf::Keyboard::O:
            events.push_back(Events::O);
            break;
        case sf::Keyboard::P:
            events.push_back(Events::P);
            break;
        case sf::Keyboard::Q:
            events.push_back(Events::Q);
            break;
        case sf::Keyboard::R:
            events.push_back(Events::R);
            break;
        case sf::Keyboard::S:
            events.push_back(Events::S);
            break;
        case sf::Keyboard::T:
            events.push_back(Events::T);
            break;
        case sf::Keyboard::U:
            events.push_back(Events::U);
            break;
        case sf::Keyboard::V:
            events.push_back(Events::V);
            break;
        case sf::Keyboard::W:
            events.push_back(Events::W);
            break;
        case sf::Keyboard::X:
            events.push_back(Events::X);
            break;
        case sf::Keyboard::Y:
            events.push_back(Events::Y);
            break;
        case sf::Keyboard::Z:
            events.push_back(Events::Z);
            break;
        case sf::Keyboard::Up:
            events.push_back(Events::keyUp);
            break;
        case sf::Keyboard::Down:
            events.push_back(Events::keyDown);
            break;
        case sf::Keyboard::Left:
            events.push_back(Events::keyLeft);
            break;
        case sf::Keyboard::Right:
            events.push_back(Events::keyRight);
            break;
        case sf::Keyboard::Num0 :
            events.push_back(Events::key0);
            break;
        case sf::Keyboard::Num1:
            events.push_back(Events::key1);
            break;
        case sf::Keyboard::Num2:
            events.push_back(Events::key2);
            break;
        case sf::Keyboard::Num3:
            events.push_back(Events::key3);
            break;
        case sf::Keyboard::Num4:
            events.push_back(Events::key4);
            break;
        case sf::Keyboard::Num5:
            events.push_back(Events::key5);
            break;
        case sf::Keyboard::Num6:
            events.push_back(Events::key6);
            break;
        case sf::Keyboard::Num7:
            events.push_back(Events::key7);
            break;
        case sf::Keyboard::Num8:
            events.push_back(Events::key8);
            break;
        case sf::Keyboard::Num9:
            events.push_back(Events::key9);
            break;
        case sf::Keyboard::Numpad0:
            events.push_back(Events::key0);
            break;
        case sf::Keyboard::Numpad1:
            events.push_back(Events::key1);
            break;
        case sf::Keyboard::Numpad2:
            events.push_back(Events::key2);
            break;
        case sf::Keyboard::Numpad3:
            events.push_back(Events::key3);
            break;
        case sf::Keyboard::Numpad4:
            events.push_back(Events::key4);
            break;
        case sf::Keyboard::Numpad5:
            events.push_back(Events::key5);
            break;
        case sf::Keyboard::Numpad6:
            events.push_back(Events::key6);
            break;
        case sf::Keyboard::Numpad7:
            events.push_back(Events::key7);
            break;
        case sf::Keyboard::Numpad8:
            events.push_back(Events::key8);
            break;
        case sf::Keyboard::Numpad9:
            events.push_back(Events::key9);
            break;
        case sf::Keyboard::Space:
            events.push_back(Events::keySpace);
            break;
        case sf::Keyboard::Escape:
            events.push_back(Events::keyEscape);
            break;
        case sf::Keyboard::BackSpace:
            events.push_back(Events::backSpace);
            break;
        case sf::Keyboard::Enter:
            events.push_back(Events::keyEnter);
            break;
        }
    return events;
}

extern "C" {
    std::unique_ptr<Arcade::Graphics::IDisplayModule> entryPoint(int width, int height)
    {
        return std::make_unique<Arcade::Graphics::SFML>(width, height);
    }
    bool isGraphic()
    {
        return true;
    }
}
