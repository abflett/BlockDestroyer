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

        inipp::extract(ini.sections["Engine"]["Initialized"], initialized);
        inipp::extract(ini.sections["Engine"]["ScreenWidth"], screenWidth);
        inipp::extract(ini.sections["Engine"]["ScreenHeight"], screenHeight);
        inipp::extract(ini.sections["Engine"]["RefreshRate"], refreshRate);
    }

    void GameSettings::saveSettings() {
        inipp::Ini<char> ini;

        ini.sections["Engine"]["Initialized"] = (initialized ? "true" : "false");
        ini.sections["Engine"]["ScreenWidth"] = std::to_string(screenWidth);
        ini.sections["Engine"]["ScreenHeight"] = std::to_string(screenHeight);
        ini.sections["Engine"]["RefreshRate"] = std::to_string(refreshRate);

        std::ofstream file("settings.ini");
        if (file) {
            ini.generate(file);
            file.close();
        }
        else {
            throw std::runtime_error("Error saving settings to settings.ini");
        }
    }

    bool GameSettings::isInitialized() const {
        return initialized;
    }

    void GameSettings::setInitialized(bool value) {
        initialized = value;
        saveSettings();
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

    void GameSettings::initializeFirstLoad(bool init, int width, int height, int refresh) {
        initialized = init;
        screenWidth = width;
        screenHeight = height;
        refreshRate = refresh;
        saveSettings();
    }
}