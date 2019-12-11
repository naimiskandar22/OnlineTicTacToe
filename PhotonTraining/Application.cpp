#include "Application.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "MyPhoton.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXBITCOUNT sizeof(unsigned int) * 8

using namespace std;


Application::Application()
{
	//m_sprite01 = new Sprite(sprtexturepath);

	MyPhoton::getInstance().connect();

}

Application::~Application()
{
}

void Application::start()
{
	srand(time(0));

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			gameManager.gameboard[j][i] = 0;
		}
	}

	turnDuration = 0;

	gameManager.currState = GAMEOVER;
	m_sprite01 = new Sprite("../media/SquareBox.bmp");

	gridbackground.makeSprite("../media/SquareBox.bmp");
	gridbackground.setPos(gridOffset.x + 128.0f * 1.0f, gridOffset.y + 128.0f * 1.0f);
	gridbackground.setScale(3.25f, 3.25f);
	gridbackground.setColor(0.502f, 0.0f, 0.0f, 1.0f);
	gridbackground.setBlendMode(ALPHA);


	gridbox1.makeSprite("../media/SquareBox.bmp");
	gridbox1.setPos(gridOffset.x + 128.0f * 0.0f, gridOffset.y + 128.0f * 0.0f);
	gridbox1.setScale(1.0f, 1.0f);
	gridbox1.setColor(1.0f, 0.6275f, 0.4784f, 1.0f);
	gridbox1.setBlendMode(ALPHA);

	gridbox2.makeSprite("../media/SquareBox.bmp");
	gridbox2.setPos(gridOffset.x + 128.0f * 1.0f, gridOffset.y + 128.0f * 0.0f);
	gridbox2.setScale(1.0f, 1.0f);
	gridbox2.setColor(1.0f, 0.6471f, 0.0f, 1.0f);
	gridbox2.setBlendMode(ALPHA);
	
	gridbox3.makeSprite("../media/SquareBox.bmp");
	gridbox3.setPos(gridOffset.x + 128.0f * 2.0f, gridOffset.y + 128.0f * 0.0f);
	gridbox3.setScale(1.0f, 1.0f);
	gridbox3.setColor(1.0f, 0.6275f, 0.4784f, 1.0f);
	gridbox3.setBlendMode(ALPHA);

	gridbox4.makeSprite("../media/SquareBox.bmp");
	gridbox4.setPos(gridOffset.x + 128.0f * 0.0f, gridOffset.y + 128.0f * 1.0f);
	gridbox4.setScale(1.0f, 1.0f);
	gridbox4.setColor(1.0f, 0.6471f, 0.0f, 1.0f);
	gridbox4.setBlendMode(ALPHA);

	gridbox5.makeSprite("../media/SquareBox.bmp");
	gridbox5.setPos(gridOffset.x + 128.0f * 1.0f, gridOffset.y + 128.0f * 1.0f);
	gridbox5.setScale(1.0f, 1.0f);
	gridbox5.setColor(1.0f, 0.6275f, 0.4784f, 1.0f);
	gridbox5.setBlendMode(ALPHA);

	gridbox6.makeSprite("../media/SquareBox.bmp");
	gridbox6.setPos(gridOffset.x + 128.0f * 2.0f, gridOffset.y + 128.0f * 1.0f);
	gridbox6.setScale(1.0f, 1.0f);
	gridbox6.setColor(1.0f, 0.6471f, 0.0f, 1.0f);
	gridbox6.setBlendMode(ALPHA);

	gridbox7.makeSprite("../media/SquareBox.bmp");
	gridbox7.setPos(gridOffset.x + 128.0f * 0.0f, gridOffset.y + 128.0f * 2.0f);
	gridbox7.setScale(1.0f, 1.0f);
	gridbox7.setColor(1.0f, 0.6275f, 0.4784f, 1.0f);
	gridbox7.setBlendMode(ALPHA);

	gridbox8.makeSprite("../media/SquareBox.bmp");
	gridbox8.setPos(gridOffset.x + 128.0f * 1.0f, gridOffset.y + 128.0f * 2.0f);
	gridbox8.setScale(1.0f, 1.0f);
	gridbox8.setColor(1.0f, 0.6471f, 0.0f, 1.0f);
	gridbox8.setBlendMode(ALPHA);

	gridbox9.makeSprite("../media/SquareBox.bmp");
	gridbox9.setPos(gridOffset.x + 128.0f * 2.0f, gridOffset.y + 128.0f * 2.0f);
	gridbox9.setScale(1.0f, 1.0f);
	gridbox9.setColor(1.0f, 0.6275f, 0.4784f, 1.0f);
	gridbox9.setBlendMode(ALPHA);

	gameStatus.makeSprite("../media/WaitPlayer.bmp");
	gameStatus.setPos(gridOffset.x - 128.0f * 1.5f, gridOffset.y + 128.0f * 2.0f);
	gameStatus.setScale(1.0f, 1.0f);
	gameStatus.setColor(1.0f, 1.0f, 1.0f, 1.0f);
	gameStatus.setBlendMode(ALPHA);

	playerBoxBG.makeSprite("../media/SquareBox.bmp");
	playerBoxBG.setPos(gridOffset.x - 128.0f * 1.5f, gridOffset.y + 128.0f * 1.0f);
	playerBoxBG.setScale(0.75f, 0.75f);
	playerBoxBG.setColor(1.0f, 1.0f, 1.0f, 0.0f);
	playerBoxBG.setBlendMode(ALPHA);

	playerBoxIcon.makeSprite("../media/SquareBox.bmp");
	playerBoxIcon.setPos(gridOffset.x - 128.0f * 1.5f, gridOffset.y + 128.0f * 1.0f);
	playerBoxIcon.setScale(0.875f, 0.875f);
	playerBoxIcon.setColor(1.0f, 1.0f, 1.0f, 0.0f);
	playerBoxIcon.setBlendMode(ALPHA);

	restartNotice.makeSprite("../media/Restart.bmp");
	restartNotice.setPos(gridOffset.x - 128.0f * 2.0f, gridOffset.y + 128.0f * 0.0f);
	restartNotice.setScale(0.75f, 0.75f);
	restartNotice.setColor(1.0f, 1.0f, 1.0f, 0.0f);
	restartNotice.setBlendMode(ALPHA);
	
}


