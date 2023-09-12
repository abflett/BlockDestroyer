#pragma once

namespace BlockDestroyer {
	class GameSettings
	{
	public:
		GameSettings();

		// Getters for private members
		int getScreenWidth() const;
		int getScreenHeight() const;
		int getRefreshRate() const;
		int getgameWidth() const;
		int getgameHeight() const;
		int getplayfieldWidth() const;
		int getplayfieldHeight() const;

		// Setters for private members
		void setScreenWidth(int value);
		void setScreenHeight(int value);
		void setRefreshRate(int value);

		void initializeFirstLoad(int width, int height, int refresh);

		void saveSettings();
	private:
		int screenWidth;
		int screenHeight;
		int refreshRate;

		int gameWidth;
		int gameHeight;
		int playfieldWidth;
		int playfieldHeight;
	};
}


