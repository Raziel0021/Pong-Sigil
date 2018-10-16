#include "Credits.h"

//#include <raylib.h>
#include <sl.h>

#include "Game/GamePlay.h"
#include "Menu.h"

using namespace game;
namespace game {
	namespace Credits
	{
		static const int FONT_SIZE_TITLE = 50;
		static const int FONT_SIZE = 35;
		static const int FONT_SIZE_URL = 16;
		static const float FONT_SIZE_HELPER = FONT_SIZE/2;
		static const int GAMETITLE_LINE_DIVIDER = 10;
		static const int CREDITS_LINE_DIVIDER = 5;
		static const float HELPER_LINE_DIVIDER = 1.2;
		static const float VERSION_LINE_DIVIDER = 1.1;
		static const int LINE_DIVIDER = 4;
		static const int DIVIDER_MEASURE_TEXT = 2;
		bool credits;
		void showCredits()
		{
			/*slSetFont(slLoadFont("res/ttf/whitrabt.ttf"), FONT_SIZE_TITLE);
			slSetTextAlign(SL_ALIGN_CENTER);*/
			slSetFontSize(FONT_SIZE_TITLE);

			slText((-slGetTextWidth("PONG") / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / GAMETITLE_LINE_DIVIDER, "PONG");
			//DrawText(FormatText("PONG "), GamePlay::CALC_HALFSCREEN_WIDTH - (MeasureText("PONG", FONT_SIZE_TITLE) / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / GAMETITLE_LINE_DIVIDER, FONT_SIZE_TITLE, DARKPURPLE);
			slText((-slGetTextWidth("Credits") / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / GAMETITLE_LINE_DIVIDER, "Credits");
			//DrawText(FormatText("Credits"), GamePlay::CALC_HALFSCREEN_WIDTH - (MeasureText("Credits", FONT_SIZE) / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / CREDITS_LINE_DIVIDER, FONT_SIZE, DARKGRAY);
			slSetFontSize(FONT_SIZE);
			slText((-slGetTextWidth("Héctor Iván Pereira") / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / LINE_DIVIDER, "Héctor Iván Pereira");
			//DrawText(FormatText("Héctor Iván Pereira"), GamePlay::CALC_HALFSCREEN_WIDTH - (MeasureText("Hector Ivan Pereira", FONT_SIZE) / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / LINE_DIVIDER, FONT_SIZE, DARKGRAY);
			slText((-slGetTextWidth("Assets Library") / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / LINE_DIVIDER+FONT_SIZE, "Assets Library");
			//DrawText(FormatText("Assets Library"), GamePlay::CALC_HALFSCREEN_WIDTH - (MeasureText("Assets Library", FONT_SIZE) / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / LINE_DIVIDER + FONT_SIZE, FONT_SIZE, DARKGRAY);
			slText((-slGetTextWidth("Raylib, Freesounds.org") / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / LINE_DIVIDER + FONT_SIZE*2, "Raylib, Freesounds.org");
			//DrawText(FormatText("Raylib, Freesounds.org"), GamePlay::CALC_HALFSCREEN_WIDTH - (MeasureText("Raylib, Freesounds.org", FONT_SIZE) / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / LINE_DIVIDER + FONT_SIZE*2, FONT_SIZE, DARKGRAY);
			slText((-slGetTextWidth("Music") / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / LINE_DIVIDER + FONT_SIZE * 3, "Music");
			//DrawText(FormatText("Music"), GamePlay::CALC_HALFSCREEN_WIDTH - (MeasureText("Music", FONT_SIZE) / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / LINE_DIVIDER + FONT_SIZE*3, FONT_SIZE, DARKGRAY);
			slText((-slGetTextWidth("michorvath") / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / LINE_DIVIDER + FONT_SIZE * 4, "michorvath");
			//DrawText(FormatText("michorvath"), GamePlay::CALC_HALFSCREEN_WIDTH - (MeasureText("michorvath", FONT_SIZE) / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / LINE_DIVIDER + FONT_SIZE*4, FONT_SIZE, DARKGRAY);
			slSetFontSize(FONT_SIZE_URL);
			slText((-slGetTextWidth("https://freesound.org/people/michorvath/") / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / LINE_DIVIDER + FONT_SIZE * 5, "https://freesound.org/people/michorvath/");
			//DrawText(FormatText("https://freesound.org/people/michorvath/"), GamePlay::CALC_HALFSCREEN_WIDTH - (MeasureText("https://freesound.org/people/michorvath/", FONT_SIZE_URL) / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / LINE_DIVIDER + FONT_SIZE * 5, FONT_SIZE_URL, DARKGRAY);
			slSetFontSize(FONT_SIZE);
			slText((-slGetTextWidth("Sounds") / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / LINE_DIVIDER + FONT_SIZE * 6, "Sounds");
			//DrawText(FormatText("Sounds"), GamePlay::CALC_HALFSCREEN_WIDTH - (MeasureText("Sounds", FONT_SIZE) / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / LINE_DIVIDER + FONT_SIZE * 6, FONT_SIZE, DARKGRAY);
			slText((-slGetTextWidth("thirteenthfail - NoiseCollector") / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / LINE_DIVIDER + FONT_SIZE * 7, "thirteenthfail - NoiseCollector");
			//DrawText(FormatText("thirteenthfail - NoiseCollector"), GamePlay::CALC_HALFSCREEN_WIDTH - (MeasureText("thirteenthfail - NoiseCollector", FONT_SIZE) / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / LINE_DIVIDER + FONT_SIZE * 7, FONT_SIZE, DARKGRAY);
			slSetFontSize(FONT_SIZE_URL);
			slText((-slGetTextWidth("https://freesound.org/people/NoiseCollector/") / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / LINE_DIVIDER + FONT_SIZE * 8, "https://freesound.org/people/NoiseCollector/");
			//DrawText(FormatText("https://freesound.org/people/NoiseCollector/"), GamePlay::CALC_HALFSCREEN_WIDTH - (MeasureText("https://freesound.org/people/NoiseCollector/", FONT_SIZE_URL) / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / LINE_DIVIDER + FONT_SIZE * 8, FONT_SIZE_URL, DARKGRAY);
			slText((-slGetTextWidth("https://freesound.org/people/thirteenthfail/") / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / LINE_DIVIDER + (FONT_SIZE * 8) + FONT_SIZE_URL, "https://freesound.org/people/thirteenthfail/");
			//DrawText(FormatText("https://freesound.org/people/thirteenthfail/"), GamePlay::CALC_HALFSCREEN_WIDTH - (MeasureText("https://freesound.org/people/thirteenthfail/", FONT_SIZE_URL) / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / LINE_DIVIDER + (FONT_SIZE * 8)+FONT_SIZE_URL, FONT_SIZE_URL, DARKGRAY);
			slSetFontSize(FONT_SIZE_HELPER);
			slText((-slGetTextWidth("Press Esc to back to Menu") / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / HELPER_LINE_DIVIDER + FONT_SIZE, "Press Esc to back to Menu");
			//DrawText(FormatText("Press Esc to back to Menu"), GamePlay::CALC_HALFSCREEN_WIDTH - (MeasureText("Press Esc to back to Menu", FONT_SIZE_HELPER) / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / HELPER_LINE_DIVIDER + FONT_SIZE, FONT_SIZE_HELPER, DARKGRAY);
			slText((-slGetTextWidth("Version 0.1") / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / VERSION_LINE_DIVIDER + FONT_SIZE, "Version 0.1");
			//DrawText(FormatText("Version 1.0"), GamePlay::CALC_HALFSCREEN_WIDTH - (MeasureText("Version 1.0", FONT_SIZE_HELPER) / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / VERSION_LINE_DIVIDER + FONT_SIZE, FONT_SIZE_HELPER, DARKGRAY);
			updateCredits();
		}
		void updateCredits()
		{
			if (slGetKey(SL_KEY_ESCAPE))
			{
				Menu::menu = true;
				credits = false;
			}
		}
	}
}