#pragma once

#include "player.h"
#include "enemy.h"
#include "laser.h"
#include "hp.h"

class Game
{
	typedef enum {STATUS_ST, STATUS_PICK, STATUS_LEVEL_ONE, STATUS_ONE, STATUS_LEVEL_TWO, STATUS_TWO, STATUS_LEVEL_THREE, STATUS_THREE, STATUS_OVER, STATUS_WIN} status_t;
	Player * player = nullptr;
	bool player_initialized = false; 
	bool debug_mode = false;
	Enemy * enemy_one = nullptr;
	Enemy * enemy_two = nullptr;
	Enemy * enemy_three = nullptr;
	Laser* laser = nullptr;
	Hp * hp = nullptr;
	void spawnEnemyOne();
	void checkEnemyOne();
	bool checkCollisionOne();
	void spawnEnemyTwo();
	void checkEnemyTwo();
	bool checkCollisionTwo();
	void spawnEnemyThree();
	void checkEnemyThree();
	bool checkCollisionThree();
	void spawnHp();
	void checkHp();
	bool checkCollisionHp();
	bool checkCollisionLaserOne();
	bool checkCollisionLaserTwo();
	bool checkCollisionLaserThree();

	status_t status = STATUS_ST;
	float box_len = CANVAS_WIDTH;
	
	unsigned int window_width = WINDOW_WIDTH;
	unsigned int window_height = WINDOW_HEIGHT;

	int enemy_number = 0;

	void updateStartScreen();
	void updateLevelOneScreen();
	void updateLevelTwoScreen();
	void updateLevelThreeScreen();
	void updateLevelLevelOneScreen();
	void updateLevelLevelTwoScreen();
	void updateLevelLevelThreeScreen();
	void updateOverScreen();
	void updateWinScreen();
	void updatePickScreen();

	void drawStartScreen();
	void drawLevelOneScreen();
	void drawLevelTwoScreen();
	void drawLevelThreeScreen();
	void drawLevelLevelOneScreen();
	void drawLevelLevelTwoScreen();
	void drawLevelLevelThreeScreen();
	void drawOverScreen();
	void drawWinScreen();
	void drawPickScreen();

	void soundlaser();
	void soundboom();

public:
	void setDebugMode(bool d) { debug_mode = d; }
	bool getDebugMode() const { return debug_mode; }
	void update();
	void draw();
	void init();
	unsigned int getWindowWidth() { return window_width; }
	unsigned int getWindowHeight() { return window_height; }
	float window2CanvasX(float x);
	float window2CanvasY(float y);

	void setWindowDimensions(unsigned int w, unsigned int h) { window_width = w; window_height = h; }

	Game();
	~Game();
};