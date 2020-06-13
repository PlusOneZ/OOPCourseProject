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

int Weapon::getATK()
{
	return m_weaponATK;
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
	m_pSprite->getPhysicsBody()->setEnabled(!isInHand);
}

void Weapon::setATK(int ATK)
{
	m_weaponATK = ATK;
}