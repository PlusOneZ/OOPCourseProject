/**
*@file Shotgun.cpp
*@author 翟晨昊
*@date 6/6/2020
*/
#include "Shotgun.h"
#include "ShotgunBullet.h"

bool Shotgun::init()
{
	Sprite* pSprite = Sprite::create("item/shotgun.png");
	if (pSprite == nullptr)
	{
		log("shotgun.png not found");
	}
	bindSprite(pSprite);
	setInterval(.4f);
	setBulletCount(3);
	return true;
}

Bullet* Shotgun::createBullet()
{
	Bullet* pBullet = ShotgunBullet::create();
	return pBullet;
}