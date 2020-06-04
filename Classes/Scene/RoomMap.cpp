/**
*@file
*RoomMap.cpp
*@author 李嘉树
*/

#include "RoomMap.h"

Scene* RoomMap::createScene(TMXTiledMap* map)
{
    auto pRef = RoomMap::create(map);
    return pRef;
}

RoomMap* RoomMap::create(TMXTiledMap* map)
{
    auto* pRet = new(std::nothrow) RoomMap(map);
    if (pRet)
    {
        if (pRet->init())
        {
            pRet->autorelease();
            return pRet;
        }
    }
    delete pRet;
    pRet = nullptr;
    return nullptr;
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
        m_pMap->setPosition(Vec2(10, 10));
        this->addChild(m_pMap, 1, 99);
    }

    auto edgeMap = Sprite::create("map/SafeMap.png");
    auto mapFrame = PhysicsBody::createEdgeBox(edgeMap->getContentSize());
    edgeMap->setPhysicsBody(mapFrame);
    edgeMap->setVisible(false);
    this->addChild(edgeMap, 0, 98);

    createBarrier();
    closeDoor();
    addPlayer(this);

    return true;
}

void RoomMap::createBarrier()
{
    auto group = m_pMap->getObjectGroup("barrier");
    ValueVector barrierObjects = group->getObjects();

    for (auto barrier : barrierObjects) {
        ValueMap& dict = barrier.asValueMap();
        float x = dict["x"].asFloat();
        float y = dict["y"].asFloat();
        float width = dict["width"].asFloat();
        float height = dict["height"].asFloat();

        PhysicsBody* tmpPhysicsBody = PhysicsBody::createBox(Size(width, height));
        tmpPhysicsBody->setDynamic(false);
        Sprite* tmpSprite = Sprite::create();
        tmpSprite->setPosition(Vec2(x, y));
        tmpSprite->setAnchorPoint(Vec2::ZERO);
        tmpSprite->setContentSize(Size(width, height));
        tmpSprite->setPhysicsBody(tmpPhysicsBody);
        this->addChild(tmpSprite);
    }
}

void RoomMap::closeDoor()
{
    auto group = m_pMap->getObjectGroup("door");
    ValueVector doorObjects = group->getObjects();

    for (auto door : doorObjects) {
        ValueMap& dict = door.asValueMap();
        float x = dict["x"].asFloat();
        float y = dict["y"].asFloat();
        float width = dict["width"].asFloat();
        float height = dict["height"].asFloat();

        PhysicsBody* tmpPhysicsBody = PhysicsBody::createBox(Size(width, height));
        tmpPhysicsBody->setDynamic(false);
        Sprite* tmpSprite = Sprite::create();
        tmpSprite->setPosition(Vec2(x, y));
        tmpSprite->setAnchorPoint(Vec2::ZERO);
        tmpSprite->setContentSize(Size(width, height));
        tmpSprite->setPhysicsBody(tmpPhysicsBody);
        this->addChild(tmpSprite);
    }
}

void RoomMap::openDoor()
{

}

void RoomMap::createEnemy()
{

}

void RoomMap::addPlayer(RoomMap* pMap)
{

}