#pragma once
#include "gameobject.h"
#include "graphics.h"

class Enemy : public GameObject, public Collidable 
{
	float pos_x, pos_y; 
	float speed;
	float size;
	graphics::Brush brush; 
	bool active = true;

public:

	void setSpeed(float sp) { speed = sp; }
	float getSpeed() { return speed; }
	void update() override; 
	void draw_one();
	void draw_two();
	void draw_three();
	void draw() override;
	void init() override;
	float getPosX() { return pos_x; }
	float getPosY() { return pos_y; }

	bool isActive() { return active; }
	Enemy(const class Game & mygame);
	~Enemy();
	Disk getCollisionHull() const override;
};