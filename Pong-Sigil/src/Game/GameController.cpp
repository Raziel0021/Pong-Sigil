#include "GameController.h"

//#include <raylib.h>
#include <sl.h>

#include "Screens/Menu.h"
#include "GamePlay.h"
#include "Screens/GameOver.h"
#include "Screens/Credits.h"

using namespace game;
using namespace Menu;
using namespace Credits;
using namespace GamePlay;
namespace game {
	bool exit = false;
	namespace gameController
	{
		void Run()
		{
			InitializeApp();
			GamePlay::InitGame();
			// Main game loop
			while (!slShouldClose() &&!exit)    // Detect window close button
			{
				// Update
				if (menu == false && gameover == false && credits == false)
				{
					GamePlay::play();
				}
				Draw();
			}
			UnloadGame();
		}

		void Draw()
		{
			// Dibujar
			//----------------------------------------------------------------------------------
			//BeginDrawing();

			//ClearBackground(RAYWHITE); 
			// background glow
			slSetForeColor(1, 1, 1, 1);

			if (menu)
			{
				Menu::showMenu();
			}
			else
			{
				if (credits)
				{
					Credits::showCredits();
				}
				else
				{
					if (gameover)
					{
						EndOfGame::showGameOver(player1.points, player2.points);
					}
					else
					{
						GamePlay::drawGame();
					}
				}
			}
			//EndDrawing();
			//----------------------------------------------------------------------------------
		}

		void InitializeApp() 
		{
			// Initialization
			//InitWindow(screenWidth, screenHeight, "Tributo a PONG");
			slWindow(screenWidth, screenHeight, "Pong-Sigil", false);
			slSetFont(slLoadFont("res/ttf/whitrabt.ttf"), 24);
			slSetTextAlign(SL_ALIGN_CENTER);
			//SetExitKey(0);
		//#define AUDIO

		#ifdef AUDIO	
			InitAudioDevice();
			ping = LoadSound("res/ping.ogg");
			pong = LoadSound("res/pong.wav");
			music = LoadMusicStream("res/michorvath.ogg");
			PlayMusicStream(music);
		#endif // AUDIO
		}
		void UnloadGame()
		{
			// De-Initialization
			#ifdef AUDIO
				UnloadSound(ping);
				UnloadSound(pong);
				UnloadMusicStream(music);
				CloseAudioDevice();
			#endif // AUDIO
			//--------------------------------------------------------------------------------------
			exit = true;
			slClose();
			//CloseWindow();        // Close window and OpenGL context
			//--------------------------------------------------------------------------------------
		}
	}
}