/**
*@file Sword.cpp
*@author 翟晨昊
*@date 6/6/2020
*/

#include "Sword.h"
#include "SwordBullet.h"

bool Sword::init()
{
	log("Trying to create sword");
	Sprite* pSprite = Sprite::create("item/swordaction1.png");
	bindSprite(pSprite);
	generatePhysicalBody(kSwordMessage, sk::tag::kSwordWeapon);
	setInterval(.2f);
	setBulletCount(0);
	setATK(4);
	return true;
}

Bullet* Sword::createBullet()
{
	Bullet* pBullet = SwordBullet::create();
	return pBullet;
}