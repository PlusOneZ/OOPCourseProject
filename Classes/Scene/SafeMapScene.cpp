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

    auto map = TMXTiledMap::create("map/testmap.tmx");
    if (map == nullptr)
    {
        log("map/test2.tmx not found.");
    }
    else
    {
        map->setAnchorPoint(Vec2::ZERO);
        map->setPosition(Vec2(300, 300));
        addChild(map, 0, 99); // with a tag of '99'
    }


    return true;
}

