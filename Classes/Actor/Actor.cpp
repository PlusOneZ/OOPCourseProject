/**
*@file Actor.cpp
*@author 肖杨
*/

#include "Actor.h"
#include "Const/Const.h"

void Actor::bindSprite(Sprite *pSprite){
    m_sprite = pSprite;
    this->addChild(m_sprite);
}

bool Actor::generatePhysics()
{
    auto body = PhysicsBody::createBox(m_sprite->getContentSize());
    body->setMass(1e10);
    body->setPositionOffset(Vec2(0.f, m_sprite->getContentSize().height / 2));
    body->setGravityEnable(false);
	body->setCategoryBitmask(sk::bitMask::kHeroCategory);
	body->setCollisionBitmask(sk::bitMask::kHeroCollision);
	body->setContactTestBitmask(sk::bitMask::kHeroContact);
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
Animate* Actor::creatActorAnimate(const char * pAnimateName, int width, int height, int frames)
{
	log("Trying to create actor");
	SpriteFrame*frame = nullptr;
	Vector<SpriteFrame*> frameVec;
	for (int i = 1; i <= frames; i++)
	{
		frame = SpriteFrame::create(StringUtils::format("%s%d.png", pAnimateName, i),
			Rect(0, 0, width, height));
		if (frame == nullptr)
		{
			log("animate %s%d.png lost", pAnimateName, i);
		}
		else
		{
			frame->setAnchorPoint(Vec2(0.5f, 0.f));
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
