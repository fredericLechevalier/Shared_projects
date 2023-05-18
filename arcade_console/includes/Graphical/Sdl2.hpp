/*
** EPITECH PROJECT, 2022
** B-OOP-400-MLH-4-1-arcade-theotime.schmeltz
** File description:
** Sdl2.hpp
*/

#pragma once
#include "IDisplayModule.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>

namespace Arcade {
    namespace Graphics {
        class Sdl2 : public IDisplayModule
        {
        public:
            /**
             * @brief Init SDL2 window
             * 
             * @param width 
             * @param height 
             */
            Sdl2(int width, int height);
            /**
             * @brief Destroy the SDL2 window
             * 
             */
            ~Sdl2();
            /**
             * @brief Set the window's Frame Rate Limit
             * 
             * @param limit 
             */
            void setFrameRateLimit(int limit);
            /**
             * @brief Put a pixel on the window
             * 
             * @param x x pos
             * @param y y pos
             * @param color color of the pixel
             */
            void putpixel(int x, int y, unsigned int color);
            /**
             * @brief Put text on the window
             * 
             * @param x x pos
             * @param y y pos
             * @param color color of the text
             * @param str text
             */
            void puttext(int x, int y, unsigned int color, const std::string &str);
            /**
             * @brief Get the window's events
             * 
             * @return std::vector<Events> 
             */
            std::vector<Events> getEvents();
            /**
             * @brief Get the Mouse Position
             * 
             * @return std::pair<x, y> 
             */
            std::pair<int, int> getMousePos();
            /**
             * @brief Get the window's status
             * 
             * @return true Opened
             * @return false Closed
             */
            bool isOpen();
            /**
             * @brief Clear the window
             * 
             */
            void clearWin();
            /**
             * @brief Refresh the window
             * 
             */
            void refreshWin();
        protected:
            SDL_Window *win;
            SDL_Renderer *rend;
            bool _isOpen;
            int frameRateLimit;
            TTF_Font *font;
        };
    }
}