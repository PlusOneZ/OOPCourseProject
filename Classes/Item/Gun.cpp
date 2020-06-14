/**
*@file Gun.cpp
*@author 翟晨昊
*@date 5/30/2020
*/
#include "Gun.h"
#include "NormalBullet.h"

bool Gun::init()
{
	Sprite* pSprite = Sprite::create("item/weapons.png");
	if (pSprite == nullptr)
	{
		log("weapons.png not found");
	}
	bindSprite(pSprite);
	generatePhysicalBody(kGunMessage, sk::tag::kGunWeapon);
	setInterval(.2f);
	setBulletCount(1);
    setDamage(1);
	return true;
}

Bullet* Gun::createBullet()
{

	Bullet* pBullet = NormalBullet::create();
	AudioEngine::play2d(sk::files::kGunShot);
	return pBullet;
}