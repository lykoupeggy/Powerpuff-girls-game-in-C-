#include "enemy.h"
#include "graphics.h"
#include "config.h"
#include "game.h"
#include <random>

void Enemy::update()
{
	pos_x -= speed * graphics::getDeltaTime(); 



	if (pos_x <- size)
	{
		active = false;
	}
}


void Enemy::draw_one()
{

	brush.fill_opacity = 0.5f;
	brush.texture = std::string(ASSET_PATH) + "enemy_one_shadow.png";
	graphics::drawRect(pos_x - 10, pos_y + 30, size + 20, size + 20, brush);
	brush.fill_opacity = 1.0f;
	brush.texture = std::string(ASSET_PATH) + "enemy_one.png";
	graphics::drawRect(pos_x, pos_y, size + 20, size + 20, brush);
	graphics::setOrientation(0.f);
	graphics::resetPose();

	if (game.getDebugMode())
	{
		graphics:: Brush br;
		br.outline_opacity = 1.0f;
		br.texture = "";
		br.fill_color[0] = 1.3f;
		br.fill_color[1] = 0.4f;
		br.fill_color[2] = 0.3f;
		br.fill_opacity = 1.0f;
		br.gradient = false;
		Disk hull = getCollisionHull();
		graphics::drawDisk(hull.cx, hull.cy, hull.radius, br);

	}

}

void Enemy::draw_two()
{

	brush.fill_opacity = 0.5f;
	brush.texture = std::string(ASSET_PATH) + "enemy_two_shadow.png";
	graphics::drawRect(pos_x - 10, pos_y + 30, size + 30, size + 20, brush);
	brush.fill_opacity = 1.0f;
	brush.texture = std::string(ASSET_PATH) + "enemy_two.png";
	graphics::drawRect(pos_x, pos_y, size + 30, size + 30, brush);
	graphics::setOrientation(0.f);
	graphics::resetPose();

	if (game.getDebugMode())
	{
		graphics::Brush br;
		br.outline_opacity = 1.0f;
		br.texture = "";
		br.fill_color[0] = 1.3f;
		br.fill_color[1] = 0.4f;
		br.fill_color[2] = 0.3f;
		br.fill_opacity = 1.0f;
		br.gradient = false;
		Disk hull = getCollisionHull();
		graphics::drawDisk(hull.cx, hull.cy, hull.radius, br);

	}

}

void Enemy::draw_three()
{

	brush.fill_opacity = 0.3f;
	brush.texture = std::string(ASSET_PATH) + "enemy_three_shadow.png";
	graphics::drawRect(pos_x - 10, pos_y + 30, size + 50 , size + 50, brush);
	brush.fill_opacity = 1.0f;
	brush.texture = std::string(ASSET_PATH) + "enemy_three.png";
	graphics::drawRect(pos_x, pos_y, size + 50, size + 50, brush);
	graphics::setOrientation(0.f);
	graphics::resetPose();

	if (game.getDebugMode())
	{
		graphics::Brush br;
		br.outline_opacity = 1.0f;
		br.texture = "";
		br.fill_color[0] = 1.3f;
		br.fill_color[1] = 0.4f;
		br.fill_color[2] = 0.3f;
		br.fill_opacity = 1.0f;
		br.gradient = false;
		Disk hull = getCollisionHull();
		graphics::drawDisk(hull.cx, hull.cy, hull.radius, br);

	}

}


void Enemy::draw()
{
}

void Enemy::init()
{
	speed = 0.3f;
	pos_x = CANVAS_WIDTH + 1.1f * size; 
	pos_y = CANVAS_HEIGHT * rand() / (float)RAND_MAX;
	size = 80;
	brush.outline_opacity = 0.0f;

}

Enemy::Enemy(const Game & mygame)
	: GameObject(mygame)
{
	init();
}

Enemy::~Enemy()
{
}

Disk Enemy::getCollisionHull() const
{
	Disk disk;
	disk.cx = pos_x;
	disk.cy = pos_y;
	disk.radius = size*0.45f;
	return disk;

}