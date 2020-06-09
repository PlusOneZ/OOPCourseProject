/**
*@file Sword.cpp
*@author 翟晨昊
*@date 6/6/2020
*/

#include "Sword.h"

bool Sword::init()
{
	log("Trying to create sword");
	int actionStep = 5;
	SpriteFrame* frame = nullptr;
	for (int i = 1; i <= actionStep; i++)
	{
		frame = SpriteFrame::create(StringUtils::format("item/swordaction%d.png", i), Rect(0, 0, 50, 50));
		if (frame == nullptr)
		{
			log("animate swordaction%d.png lost", i);
		}
		else
		{
			frame->setAnchorPoint(Vec2(0.5, 0.));
			actionVec.pushBack(frame);
		}
	}
	setInterval(.2f);
	setBulletCount(0);
	return true;
}

Animate* Sword::attack()
{
	Animation* animation = Animation::createWithSpriteFrames(actionVec);
	animation->setLoops(1);
	animation->setDelayPerUnit(0.1f);
	Animate* action = Animate::create(animation);
	action->retain();
	m_pSprite->runAction(action);
	log("sword attack!");
	return action;
}