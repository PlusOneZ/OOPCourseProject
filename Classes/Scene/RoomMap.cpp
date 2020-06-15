/**
*@file
*RoomMap.cpp
*@author 李嘉树
*/

#include "RoomMap.h"

int RoomMap::m_mapNumber = 1;

Scene* RoomMap::createScene(TMXTiledMap* map)
{
    auto scene = Scene::createWithPhysics();
    auto layer = RoomMap::create(map);
    scene->addChild(layer);
    scene->getPhysicsWorld()->setGravity(Vec2::ZERO);
    return scene;
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
    createDoor();

    addPlayerAssassin();
    
    //this->addChild(Hero::m_pPresentHero, 3, kHeroTag);
    //Hero::m_pPresentHero->setPosition(Vec2(900, 300));

    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(RoomMap::onContactBegin, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

    /*
    auto keyBoardListener = EventListenerKeyboard::create();
    keyBoardListener->onKeyPressed = CC_CALLBACK_2(Hero::onKeyPressed, Hero::m_pPresentHero);
    keyBoardListener->onKeyReleased = CC_CALLBACK_2(Hero::onKeyReleased, Hero::m_pPresentHero);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyBoardListener, this);
    */
    

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
        tmpPhysicsBody->setCategoryBitmask(sk::bitMask::kMapCategory);
        tmpPhysicsBody->setCollisionBitmask(sk::bitMask::kMapCollision);
        tmpPhysicsBody->setContactTestBitmask(sk::bitMask::kMapContact);

        Sprite* tmpSprite = Sprite::create();
        tmpSprite->setPosition(Vec2(x, y));
        tmpSprite->setAnchorPoint(Vec2::ZERO);
        tmpSprite->setContentSize(Size(width, height));
        tmpSprite->setPhysicsBody(tmpPhysicsBody);

        this->addChild(tmpSprite, 2, 200);
    }
}

void RoomMap::createDoor()
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
        tmpPhysicsBody->setCategoryBitmask(sk::bitMask::kDoorCategory);
        tmpPhysicsBody->setCollisionBitmask(sk::bitMask::kDoorCollision);
        tmpPhysicsBody->setContactTestBitmask(sk::bitMask::kDoorContact);

        Sprite* tmpSprite = Sprite::create();
        tmpSprite->setPosition(Vec2(x, y));
        tmpSprite->setAnchorPoint(Vec2::ZERO);
        tmpSprite->setContentSize(Size(width, height));
        tmpSprite->setPhysicsBody(tmpPhysicsBody);

        this->addChild(tmpSprite, 2, 300);
    }
}

bool RoomMap::onContactBegin(PhysicsContact& contact)
{
    auto nodeA = contact.getShapeA()->getBody()->getNode();
    auto nodeB = contact.getShapeB()->getBody()->getNode();
    if (nodeA != nullptr && nodeB != nullptr)
    {
        if ((nodeA->getTag() == sk::tag::kHero && nodeB->getTag()==300)
            || (nodeB->getTag() == sk::tag::kHero && nodeA->getTag() == 300))
        {
            m_mapNumber++;
            //Hero::m_pPresentHero->retain();
            //this->removeChildByTag(kHeroTag);
            auto map = createTiled(m_mapNumber);
            if (!map)
            {
                return false;
            }
            auto nextRoom = createScene(map);
            Director::getInstance()->replaceScene(nextRoom);
            return true;
        }
    }
    return false;
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
        this->myHero = assassin;
        assassin->generatePhysics();
        assassin->setPosition(Vec2(640, 200));
        this->addChild(assassin, 3, sk::tag::kHero);
        assassin->rest();

        auto keyBoardListener = EventListenerKeyboard::create();
        keyBoardListener->onKeyPressed = CC_CALLBACK_2(Hero::onKeyPressed, assassin);
        keyBoardListener->onKeyReleased = CC_CALLBACK_2(Hero::onKeyReleased, assassin);

        _eventDispatcher->addEventListenerWithSceneGraphPriority(keyBoardListener, this);
    }
}

TMXTiledMap* RoomMap::createTiled(int mapNumber)
{
    if (mapNumber == 1) return TMXTiledMap::create("map/BirthRoom.tmx");
    if (mapNumber == 2) return TMXTiledMap::create("map/MonsterRoom1.tmx");
    if (mapNumber == 3) return TMXTiledMap::create("map/MonsterRoom2.tmx");
    if (mapNumber == 4) return TMXTiledMap::create("map/ShopRoom.tmx");
    if (mapNumber == 5) return TMXTiledMap::create("map/BossRoom.tmx");
    return nullptr;
}