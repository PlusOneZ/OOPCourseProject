/**
*@file Bullet.cpp
*@author 翟晨昊
*@date 5/30/2020
*/
#include "Bullet.h"

float Bullet::getSpeed()
{
    return m_bulletSpeed;
}

void Bullet::setSpeed(float speed)
{
    m_bulletSpeed = speed;
}

void Bullet::bindSprite(Sprite* pSprite)
{
    m_pBulletSprite = pSprite;
    auto body = PhysicsBody::createBox(m_pBulletSprite->getContentSize());
    m_pBulletSprite->setPhysicsBody(body);
    body->setCategoryBitmask(0x1100);
    body->setCollisionBitmask(0x0011);
    body->setContactTestBitmask(0x0011);
    body->setTag(200);
    this->addChild(m_pBulletSprite);
}

void Bullet::moveEnd()
{
    m_isArrive = true;
    this->removeAllChildrenWithCleanup(true);
    this->autorelease();
}