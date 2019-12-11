#pragma once

#include "MyPhoton.h"
#include "Sprite.h"
#include "GameObject.h"

#include <list>

enum GameState
{
	GAMEOVER = 0,
	PLAYING,
};

enum GameTurn
{
	CROSS,
	CIRCLE,
	SPECTATOR,
};

struct GameManager
{
	GameTurn currTurn;
	GameState currState;
	GameTurn gameWinner;

	int gameboard[3][3];
};

class Application
{
private: 
	unsigned char game_data = 0;



protected:
	int m_method;

	GameObject gridObjects[9];

	Sprite*		m_sprite01;
	GameObject	m_object1;
	GameObject	m_object2;
	GameObject	m_object3;
	GameObject	m_object4; 
	GameObject	m_object5;
	GameObject	m_object6;
	GameObject	m_object7;
	GameObject	m_object8;
	GameObject	m_object9;

	GameObject	gridbackground;
	GameObject	gridbox1;
	GameObject	gridbox2;
	GameObject	gridbox3;
	GameObject	gridbox4;
	GameObject	gridbox5;
	GameObject	gridbox6;
	GameObject	gridbox7;
	GameObject	gridbox8;
	GameObject	gridbox9;

	GameObject gameStatus;
	GameObject playerBoxBG;
	GameObject playerBoxIcon;

	GameObject restartNotice;

public: 

	Application();
	~Application();


	static Application& getInstance()
	{
		static Application app;
		return app;
	}

	//Assigned shape for local player
	GameTurn assignedTurn = SPECTATOR;

	//Game manager for local player
	GameManager gameManager;

	//Offset of drawn game board
	Vector2 gridOffset = Vector2(410.0f, 150.0f);
	int turnDuration;


	void OnReceivedOpponentData(unsigned char data);

	virtual void start();
	virtual void update(double elapsedTime);
	virtual void draw();
	virtual void onKeyPressed(int key);
	virtual void onKeyReleased(int key);
	virtual void onKeyHold(int key);
	virtual void onMousePressed(int button, Vector2 position);
	virtual void onMouseReleased(int button);
	virtual void onMouseHold(int button);
	virtual void onMouseMoved(double mousePosX, double mousePosY);

	virtual void RunGame();
	virtual void CheckGameCondition(unsigned char data);
	virtual void PackGameData(unsigned char data);
	unsigned int ExtractGameData(unsigned char bitCount);


};
