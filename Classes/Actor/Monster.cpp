//
// Created by Zhengyi on 2020/6/3.
//

#include "Monster.h"


Animate *Monster::creatMonsterAnimate(const std::string &textureName, int num)
{
    if (num <= 0) {
        log("Invalid number in Monster::creatMonsterAnimate: %d", num);
        return nullptr;
    }
    int i = 1;
    SpriteFrame *pFrame = nullptr;
    Vector<SpriteFrame* > frameVec;
    for ( ;i <= num; ++i)
    {
        pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(textureName
                 + std::to_string(i) + ".png");
        if (pFrame != nullptr)
        {
            pFrame->setAnchorPoint(Vec2(0.5, 0.));
            frameVec.pushBack(pFrame);
        }
        else
        {
            log("%s%d not found", textureName.c_str(), i);
        }
    }
    if (frameVec.empty())
        return nullptr;
    auto animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.2f);
    auto action = Animate::create(animation);
    action->retain();
    return action;
}

bool Monster::loadAllAnimate()
{
    static bool isAllLoaded = false;
    if (isAllLoaded)
        return true;

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(sk::files::kYellowCrawPlist,
            sk::files::kYellowCrawPng);

    isAllLoaded = true;
    return true;
}

void Monster::wanderSpeed(float dt)
{
    float xSpeed = RandomHelper::random_real(-1., 1.);
    float ySpeed = RandomHelper::random_real(-1., 1.);
    auto vTemp   = Vec2(xSpeed, ySpeed);
    m_curSpeed   = vTemp / vTemp.getLength() * m_wanderSpeed;
    // TODO 增强随机性
}


void Monster::die()
{
    this->stopAllActions();
    if (m_pDieAnimation == nullptr)
    {
        log("dead animation not available");
        return;
    }
    else
    {
        this->runAction(m_pDieAnimation);
    }
    // TODO 回收怪物
}

void Monster::reduceHealth(int amount)
{
    if (amount > m_curHealth || m_curHealth <= 0)
        die();
    else
        m_curHealth -= amount;
}


