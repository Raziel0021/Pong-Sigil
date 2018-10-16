#include "GamePlay.h"

//#include <raylib.h>
#include <stdlib.h>
#include <time.h>
#include <sl.h>

#include "Screens\GameOver.h"
#include "Screens\Menu.h"

using namespace game;
namespace game {
	namespace GamePlay
	{
		Player player1;
		Player player2;
		Ball ball;

		const int screenWidth = 800;
		const int screenHeight = 600;
		bool gameover = false;
		bool machineON = false;

		//Sound ping, pong;
		//Music music;

		const int CALC_HALFSCREEN_HEIGHT = screenHeight / 2;
		const int CALC_HALFSCREEN_WIDTH = screenWidth / 2;
		static int FONT_SIZE_HELPER = 25;
		static const float HELPER_LINE_DIVIDER = 1.7;
		static const float MUSIC_HELPER_LINE_DIVIDER = 1.1;
		static const int DIVIDER_MEASURE_TEXT = 2;
		static bool mute;

		static const int INIT_PLAYERS_POSITION_X = 20;
		static const double PLAYER_SIZE_X = 10;
		static const double PLAYER_SIZE_Y = 80;
		//static const Vector2 PLAYERS_SIZE = { 10,80 };
		const int INIT_PLAYERS_POINTS = 0;
		static const int PLAYER_LIM_POINTS = 10;
		static const double INIT_BALLSPEED_X = 0;
		static const double INIT_BALLSPEED_Y = 0;
		//static const Vector2 INIT_BALLSPEED = { 0,0 };
		static const double LAUNCH_BALL_SPEED_X = 0;
		static const double LAUNCH_BALL_SPEED_Y = 0;
		//static const Vector2 LAUNCH_BALL_SPEED = {5,3};
		static const int BALL_RADIUS = 20;
		static const float BALL_COLLISION_SPEED_X = -1.018;
		static const float BALL_SPEED_MULTIPLIER = 75;
		static const float BALL_COLLISION_SPEED_MULTIPLIER_Y=4;

		static const float WALLS_SPEED_MULTIPLIER = -1;
		static const float PLAYER_MOVE_SPEED = 450;
		static const int CALC_PLAYER_TOP_LIM = 10;
		static const int CALC_PLAYER_BOT_LIM = 5;

		static const int FONT_SIZE_POINTS = 60;
		static const int POINTS_POS_Y = 10;
		static const int POINTS_POS_X_PLAYER1 = GamePlay::CALC_HALFSCREEN_WIDTH - 80;
		static const int POINTS_POS_X_PLAYER2 = GamePlay::CALC_HALFSCREEN_WIDTH + 20;

