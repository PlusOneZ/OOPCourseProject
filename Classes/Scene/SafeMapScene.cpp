//
// Created by Zhengyi on 2020/5/8.
//

#include "SafeMapScene.h"
#include <iostream>

cocos2d::Scene *SafeMap::createScene()
{
    return SafeMap::create();
}

bool SafeMap::init()
{
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto map = TMXTiledMap::create("/Users/plusone/Desktop/Coding/CPP_proj/SoulKnight/Resources/sm2.tmx");
    if (map == nullptr)
    {
        log("map/test2.tmx not found.");
    }
    else
    {
        map->setAnchorPoint(Vec2(1, 0));
        map->setPosition(Vec2(960, 0));
        addChild(map, 0, 99); // with a tag of '99'

    }

    auto test = Sprite::create("/Users/plusone/Desktop/Coding/CPP_proj/SoulKnight/Resources/Resource/1.1.png");
    if (test == nullptr)
    {
        log("1.1.png not found");
    }
    else
    {
        test->setPosition(300, 200);
        addChild(test, 1, 98);
    }

    return true;
}

