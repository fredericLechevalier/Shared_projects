/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-theotime.schmeltz
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <iostream>
#include <memory>

class Error: public std::exception
{
    public:
        explicit Error(const std::string logsName) { _logs = std::ofstream(logsName, std::ofstream::out); }
        virtual const void writeLogs(const std::string str) { _logs << str; }
        virtual ~Error() noexcept { _logs.close(); }
    protected :
        std::ofstream _logs;
};

#endif /* !ERROR_HPP_ */
