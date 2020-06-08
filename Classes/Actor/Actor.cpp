/**
*@file Actor.cpp
*@author 肖杨
*/

#include "Actor.h"

void Actor::bindSprite(Sprite *pSprite){
    m_sprite = pSprite;
    this->addChild(m_sprite);
}

bool Actor::generatePhysics()
{
    auto body = PhysicsBody::createBox(m_sprite->getContentSize());
    body->setMass(1e10);
    body->setGravityEnable(false);
	body->setCategoryBitmask(k_HeroCategoryBitmask);
	body->setCollisionBitmask(k_HeroCollisionBitmask);
	body->setContactTestBitmask(k_HeroContactTestBitmask);
    this->setPhysicsBody(body);

    return true;
}

/**
 * @brief  创建
 * @bug    传参错误导致无法正常生成动
 * @date   05/25/2020 [bug fixed: 卓正一]
 * @param  pAnimateName 动画文件名（字符串）
 * @author 肖杨
*/
Animate* Actor::creatActorAnimate(const char * pAnimateName, int width, int height)
{
	log("Trying to create hero");
	int moveFrameNum = 4;
	SpriteFrame*frame = nullptr;
	Vector<SpriteFrame*> frameVec;
	for (int i = 1; i <= moveFrameNum; i++)
	{
		frame = SpriteFrame::create(StringUtils::format("%s%d.png", pAnimateName, i),
			Rect(0, 0, width, height));
		if (frame == nullptr)
		{
			log("animate %s%d.png lost", pAnimateName, i);
		}
		else
		{
			frame->setAnchorPoint(Vec2(0.5, 0.));
			frameVec.pushBack(frame);
		}
	}
	Animation*animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.2f);
	Animate*action = Animate::create(animation);
	action->retain();
	return action;
}
