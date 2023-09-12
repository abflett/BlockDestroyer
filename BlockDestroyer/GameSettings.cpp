#include "GameSettings.h"
#include <inipp.h>
#include <iostream>
#include <fstream>
#include <stdexcept>

namespace BlockDestroyer {
    GameSettings::GameSettings() {
        inipp::Ini<char> ini;
        std::ifstream file("settings.ini");

        if (file) {
            ini.parse(file);
            file.close();
        }
        else {
            throw std::runtime_error("Error loading settings.ini");
        }

        /*inipp::extract(ini.sections["Engine"]["Initialized"], initialized);*/
        inipp::extract(ini.sections["Engine"]["ScreenWidth"], screenWidth);
        inipp::extract(ini.sections["Engine"]["ScreenHeight"], screenHeight);
        inipp::extract(ini.sections["Engine"]["RefreshRate"], refreshRate);
        inipp::extract(ini.sections["Engine"]["GameWidth"], gameWidth);
        inipp::extract(ini.sections["Engine"]["GameHeight"], gameHeight);
        inipp::extract(ini.sections["Engine"]["PlayfieldWidth"], playfieldWidth);
        inipp::extract(ini.sections["Engine"]["PlayfieldHeight"], playfieldHeight);
    }

    void GameSettings::saveSettings() {
        inipp::Ini<char> ini;

        /*ini.sections["Engine"]["Initialized"] = (initialized ? "true" : "false");*/
        ini.sections["Engine"]["ScreenWidth"] = std::to_string(screenWidth);
        ini.sections["Engine"]["ScreenHeight"] = std::to_string(screenHeight);
        ini.sections["Engine"]["RefreshRate"] = std::to_string(refreshRate);
        ini.sections["Engine"]["GameWidth"] = std::to_string(gameWidth);
        ini.sections["Engine"]["GameHeight"] = std::to_string(gameHeight);
        ini.sections["Engine"]["PlayfieldWidth"] = std::to_string(playfieldWidth);
        ini.sections["Engine"]["PlayfieldHeight"] = std::to_string(playfieldHeight);

        std::ofstream file("settings.ini");
        if (file) {
            ini.generate(file);
            file.close();
        }
        else {
            throw std::runtime_error("Error saving settings to settings.ini");
        }
    }

    int GameSettings::getScreenWidth() const {
        return screenWidth;
    }

    void GameSettings::setScreenWidth(int value) {
        screenWidth = value;
        saveSettings();
    }

    int GameSettings::getScreenHeight() const {
        return screenHeight;
    }

    void GameSettings::setScreenHeight(int value) {
        screenHeight = value;
        saveSettings();
    }

    int GameSettings::getRefreshRate() const {
        return refreshRate;
    }

    void GameSettings::setRefreshRate(int value) {
        refreshRate = value;
        saveSettings();
    }

    int GameSettings::getGameWidth() const {
        return gameWidth;
    }

    int GameSettings::getGameHeight() const {
        return gameHeight;
    }

    int GameSettings::getPlayfieldWidth() const {
        return playfieldWidth;
    }

    int GameSettings::getPlayfieldHeight() const {
        return playfieldHeight;
    }

    void GameSettings::initializeFirstLoad(int width, int height, int refresh) {
        screenWidth = width;
        screenHeight = height;
        refreshRate = refresh;
        saveSettings();
    }
}