/*
** EPITECH PROJECT, 2022
** B-OOP-400-MLH-4-1-arcade-theotime.schmeltz
** File description:
** Core.hpp
*/

#pragma once
#include "DLLoader.hpp"
#include <sys/types.h>
#include <dirent.h>
#include <chrono>
#include <thread>

namespace Arcade {
    class Core
    {
        public:
            /**
             * @brief Construct a new Core and open the first graphical lib
             * 
             * @param firstLib 
             */
            Core(std::string firstLib);
            /**
             * @brief Destroy the Core
             * 
             */
            ~Core();
            /**
             * @brief Main loop of the project
             * 
             */
            void loop();
            /**
             * @brief Display the Arcade's menu
             * 
             */
            void displayMenu();
            /**
             * @brief Compress an Rgba Color
             * 
             * @param r red
             * @param g green
             * @param b blue
             * @param a alpha
             * @return unsigned int compressedColor
             */
            unsigned int compresFromRgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
            /**
             * @brief Open /lib and store the libs
             * 
             */
            void getLibs();
            /**
             * @brief Handle Events in the main Menu
             * 
             */
            void menuEventHandling();
            /**
             * @brief Handle Events in games
             * 
             */
            void gameEventHandling();
            /**
             * @brief Load a new graphical lib
             * 
             * @param libName 
             */
            void changeGraphicalLib(std::string libName);
            /**
             * @brief Load a new game lib
             * 
             * @param libName 
             */
            void changeGameLib(std::string libName);
            /**
             * @brief Set the User Name
             * 
             */
            void setUserName(void);
            /**
             * @brief Launch the selected game
             * 
             */
            void launchGame(void);
            /**
             * @brief Put each pixels of the map
             * 
             * @param pixels 
             */
            void putMapsPixels(const std::unordered_map<long, unsigned int> &pixels);
            /**
             * @brief Get the High Scores from highscores directory
             * 
             */
            void getHighScores(void);
            /**
             * @brief Check if the user beat the highscore
             * 
             */
            void checkHighScores(void);
            /**
             * @brief Save Scores and close the Arcade
             * 
             */
            void saveScoresAndClose(void);
        protected:
            DLLoader libsLoader;

            std::unique_ptr<Graphics::IDisplayModule> graphicalLib;
            std::vector<std::string> graphicalLibs;
            std::string graphicalName;
            std::string graphicalNameCleared;
            int graphicalLibUsed;

            std::unique_ptr<Game::IGameModule> gameLib;
            std::vector<std::string> gameLibs;
            std::string gameName;
            std::string gameNameCleared;
            int gameLibUsed;
            std::vector<std::string> highScores;
            size_t score;

            bool openMenu;
            std::vector <Graphics::IDisplayModule::Events> eventInputs;
            Graphics::IDisplayModule::Events event;
            int select = 0;
            std::string userName;
    };
}