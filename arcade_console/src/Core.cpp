/*
** EPITECH PROJECT, 2022
** B-OOP-400-MLH-4-1-arcade-theotime.schmeltz
** File description:
** Core.cpp
*/

#include "../includes/Core.hpp"
#include <string.h>

std::pair<int, int> long_to_coords(long nbr)
{
    return {nbr >> 32, static_cast<int>(nbr)};
}

Arcade::Core::Core(std::string firstLib)
{
    this->libsLoader.loadGraphicalHandler(firstLib);
    bool (*func)() = this->libsLoader.getGraphicalInstance<bool ()>("isGraphic");
    if (!func())
        exit(84);
    std::unique_ptr<Arcade::Graphics::IDisplayModule> (*funcEntry)(int, int) =
    this->libsLoader.getGraphicalInstance<std::unique_ptr<Arcade::Graphics::IDisplayModule> (int, int)>("entryPoint");
    this->graphicalLib.reset();
    this->graphicalLib = funcEntry(1920, 1080);
    this->graphicalName = firstLib;
    this->gameLibUsed = -1;
    this->userName = "Anonymous";
    this->openMenu = false;
    this->gameName = "";
    this->score = 0;
    this->graphicalNameCleared = firstLib.erase((firstLib.size() - 3), firstLib.size() - 1);
    this->graphicalNameCleared = this->graphicalNameCleared.erase(0, 11);
    srand(time(NULL));
}

void Arcade::Core::changeGraphicalLib(std::string libName)
{
    std::string libPath = "lib/" + libName;
    this->graphicalLib.reset();
    this->libsLoader.loadGraphicalHandler(libPath);
    std::unique_ptr<Arcade::Graphics::IDisplayModule> (*funcEntry)(int, int) =
    this->libsLoader.getGraphicalInstance<std::unique_ptr<Arcade::Graphics::IDisplayModule> (int, int)>("entryPoint");
    this->graphicalLib = funcEntry(1920, 1080);
    this->graphicalName = libPath;
    this->graphicalNameCleared = libName.erase((libName.size() - 3), libName.size() - 1);
    this->graphicalNameCleared = this->graphicalNameCleared.erase(0, 7);
}

void Arcade::Core::changeGameLib(std::string libName)
{
    std::string libPath = "lib/" + libName;
    this->gameLib.reset();
    this->libsLoader.loadGameHandler(libPath);
    std::unique_ptr<Arcade::Game::IGameModule> (*funcEntry)(int, int) =
    this->libsLoader.getGameInstance<std::unique_ptr<Arcade::Game::IGameModule> (int, int)>("entryPoint");
    this->gameLib = funcEntry(1920, 1080);
    this->gameName = libPath;
    this->gameNameCleared = libName.erase((libName.size() - 3), libName.size() - 1);
    this->gameNameCleared = this->gameNameCleared.erase(0, 7);
}

Arcade::Core::~Core()
{
    saveScoresAndClose();
}

unsigned int Arcade::Core::compresFromRgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    return r << 24 | g << 16 | b << 8 | a;
}

void Arcade::Core::putMapsPixels(const std::unordered_map<long, unsigned int> &pixels)
{
    for (auto i = pixels.begin(); i != pixels.end(); ++i)
        this->graphicalLib->putpixel(long_to_coords(i->first).first, long_to_coords(i->first).second, i->second);
}

void Arcade::Core::getHighScores()
{
    DIR *dir = opendir("highscores/");
    struct dirent *dr;
    std::fstream f;
    int i = 0;
    std::string fileName;
    while (dr = readdir(dir)) {
        if (dr->d_name[0] != '.') {
            fileName = "highscores/";
            fileName.append(dr->d_name);
            f.open(fileName, std::fstream::in);
            this->highScores.push_back(dr->d_name);
            this->highScores.at(i) += " :\n\n";
            if (f.is_open()) {
                while (!f.eof())
                    this->highScores.at(i) += f.get();
            this->highScores.at(i).erase(this->highScores.at(i).size() - 1);
            }
            f.close();
            ++i;
            fileName.clear();
        }
    }
}

void Arcade::Core::getLibs()
{
    DIR *dir = opendir("lib/");
    struct dirent *dr;
    char filePath[100] = "";
    bool (*func)();
    bool graphical;

    while (dr = readdir(dir)) {
        if (dr->d_name[0] != '.') {
            memset(filePath, 0, 100);
            strcat(filePath, "lib/");
            strcat(filePath, dr->d_name);
            graphical = this->libsLoader.checkGraphical(filePath); 
            if (!graphical)
                this->gameLibs.push_back(dr->d_name);
            if (graphical) {
                this->graphicalLibs.push_back(dr->d_name);
                if (filePath == this->graphicalName)
                    this->graphicalLibUsed = this->graphicalLibs.size() - 1;
            }
        }
    }
}

