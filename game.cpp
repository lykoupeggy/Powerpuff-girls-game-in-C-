#include "game.h"
#include "graphics.h"
#include "config.h"
#include <iostream>

////////////////////////////////////////////////////////////ENEMY ONE
void Game::spawnEnemyOne()
{
	if (!enemy_one && enemy_number < 11)
	{
		enemy_one = new Enemy(*this);
		enemy_number++;
	}

}

void Game::checkEnemyOne()
{
	if (enemy_one && !enemy_one->isActive())
	{
		delete enemy_one;
		enemy_one = nullptr;
	}
}

bool Game::checkCollisionOne()
{
	if (!player || !enemy_one)
	{

		return false;

	}

	Disk d1 = player->getCollisionHull();
	Disk d2 = enemy_one->getCollisionHull();

	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;

	if (sqrt(dx * dx + dy * dy) < d1.radius + d2.radius)
	{
		player->drainLife(0.1f);

		return true;
	}
	else
	{
		return false;
	}
}

////////////////////////////////////////////////////////////////////////////ENEMY TWO
void Game::spawnEnemyTwo()
{
	if (!enemy_two && enemy_number < 20)
	{
		enemy_two = new Enemy(*this);
		enemy_number++;
	}
}

void Game::checkEnemyTwo()
{
	if (enemy_two && !enemy_two->isActive())
	{
		delete enemy_two;
		enemy_two = nullptr;
	}
}

bool Game::checkCollisionTwo()
{
	if (!player || !enemy_two)
	{

		return false;

	}

	Disk d1 = player->getCollisionHull();
	Disk d2 = enemy_two->getCollisionHull();

	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;

	if (sqrt(dx * dx + dy * dy) < d1.radius + d2.radius)
	{
		player->drainLife(0.1f);
		return true;
	}
	else
	{
		return false;
	}
}

///////////////////////////////////////////////////////////////////////////ENEMY THREE
void Game::spawnEnemyThree()
{
	if (!enemy_three && enemy_number < 30)
	{
		enemy_three = new Enemy(*this);
		enemy_number++;
	}
}

void Game::checkEnemyThree()
{
	if (enemy_three && !enemy_three->isActive())
	{
		delete enemy_three;
		enemy_three = nullptr;
	}
}

bool Game::checkCollisionThree()
{
	if (!player || !enemy_three)
	{

		return false;

	}

	Disk d1 = player->getCollisionHull();
	Disk d2 = enemy_three->getCollisionHull();

	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;

	if (sqrt(dx * dx + dy * dy) < d1.radius + d2.radius)
	{
		player->drainLife(0.1f);
		return true;
	}
	else
	{
		return false;
	}
}

//////////////////////////////////////////////////////////////////HP 
void Game::spawnHp()
{
	if (!hp)
	{
		hp = new Hp(*this);
	}

}

void Game::checkHp()
{
	if (hp && !hp->isActive())
	{ 
		delete hp;
		hp = nullptr;
	}
}

bool Game::checkCollisionHp()
{
	if (!player || !hp)
	{

		return false;

	}

	Disk d1 = player->getCollisionHull();
	Disk d2 = hp->getCollisionHp();

	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;

	if (sqrt(dx * dx + dy * dy) < d1.radius + d2.radius)
	{
		player->addLife(0.1f);
		return true;
	}
	else
	{
		return false;
	}
}
///////////////////////////////////////////////////////////////////////////LASER

bool Game::checkCollisionLaserTwo()
{
	if (!laser || !enemy_two)
	{

		return false;

	}

	Disk d1 = laser->getCollisionHull();
	Disk d2 = enemy_two->getCollisionHull();

	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;

	if (sqrt(dx * dx + dy * dy) < d1.radius + d2.radius)
	{

		return true;
	}
	else
	{
		return false;
	}
}

bool Game::checkCollisionLaserThree()
{
	if (!laser || !enemy_three)
	{

		return false;

	}

	Disk d1 = laser->getCollisionHull();
	Disk d2 = enemy_three->getCollisionHull();

	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;

	if (sqrt(dx * dx + dy * dy) < d1.radius + d2.radius)
	{

		return true;
	}
	else
	{
		return false;
	}
}

