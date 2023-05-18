/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-theotime.schmeltz
** File description:
** CriticalError
*/

#ifndef CRITICAL_ERROR_HPP_
#define CRITICAL_ERROR_HPP_

#include <iostream>
#include <memory>

class CriticalError : public std::exception
{
    public:
        explicit CriticalError(std::string msg) {_msg = "CRITICAL ERROR : " + msg;}
        virtual ~CriticalError() noexcept {}
        virtual const char* what() const noexcept {return _msg.c_str();}
    protected :
        std::string _msg;
};

#endif /* !CRITICAL_ERROR_HPP_ */
