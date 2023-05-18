/*
** EPITECH PROJECT, 2022
** B-OOP-400-MLH-4-1-arcade-theotime.schmeltz
** File description:
** SFML.hpp
*/

#pragma once
#include "IDisplayModule.hpp"
#include <SFML/Graphics.hpp>

namespace Arcade {
    namespace Graphics {
        class SFML : public IDisplayModule
        {
        public:
            /**
             * @brief Init SFML window
             * 
             * @param width 
             * @param height 
             */
            SFML(int width, int height);
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
            void refreshWin(); //fonctions only called from inside the class :
            /**
             * @brief Get the Events Mouse object
             * 
             * @param events 
             * @param event 
             * @return std::vector<Events> 
             */
            std::vector<Events> getEventsMouse(std::vector<Arcade::Graphics::SFML::Events> events, sf::Event event);
            /**
             * @brief Get the Events Keys object
             * 
             * @param events 
             * @param event 
             * @return std::vector<Events> 
             */
            std::vector<Events> getEventsKeys(std::vector<Arcade::Graphics::SFML::Events> events, sf::Event event);

        protected:
            std::unique_ptr<sf::RenderWindow> _window;
            sf::Font _font;
            bool _isOpen;
        };
    }
}