bool Game::checkCollisionLaserOne()
{
	if (!laser || !enemy_one)
	{

		return false;

	}

	Disk d1 = laser->getCollisionHull();
	Disk d2 = enemy_one->getCollisionHull();

	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;

	if (sqrt(dx * dx + dy * dy) < d1.radius + d2.radius)
	{

		return true;
	}
	else
	{
		return false;
	}
}

////////////////////////////////////////////////////////////////////////UPDATES


///////////////////////////////////////////////////////////////////////START SCREEN
void Game::updateStartScreen()
{

	if ((graphics::getKeyState(graphics::SCANCODE_RETURN)) || (graphics::getKeyState(graphics::SCANCODE_KP_ENTER)))
	{
		graphics::playMusic(std::string(ASSET_PATH) + "INTRO.mp3", 0.5f, false, 0);

		status = STATUS_PICK;
	}
}


///////////////////////////////////////////////////////////////////////PICK CHARACTER SCREEN
void Game::updatePickScreen() 
{
	if ((graphics::getKeyState(graphics::SCANCODE_1)) || (graphics::getKeyState(graphics::SCANCODE_KP_1)))
	{	
		player = new Player(*this);

		player->setSelect(1);
		graphics::playSound(std::string(ASSET_PATH) + "bubbles.mp3", 0.5f, false);
		status = STATUS_LEVEL_ONE;
		graphics::stopMusic(0);

		graphics::playMusic(std::string(ASSET_PATH) + "fight_song.mp3", 0.5f, true, 9000);

	}
	else if ((graphics::getKeyState(graphics::SCANCODE_2)) || (graphics::getKeyState(graphics::SCANCODE_KP_2)))
	{
		player = new Player(*this);

		player->setSelect(2);
		graphics::playSound(std::string(ASSET_PATH) + "blossom.mp3", 0.5f, false);
		status = STATUS_LEVEL_ONE;
		graphics::stopMusic(0);

		graphics::playMusic(std::string(ASSET_PATH) + "fight_song.mp3", 0.5f, true, 9000);

	}
	else if ((graphics::getKeyState(graphics::SCANCODE_3)) || (graphics::getKeyState(graphics::SCANCODE_KP_3)))
	{

		player = new Player(*this);

		player->setSelect(3);
		graphics::playSound(std::string(ASSET_PATH) + "butter.mp3", 0.5f, false);
		status = STATUS_LEVEL_ONE;
		graphics::stopMusic(0);

		graphics::playMusic(std::string(ASSET_PATH) + "fight_song.mp3", 0.5f, true, 9000);

	}

}


///////////////////////////////////////////////////////////////////////LEVEL ONE SCREEN
void Game::updateLevelOneScreen()
{

	if (!player_initialized && graphics::getGlobalTime() > 1000)
	{
		player_initialized = true;
	}

	if (player)
		player->update();

	checkEnemyOne();
	spawnEnemyOne();

	if (enemy_one)
		enemy_one->update();

	if (graphics::getKeyState(graphics::SCANCODE_SPACE))
	{
		laser = new Laser(*this);
		laser->setPosX(player->getPosX());
		laser->setPosY(player->getPosY());
		soundlaser();

	} 
	if(laser)
		laser->update();


	if (checkCollisionLaserOne())
	{
		delete enemy_one;
		enemy_one = nullptr;

	}

	if (checkCollisionOne())
	{
		soundboom();
		delete enemy_one;
		enemy_one = nullptr;
	}



	if (enemy_number >= 11)
	{
		player->setMaxLife();
		enemy_number = 0;
		status = STATUS_LEVEL_TWO;
	}

	if (player->getRemainingLife() == 0.0f)
	{
		player->setMaxLife();
		enemy_number = 0;
		status = STATUS_OVER;
		graphics::playMusic(std::string(ASSET_PATH) + "lost.mp3", 0.5f, false, 0);

	}

}

