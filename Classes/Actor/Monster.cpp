//
// Created by Zhengyi on 2020/6/3.
//

#include "Monster.h"

bool Monster::init()
{
    scheduleUpdate();
    return true;
}

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
        pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(textureName + std::to_string(i));
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

void Monster::wander()
{

}

void Monster::follow()
{

}

void Monster::die()
{

}

void Monster::reduceHealth(int amount)
{

}


