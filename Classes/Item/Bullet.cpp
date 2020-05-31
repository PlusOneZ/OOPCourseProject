/**
*@file Bullet.cpp
*@author 翟晨昊
*@date 5/30/2020
*/
#include "Bullet.h"

float Bullet::getSpeed()
{
    return bulletSpeed;
}

void Bullet::setSpeed(float speed)
{
    bulletSpeed = speed;
}

void Bullet::bindSprite(Sprite* pSprite)
{
    m_pBulletSprite = pSprite;
    this->addChild(m_pBulletSprite);
}

void Bullet::moveEnd()
{
    isArrive = true;
    this->autorelease();
}