///////////////////////////////////////////////////////////////////////LEVEL TWO SCREEN
void Game::updateLevelTwoScreen()
{

	if (!player_initialized && graphics::getGlobalTime() > 1000)
	{
		//player = new Player(*this);
		player_initialized = true;
	}

	if (player)
		player->update();

	checkEnemyTwo();
	spawnEnemyTwo();
	enemy_two->setSpeed(0.5f);

	if (enemy_two)
		enemy_two->update();

	if (graphics::getKeyState(graphics::SCANCODE_SPACE))
	{
		laser = new Laser(*this);
		laser->setPosX(player->getPosX());
		laser->setPosY(player->getPosY());
		soundlaser();

	}
	if (laser)
		laser->update();

	if (checkCollisionLaserTwo())
	{
		delete enemy_two;
		enemy_two = nullptr;

	}

	if (checkCollisionTwo())
	{
		soundboom();
		delete enemy_two;
		enemy_two = nullptr;
	}

	if (enemy_number == 10)
	{
		checkHp();
		spawnHp();
	}
	if (hp)
		hp->update();


	if (checkCollisionHp())
	{
		delete hp;
		hp = nullptr;
	}

	
	if (enemy_number == 18)
	{

		checkHp();
		spawnHp();
	}
	if (hp)
		hp->update();


	if (checkCollisionHp())
	{
		delete hp;
		hp = nullptr;
	}
	
	if (enemy_number >= 20)
	{
		player->setMaxLife();
		enemy_number = 0;
		status = STATUS_LEVEL_THREE;
	}

	if (player->getRemainingLife() == 0.0f)
	{
		player->setMaxLife();
		enemy_number = 0;
		status = STATUS_OVER;
		graphics::playMusic(std::string(ASSET_PATH) + "lost.mp3", 0.5f, false, 0);

	}

}

///////////////////////////////////////////////////////////////////////LEVEL THREE SCREEN
void Game::updateLevelThreeScreen()
{

	if (!player_initialized && graphics::getGlobalTime() > 1000)
	{
		//player = new Player(*this);
		player_initialized = true;
	}

	if (player)
		player->update();

	checkEnemyThree();
	spawnEnemyThree();
	enemy_three->setSpeed(0.7f);

	if (enemy_three)
		enemy_three->update();

	if (graphics::getKeyState(graphics::SCANCODE_SPACE))
	{
		laser = new Laser(*this);
		laser->setPosX(player->getPosX());
		laser->setPosY(player->getPosY());
		soundlaser();

	}
	if (laser)
		laser->update();

	if (checkCollisionLaserThree())
	{
		delete enemy_three;
		enemy_three = nullptr;
	}


	if (checkCollisionThree())
	{
		soundboom();
		delete enemy_three;  
		enemy_three = nullptr;
	}


	if (enemy_number == 10)
	{
		checkHp();
		spawnHp();
	}
	if (hp)
		hp->update();


	if (checkCollisionHp())
	{
		delete hp;
		hp = nullptr;
	}


	if (enemy_number == 22)
	{

		checkHp();
		spawnHp();
	}
	if (hp)
		hp->update();


	if (checkCollisionHp())
	{
		delete hp;
		hp = nullptr;
	}


	if (enemy_number >= 30)
	{
		player->setMaxLife();
		enemy_number = 0;
		status = STATUS_WIN;
		graphics::playMusic(std::string(ASSET_PATH) + "end.mp3", 0.5f, false, 0);

	}

	if (player->getRemainingLife() == 0.0f)
	{
		player->setMaxLife();
		enemy_number = 0;
		status = STATUS_OVER;
		graphics::playMusic(std::string(ASSET_PATH) + "lost.mp3", 0.5f, false, 0);

	}

}

///////////////////////////////////////////////////////////////////////PRELEVEL ONE SCREEN
void Game::updateLevelLevelOneScreen()
{
	if ((graphics::getKeyState(graphics::SCANCODE_RETURN)) || (graphics::getKeyState(graphics::SCANCODE_KP_ENTER)))
	{
		status = STATUS_ONE;
	}
}

///////////////////////////////////////////////////////////////////////PRELEVEL TWO SCREEN
void Game::updateLevelLevelTwoScreen()
{
	if ((graphics::getKeyState(graphics::SCANCODE_RETURN)) || (graphics::getKeyState(graphics::SCANCODE_KP_ENTER)))
	{
		status = STATUS_TWO;
	}
}

///////////////////////////////////////////////////////////////////////PRELEVEL THREE SCREEN
void Game::updateLevelLevelThreeScreen()
{
	if ((graphics::getKeyState(graphics::SCANCODE_RETURN)) || (graphics::getKeyState(graphics::SCANCODE_KP_ENTER)))
	{
		status = STATUS_THREE;
	}
}

///////////////////////////////////////////////////////////////////////GAME OVER SCREEN
void Game::updateOverScreen()
{
	
	if ((graphics::getKeyState(graphics::SCANCODE_RETURN)) || (graphics::getKeyState(graphics::SCANCODE_KP_ENTER)))
	{
		status = STATUS_ST;
		graphics::stopMusic(0);

	}
}

