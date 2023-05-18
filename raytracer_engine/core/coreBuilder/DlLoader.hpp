/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-theotime.schmeltz
** File description:
** DLloader
*/

#pragma once

#include <dlfcn.h>
#include <fstream>
#include "../CriticalError.hpp"
#include "../Error.hpp"

/**
 * @brief an class for encapsulate function from the dlfcn library and for get an object from a .so shared library file
 *
 * @tparam T the type of the object that you want
 */
template<typename T>
class DLLoader {
    /**
     * @brief nested class error for handle the errors that can occur in the dlloader class
     *
     */
    public :
        /**
         * @brief Construct a new DLLoader object, default constructor
         *
         */
        DLLoader();
        /**
         * @brief Construct a new DLLoader object with an path
         *
         * @param path
         */
        DLLoader(const std::string &);
        /**
         * @brief construct a new dllLoader object with an already active .so lib
         *
         */
        DLLoader(void *&);
        /**
         * @brief Destroy the DLLoader object
         *
         */
        ~DLLoader();
        /**
         * @brief load a new shared library
         *
         * @param path
         */
        void load(const std::string &);
        /**
         * @brief close the actual shared library
         *
         */
        void close();
        /**
         * @brief Get the factory of the object
         *
         * @return T the object
         */
        std::unique_ptr<T> getFactory();
        /**
         * @brief override of the = operator for just change the actual lib inside of the object
         *
         * @param other
         */
        void operator=(const DLLoader& other);
        /**
         * @brief get the last error occured
         *
         * @return const std::string
         */
        const std::string error() const;
        /**
         * @brief realease the pointer of the actual active lib
         *
         * @return void*& a refrence to the pointer
         */
        void *& operator*();
    private:
        void *_actLib;
};

template<typename T>
DLLoader<T>::DLLoader()
{
    _actLib = NULL;
}

template<typename T>
DLLoader<T>::DLLoader(void *& lib)
{
    this->_actLib = lib;
}

template<typename T>
void DLLoader<T>::load(const std::string &name)
{
    std::fstream file;
    file.open(name, std::ios::in);
    if (!file)
        throw (CriticalError("No file or cannot open file " + name));
    file.close();
    _actLib = dlopen(name.c_str(), RTLD_NOW | RTLD_LAZY);
    if (_actLib == NULL) {
        std::string error(dlerror());
        throw (CriticalError(error + " at " + name));
    }
}

template<typename T>
const std::string DLLoader<T>::error() const
{
    char *tmp = dlerror();
    std::string nw_string = "";
    if (tmp == NULL) return nw_string;
    nw_string = tmp;
    return nw_string;
}

template<typename T>
DLLoader<T>::DLLoader(const std::string &name)
{
    load(name);
}

template<typename T>
DLLoader<T>::~DLLoader()
{
    // dlclose(_actLib);
}

template<typename T>
void DLLoader<T>::close()
{
    dlclose(_actLib);
    _actLib = NULL;
}

template<typename T>
std::unique_ptr<T> DLLoader<T>::getFactory()
{
    if (!_actLib)
        throw (CriticalError("No lib inside of the object"));
    std::unique_ptr<T> (*ptr_func)() = reinterpret_cast<std::unique_ptr<T>(*)()>(dlsym(_actLib, "getFactory"));
    return ptr_func();
}

template<typename T>
void DLLoader<T>::operator=(const DLLoader& other)
{
    _actLib = other._actLib;
}

template<typename T>
void *& DLLoader<T>::operator*()
{
    return _actLib;
}