#pragma once

namespace BlockDestroyer {
	class GameSettings
	{
	public:
		GameSettings();

		// Getters for private members
		bool isInitialized() const;
		int getScreenWidth() const;
		int getScreenHeight() const;
		int getRefreshRate() const;

		// Setters for private members
		void setInitialized(bool value);
		void setScreenWidth(int value);
		void setScreenHeight(int value);
		void setRefreshRate(int value);

		void initializeFirstLoad(bool initialized, int width, int height, int refresh);

		void saveSettings();
	private:
		bool initialized;
		int screenWidth;
		int screenHeight;
		int refreshRate;
	};
}


