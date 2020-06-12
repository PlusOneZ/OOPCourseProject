/**
*@file   Trap.cpp
*@author Р¤Со
*@date   6/12/2020
*/
#include "Trap.h"

void Trap::update(float dt)
{
	static double time = m_trapTime;
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
		}
	}
	return false;
}

void Trap::setTrapTime(double time)
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