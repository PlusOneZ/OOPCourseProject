/**
 * @file Monster.h
 * @date 06/08/2020 [created by 卓正一]
 */

#include "Monster.h"

bool Monster::init() {
    m_curHealth = m_fullHealth;
    scheduleUpdate();
    return true;
}

void Monster::wanderSpeed(float dt)
{
    float xSpeed = RandomHelper::random_real(-1., 1.);
    float ySpeed = RandomHelper::random_real(-1., 1.);
    auto vTemp   = Vec2(xSpeed, ySpeed);
    m_curSpeed   = vTemp / vTemp.getLength() * m_wanderSpeed;
    getPhysicsBody()->setVelocity(m_curSpeed);
    // TODO 增强随机性

    m_facing = (m_curSpeed.x > 0 ? sk::kRight : sk::kLeft);
    if (m_facing == sk::kRight)
    {
        m_sprite->setFlippedX(false);
    }
    else
    {
        m_sprite->setFlippedX(true);
    }
}


void Monster::die()
{
    this->stopAllActions();
    auto dieSprite = Sprite::create(m_pDieSprite);
    if (dieSprite == nullptr)
    {
        log("dead not available");
    }
    else
    {
        // 移除关节
        for (auto &joint : getPhysicsBody()->getJoints())
        {
            if (joint != nullptr)
            {
                joint->removeFormWorld();
            }
        }
        dieSprite->setPosition(this->getPosition());
        this->getParent()->addChild(dieSprite);
    }

    // 掉落金币
    int amount = RandomHelper::random_int(0, m_fullHealth / 10);
    if (amount <= 0)
    {
        this->removeFromParentAndCleanup(true);
        return;
    }
	Hero::getInstance()->gainCoins(amount);
    this->removeFromParentAndCleanup(true);
}

void Monster::reduceHealth(int amount)
{
    if (amount > m_curHealth || m_curHealth <= 0)
        die();
    else
        m_curHealth -= amount;
}

bool Monster::generatePhysics(float mass)
{
    if (m_sprite == nullptr)
    {
        log("No sprite to create physics body");
        return false;
    }
    auto body = PhysicsBody::createCircle(m_sprite->getContentSize().width / 2);
//    auto body = PhysicsBody::createBox(m_sprite->getContentSize());
    body->setMass(mass);
    body->setGravityEnable(false);
    body->setPositionOffset(Vec2(0, m_sprite->getContentSize().height / 2));
    body->setCategoryBitmask(sk::bitMask::kMonsterCategory);
    body->setContactTestBitmask(sk::bitMask::kMonsterContact);
    body->setCollisionBitmask(sk::bitMask::kMonsterCollision);
    body->setRotationEnable(false);
    this->setPhysicsBody(body);

    return true;
}

bool Monster::onContactBegin(PhysicsContact &contact)
{
    m_curSpeed = Vec2(0, 0);
    return false;
}

void Monster::move()
{
    if (m_pMoveAnimation)
        m_sprite->runAction(m_pMoveAnimation);
}

