#include "player.h"
#include "graphics.h"
#include "game.h"

Player::Player(const Game & mygame)
	: GameObject(mygame)
{
}

void Player::update()
{

	if (graphics::getKeyState(graphics::SCANCODE_RIGHT))
	{
		pos_x += speed * graphics::getDeltaTime() / 10.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_LEFT))
	{
		pos_x -= speed * graphics::getDeltaTime() / 10.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_DOWN))
	{
		pos_y += speed * graphics::getDeltaTime() / 10.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_UP))
	{
		pos_y -= speed * graphics::getDeltaTime() / 10.0f;
	}

	if (pos_x < 0) pos_x = 0;
	if (pos_x > CANVAS_WIDTH) pos_x = CANVAS_WIDTH;
	if (pos_y < 0) pos_y = 0;
	if (pos_y > CANVAS_HEIGHT) pos_y = CANVAS_HEIGHT;

}

void Player::draw()
{
	
		//float glow = 0.5f + 0.5f * sinf(graphics::getGlobalTime()/10); // anabosbhnei

		graphics::Brush br;
		
		//peristrofi eikonas 
		//graphics::setOrientation(-90.f);
		if (getSelect() == 1)
		{
			
			br.outline_opacity = 0.0f;
			br.fill_opacity = 0.5f;
			br.texture = std::string(ASSET_PATH) + "blue_player_shadow.png";
			graphics::drawRect(pos_x - 10, pos_y + 30, 80, 80, br);

			br.outline_opacity = 0.0f;
			br.fill_opacity = 1.0f;
			br.texture = std::string(ASSET_PATH) + "blue_player.png";
			graphics::drawRect(pos_x, pos_y, 80, 80, br);

			graphics::setOrientation(0.f);
			br.texture = "";
			graphics::resetPose();

		}
		else if (getSelect() == 2)
		{
			br.outline_opacity = 0.0f;

			br.fill_opacity = 0.5f;
			br.texture = std::string(ASSET_PATH) + "red_player_shadow.png";
			graphics::drawRect(pos_x - 10, pos_y + 30, 80, 80, br);

			br.fill_opacity = 1.0f;
			br.texture = std::string(ASSET_PATH) + "red_player.png";
			graphics::drawRect(pos_x, pos_y, 80, 80, br); 
			
			graphics::setOrientation(0.f);
			br.texture = "";

		}
		else if (getSelect() == 3)
		{
			br.outline_opacity = 0.0f;

			br.fill_opacity = 0.5f;
			br.texture = std::string(ASSET_PATH) + "green_player_shadow.png";
			graphics::drawRect(pos_x - 10, pos_y + 30, 80, 80, br);

			br.fill_opacity = 1.0f;
			br.texture = std::string(ASSET_PATH) + "green_player.png";
			graphics::drawRect(pos_x, pos_y, 80, 80, br);
			graphics::setOrientation(0.f);
			br.texture = "";

		}
		
		if (game.getDebugMode())
		{
			br.outline_opacity = 1.0f;
			br.texture = "";
			br.fill_color[0] = 0.3f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 0.3f;
			br.fill_opacity = 1.0f;
			br.gradient = false;
			Disk hull = getCollisionHull();
			graphics::drawDisk(hull.cx, hull.cy, hull.radius, br);

		}
}


void Player::init()
{
}

Disk Player::getCollisionHull() const
{
	Disk disk;
	disk.cx = pos_x;
	disk.cy = pos_y;
	disk.radius = 45.0f;
	return disk;
}

void Player::drainLife(float amount)
{
	life = std::max<float>(0.0f, life - amount);

}