		static double midline_x = (float)GamePlay::CALC_HALFSCREEN_WIDTH;
		static double midline_y = 20;
		//static Vector2 midLine = { (float)GamePlay::CALC_HALFSCREEN_WIDTH, 20 };
		static const double MIDLINE_SIZE_X = 5;
		static const double MIDLINE_SIZE_Y = GamePlay::screenHeight - 40;
		//static const Vector2 MIDLINE_SIZE = {5,GamePlay::screenHeight - 40 };
		void InitGame()
		{
			srand(time(NULL));
			Menu::menu = true;
			mute = false;
			// Initialize player1
			player1.position_x = INIT_PLAYERS_POSITION_X;
			player1.position_y = CALC_HALFSCREEN_HEIGHT;
			player1.size_x = PLAYER_SIZE_X;
			player1.size_y = PLAYER_SIZE_Y;
			player1.points = INIT_PLAYERS_POINTS;

			// Initialize player2
			player2.position_x = (float)screenWidth - INIT_PLAYERS_POSITION_X;
			player2.position_x = CALC_HALFSCREEN_HEIGHT;
			player2.size_x = PLAYER_SIZE_X;
			player2.size_y = PLAYER_SIZE_Y;
			player2.points = INIT_PLAYERS_POINTS;

			// Initialize ball
			ball.position_x = CALC_HALFSCREEN_WIDTH;
			ball.position_y = CALC_HALFSCREEN_HEIGHT;
			ball.speed_x = INIT_BALLSPEED_X;
			ball.speed_y = INIT_BALLSPEED_Y;
			ball.radius = BALL_RADIUS;
			ball.active = false;
		}
		void play()
		{
			//-------------------------------------- Music and Sound ------------------------------------------
			if (slGetKey('M')) 
			{
				mute = !mute;
			}
			//#define AUDIO
			#ifdef AUDIO	
				UpdateMusicStream(music);
				if (mute) 
				{
					PauseMusicStream(music);
				}
			#endif // AUDIO

			//--------------------------------------- Player 1 move -------------------------------------------
			if (slGetKey('W')) player1.position_y -= PLAYER_MOVE_SPEED * slGetDeltaTime();
			if ((player1.position_y - player1.size_y / CALC_PLAYER_TOP_LIM) <= 0) player1.position_y = player1.size_y / CALC_PLAYER_TOP_LIM;
			if (slGetKey('S')) player1.position_y += PLAYER_MOVE_SPEED * slGetDeltaTime();
			if ((player1.position_y + player1.size_y + CALC_PLAYER_BOT_LIM) >= screenHeight) player1.position_y = screenHeight - player1.size_y - CALC_PLAYER_BOT_LIM;
			//-------------------------------------------------------------------------------------------------

			if (machineON)
			{
				//--------------------------------------IA-Player---------------------------------------------
					if ((player2.position_y + player2.size_y / 2) > ball.position_y) player2.position_y -= PLAYER_MOVE_SPEED * slGetDeltaTime();
					if ((player2.position_y - player2.size_y / CALC_PLAYER_TOP_LIM) <= 0) player2.position_y = player2.size_y / CALC_PLAYER_TOP_LIM;
					if ((player2.position_y + player2.size_y / 2) < ball.position_y) player2.position_y += PLAYER_MOVE_SPEED * slGetDeltaTime();
					if ((player2.position_y + player2.size_y + CALC_PLAYER_BOT_LIM) >= screenHeight) player2.position_y = screenHeight - player2.size_y - CALC_PLAYER_BOT_LIM;
			}
			else
			{
				//--------------------------------------- Player 2 move -------------------------------------------
				if (slGetKey(SL_KEY_UP)) player2.position_y -= PLAYER_MOVE_SPEED * slGetDeltaTime();
				if ((player2.position_y - player2.size_y / CALC_PLAYER_TOP_LIM) <= 0) player2.position_y = player2.size_y / CALC_PLAYER_TOP_LIM;
				if (slGetKey(SL_KEY_DOWN)) player2.position_y += PLAYER_MOVE_SPEED * slGetDeltaTime();
				if ((player2.position_y + player2.size_y + CALC_PLAYER_BOT_LIM) >= screenHeight) player2.position_y = screenHeight - player2.size_y - CALC_PLAYER_BOT_LIM;
				//-------------------------------------------------------------------------------------------------
			}

			// Ball launching logic
			if (!ball.active)
			{
				if (slGetKey(' '))
				{
					ball.active = true;
					ball.speed_x = (-1+rand() % 2) * LAUNCH_BALL_SPEED_X;
					ball.speed_y = (-5+rand() % 6) * LAUNCH_BALL_SPEED_Y;
					while (ball.speed_x == 0)
					{
						ball.speed_x = (-1 + rand() % 2) * LAUNCH_BALL_SPEED_X;
					}
				}
			}
			// Ball movement logic
			if (ball.active)
			{
				ball.position_x += ball.speed_x*BALL_SPEED_MULTIPLIER * slGetDeltaTime();
				ball.position_y += ball.speed_y*BALL_SPEED_MULTIPLIER * slGetDeltaTime();
			}
			else
			{
				ball.position_x = CALC_HALFSCREEN_WIDTH;
				ball.position_y = CALC_HALFSCREEN_HEIGHT;
			}
			// Collision logic: ball vs walls 
			if (((ball.position_y + ball.radius) >= screenHeight) || ((ball.position_y - ball.radius) <= 0))
			{
				if ((ball.position_y + ball.radius) >= screenHeight)
				{
					ball.position_y = screenHeight - ball.radius;
				}
				else if ((ball.position_y - ball.radius) <= 0)
				{
					ball.position_y = ball.radius;
				}
				ball.speed_y *= WALLS_SPEED_MULTIPLIER;
			}
			if ((ball.position_y - ball.radius) <= 0)
			{
				ball.speed_x = INIT_BALLSPEED_X;
				ball.speed_y = INIT_BALLSPEED_Y;
				ball.active = false;

				player2.points++;
				if (player2.points >= PLAYER_LIM_POINTS)
				{
					gameover = true;
				}
				player1.position_y = CALC_HALFSCREEN_HEIGHT;
				player2.position_y = CALC_HALFSCREEN_HEIGHT;
			}
			if ((ball.position_x + ball.radius) >= screenWidth)
			{
				ball.speed_x = INIT_BALLSPEED_X;
				ball.speed_y = INIT_BALLSPEED_Y;
				ball.active = false;

				player1.points++;

				if (player1.points >= PLAYER_LIM_POINTS)
				{
					gameover = true;
				}

				player1.position_y = CALC_HALFSCREEN_HEIGHT;
				player2.position_y = CALC_HALFSCREEN_HEIGHT;
			}
			// Collision logic: ball vs player1
//			if (CheckCollisionCircleRec(ball.position, ball.radius, { player1.position.x - player1.size.x / 2, player1.position.y , player1.size.x, player1.size.y }))
//			{
//				if (ball.speed.x != 0)
//				{
//					ball.position.x = player1.position.x + player1.size.x + ball.radius;
//					ball.speed.x *= BALL_COLLISION_SPEED_X;
//					if (ball.speed.y >= 0)
//					{
//						ball.speed.y = (ball.position.y - player1.position.y) / (player1.size.y / 2) * BALL_COLLISION_SPEED_MULTIPLIER_Y;
//					}
//					else
//					{
//						ball.speed.y = (ball.position.y - player1.position.y) / (player1.size.y / 2) * -BALL_COLLISION_SPEED_MULTIPLIER_Y;
//					}
//				}
//#ifdef AUDIO	
//				if (!mute)
//				{
//					if (GetRandomValue(0, 1) != 0)
//						PlaySound(ping);
//					else
//						PlaySound(pong);
//				}
//#endif // AUDIO
//			}
			// Collision logic: ball vs player2
			//if (CheckCollisionCircleRec(ball.position, ball.radius, { player2.position.x + player2.size.x / 2, player2.position.y , player2.size.x, player2.size.y }))
			//{
			//	if (ball.speed.x != 0)
			//	{
			//		ball.position.x = player2.position.x - player1.size.x / 2 - ball.radius / 2;
			//		ball.speed.x *= BALL_COLLISION_SPEED_X;
			//		if (ball.speed.y >= 0)
			//		{
			//			ball.speed.y = (ball.position.y - player2.position.y) / (player2.size.y / 2) * BALL_COLLISION_SPEED_MULTIPLIER_Y;
			//		}
			//		else
			//		{
			//			ball.speed.y = (ball.position.y - player2.position.y) / (player2.size.y / 2) * -BALL_COLLISION_SPEED_MULTIPLIER_Y;
			//		}
			//	}
			//#ifdef AUDIO	
			//	if (!mute) 
			//	{
			//		if (GetRandomValue(0, 1) != 0)
			//			PlaySound(ping);
			//		else
			//			PlaySound(pong);
			//	}
			//#endif // AUDIO
			//}
		}
		void drawGame()
		{
			slSetFont(slLoadFont("res/ttf/whitrabt.ttf"), FONT_SIZE_POINTS);
			slSetTextAlign(SL_ALIGN_CENTER);
			slSetFontSize(FONT_SIZE_POINTS);
			//slText(POINTS_POS_X_PLAYER1, POINTS_POS_Y,GamePlay::player1.points);
			//DrawText(FormatText("%02i", GamePlay::player1.points),POINTS_POS_X_PLAYER1, POINTS_POS_Y, FONT_SIZE_POINTS, DARKGRAY);

			//DrawText(FormatText("%02i", GamePlay::player2.points), POINTS_POS_X_PLAYER2, POINTS_POS_Y, FONT_SIZE_POINTS, DARKGRAY);

			slRectangleFill(midline_x,midline_y, MIDLINE_SIZE_X,MIDLINE_SIZE_Y);
			//DrawRectangle(midLine.x, midLine.y, MIDLINE_SIZE.x, MIDLINE_SIZE.y, DARKGRAY);

			if (!ball.active)
			{
				slSetFontSize(FONT_SIZE_HELPER);
				slText(-(slGetTextWidth("Press Space to Start") / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / HELPER_LINE_DIVIDER, "Press Space to Start");
				//DrawText(FormatText("Press Space to Start"), GamePlay::CALC_HALFSCREEN_WIDTH - (MeasureText("Press Space to Start", FONT_SIZE_HELPER) / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / HELPER_LINE_DIVIDER, FONT_SIZE_HELPER, GRAY);
			}
			slSetFontSize(FONT_SIZE_HELPER);
			slText(-(slGetTextWidth("Press M ON/OFF Mute") / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / MUSIC_HELPER_LINE_DIVIDER, "Press M ON/OFF Mute");
			//DrawText(FormatText("Press M ON/OFF Mute"), GamePlay::CALC_HALFSCREEN_WIDTH - (MeasureText("Press M ON/OFF Mute", FONT_SIZE_HELPER) / DIVIDER_MEASURE_TEXT), GamePlay::screenHeight / MUSIC_HELPER_LINE_DIVIDER, FONT_SIZE_HELPER, GRAY);
			slCircleFill(GamePlay::ball.position_x, GamePlay::ball.position_y, GamePlay::ball.radius,0);
			//DrawCircleV(GamePlay::ball.position, GamePlay::ball.radius, DARKPURPLE);
			slRectangleFill(GamePlay::player1.position_x, GamePlay::player1.position_y, GamePlay::player1.size_x, GamePlay::player1.size_y);
			//DrawRectangle(GamePlay::player1.position.x, GamePlay::player1.position.y, GamePlay::player1.size.x, GamePlay::player1.size.y, DARKPURPLE);
			slRectangleFill(GamePlay::player2.position_x, GamePlay::player2.position_y, GamePlay::player2.size_x, GamePlay::player2.size_y);
			//DrawRectangle(GamePlay::player2.position.x, GamePlay::player2.position.y, GamePlay::player2.size.x, GamePlay::player2.size.y, DARKPURPLE);
		}
	}
}