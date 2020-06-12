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


