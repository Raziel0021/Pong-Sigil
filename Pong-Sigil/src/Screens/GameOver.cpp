#include "GameOver.h"

//#include <raylib.h>
#include <sl.h>

#include "Game\GamePlay.h"
#include "Menu.h"
#include "Game/GameController.h"

using namespace game;
namespace game {
	namespace EndOfGame
	{
		static const int FONT_SIZE_TITLE=60;
		static const int FONT_SIZE_OPTIONS = 30;
		static const int DIVIDER_MEASURE_TEXT = 2;
		static const float TITLE_LINE_DIVIDER = 4.5;
		static const int WINNER_LINE_DIVIDER = 3;
		static const float OPTIONS_LINE_DIVIDER = 2.5f;

		void showGameOver(int jug1, int jug2)
		{
			/*slSetFont(slLoadFont("res/ttf/whitrabt.ttf"), FONT_SIZE_TITLE);
			slSetTextAlign(SL_ALIGN_CENTER);*/
			slSetFontSize(FONT_SIZE_TITLE);

			slText((-slGetTextWidth("Game Over") / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / TITLE_LINE_DIVIDER, "GameOver");
			//DrawText(FormatText("Game Over"), GamePlay::CALC_HALFSCREEN_WIDTH - (MeasureText("Game Over", FONT_SIZE_TITLE) / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / TITLE_LINE_DIVIDER, FONT_SIZE_TITLE, DARKPURPLE);
			if (jug1 > jug2)
			{
				slText((-slGetTextWidth("Ganador Jugador 1") / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / WINNER_LINE_DIVIDER, "Ganador Jugador 1");
				//DrawText(FormatText("Ganador Jugador 1"), GamePlay::CALC_HALFSCREEN_WIDTH - (MeasureText("Ganador Jugador 1", FONT_SIZE_TITLE) / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / WINNER_LINE_DIVIDER, FONT_SIZE_TITLE, DARKPURPLE);
			}
			else
			{
				slText((-slGetTextWidth("Ganador Jugador 2") / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / WINNER_LINE_DIVIDER, "Ganador Jugador 2");
				//DrawText(FormatText("Ganador Jugador 2"), GamePlay::CALC_HALFSCREEN_WIDTH - (MeasureText("Ganador Jugador 2", FONT_SIZE_TITLE) / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / WINNER_LINE_DIVIDER, FONT_SIZE_TITLE, DARKPURPLE);
			}
			slSetFontSize(FONT_SIZE_OPTIONS);
			slText((-slGetTextWidth("1.Menu") / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / OPTIONS_LINE_DIVIDER+FONT_SIZE_TITLE, "1.Menu");
			//DrawText(FormatText("1.Menu"), GamePlay::CALC_HALFSCREEN_WIDTH - (MeasureText("1.Menu", FONT_SIZE_OPTIONS) / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / OPTIONS_LINE_DIVIDER + FONT_SIZE_TITLE, FONT_SIZE_OPTIONS, DARKGRAY);
			slText((-slGetTextWidth("2.Exit") / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / OPTIONS_LINE_DIVIDER + (FONT_SIZE_TITLE+FONT_SIZE_OPTIONS), "2.Exit");
			//DrawText(FormatText("2.Salir"), GamePlay::CALC_HALFSCREEN_WIDTH - (MeasureText("2.Salir", FONT_SIZE_OPTIONS) / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / OPTIONS_LINE_DIVIDER + (FONT_SIZE_TITLE + FONT_SIZE_OPTIONS), FONT_SIZE_OPTIONS, DARKGRAY);

			updateGameOver();
		}
		void updateGameOver()
		{
			if (slGetKey(SL_KEY_KEYPAD_2))
				gameController::UnloadGame();
				//CloseWindow();
			if (slGetKey(SL_KEY_KEYPAD_1))
			{
				Menu::menu = true;
				if (GamePlay::machineON) 
				{
					GamePlay::machineON = false;
				}
				GamePlay::gameover = false;
				GamePlay::player1.points = GamePlay::INIT_PLAYERS_POINTS;
				GamePlay::player2.points = GamePlay::INIT_PLAYERS_POINTS;
			}
		}
	}
}