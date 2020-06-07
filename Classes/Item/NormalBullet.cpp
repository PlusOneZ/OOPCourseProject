/**
*@file NormalBullet.cpp
*@author 翟晨昊
*@date 5/30/2020
*/
#include "NormalBullet.h"

bool NormalBullet::init()
{
	Sprite* pSprite = Sprite::create("item/gunbullet.png");
	if (pSprite == nullptr)
	{
		log("gunbullet.png not found");
	}
	bindSprite(pSprite);
	setSpeed(3);
    m_isArrive = false;
	return true;
}

void NormalBullet::attack(float mouseX, float mouseY, Point heroPoint, int curFacing)
{
	heroPoint.x += (curFacing == 0 ? 25.0 : -25.0);
	heroPoint.y += 20.0;
	m_pBulletSprite->setPosition(heroPoint);

	auto v = Vec2(mouseX - heroPoint.x, mouseY - heroPoint.y);
	v.normalize();
	v *= 400;
	m_pBulletSprite->getPhysicsBody()->setVelocity(v);
}