void Application::update(double elapsedTime)
{
	MyPhoton::getInstance().run();

	gridbackground.draw();

	gridbox1.draw();
	gridbox2.draw();
	gridbox3.draw();
	gridbox4.draw();
	gridbox5.draw();
	gridbox6.draw();
	gridbox7.draw();
	gridbox8.draw();
	gridbox9.draw();

	for (int i = 0; i < 9; i++)
	{
		if (gameManager.gameboard[i % 3][i / 3] != 0)
		{
			gridObjects[i].draw();
		}
	}
	
	gameStatus.draw();
	playerBoxBG.draw();
	playerBoxIcon.draw();
	restartNotice.draw();

}

void Application::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_object1.draw();
	m_object2.draw();
}



void Application::OnReceivedOpponentData(unsigned char data)
{
	game_data = 0;

	game_data = data;

	//Extract current game state
	int check_state = gameManager.currState;
	gameManager.currState = (GameState)ExtractGameData(1);

	if ((int)gameManager.currState == 0)
	{
		playerBoxIcon.setColor(1.0f, 1.0f, 1.0f, 1.0f);
		cout << "CLICK THE BOARD TO RESET" << endl;
	}

	if (check_state == 0 && gameManager.currState == 1)
	{
		RunGame();
		gameManager.currTurn = (GameTurn)ExtractGameData(1);
		return;
	}

	//Extract new turn
	gameManager.currTurn = (GameTurn)ExtractGameData(1);


	playerBoxBG.setColor(0.0f, 1.0f, 0.0f, 1.0f);
	gameStatus.makeSprite("../media/YourTurn.bmp");

	//Extract game board data

	int value = ExtractGameData(2);
	int x = ExtractGameData(2);
	int y = ExtractGameData(2);


	gameManager.gameboard[x][y] = value;

	if (gameManager.gameboard[x][y] == 1)
	{
		gridObjects[x + y * 3].makeSprite("../media/GridCircle.bmp");
	}
	else if (gameManager.gameboard[x][y] == 2)
	{
		gridObjects[x + y * 3].makeSprite("../media/GridCross.bmp");
	}

	turnDuration++;

}



