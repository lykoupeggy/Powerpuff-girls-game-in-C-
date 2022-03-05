#pragma once
#include "gameobject.h"
#include "graphics.h"

class Hp : public GameObject, public Collidable
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
	void draw() override;
	void init() override;
	bool isActive() { return active; }
	Hp(const class Game& mygame);
	~Hp();
	Disk getCollisionHp() const;
	Disk getCollisionHull() const override; 

};
