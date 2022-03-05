#include "hp.h"
#include "graphics.h"
#include "config.h"
#include "game.h"
#include <random>

void Hp::update()
{
	pos_x -= speed * graphics::getDeltaTime();



	if (pos_x < -size)
	{
		active = false;
	}
}


void Hp::draw()
{

	brush.fill_opacity = 0.5f;
	brush.texture = std::string(ASSET_PATH) + "hp_shadow.png";
	graphics::drawRect(pos_x - 10, pos_y + 30, size, size, brush);
	brush.fill_opacity = 1.0f;
	brush.texture = std::string(ASSET_PATH) + "hp.png";
	graphics::drawRect(pos_x, pos_y, size, size, brush);
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

void Hp::init()
{
	speed = 0.3f;
	pos_x = CANVAS_WIDTH + 1.1f * size;
	pos_y = CANVAS_HEIGHT * rand() / (float)RAND_MAX;
	size = 50;
	brush.outline_opacity = 0.0f;

}

Hp::Hp(const Game& mygame)
	: GameObject(mygame)
{
	init();
}

Hp::~Hp()
{
}

Disk Hp::getCollisionHp() const
{
	Disk disk;
	disk.cx = pos_x;
	disk.cy = pos_y;
	disk.radius = size * 0.45f;
	return disk;

}

Disk Hp::getCollisionHull() const
{
	return Disk();
}
