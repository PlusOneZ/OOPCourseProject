/**
*@file SpearBullet.cpp
*@author 翟晨昊
*@date 6/19/2020
*/
#include <Actor/Hero.h>
#include "SpearBullet.h"

bool SpearBullet::init()
{
	int actionStep = 5;
	SpriteFrame* frame_r = nullptr;
	SpriteFrame* frame_l = nullptr;
	for (int i = 1; i <= actionStep; i++)
	{
		frame_r = SpriteFrame::create(StringUtils::format("item/bullets/spear_action%d.png", i),
			Rect(0, 0, 60, 15));
		frame_l = SpriteFrame::create(StringUtils::format("item/bullets/spear_action%d.png", i),
			Rect(0, 0, 60, 15));
		if (frame_l == nullptr || frame_r == nullptr)
		{
			log("animate spear_action%d.png lost", i);
		}
		else
		{
			frame_r->setAnchorPoint(Vec2(0.f, 0.5f));
			m_rightActionVec.pushBack(frame_r);
			frame_l->setAnchorPoint(Vec2(1.f, 0.5f));
			m_leftActionVec.pushBack(frame_l);
		}
	}
	auto fig = "item/spear1.png";
	m_pBulletSprite = Sprite::create(fig);
	bindSprite(m_pBulletSprite, sk::Kind::kSelf, sk::BulletShape::kRectangle, sk::tag::kCloseDamage);
	return true;
}

void SpearBullet::attack(float mouseX, float mouseY, Point heroPoint, int curFacing, Node* p_sprite)
{
	if (Hero::getInstance() == nullptr)
		return;
	if (curFacing == sk::kLeft)
	{
		m_pBulletSprite->setFlippedX(true);
	}
	auto point = heroPoint + Vec2((curFacing == sk::kRight ? 35.f : -35.f), 20.f);
	m_pBulletSprite->setPosition(point);

	auto joint = PhysicsJointFixed::construct(Hero::getInstance()->getPhysicsBody(),
		m_pBulletSprite->getPhysicsBody(), heroPoint);
	joint->setCollisionEnable(false);
	Hero::getInstance()->getScene()->getPhysicsWorld()->addJoint(joint);

	Animation* animation = nullptr;
	if (curFacing == sk::kRight)
	{
		animation = Animation::createWithSpriteFrames(m_rightActionVec);
	}
	else
	{
		animation = Animation::createWithSpriteFrames(m_leftActionVec);
	}
	animation->setLoops(1);
	animation->setDelayPerUnit(0.1f);
	Animate* actionOne = Animate::create(animation);
	auto end = CallFunc::create([&]() {
		//        getScene()->getPhysicsWorld()->removeJoint(joint);
		this->removeFromParentAndCleanup(true);
		});
	actionOne->retain();
	auto seq = Sequence::create(actionOne, end, nullptr);
	m_pBulletSprite->runAction(seq);
	log("spear attack!");
}