///////////////////////////////////////////////////////////////////////WIN SCREEN
void Game::updateWinScreen()
{
	if ((graphics::getKeyState(graphics::SCANCODE_RETURN)) || (graphics::getKeyState(graphics::SCANCODE_KP_ENTER)))
	{
		status = STATUS_ST;
		graphics::stopMusic(0);

	}
}

///////////////////////////////////////////////////////////////////////DRAWS


///////////////////////////////////////////////////////////////////////DRAWS START SCREEN
void Game::drawStartScreen()
{
	graphics::Brush brush;
	brush.texture = std::string(ASSET_PATH) + "start.png";
	brush.outline_opacity = 0.0f;

	graphics::drawRect(CANVAS_WIDTH /3 , CANVAS_HEIGHT /2 , 700, 462, brush);


	graphics::Brush br;
	char info[40];
	sprintf_s(info, "Press ENTER to start");
	graphics::drawText(CANVAS_WIDTH-450, CANVAS_HEIGHT/20, 20, info, br);


}

///////////////////////////////////////////////////////////////////////DRAWS PICK SCREEN
void Game::drawPickScreen()
{

	graphics::Brush brush2;

	brush2.texture = std::string(ASSET_PATH) + "picktwo.png";
	brush2.outline_opacity = 1.0f;

	//DRAW BACKROUND
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, brush2);


	graphics::Brush br2;
	char infotwo[100];
	sprintf_s(infotwo, "Press  1  for  Bubbles,  2  for  Blossom and  3  for  Buttercup");
	graphics::drawText( CANVAS_WIDTH - 990 , CANVAS_HEIGHT - 50, 18.5f , infotwo, br2);

	
}

///////////////////////////////////////////////////////////////////////LEVEL ONE SCREEN
void Game::drawLevelOneScreen()
{

	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "back1.png";
	br.outline_opacity = 1.0f;

	//DRAW BACKROUND
	graphics::drawRect(CANVAS_WIDTH /2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

	//DRAW PLAYER
	if (player)
	{
		player->draw();
	}
	//DRAW ENEMY
	if (enemy_one)
		enemy_one->draw_one();
	
	if (laser)
		laser->draw();

	if (player && debug_mode)
	{
		char info[40];
		sprintf_s(info, "Player pos: (%5.1f, %5.1f)", player->getPosX(), player->getPosY());
		graphics::drawText(20, 20, 15, info, br);

	}

	float player_life = player ? player->getRemainingLife() : 0.0f;

	br.outline_opacity = 1.0f;
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;
	br.texture = "";
	br.fill_secondary_color[0] = 1.0f * (1.0f - player_life) + player_life * 0.2f;
	br.fill_secondary_color[1] = 0.2f;
	br.fill_secondary_color[2] = 0.2f * (1.0f - player_life) + player_life * 1.0f;
	br.gradient = true;
	br.gradient_dir_u = 1.0f;
	br.gradient_dir_v = 0.0f;
	graphics::drawRect(CANVAS_WIDTH - 100 - ((1.0f - player_life) * 120 / 2), 30, player_life * 120, 30, br);

	br.outline_opacity = 1.0f;
	br.gradient = false;
	br.fill_opacity = 0.0f;

	graphics::drawRect(CANVAS_WIDTH - 100, 30, 120, 30, br);

	
}

///////////////////////////////////////////////////////////////////////LEVEL TWO SCREEN

void Game::drawLevelTwoScreen()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "back2.png";
	br.outline_opacity = 1.0f;

	//DRAW BACKROUND
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

	//DRAW PLAYER
	if (player)
	{
		player->draw();
	}

	//DRAW ENEMY
	if (enemy_two)
		enemy_two->draw_two();
	
	if (hp)
		hp->draw();

	if (laser)
		laser->draw();

	if (player && debug_mode)
	{
		char info[40];
		sprintf_s(info, "Player pos: (%5.1f, %5.1f)", player->getPosX(), player->getPosY());
		graphics::drawText(20, 20, 15, info, br);

	}

	float player_life = player ? player->getRemainingLife() : 0.0f;

	br.outline_opacity = 1.0f;
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;
	br.texture = "";
	br.fill_secondary_color[0] = 1.0f * (1.0f - player_life) + player_life * 0.2f;
	br.fill_secondary_color[1] = 0.2f;
	br.fill_secondary_color[2] = 0.2f * (1.0f - player_life) + player_life * 1.0f;
	br.gradient = true;
	br.gradient_dir_u = 1.0f;
	br.gradient_dir_v = 0.0f;
	graphics::drawRect(CANVAS_WIDTH - 100 - ((1.0f - player_life) * 120 / 2), 30, player_life * 120, 30, br);

	br.outline_opacity = 1.0f;
	br.gradient = false;
	br.fill_opacity = 0.0f;

	graphics::drawRect(CANVAS_WIDTH - 100, 30, 120, 30, br);

}

