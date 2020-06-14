/**
*@file ShotgunBullet.cpp
*@author 翟晨昊
*@date 6/6/2020
*/
#include "ShotgunBullet.h"

bool ShotgunBullet::init()
{
	Sprite* pSprite = Sprite::create("item/shotgunbullet.png");
	if (pSprite == nullptr)
	{
		log("shotgunbullet.png not found");
	}
    bindSprite(pSprite, sk::Kind::kSelf);
	setSpeed(4);
	m_isArrive = false;
	return true;
}

void ShotgunBullet::attack(float mouseX, float mouseY, Point heroPoint, int curFacing)
{
	heroPoint.x += (curFacing == 0 ? 25.0f : -25.0f);
	heroPoint.y += 20.0;
	m_pBulletSprite->setPosition(heroPoint);
	float k = (mouseY - heroPoint.y) / (mouseX - heroPoint.x);
	launchPath(k, mouseX - heroPoint.x);
}

void ShotgunBullet::launchPath(float k, float shootDirection)
{
    float sign = (shootDirection > 0 ? 1.f : -1.f);
	float random = (static_cast<float >(rand() % (200)) + (k - 0.1f) * 1000.f) / 1000;
	auto v = Vec2(sign, sign * random);
	v.normalize();
	v *= 700;
	m_pBulletSprite->getPhysicsBody()->setVelocity(v);
}

