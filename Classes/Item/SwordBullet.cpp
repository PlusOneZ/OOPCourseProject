/**
*@file SwordBullet.cpp
*@author 翟晨昊
*@date 6/13/2020
*/
#include "SwordBullet.h"

bool SwordBullet::init()
{
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
	auto fig = AutoPolygon::generatePolygon("item/swordaction1.png");
	m_pBulletSprite = Sprite::create(fig);
	bindSprite(m_pBulletSprite, sk::Kind::kSelf);
	return true;
}

void SwordBullet::attack(float mouseX, float mouseY, Point heroPoint, int curFacing)
{
	if (curFacing == sk::kLeft)
	{
		m_pBulletSprite->setFlippedX(true);
	}
	heroPoint.x += (curFacing == 0 ? 25.0 : -25.0);
	heroPoint.y += 20.0;
	m_pBulletSprite->setPosition(heroPoint);
	Animation* animation = Animation::createWithSpriteFrames(actionVec);
	animation->setLoops(1);
	animation->setDelayPerUnit(0.1f);
	Animate* actionOne = Animate::create(animation);
	actionOne->retain();
	m_pBulletSprite->runAction(actionOne);
	log("sword attack!");
}