///////////////////////////////////////////////////////////////////////LEVEL THREE SCREEN

void Game::drawLevelThreeScreen()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "back3.png";
	br.outline_opacity = 1.0f;

	//DRAW BACKROUND
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

	//DRAW PLAYER
	if (player)
	{
		player->draw();
	}
	//DRAW ENEMY
	if (enemy_three)
		enemy_three->draw_three();

	if (hp)
		hp->draw();

	if (laser)
		laser->draw();

	if (player && debug_mode)
	{
		char info[40];
		sprintf_s(info, "Player pos: (%5.1f, %5.1f)", player->getPosX(), player->getPosY());
		graphics::drawText(20, 20, 15, info, br);

	}

	float player_life = player ? player->getRemainingLife() : 0.0f;

	br.outline_opacity = 1.0f;
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;
	br.texture = "";
	br.fill_secondary_color[0] = 1.0f * (1.0f - player_life) + player_life * 0.2f;
	br.fill_secondary_color[1] = 0.2f;
	br.fill_secondary_color[2] = 0.2f * (1.0f - player_life) + player_life * 1.0f;
	br.gradient = true;
	br.gradient_dir_u = 1.0f;
	br.gradient_dir_v = 0.0f;
	graphics::drawRect(CANVAS_WIDTH - 100 - ((1.0f - player_life) * 120 / 2), 30, player_life * 120, 30, br);

	br.outline_opacity = 1.0f;
	br.gradient = false;
	br.fill_opacity = 0.0f;
	
	graphics::drawRect(CANVAS_WIDTH - 100, 30, 120, 30, br);
	
}

///////////////////////////////////////////////////////////////////////PRELEVEL ONE SCREEN

void Game::drawLevelLevelOneScreen()
{
	graphics::Brush brush;
	brush.texture = std::string(ASSET_PATH) + "start.png";
	brush.outline_opacity = 0.0f;

	//DRAW BACKROUND
	graphics::drawRect(CANVAS_WIDTH / 3, CANVAS_HEIGHT / 2, 700, 462, brush);


	graphics::Brush br;
	char info[40];
	sprintf_s(info, "Level ONE |");
	graphics::drawText(CANVAS_WIDTH / 2 , CANVAS_HEIGHT / 20, 20, info, br);
	char infotwo[70];
	sprintf_s(info, "Press ENTER to start");
	graphics::drawText(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 10, 20, info, br);
}

///////////////////////////////////////////////////////////////////////PRELEVEL TWO SCREEN

void Game::drawLevelLevelTwoScreen()
{
	graphics::Brush brush;
	brush.texture = std::string(ASSET_PATH) + "start.png";
	brush.outline_opacity = 0.0f;

	//DRAW BACKROUND
	graphics::drawRect(CANVAS_WIDTH / 3, CANVAS_HEIGHT / 2, 700, 462, brush);


	graphics::Brush br;
	char info[40];
	sprintf_s(info, "Level TWO |");
	graphics::drawText(CANVAS_WIDTH - 450, CANVAS_HEIGHT / 20, 20, info, br);
	char infotwo[70];
	sprintf_s(info, "Press ENTER to start");
	graphics::drawText(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 10, 20, info, br);
}

///////////////////////////////////////////////////////////////////////PRELEVEL THREE SCREEN

void Game::drawLevelLevelThreeScreen()
{
	graphics::Brush brush;
	brush.texture = std::string(ASSET_PATH) + "start.png";
	brush.outline_opacity = 0.0f;

	//DRAW BACKROUND
	graphics::drawRect(CANVAS_WIDTH / 3, CANVAS_HEIGHT / 2, 700, 462, brush);


	graphics::Brush br;
	char info[40];
	sprintf_s(info, "Level THREE |");
	graphics::drawText(CANVAS_WIDTH - 450, CANVAS_HEIGHT / 20, 20, info, br);
	char infotwo[70];
	sprintf_s(info, "Press ENTER to start");
	graphics::drawText(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 10, 20, info, br);
}

