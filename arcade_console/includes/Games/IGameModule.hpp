/*
** EPITECH PROJECT, 2022
** B-OOP-400-MLH-4-1-arcade-theotime.schmeltz
** File description:
** IGameModule.hpp
*/

#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include "../Graphical/IDisplayModule.hpp"
#include <unordered_map>
#include <memory>
#include <algorithm>

namespace Arcade {
    namespace Game {
        class IGameModule {
            public:
                /**
                 * @brief Get the Resolution of the game
                 * 
                 * @return std::pair<int x, int y> 
                 */
                virtual std::pair<int, int> getResolution() const = 0;
                /**
                 * @brief Start the game
                 * 
                 */
                virtual void start() = 0;
                /**
                 * @brief End the game
                 * 
                 */
                virtual void end() = 0;
                /**
                 * @brief Get the Score
                 * 
                 * @return const size_t& score
                 */
                virtual const size_t &getScore() const = 0;
                /**
                 * @brief Set the User's Keyboard Inputs
                 * 
                 * @param Events key 
                 */
                virtual void setInputs(std::vector<Arcade::Graphics::IDisplayModule::Events> e) = 0;
                /**
                 * @brief Get a map of pixels
                 * 
                 * @return const std::unordered_map<long position, unsigned int color>& 
                 */
                virtual const std::unordered_map<long, unsigned int> &getPixels() const = 0;
                /**
                 * @brief Refresh the game
                 * 
                 */
                virtual void refresh() = 0;
                /**
                 * @brief Restart the game
                 * 
                 */
                virtual void reset() = 0;
        };
    }
}