void Application::onKeyPressed(int key)
{

}

void Application::onKeyReleased(int key)
{
}

void Application::onKeyHold(int key)
{

}

void Application::onMousePressed(int button, Vector2 position)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT)
	{
		unsigned char data_retrieve = 0;

		if (gameManager.currTurn == assignedTurn && gameManager.currState == PLAYING)
		{
			if (position.x > (gridOffset.x + 128.0f * 3.0f - 64.0f))
				return;
			if (position.y > (gridOffset.y + 128.0f * 3.0f - 64.0f))
				return;
			if (position.x < (gridOffset.x - 64.0f))
				return;
			if (position.y < (gridOffset.y - 64.0f))
				return;

			int x, y;

			x = (position.x - gridOffset.x + 64.0f) / 128.0f;
			y = (position.y - gridOffset.y + 64.0f) / 128.0f;

			

			if (gameManager.gameboard[x][y] == 0)
			{
				if (gameManager.currTurn == CIRCLE)
				{
					gameManager.gameboard[x][y] = 1;
					gameManager.currTurn = CROSS;

					gridObjects[x + y * 3].makeSprite("../media/GridCircle.bmp");

					data_retrieve = (data_retrieve << 2) | y;
					data_retrieve = (data_retrieve << 2) | x;
					data_retrieve = (data_retrieve << 2) | 1;

				}
				else if (gameManager.currTurn == CROSS)
				{
					gameManager.gameboard[x][y] = 2;
					gameManager.currTurn = CIRCLE;

					gridObjects[x + y * 3].makeSprite("../media/GridCross.bmp");


					data_retrieve = (data_retrieve << 2) | y;
					data_retrieve = (data_retrieve << 2) | x;
					data_retrieve = (data_retrieve << 2) | 2;
				}

				turnDuration++;


				playerBoxBG.setColor(0.5f, 0.5f, 0.5f, 1.0f);

				gameStatus.makeSprite("../media/OpponentTurn.bmp");

				CheckGameCondition(data_retrieve);
			}
		}
		else if (gameManager.currState == GAMEOVER && (assignedTurn == CIRCLE || assignedTurn == CROSS))
		{
			RunGame();

			data_retrieve = (data_retrieve << 2) | 0;
			data_retrieve = (data_retrieve << 2) | 0;
			data_retrieve = (data_retrieve << 2) | 0;

			CheckGameCondition(data_retrieve);
		}
	}
}

void Application::onMouseReleased(int button)
{

}

void Application::onMouseHold(int button)
{

}

void Application::onMouseMoved(double mousePosX, double mousePosY)
{

}

