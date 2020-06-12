/**
*@file Weapon.cpp
*@author 翟晨昊
*@date 5/30/2020
*/
#include"Weapon.h"

Bullet* Weapon::createBullet()
{
	return nullptr;
}

Animate* Weapon::attack()
{
	return nullptr;
}

 Weapon* Weapon::remake()
{
	return nullptr;
}

float Weapon::getInterval()
{
	return m_attackInterval;
}

int Weapon::getBulletCount()
{
	return m_bulletCount;
}

bool Weapon::getState()
{
	return m_isInHand;
}

void Weapon::setInterval(float interval)
{
    m_attackInterval = interval;
}

void Weapon::setBulletCount(int count)
{
	m_bulletCount = count;
}

void Weapon::setState(bool isInHand)
{
	m_isInHand = isInHand;
	if (isInHand == true)
	{
		_eventDispatcher->pauseEventListenersForTarget(this, true);
	}
	else
	{
		_eventDispatcher->resumeEventListenersForTarget(this, true);
	}
}

void Weapon::setPhysicalBody(std::string message, const int weaponTag)
{
	m_pSprite->setTag(weaponTag);
	m_pMessage = showMessage(message);
	m_pMessage->setVisible(false);
	m_pMessage->setPosition(this->getPosition().x, this->getPosition().y + 40);
	this->addChild(m_pMessage);
	auto size = m_pSprite->getContentSize();
	size.width *= 1;
	size.height *= 1;
	auto body = PhysicsBody::createBox(size);
	body->setDynamic(false);
	body->setGravityEnable(false);
	body->setCategoryBitmask(sk::bitMask::kItemCategory);
	body->setCollisionBitmask(sk::bitMask::kItemCollision);
	body->setContactTestBitmask(sk::bitMask::kItemContact);
	m_pSprite->setPhysicsBody(body);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Item::onContactBegin, this);
	contactListener->onContactSeparate = CC_CALLBACK_1(Item::onContactSeparate, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
}

void Weapon::interact()
{
}