void Arcade::Core::setUserName()
{
    if (this->eventInputs.at(0) >= Arcade::Graphics::IDisplayModule::Events::A && this->eventInputs.at(0) <= Arcade::Graphics::IDisplayModule::Events::Z)
        this->userName += this->eventInputs.at(0) + 97;
    if (this->eventInputs.at(0) == Arcade::Graphics::IDisplayModule::Events::keySpace)
        this->userName += " ";
    if (this->eventInputs.at(0) == Arcade::Graphics::IDisplayModule::Events::backSpace && this->userName.length() != 0)
        this->userName.erase(this->userName.length() - 1);
}

void Arcade::Core::menuEventHandling()
{
    this->eventInputs = this->graphicalLib->getEvents();
    if (this->eventInputs.size() > 0) {
        if (this->eventInputs.at(0) == Arcade::Graphics::IDisplayModule::Events::keyEscape)
            saveScoresAndClose();
        if (this->select == this->gameLibs.size() + this->graphicalLibs.size()
        && this->eventInputs.at(0) != Arcade::Graphics::IDisplayModule::Events::keyUp
        && this->eventInputs.at(0) != Arcade::Graphics::IDisplayModule::Events::keyDown) {
            this->setUserName();
            this->eventInputs.clear();
            return;
        }
        if (this->eventInputs.at(0) == Arcade::Graphics::IDisplayModule::keySpace) {
            if (this->gameName != "" && this->userName != "") {
                this->openMenu = false;
            }
        }
        if (this->eventInputs.at(0) == Arcade::Graphics::IDisplayModule::Events::keyDown) {
            ++this->select;
            if (this->select == this->graphicalLibs.size() + this->gameLibs.size() + 1)
                this->select = 0;
        }
        if (this->eventInputs.at(0) == Arcade::Graphics::IDisplayModule::Events::keyUp) {
            --this->select;
            if (this->select < 0)
                this->select = this->graphicalLibs.size() + this->gameLibs.size();
        }
        if (this->eventInputs.at(0) == Arcade::Graphics::IDisplayModule::Events::keyEnter) {
            if (this->select < this->graphicalLibs.size() && this->select != this->graphicalLibUsed) {
                this->graphicalLibUsed = this->select;
                changeGraphicalLib(this->graphicalLibs.at(this->select));
            }
            else {
                this->gameLibUsed = this->select - (this->graphicalLibs.size());
                changeGameLib(this->gameLibs.at(this->gameLibUsed));
            }
        }
        if (this->eventInputs.at(0) == Arcade::Graphics::IDisplayModule::Events::G) {
            if (this->gameLibUsed != -1 && this->gameLibs.size() - 1 > this->gameLibUsed)
                ++this->gameLibUsed;
            else
                this->gameLibUsed = 0;
            this->changeGameLib(this->gameLibs.at(this->gameLibUsed));
        }
        else if (this->eventInputs.at(0) == Arcade::Graphics::IDisplayModule::Events::L) {
            if (this->graphicalLibs.size() - 1 > this->graphicalLibUsed)
                ++this->graphicalLibUsed;
            else
                this->graphicalLibUsed = 0;
            this->changeGraphicalLib(this->graphicalLibs.at(this->graphicalLibUsed));
        }
        this->eventInputs.clear();
    }
}

void Arcade::Core::gameEventHandling()
{
    this->eventInputs = this->graphicalLib->getEvents();
    if (this->eventInputs.size() > 0) {
        if (this->eventInputs.at(0) == Arcade::Graphics::IDisplayModule::Events::keyEscape)
            saveScoresAndClose();
        if (this->eventInputs.at(0) == Arcade::Graphics::IDisplayModule::Events::backSpace) {
            this->openMenu = true;
            loop();
        }
        if (this->eventInputs.at(0) == Arcade::Graphics::IDisplayModule::Events::G) {
            if (this->gameLibUsed != -1 && this->gameLibs.size() - 1 > this->gameLibUsed)
                ++this->gameLibUsed;
            else
                this->gameLibUsed = 0;
            this->changeGameLib(this->gameLibs.at(this->gameLibUsed));
        }
        else if (this->eventInputs.at(0) == Arcade::Graphics::IDisplayModule::Events::L) {
            if (this->graphicalLibs.size() - 1 > this->graphicalLibUsed)
                ++this->graphicalLibUsed;
            else
                this->graphicalLibUsed = 0;
            this->changeGraphicalLib(this->graphicalLibs.at(this->graphicalLibUsed));
        }
        else if (this->eventInputs.at(0) == Arcade::Graphics::IDisplayModule::Events::R)
            this->gameLib->reset();
        else
            this->gameLib->setInputs(this->eventInputs);
        this->eventInputs.clear();
    }
    else
        this->gameLib->setInputs(this->eventInputs);
}

