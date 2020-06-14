/**
*@file   Trap.cpp
*@author Ф��
*@date   6/12/2020
*/
#include "Trap.h"

void Trap::update(float dt)
{
	static float time = m_trapTime;
	time -= dt;
	if (time <= 0)
	{
		trapEnd();
	}
}

bool Trap::onContactBegin(PhysicsContact& contact)
{
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();

	if (nodeA != nullptr && nodeB != nullptr)
	{
		if ((nodeA->getTag() == sk::tag::kHero || nodeB->getTag() == sk::tag::kHero)
			&& (nodeA->getTag() == this->getTag() || nodeB->getTag() == this->getTag()))
		{
			this->scheduleUpdate();
			this->trapStart();
			_eventDispatcher->pauseEventListenersForTarget(this, true);
		}
	}
	return false;
}

void Trap::setTrapTime(float time)
{
	m_trapTime = time;
}

void Trap::generatePhysicalBody(const int trapTag)
{
	m_pSprite->setTag(trapTag);
	auto size = m_pSprite->getContentSize();
	auto body = PhysicsBody::createBox(size);
	body->setDynamic(false);
	body->setGravityEnable(false);
	body->setCategoryBitmask(sk::bitMask::kItemCategory);
	body->setCollisionBitmask(sk::bitMask::kItemCollision);
	body->setContactTestBitmask(sk::bitMask::kItemContact);
	m_pSprite->setPhysicsBody(body);

	this->addChild(m_pSprite);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Trap::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
}

bool FreezeTrap::init()
{
	m_pSprite = Sprite::create("item/freeze_trap.png");
	m_trapTime = 2.0;
	generatePhysicalBody(sk::tag::kFreezeTrap);
	return true;
}

void FreezeTrap::trapStart()
{
	HeroBuff.rooted(m_trapTime);
	m_pSprite->setVisible(false);
}

void FreezeTrap::trapEnd()
{
	HeroBuff.rootedEnd(m_trapTime);
	this->removeFromParentAndCleanup(true);
}

bool FlameTrap::init()
{
	m_pSprite = Sprite::create("item/flame_trap.png");
	m_trapTime = 3.0;
	generatePhysicalBody(sk::tag::kFlameTrap);
	return true;
}

void FlameTrap::trapStart()
{
	HeroBuff.flaming();
	m_pSprite->setVisible(false);
}

void FlameTrap::trapEnd()
{
	HeroBuff.flamingEnd();
	this->removeFromParentAndCleanup(true);
}

void FlameTrap::update(float dt)
{
	static float time = m_trapTime;
	static float flameTime = 0;
	time -= dt;
	flameTime += dt;
	if (flameTime >= 1)
	{
		flameTime -= 1;
        Hero::m_pPresentHero->reduceHealth();
	}
	if (time <= 0)
	{
		trapEnd();
	}
}