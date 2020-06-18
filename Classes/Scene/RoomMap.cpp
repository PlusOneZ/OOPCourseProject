/**
*@file
*RoomMap.cpp
*@author 李嘉树
*/

#include "RoomMap.h"
#include "Actor/Knight.h"

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
        this->addChild(m_pMap, 0, 99);
    }

    ifDoor = false;

    createBarrier();
    //createDoor();

	if (Hero::m_pPresentHero == nullptr)
	{
		addPlayer(sk::HeroID::kAssassin);
	}

    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(RoomMap::onContactBegin, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

    HeroUI* testUI = HeroUI::create();
    testUI->setPosition(118.5f, 661.5f);
    this->addChild(testUI, 5, sk::tag::kHeroUI);

    Monster::loadAllAnimate();
    auto dm1 = MonsterWithGun::create();
    dm1->generatePhysics(20.f);

    dm1->setPosition(500, 400);
    this->addChild(dm1, 9, sk::tag::kMonster);

    auto dm2 = MonsterWithGun::create();
    dm2->generatePhysics(20.f);

    dm2->setPosition(700, 400);
    this->addChild(dm2, 9, sk::tag::kMonster);

    auto dm3 = MonsterCrawShoot::create();
    dm3->generatePhysics(20.f);

    dm3->setPosition(300, 200);
    this->addChild(dm3, 9, sk::tag::kMonster);

    auto dm4 = MonsterCrawShoot::create();
    dm4->generatePhysics(20.f);

    dm4->setPosition(900, 200);
    this->addChild(dm4, 9, sk::tag::kMonster);

    this->scheduleUpdate();

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

        this->addChild(tmpSprite, 2, sk::tag::kBarrier);
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

        this->addChild(tmpSprite, 2, sk::tag::kDoor);
    }
}

bool RoomMap::onContactBegin(PhysicsContact& contact)
{
    auto nodeA = contact.getShapeA()->getBody()->getNode();
    auto nodeB = contact.getShapeB()->getBody()->getNode();
    if (nodeA != nullptr && nodeB != nullptr)
    {
        if ((nodeA->getTag() == sk::tag::kHero && nodeB->getTag()== sk::tag::kDoor)
            || (nodeB->getTag() == sk::tag::kHero && nodeA->getTag() == sk::tag::kDoor))
        {
            m_mapNumber++;
            auto map = createTiled(m_mapNumber);
            if (!map)
            {
                return false;
            }
            auto nextRoom = createScene(map);
			auto hero = Hero::m_pPresentHero;
			hero->retain();
			hero->removeFromParentAndCleanup(false);
			hero->setPosition(640.f, 100.f);
			hero->generatePhysics();
			nextRoom->addChild(Hero::m_pPresentHero, 3);
			auto keyBoardListener = EventListenerKeyboard::create();
			keyBoardListener->onKeyPressed = CC_CALLBACK_2(Hero::onKeyPressed, hero);
			keyBoardListener->onKeyReleased = CC_CALLBACK_2(Hero::onKeyReleased, hero);
			_eventDispatcher->addEventListenerWithSceneGraphPriority(keyBoardListener, nextRoom);

			BulletLayer* bulletLayer = BulletLayer::create();
			bulletLayer->retain();
			bulletLayer->bindHero(hero);
			nextRoom->addChild(bulletLayer, 8, 450);
            Director::getInstance()->replaceScene(nextRoom);

            return true;
        }
        if ((nodeA->getTag() == sk::tag::kHero && nodeB->getTag() == sk::tag::kBarrier)
            || (nodeB->getTag() == sk::tag::kHero && nodeA->getTag() == sk::tag::kBarrier))
        {
            if (nodeA->getTag() == sk::tag::kHero)
            {
                auto v = nodeA->getPhysicsBody()->getVelocity();
                nodeA->getPhysicsBody()->setVelocity(-v);
                return true;
            }
            else
            {
                auto v = nodeB->getPhysicsBody()->getVelocity();
                nodeB->getPhysicsBody()->setVelocity(-v);
                return true;
            }
        }
        if ((nodeA->getTag() == sk::tag::kMonster && nodeB->getTag() == sk::tag::kBarrier)
            || (nodeB->getTag() == sk::tag::kMonster && nodeA->getTag() == sk::tag::kBarrier))
        {
            if (nodeA->getTag() == sk::tag::kMonster)
            {
                auto v = nodeA->getPhysicsBody()->getVelocity();
                nodeA->getPhysicsBody()->setVelocity(-v);
                return true;
            }
            else
            {
                auto v = nodeB->getPhysicsBody()->getVelocity();
                nodeB->getPhysicsBody()->setVelocity(-v);
                return true;
            }
        }
    }
    return false;
}

void RoomMap::addPlayer(sk::HeroID id)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	PolygonInfo fig;
	Hero* hero;
	if (id == sk::HeroID::kAssassin)
	{
		fig = AutoPolygon::generatePolygon("Actor/assassin_rest1.png");
	}
	else
	{
		fig = AutoPolygon::generatePolygon("Actor/knight_rest1.png");
	}
	Sprite* heroSprite = Sprite::create(fig);

	if (heroSprite == nullptr)
	{
		log("hero picture not found");
	}
	else
	{
		if (id == sk::HeroID::kAssassin)
		{
			hero = Assassin::create();
		}
		else
		{
			hero = Knight::create();
		}
		hero->bindSprite(heroSprite);
		hero->generatePhysics();
		hero->setPosition(640.f, 500.f);
		this->addChild(hero, 4, sk::tag::kHero);
		hero->rest();

		BulletLayer* bulletLayer = BulletLayer::create();
		bulletLayer->retain();
		bulletLayer->bindHero(hero);
		this->addChild(bulletLayer, 8, sk::tag::kBulletLayer);

		auto keyBoardListenerHero = EventListenerKeyboard::create();
		keyBoardListenerHero->onKeyPressed = CC_CALLBACK_2(Hero::onKeyPressed, hero);
		keyBoardListenerHero->onKeyReleased = CC_CALLBACK_2(Hero::onKeyReleased, hero);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(keyBoardListenerHero, this);
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

void RoomMap::update(float dt)
{
    auto node = this->getChildByTag(sk::tag::kMonster);
    if (node == nullptr)
    {
        if (!ifDoor)
        {
            Treasure* testTreasure = Treasure::create();
            testTreasure->setPosition(640, 200);
            this->addChild(testTreasure, 3, sk::tag::kTreasure);
            createDoor();
            ifDoor = true;
        }
    }
}