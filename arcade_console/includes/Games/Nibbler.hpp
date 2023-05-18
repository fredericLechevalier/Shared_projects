/*
** EPITECH PROJECT, 2022
** B-OOP-400-MLH-4-1-arcade-theotime.schmeltz
** File description:
** Nibbler.hpp
*/

#pragma once
#include "IGameModule.hpp"
#include <chrono>

namespace Arcade {
    namespace Game {
        class Nibbler : public IGameModule
        {
        public:
            /**
             * @brief Init Nibbler
             * 
             */
            Nibbler();
            /**
             * @brief Destroy Nibbler
             * 
             */
            ~Nibbler();
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
            void setInputs(std::vector<Arcade::Graphics::IDisplayModule::Events>);
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
             * @brief Convert the snake, fruits and walls into an std::unordered_map<long, unsigned int>
             * 
             */
            void convertMap(void);
            /**
             * @brief Move the snake
             * 
             */
            void moveNibbler(void);
            /**
             * @brief Handle the events
             * 
             */
            void eventHandling(void);
            /**
             * @brief Check fruits and snake colisions
             * 
             */
            void checkFruit(void);
            /**
             * @brief Check snake colisions with himself
             * 
             */
            void checkDeath(void);
            /**
             * @brief Convert map from string to coords in std::vector<long>
             * 
             */
            void getMapCoords(void);
            /**
             * @brief check snake colisions with walls, change direction or stop depending the case
             * 
             * @param x 
             * @param y 
             */
            void checkWalls(int x, int y);
            /**
             * @brief check if the snake ate all fruits, change level if true
             * 
             */
            void checkWin(void);
            /**
             * @brief increase level member to go to next level
             * 
             */
            void getNextLevel(void);
            /**
             * @brief initialize the time_ member to make the time bar
             * 
             */
            void initTime(void);
            /**
             * @brief check time_ member to increase timeBar length, if timeBar touches the right screen limit, stops the game
             * 
             */
            void checkTime(void);

        protected:
            int nibblerLength;
            bool isAlive;
            size_t score;
            char direction;
            std::vector<long> nibbler;
            std::vector<Arcade::Graphics::IDisplayModule::Events> events;
            std::unordered_map<long, unsigned int> map;
            std::vector<long> fruit;
            std::vector <std::vector <std::string>> mapWalls;
            std::vector<long> walls;
            long wall;
            std::string mapInString;
            bool isMoving;
            int level;
            std::chrono::system_clock::time_point time_;
            std::vector<char> timeBar;
        };
    }
}

