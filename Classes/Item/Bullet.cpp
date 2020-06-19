/**
*@file Bullet.cpp
*@author 翟晨昊
*@date 5/30/2020
*/
#include "Bullet.h"
#include "Const/Const.h"

float Bullet::getSpeed()
{
    return m_bulletSpeed;
}

void Bullet::setSpeed(float speed)
{
    m_bulletSpeed = speed;
}

void Bullet::bindSprite(Sprite *pSprite, sk::Kind kind, sk::BulletShape shape, int tag)
{
    PhysicsBody* body = nullptr;
    m_pBulletSprite = pSprite;
    if (shape == sk::BulletShape::kCircle)
    {
        body = PhysicsBody::createCircle(m_pBulletSprite->getContentSize().width / 2);
    }
    else if (shape == sk::BulletShape::kRectangle)
    {
        body = PhysicsBody::createBox(m_pBulletSprite->getContentSize());
    }
    if (kind == sk::Kind::kSelf)
    {
        body->setCategoryBitmask(sk::bitMask::kSelfBulletCategory);
        body->setCollisionBitmask(sk::bitMask::kSelfBulletCollision);
        body->setContactTestBitmask(sk::bitMask::kSelfBulletContact);
        body->setRotationEnable(false);
        m_pBulletSprite->setPhysicsBody(body);
    }
    else if (kind == sk::Kind::kMonster)
    {
        body->setCategoryBitmask(sk::bitMask::kMonsterBulletCategory);
        body->setCollisionBitmask(sk::bitMask::kMonsterBulletCollision);
        body->setContactTestBitmask(sk::bitMask::kMonsterBulletContact);
        body->setRotationEnable(false);
        m_pBulletSprite->setPhysicsBody(body);
    }
    this->addChild(m_pBulletSprite, 3, tag);
}


void Bullet::moveEnd()
{
    m_isArrive = true;
    this->removeAllChildrenWithCleanup(true);
    this->autorelease();
}

void Bullet::setDamage(int damage)
{
    m_damage = damage;
}

int Bullet::getDamage()
{
    return m_damage;
}