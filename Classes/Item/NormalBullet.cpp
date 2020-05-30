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
	isArrive = false;
	return true;
}

void NormalBullet::attack(float mouseX, float mouseY, Point heroPoint)
{
	heroPoint.x += 25.0;
	heroPoint.y += 20.0;
	Point mousePoint = Vec2(mouseX, mouseY);
	m_pBulletSprite->setPosition(heroPoint);
	auto moveTo = MoveTo::create(10.0/bulletSpeed, mousePoint);
	auto callFunc = CallFunc::create([&]() {
		moveEnd();
		});
	auto actions = Sequence::create(moveTo, callFunc, NULL);
	this->runAction(actions);
}