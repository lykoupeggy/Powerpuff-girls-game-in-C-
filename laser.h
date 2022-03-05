#pragma once
#include "gameobject.h"
#include "config.h"
#include <iostream>
#include "graphics.h"


class Laser : public GameObject, public Collidable
{
	float pos_x;
	float pos_y;
	float speed;
	float size;
	graphics::Brush brush;
	bool active = true;

public:
	Laser(const class Game& mygame);
	~Laser();
	void update() override;
	bool isActive() { return active; }
	void draw() override;

	void init() override;

	float getPosY() { return pos_y; }
	float getPosX() { return pos_x; }

	void setPosY(float y) { pos_y = y; }
	void setPosX(float x) { pos_x = x; }

	Disk getCollisionHull() const override;

}; 