void Application::RunGame()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			gameManager.gameboard[j][i] = 0;
		}
	}
	gameManager.currState = PLAYING;

	turnDuration = 0;

	restartNotice.setColor(1.0f, 1.0f, 1.0f, 0.0f);

	m_object1.makeSprite("../media/GridCross.bmp");
	m_object1.setPos(gridOffset.x + 128.0f * 0.0f, gridOffset.y + 128.0f * 0.0f);
	m_object1.setScale(1.5f, 1.5f);
	m_object1.setColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_object1.setBlendMode(ALPHA);

	gridObjects[0] = m_object1;


	m_object2.makeSprite("../media/GridCross.bmp");
	m_object2.setPos(gridOffset.x + 128.0f * 1.0f, gridOffset.y + 128.0f * 0.0f);
	m_object2.setScale(1.5f, 1.5f);
	m_object2.setColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_object2.setBlendMode(ALPHA);

	gridObjects[1] = m_object2;


	m_object3.makeSprite("../media/GridCross.bmp");
	m_object3.setPos(gridOffset.x + 128.0f * 2.0f, gridOffset.y + 128.0f * 0.0f);
	m_object3.setScale(1.5f, 1.5f);
	m_object3.setColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_object3.setBlendMode(ALPHA);

	gridObjects[2] = m_object3;


	m_object4.makeSprite("../media/GridCross.bmp");
	m_object4.setPos(gridOffset.x + 128.0f * 0.0f, gridOffset.y + 128.0f * 1.0f);
	m_object4.setScale(1.5f, 1.5f);
	m_object4.setColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_object4.setBlendMode(ALPHA);

	gridObjects[3] = m_object4;


	m_object5.makeSprite("../media/GridCross.bmp");
	m_object5.setPos(gridOffset.x + 128.0f * 1.0f, gridOffset.y + 128.0f * 1.0f);
	m_object5.setScale(1.5f, 1.5f);
	m_object5.setColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_object5.setBlendMode(ALPHA);

	gridObjects[4] = m_object5;


	m_object6.makeSprite("../media/GridCross.bmp");
	m_object6.setPos(gridOffset.x + 128.0f * 2.0f, gridOffset.y + 128.0f * 1.0f);
	m_object6.setScale(1.5f, 1.5f);
	m_object6.setColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_object6.setBlendMode(ALPHA);

	gridObjects[5] = m_object6;


	m_object7.makeSprite("../media/GridCross.bmp");
	m_object7.setPos(gridOffset.x + 128.0f * 0.0f, gridOffset.y + 128.0f * 2.0f);
	m_object7.setScale(1.5f, 1.5f);
	m_object7.setColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_object7.setBlendMode(ALPHA);

	gridObjects[6] = m_object7;


	m_object8.makeSprite("../media/GridCross.bmp");
	m_object8.setPos(gridOffset.x + 128.0f * 1.0f, gridOffset.y + 128.0f * 2.0f);
	m_object8.setScale(1.5f, 1.5f);
	m_object8.setColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_object8.setBlendMode(ALPHA);

	gridObjects[7] = m_object8;


	m_object9.makeSprite("../media/GridCross.bmp");
	m_object9.setPos(gridOffset.x + 128.0f * 2.0f, gridOffset.y + 128.0f * 2.0f);
	m_object9.setScale(1.5f, 1.5f);
	m_object9.setColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_object9.setBlendMode(ALPHA);

	gridObjects[8] = m_object9;
	

	playerBoxBG.setColor(0.5f, 0.5f, 0.5f, 1.0f);

	if (assignedTurn == CIRCLE)
		playerBoxIcon.makeSprite("../media/GridCircle.bmp");
	else
		playerBoxIcon.makeSprite("../media/GridCross.bmp");

	playerBoxIcon.setColor(1.0f, 1.0f, 1.0f, 1.0f);

	if (gameManager.currTurn == assignedTurn)
	{
		playerBoxBG.setColor(0.0f, 1.0f, 0.0f, 1.0f);
		gameStatus.makeSprite("../media/YourTurn.bmp");
	}
	else
	{
		playerBoxBG.setColor(0.5f, 0.5f, 0.5f, 1.0f);
		gameStatus.makeSprite("../media/OpponentTurn.bmp");
	}

}