void Arcade::Core::displayMenu()
{
    int i = 0;
    int j = 0;
    std::string libName;

    this->openMenu = true;

    while (this->graphicalLib->isOpen() && this->openMenu == true) {
        this->graphicalLib->puttext(10, 4, compresFromRgba(255, 255, 255, 255), "Libraries :");
        while (i < this->graphicalLibs.size()) {
            libName = this->graphicalLibs.at(i);
            if (strstr(this->graphicalName.c_str(), libName.c_str()) != NULL)
                libName += " (current)";
            if (this->select == i)
                libName += " <==";
            this->graphicalLib->puttext(10, 40 + (i * 40), compresFromRgba(255, 255, 255, 255), libName);
            ++i;
        }
        this->graphicalLib->puttext(10, 80 + (i * 40), compresFromRgba(255, 255, 255, 255), "Games :");
        while (j < this->gameLibs.size()) {
            libName = this->gameLibs.at(j);
            if (this->gameLibUsed != -1) {
                if (strstr(this->gameName.c_str(), libName.c_str()) != NULL)
                    libName += " (current)";
            }
            if (this->select == j + i)
                libName += " <==";
            this->graphicalLib->puttext(10, 240 + (j * 40), compresFromRgba(255, 255, 255, 255), libName);
            ++j;
        }
        if (this->select == this->gameLibs.size() + this->graphicalLibs.size())
            this->graphicalLib->puttext(10, 240 + ((j + 1) * 40), compresFromRgba(255, 255, 255, 255), "USER NAME : " + this->userName + " <==");
        else
            this->graphicalLib->puttext(10, 240 + ((j + 1) * 40), compresFromRgba(255, 255, 255, 255), "USER NAME : " + this->userName);
        this->graphicalLib->puttext(1920 / 2, 0, compresFromRgba(255, 255, 255, 255), "High Scores :");
        for (int x = 0; x != this->highScores.size(); ++x)
            this->graphicalLib->puttext(1920 / 2, x * 100 + 50, compresFromRgba(255, 255, 255, 255), this->highScores.at(x).c_str());
        i = 0;
        j = 0;
        this->graphicalLib->refreshWin();
        this->graphicalLib->clearWin();
        menuEventHandling();
    }
}

void Arcade::Core::saveScoresAndClose()
{
    FILE *file;
    std::string fileName;
    std::string gameName;
    std::string gameScore;
    for (int i = 0; i != this->highScores.size(); ++i) {
        fileName = "highscores/";
        gameName = this->highScores.at(i);
        gameScore = this->highScores.at(i);
        gameScore.erase(0, gameScore.find_first_of(':') + 3);
        gameName.erase(gameName.find_first_of(':'), gameName.size());
        fileName += gameName;
        fileName.erase(fileName.find_last_of(' '), fileName.size());
        file = fopen(fileName.c_str(), "w+");
        fprintf(file, gameScore.c_str());
        fclose(file);
    }
    exit(0);
}

void Arcade::Core::checkHighScores()
{
    int pos = -1;
    int currentScore = this->score;
    this->score = this->gameLib->getScore();
    std::string currentGame = this->gameName;
    std::string highScore;
    currentGame.erase(this->gameName.size() - 3, 3);
    currentGame.erase(0, 4);
    for (int i = 0; i != this->highScores.size(); ++i)
        if (strstr(this->highScores.at(i).c_str(), currentGame.c_str()) != NULL)
            pos = i;
    if (pos != -1) {
        highScore = this->highScores.at(pos);
        highScore.erase(0, highScore.find_last_of(' '));
        if (atoi(highScore.c_str()) < currentScore) {
            this->highScores.at(pos).erase(this->highScores.at(pos).find_last_of(':'), this->highScores.at(pos).size());
            this->highScores.at(pos) += ":\n\n";
            this->highScores.at(pos) += this->userName;
            this->highScores.at(pos) += " ";
            this->highScores.at(pos) += std::to_string(currentScore);
        }
    } else {
        this->highScores.push_back(currentGame);
        this->highScores.at(this->highScores.size() - 1) += " :\n\n";
        this->highScores.at(this->highScores.size() - 1) += this->userName;
        this->highScores.at(this->highScores.size() - 1) += " ";
        this->highScores.at(this->highScores.size() - 1) += std::to_string(currentScore);
    }
}

void Arcade::Core::launchGame()
{
    this->gameLib->start();
    while (this->graphicalLib->isOpen()) {
        std::this_thread::sleep_for(std::chrono::microseconds(100000));
        gameEventHandling();
        this->graphicalLib->puttext(0, 0, compresFromRgba(255, 255, 255, 255), "Game: "
        + this->gameNameCleared + "   Library used: " + this->graphicalNameCleared
        + "   Username: " + this->userName + "   Score: " + std::to_string(this->score));
        this->graphicalLib->puttext(0, 25, compresFromRgba(255, 255, 255, 255), "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
        this->graphicalLib->refreshWin();
        this->graphicalLib->clearWin();
        this->gameLib->refresh();
        this->putMapsPixels(this->gameLib->getPixels());
        if (this->gameLib->getScore() >= this->score)
            this->score = this->gameLib->getScore();
        else
            checkHighScores();
    }
}

void Arcade::Core::loop()
{
    if (this->graphicalLibs.size() == 0) {
        getLibs();
        getHighScores();
    }
    while (this->graphicalLib->isOpen()) {
        displayMenu();
        launchGame();
    }
}