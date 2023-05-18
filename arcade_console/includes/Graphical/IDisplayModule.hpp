/*
** EPITECH PROJECT, 2022
** Test
** File description:
** IDisplayModule.hpp
*/

#pragma once
#include <vector>
#include <iostream>
#include <dlfcn.h>
#include <stdlib.h>
#include <memory>
#include <utility>
#include <unistd.h>
#include <fstream>

namespace Arcade {
    namespace Graphics {
        class IDisplayModule {
            public:
                enum Events {
                    A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,
                    keyUp,
                    keyDown,
                    keyLeft,
                    keyRight,
                    key1,
                    key2,
                    key3,
                    key4,
                    key5,
                    key6,
                    key7,
                    key8,
                    key9,
                    key0,
                    keySpace,
                    keyEscape,
                    keyEnter,
                    rightClic,
                    leftClic,
                    backSpace,
                    close,
                };
                virtual ~IDisplayModule() = default;
                /**
                 * @brief Set the window's Frame Rate Limit
                 * 
                 * @param limit 
                 */
                virtual void setFrameRateLimit(int limit) = 0;
                /**
                 * @brief Put a pixel on the window
                 * 
                 * @param x x pos
                 * @param y y pos
                 * @param color color of the pixel
                 */
                virtual void putpixel(int x, int y, unsigned int color) = 0;
                /**
                 * @brief Put text on the window
                 * 
                 * @param x x pos
                 * @param y y pos
                 * @param color color of the text
                 * @param str text
                 */
                virtual void puttext(int x, int y, unsigned int color, const std::string &str) = 0;
                /**
                 * @brief Get the window's events
                 * 
                 * @return std::vector<Events> 
                 */
                virtual std::vector<Events> getEvents() = 0;
                /**
                 * @brief Get the Mouse Position
                 * 
                 * @return std::pair<x, y> 
                 */
                virtual std::pair<int, int> getMousePos() = 0;
                /**
                 * @brief Get the window's status
                 * 
                 * @return true Opened
                 * @return false Closed
                 */
                virtual bool isOpen() = 0;
                /**
                 * @brief Clear the window
                 * 
                 */
                virtual void clearWin() = 0;
                /**
                 * @brief Refresh the window
                 * 
                 */
                virtual void refreshWin() = 0;
        };
    }
}
