/*
** EPITECH PROJECT, 2022
** B-OOP-400-MLH-4-1-arcade-theotime.schmeltz
** File description:
** Snake.hpp
*/

#pragma once
#include "IGameModule.hpp"

namespace Arcade {
    namespace Game {
        class Snake : public IGameModule
        {
        public:
            /**
             * @brief Init Snake
             * 
             */
            Snake();
            /**
             * @brief Destroy Snake
             * 
             */
            ~Snake();
            /**
             * @brief Get the Resolution of the game
             * 
             * @return std::pair<int x, int y> 
             */
            std::pair<int, int> getResolution() const;
            /**
             * @brief Start the game
             * 
             */
            void start();
            /**
             * @brief End the game
             * 
             */
            void end();
            /**
             * @brief Get the Score
             * 
             * @return const size_t& score
             */
            const size_t &getScore() const;
            /**
             * @brief Set the User's Keyboard Inputs
             * 
             * @param Events key 
             */
            void setInputs(std::vector<Arcade::Graphics::IDisplayModule::Events> e);
            /**
             * @brief Get a map of pixels
             * 
             * @return const std::unordered_map<long position, unsigned int color>& 
             */
            const std::unordered_map<long, unsigned int> &getPixels() const;
            /**
             * @brief Refresh the game
             * 
             */
            void refresh();
            /**
             * @brief Restart the game
             * 
             */
            void reset();
            /**
             * @brief Compress a RGBA color into a single unsigned int
             * 
             * @param r Red
             * @param g Green
             * @param b Blue
             * @param a Alpha
             * @return unsigned int color 
             */
            unsigned int compresFromRgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
            /**
             * @brief Convert the snake and fruit into an std::unordered_map<long, unsigned int>
             * 
             */
            void convertMap(void);
            /**
             * @brief Move the snake
             * 
             */
            void moveSnake(void);
            /**
             * @brief Handle the events
             * 
             */
            void eventHandling(void);
            /**
             * @brief Check fruit and snake colisions
             * 
             */
            void checkFruit(void);
            /**
             * @brief Check snake colisions with walls and himself
             * 
             */
            void checkDeath(void);
        protected:
            int snakeLength;
            bool alive;
            size_t score;
            char direction;
            std::vector<long> snake;
            std::vector<Arcade::Graphics::IDisplayModule::Events> events;
            std::unordered_map<long, unsigned int> map;
            long fruit;
        };
    }
}
