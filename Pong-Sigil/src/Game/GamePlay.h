#ifndef GAMEPLAY_H
#define GAMEPLAY_H


//#include <raylib.h>

namespace game {
	namespace GamePlay
	{
		struct Player
		{
			double position_x;
			double position_y;
			//Vector2 position;
			double size_x;
			double size_y;
			//Vector2 size;
			int points;
		};

		struct Ball
		{
			double position_x;
			double position_y;
			//Vector2 position;
			double speed_x;
			double speed_y;
			//Vector2 speed;
			int radius;
			bool active;
		};

		extern Ball ball;
		extern Player player1, player2;

		//extern Sound ping, pong;
		//extern Music music;
		
		extern const int screenWidth;
		extern const int screenHeight;
		extern bool gameover;
		extern bool machineON;

		extern const int INIT_PLAYERS_POINTS;

		extern const int CALC_HALFSCREEN_HEIGHT;
		extern const int CALC_HALFSCREEN_WIDTH;

		void InitGame();
		void play();
		
		void drawGame();
	}
}
#endif // !GAMEPLAY_H