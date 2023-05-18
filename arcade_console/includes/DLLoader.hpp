/*
** EPITECH PROJECT, 2022
** Test
** File description:
** DLLoader.hpp
*/

#pragma once
#include "Graphical/IDisplayModule.hpp"
#include "Games/IGameModule.hpp"

class DLLoader {
public:
    /**
     * @brief Construct a new DLLoader object
     * 
     */
    DLLoader() {};

    /**
     * @brief Open and store a graphical dynamic lib
     * 
     * @param libname 
     */
    void loadGraphicalHandler(std::string libname)
    {
        if (this->graphicalHandler != NULL)
            dlclose(graphicalHandler);
        this->graphicalHandler = NULL;
        this->graphicalHandler = dlopen(libname.c_str(), RTLD_LAZY | RTLD_NOW);
    }

    /**
     * @brief Open and store a game dynamic lib
     * 
     * @param libname 
     */
    void loadGameHandler(std::string libname)
    {
        if (this->gameHandler != NULL)
            dlclose(gameHandler);
        this->gameHandler = NULL;
        this->gameHandler = dlopen(libname.c_str(), RTLD_LAZY | RTLD_NOW);
    }

    /**
     * @brief Get the Game Instance
     * 
     * @tparam T func prototype
     * @param func funcName
     * @return T* func(T)
     */
    template <typename T>
    T* getGameInstance(std::string func)
    {
        if (this->gameHandler != NULL) {
            void *dlg = dlsym(this->gameHandler, func.c_str());
            if (dlg == NULL)
                return nullptr;
            return reinterpret_cast<T*>(dlg);
        }
        std::cout << dlerror() << std::endl;
        exit(84);
        return nullptr;
    }

    /**
     * @brief Destroy the DLLoader
     * 
     */
    ~DLLoader()
    {
        if (this->graphicalHandler != NULL)
            dlclose(this->graphicalHandler);
        if (this->checkHandler != NULL)
            dlclose(this->checkHandler);
        if (this->gameHandler != NULL)
            dlclose(this->gameHandler);
    }

    /**
     * @brief Get the Graphical Instance
     * 
     * @tparam T func prototype
     * @param func funcName
     * @return T* func(T)
     */
    template <typename T>
    T* getGraphicalInstance(std::string func)
    {
        if (this->graphicalHandler != NULL) {
            void *dlg = dlsym(this->graphicalHandler, func.c_str());
            if (dlg == NULL)
                return nullptr;
            return reinterpret_cast<T*>(dlg);
        }
        std::cout << dlerror() << std::endl;
        exit(84);
        return nullptr;
    }

    /**
     * @brief Check if a dynamic lib is whether a game or graphical lib
     * 
     * @param libname 
     * @return true if the lib is a graphical lib
     * @return false if the lib is a game lib
     */
    bool checkGraphical(std::string libname)
    {
        if (this->checkHandler != NULL)
            dlclose(checkHandler);
        this->checkHandler = dlopen(libname.c_str(), RTLD_LAZY | RTLD_NOW);
        if (!this->checkHandler)
            return NULL;
        bool (*func)(void) = reinterpret_cast<bool (*)(void)>(dlsym(this->checkHandler, "isGraphic"));
        return (func());
    }

protected:
    void *graphicalHandler = nullptr;
    void *gameHandler = nullptr;
    void *checkHandler = nullptr;
};