///////////////////////////////////////////////////////////////////////GAME OVER SCREEN
void Game::drawOverScreen()
{

	graphics::Brush br;
	char info[40];
	char infotwo[45];
	sprintf_s(info, "GAME OVER");
	sprintf_s(infotwo, "Press ENTER to play again");
	graphics::drawText(CANVAS_WIDTH - 450, CANVAS_HEIGHT / 20, 20, info, br);
	graphics::drawText(CANVAS_WIDTH - 550, CANVAS_HEIGHT / 10, 20, infotwo, br);
	
	br.texture = std::string(ASSET_PATH) + "gameover.png";
	br.outline_opacity = 1.0f;

	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

}

///////////////////////////////////////////////////////////////////////WIN SCREEN

void Game::drawWinScreen()
{
	graphics::Brush br;
	char info[40];
	char infotwo[45];
	sprintf_s(info, "YOU WON !");
	sprintf_s(infotwo, "Press ENTER to play agian");
	graphics::drawText(CANVAS_WIDTH - 450, CANVAS_HEIGHT / 20, 20, info, br);
	graphics::drawText(CANVAS_WIDTH - 550, CANVAS_HEIGHT / 10, 20, infotwo, br);


	graphics::Brush brush;
	brush.texture = std::string(ASSET_PATH) + "win.png";
	brush.outline_opacity = 0.0f;

	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, brush);

}

///////////////////////////////////////////////////////////////////////UPDATES BY STATUS
void Game::update()
{
	if (status == STATUS_ST) {

		updateStartScreen();
	}
	else if (status == STATUS_PICK)
	{
		updatePickScreen();
	}
	else if (status == STATUS_LEVEL_ONE)
	{
		updateLevelLevelOneScreen();
	}
	else if (status == STATUS_ONE)
	{
		updateLevelOneScreen();
	}
	else if (status == STATUS_LEVEL_TWO)
	{
		updateLevelLevelTwoScreen();
	}
	else if (status == STATUS_TWO)
	{
		updateLevelTwoScreen();
	}
	else if (status == STATUS_LEVEL_THREE)
	{
		updateLevelLevelThreeScreen();
	}
	else if (status == STATUS_THREE)
	{
		updateLevelThreeScreen();
	}
	else if (status == STATUS_OVER)
	{
		updateOverScreen();
	}
	else if (status == STATUS_WIN)
	{
		updateWinScreen();
	}

}

///////////////////////////////////////////////////////////////////////DRAWS BY STATUS
void Game::draw()
{

	if (status == STATUS_ST) {

		drawStartScreen();
	}
	else if (status == STATUS_PICK)
	{
		drawPickScreen();
	}
	else if (status == STATUS_LEVEL_ONE)
	{
		drawLevelLevelOneScreen();
	}
	else if (status == STATUS_ONE)
	{
		drawLevelOneScreen();
	}
	else if (status == STATUS_LEVEL_TWO)
	{
		drawLevelLevelTwoScreen();
	}
	else if (status == STATUS_TWO)
	{
		drawLevelTwoScreen();
	}
	else if (status == STATUS_LEVEL_THREE)
	{
		drawLevelLevelThreeScreen();
	}
	else if ( status == STATUS_THREE )
	{
		drawLevelThreeScreen();
	}
	else if (status == STATUS_OVER)
	{
		drawOverScreen();
	}
	else if (status == STATUS_WIN)
	{
		drawWinScreen();
	}
}

void Game::init()
{
	graphics::setFont(std::string(ASSET_PATH) + "pgfont.ttf");

}

float Game::window2CanvasX(float x)
{
	return x * CANVAS_WIDTH / (float)window_width;
}

float Game::window2CanvasY(float y)
{
	return y * CANVAS_HEIGHT / (float)window_height;
}

Game::Game()
{

}

Game::~Game()
{
	if (player)
	{
		delete player;
	}
}

void Game::soundlaser()
{
		graphics::playSound(std::string(ASSET_PATH) + "laser.mp3", 0.5f, false);
			
}

void Game::soundboom()
{
	graphics::playSound(std::string(ASSET_PATH) + "hit.mp3", 0.5f, false);

}
