/*
** EPITECH PROJECT, 2022
** B-OOP-400-MLH-4-1-arcade-theotime.schmeltz
** File description:
** Ncurses.hpp
*/

#pragma once
#include "IDisplayModule.hpp"
#include <ncurses.h>
#include <tuple>
#include <chrono>

namespace Arcade {
    namespace Graphics {
        class Ncurses : public IDisplayModule {
            public:
                /**
                 * @brief Init Ncurses "window"
                 * 
                 */
                Ncurses();
                /**
                 * @brief Destroy the Ncurses "window"
                 * 
                 */
                ~Ncurses();
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
            
            private:
                bool isOpen_;
                int ch_;
                int winHeight;
                int winLength;
                int limit_;
                std::chrono::system_clock::time_point time_;

        };
    }
}