/*
** EPITECH PROJECT, 2022
** B-OOP-400-MLH-4-1-arcade-theotime.schmeltz
** File description:
** Sdl2.cpp
*/

#include "../../includes/Graphical/Sdl2.hpp"

Arcade::Graphics::Sdl2::Sdl2(int width, int height)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
        exit (84);
    }
    TTF_Init();
    this->win = SDL_CreateWindow("Arcade SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_FULLSCREEN);
    this->rend = SDL_CreateRenderer(this->win, -1, SDL_RENDERER_ACCELERATED);
    this->_isOpen = true;
    this->font = TTF_OpenFont("doc/two_p_font.ttf", 24);
    if (!this->font) {
        std::cout << TTF_GetError() << std::endl;
        exit(84);
    }
    SDL_SetRenderDrawColor(this->rend, 0, 0, 0, 255);
}

Arcade::Graphics::Sdl2::~Sdl2()
{
    SDL_DestroyRenderer(this->rend);
    SDL_DestroyWindow(this->win);
}

void Arcade::Graphics::Sdl2::setFrameRateLimit(int limit)
{
    SDL_Delay(1000 / limit);
    this->frameRateLimit = limit;
}

void Arcade::Graphics::Sdl2::putpixel(int x, int y, unsigned int color)
{
    SDL_SetRenderDrawColor(this->rend, color >> 24, color >> 16, color >> 8, color);
    SDL_RenderDrawPoint(this->rend, x, y);
}

void Arcade::Graphics::Sdl2::puttext(int x, int y, unsigned int color, const std::string &str)
{
    SDL_Color Color;

    Color.r = color >> 24;
    Color.g = color >> 16;
    Color.b = color >> 8;
    Color.a = color;
    SDL_Surface *surface = TTF_RenderText_Solid(this->font, str.c_str(), Color);
    SDL_Texture *Message = SDL_CreateTextureFromSurface(this->rend, surface);
    int height = 0;
    int width = 0;
    SDL_QueryTexture(Message, NULL, NULL, &width, &height);
    SDL_Rect txtRect = {x, y, width, height};
    SDL_RenderCopy(this->rend, Message, NULL, &txtRect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(Message);
}

std::vector<Arcade::Graphics::IDisplayModule::Events> Arcade::Graphics::Sdl2::getEvents()
{
    SDL_Event e;
    std::vector<Arcade::Graphics::IDisplayModule::Events> events;
    while (SDL_PollEvent(&e) > 0) {
        if (e.type == SDL_QUIT) {
            events.push_back(Arcade::Graphics::IDisplayModule::Events::close);
            this->_isOpen = false;
            break;
        }
        if (e.type == SDL_MOUSEBUTTONDOWN) {
            if (e.button.button == SDL_BUTTON_LEFT) {
                events.push_back(Arcade::Graphics::IDisplayModule::Events::leftClic);
                break;
            }
            if (e.button.button == SDL_BUTTON_RIGHT) {
                events.push_back(Arcade::Graphics::IDisplayModule::Events::rightClic);
                break;
            }
        }
        if (e.type == SDL_KEYDOWN) {
            if (e.key.keysym.sym == SDLK_UP) {
                events.push_back(Arcade::Graphics::IDisplayModule::Events::keyUp);
                break;
            }
            if (e.key.keysym.sym == SDLK_DOWN) {
                events.push_back(Arcade::Graphics::IDisplayModule::Events::keyDown);
                break;
            }
            if (e.key.keysym.sym == SDLK_LEFT) {
                events.push_back(Arcade::Graphics::IDisplayModule::Events::keyLeft);
                break;
            }
            if (e.key.keysym.sym == SDLK_RIGHT) {
                events.push_back(Arcade::Graphics::IDisplayModule::Events::keyRight);
                break;
            }
            if (e.key.keysym.sym == SDLK_1) {
                events.push_back(Arcade::Graphics::IDisplayModule::Events::key1);
                break;
            }
            if (e.key.keysym.sym == SDLK_2) {
                events.push_back(Arcade::Graphics::IDisplayModule::Events::key2);
                break;
            }
            if (e.key.keysym.sym == SDLK_3) {
                events.push_back(Arcade::Graphics::IDisplayModule::Events::key3);
                break;
            }
            if (e.key.keysym.sym == SDLK_4) {
                events.push_back(Arcade::Graphics::IDisplayModule::Events::key4);
                break;
            }
            if (e.key.keysym.sym == SDLK_5) {
                events.push_back(Arcade::Graphics::IDisplayModule::Events::key5);
                break;
            }
            if (e.key.keysym.sym == SDLK_6) {
                events.push_back(Arcade::Graphics::IDisplayModule::Events::key6);
                break;
            }
            if (e.key.keysym.sym == SDLK_7) {
                events.push_back(Arcade::Graphics::IDisplayModule::Events::key7);
                break;
            }
            if (e.key.keysym.sym == SDLK_8) {
                events.push_back(Arcade::Graphics::IDisplayModule::Events::key8);
                break;
            }
            if (e.key.keysym.sym == SDLK_9) {
                events.push_back(Arcade::Graphics::IDisplayModule::Events::key9);
                break;
            }
            if (e.key.keysym.sym == SDLK_0) {
                events.push_back(Arcade::Graphics::IDisplayModule::Events::key0);
                break;
            }
            if (e.key.keysym.sym == SDLK_SPACE) {
                events.push_back(Arcade::Graphics::IDisplayModule::Events::keySpace);
                break;
            }
            if (e.key.keysym.sym == SDLK_ESCAPE) {
                events.push_back(Arcade::Graphics::IDisplayModule::Events::keyEscape);
                break;
            }
            if (e.key.keysym.sym == SDLK_RETURN) {
                events.push_back(Arcade::Graphics::IDisplayModule::Events::keyEnter);
                break;
            }
            if (e.key.keysym.sym == SDLK_BACKSPACE) {
                events.push_back(Arcade::Graphics::IDisplayModule::Events::backSpace);
                break;
            }
            events.push_back(static_cast<Arcade::Graphics::IDisplayModule::Events>(e.key.keysym.sym - 97));
            break;
        }
    }
    return (events);
}

std::pair<int, int> Arcade::Graphics::Sdl2::getMousePos()
{
    int x;
    int y;
    SDL_GetGlobalMouseState(&x, &y);
    return (std::pair<int, int>(x, y));
}

bool Arcade::Graphics::Sdl2::isOpen()
{
    return (this->_isOpen);
}

void Arcade::Graphics::Sdl2::clearWin()
{
    SDL_RenderClear(this->rend);
}

void Arcade::Graphics::Sdl2::refreshWin()
{
    SDL_RenderPresent(this->rend);
    SDL_SetRenderDrawColor(this->rend, 0, 0, 0, 255);
}

extern "C" {
    std::unique_ptr<Arcade::Graphics::IDisplayModule> entryPoint(int width, int height)
    {
        return std::make_unique<Arcade::Graphics::Sdl2>(width, height);
    }
    bool isGraphic()
    {
        return true;
    }
}
