/**
*@file
*RoomMap.cpp
*@author 李嘉树
*/

#include "RoomMap.h"

Scene* RoomMap::createScene(TMXTiledMap* map)
{
	auto pRef = RoomMap::create();
	pRef->m_pMap = map;
	return pRef;
}

bool RoomMap::init()
{
    if (!Scene::init())
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    if (m_pMap == nullptr)
    {
		log("tile map not found");
    }
    else
    {
		m_pMap->setAnchorPoint(Vec2::ZERO);
		m_pMap->setPosition(Vec2(10,10));
        addChild(m_pMap, 0, 99);
    }

    closeDoor();
    addPlayer(this);

    return true;
}