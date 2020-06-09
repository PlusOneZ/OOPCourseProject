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

    ifMove = false;

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

    return true;
}

void RoomMap::createBarrier()
{
    auto group = m_pMap->getObjectGroup("barrier");
    ValueVector barrierObjects = group->getObjects();

    for (auto barrier : barrierObjects) 
    {
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

    for (auto door : doorObjects) 
    {
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

        auto contactListener = EventListenerPhysicsContact::create();
        contactListener->onContactBegin = CC_CALLBACK_1(RoomMap::onContactBegin, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

        this->addChild(tmpSprite);
    }
}

bool RoomMap::onContactBegin(PhysicsContact& contact)
{
    auto nodeA = contact.getShapeA()->getBody()->getNode();
    auto nodeB = contact.getShapeB()->getBody()->getNode();
    if (nodeA != nullptr && nodeB != nullptr)
    {
        if (nodeA->getTag() == kHeroTag || nodeB->getTag() == kHeroTag)
        {
            ifMove = true;
        }
    }
    return false;
}

bool RoomMap::ifMoveToAnotherRoom()
{
    return ifMove;
}

void RoomMap::moveStatusChange()
{
    ifMove = false;
}

void RoomMap::addPlayerAssassin()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto fig = AutoPolygon::generatePolygon("Actor/assassin_rest1.png");
    Sprite* assassinSprite = Sprite::create(fig);
    if (assassinSprite == nullptr)
    {
        log("assassin_rest1.png not found");
    }
    else
    {
        Assassin* assassin = Assassin::create();
        assassin->bindSprite(assassinSprite);
        Hero::m_pPresentHero = assassin;
        assassin->generatePhysics();
        assassin->setPosition(Point(Vec2(visibleSize.width / 2 + origin.x + 75.0,
            visibleSize.height / 2 + origin.y + 150.0)));
        this->addChild(assassin, 3, kHeroTag);
        assassin->rest();

        auto keyBoardListener = EventListenerKeyboard::create();
        keyBoardListener->onKeyPressed = CC_CALLBACK_2(Hero::onKeyPressed, assassin);
        keyBoardListener->onKeyReleased = CC_CALLBACK_2(Hero::onKeyReleased, assassin);

        _eventDispatcher->addEventListenerWithSceneGraphPriority(keyBoardListener, this);
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