void Application::CheckGameCondition(unsigned char data)
{
	int result = 0;

	//Checks if circle wins
	//Horizontal check
	if (gameManager.gameboard[0][0] == 1 && gameManager.gameboard[1][0] == 1 && gameManager.gameboard[2][0] == 1)
	{
		result = 1;
	}
	else if (gameManager.gameboard[0][1] == 1 && gameManager.gameboard[1][1] == 1 && gameManager.gameboard[2][1] == 1)
	{
		result = 1;
	}
	else if (gameManager.gameboard[0][2] == 1 && gameManager.gameboard[1][2] == 1 && gameManager.gameboard[2][2] == 1)
	{
		result = 1;
	}
	
	//Vertical check
	if (gameManager.gameboard[0][0] == 1 && gameManager.gameboard[0][1] == 1 && gameManager.gameboard[0][2] == 1)
	{
		result = 1;
	}
	else if (gameManager.gameboard[1][0] == 1 && gameManager.gameboard[1][1] == 1 && gameManager.gameboard[1][2] == 1)
	{
		result = 1;
	}
	else if (gameManager.gameboard[2][0] == 1 && gameManager.gameboard[2][1] == 1 && gameManager.gameboard[2][2] == 1)
	{
		result = 1;
	}

	//Diagonal check
	if (gameManager.gameboard[0][0] == 1 && gameManager.gameboard[1][1] == 1 && gameManager.gameboard[2][2] == 1)
	{
		result = 1;
	}
	else if (gameManager.gameboard[0][2] == 1 && gameManager.gameboard[1][1] == 1 && gameManager.gameboard[2][0] == 1)
	{
		result = 1;
	}


	//Checks if cross wins
	//Horizontal check
	if (gameManager.gameboard[0][0] == 2 && gameManager.gameboard[1][0] == 2 && gameManager.gameboard[2][0] == 2)
	{
		result = 2;
	}
	else if (gameManager.gameboard[0][1] == 2 && gameManager.gameboard[1][1] == 2 && gameManager.gameboard[2][1] == 2)
	{
		result = 2;
	}
	else if (gameManager.gameboard[0][2] == 2 && gameManager.gameboard[1][2] == 2 && gameManager.gameboard[2][2] == 2)
	{
		result = 2;
	}

	//Vertical check
	if (gameManager.gameboard[0][0] == 2 && gameManager.gameboard[0][1] == 2 && gameManager.gameboard[0][2] == 2)
	{
		result = 2;
	}
	else if (gameManager.gameboard[1][0] == 2 && gameManager.gameboard[1][1] == 2 && gameManager.gameboard[1][2] == 2)
	{
		result = 2;
	}
	else if (gameManager.gameboard[2][0] == 2 && gameManager.gameboard[2][1] == 2 && gameManager.gameboard[2][2] == 2)
	{
		result = 2;
	}

	//Diagonal check
	if (gameManager.gameboard[0][0] == 2 && gameManager.gameboard[1][1] == 2 && gameManager.gameboard[2][2] == 2)
	{
		result = 2;
	}
	else if (gameManager.gameboard[0][2] == 2 && gameManager.gameboard[1][1] == 2 && gameManager.gameboard[2][0] == 2)
	{
		result = 2;
	}

	if ((turnDuration >= 9) || result != 0)
	{
		std::cout << "CLICK THE BOARD TO RESET" << std::endl;
		gameManager.currState = GAMEOVER;

		gameStatus.makeSprite("../media/Draw.bmp");

		if (result == 1)
		{
			gameManager.currTurn = CIRCLE;

			if((int)assignedTurn == 0)
				gameStatus.makeSprite("../media/Won.bmp");
			else 
				gameStatus.makeSprite("../media/Lost.bmp");
		}
		else
		{
			gameManager.currTurn = CROSS;

			if ((int)assignedTurn == 1)
				gameStatus.makeSprite("../media/Won.bmp");
			else
				gameStatus.makeSprite("../media/Lost.bmp");
		}

		restartNotice.setColor(1.0f, 1.0f, 1.0f, 1.0f);
	}

	PackGameData(data);
}

void Application::PackGameData(unsigned char data)
{
	game_data = 0;

	//Pack the game board value first
	game_data = (game_data << 6) |data;

	
	//Pack the new turn
	game_data = (game_data << 1) | gameManager.currTurn;


	//Pack the current game state ie Playing, Game Over.
	game_data = (game_data << 1) | gameManager.currState;

	MyPhoton::getInstance().sendMyData(game_data);

	
}

unsigned int Application::ExtractGameData(unsigned char bitCount)
{
	int temp = pow(2.0, bitCount) - 1;

	int result = game_data & temp;

	game_data = (game_data >> bitCount);

	return result;
}
