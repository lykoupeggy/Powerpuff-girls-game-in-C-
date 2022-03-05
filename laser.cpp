#include "laser.h"
#include "graphics.h"
#include "game.h"
#include "config.h"


Laser::Laser(const Game& mygame)
    : GameObject(mygame)
{
    init();
}

Laser::~Laser()
{
}

void Laser::update()
{
   // pos_x = getPosX();
   // pos_y = getPosY();

    pos_x += speed * graphics::getDeltaTime();

    if (pos_x < -size)
    {
        active = false;
    }
}

void Laser::draw()
{
	graphics::Brush br;

    float glow = 0.5f + 0.5f * sinf(graphics::getGlobalTime()/10); // anabosbhnei

    br.fill_color[0] = 1.0f;
    br.fill_color[1] = 0.2f + glow * 0.5f;
    br.fill_color[2] = 0.0f;
    br.fill_secondary_color[0] = 0.3f;
    br.fill_secondary_color[1] = 0.1f;
    br.fill_secondary_color[2] = 0.0f;
    br.fill_opacity = 1.0f;
    br.fill_secondary_opacity = 0.0f;
    br.gradient = true;
    br.outline_opacity = 0.0f;

    graphics::drawDisk(pos_x, pos_y, 60, br);
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

void Laser::init()
{
    speed = 0.6f;
    size = 30;
    brush.outline_opacity = 0.0f;
   
}

Disk Laser::getCollisionHull() const
{
    Disk disk;
    disk.cx = pos_x;
    disk.cy = pos_y;
    disk.radius = size * 0.45f;
    return disk;
}
 