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
        this->addChild(m_pMap, 0, 99);
    }

    ifDoor = false;

    createBarrier();

    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(RoomMap::onContactBegin, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

    HeroUI* testUI = HeroUI::create();
    testUI->setPosition(118.5f, 661.5f);
    this->addChild(testUI, 5, sk::tag::kHeroUI);

    if (m_mapNumber == 2 || m_mapNumber == 6)
    {
        Monster::loadAllAnimate();
        auto dm1 = createMonsterRand();
        dm1->generatePhysics(20.f);

        dm1->setPosition(500, 370);
        this->addChild(dm1, 9, sk::tag::kMonster);

        auto dm2 = createMonsterRand();
        dm2->generatePhysics(20.f);

        dm2->setPosition(700, 370);
        this->addChild(dm2, 9, sk::tag::kMonster);

        auto dm3 = createMonsterRand();
        dm3->generatePhysics(20.f);

        dm3->setPosition(300, 200);
        this->addChild(dm3, 9, sk::tag::kMonster);

        auto dm4 = createMonsterRand();
        dm4->generatePhysics(20.f);

        dm4->setPosition(900, 200);
        this->addChild(dm4, 9, sk::tag::kMonster);

        FreezeTrap* testFreeze = FreezeTrap::create();
        testFreeze->setPosition(200, 400);
        this->addChild(testFreeze, 3, sk::tag::kFreezeTrap);

        FreezeTrap* testFreeze1 = FreezeTrap::create();
        testFreeze1->setPosition(900, 200);
        testFreeze1->getChildByTag(sk::tag::kFreezeTrap)->setTag(sk::tag::kFreezeTrap + 50);
        this->addChild(testFreeze1, 3, sk::tag::kFreezeTrap + 50);

        AssassinStatue* testSpeed = AssassinStatue::create();
        testSpeed->setPosition(880, 500);
        this->addChild(testSpeed, 3, sk::tag::kAssassinStatue);
    }
    else if (m_mapNumber == 3 || m_mapNumber == 7)
    {
        Monster::loadAllAnimate();
        auto dm1 = createMonsterRand();
        dm1->generatePhysics(20.f);

        dm1->setPosition(500, 370);
        this->addChild(dm1, 9, sk::tag::kMonster);

        auto dm2 = createMonsterRand();
        dm2->generatePhysics(20.f);

        dm2->setPosition(700, 400);
        this->addChild(dm2, 9, sk::tag::kMonster);

        auto dm3 = createMonsterRand();
        dm3->generatePhysics(20.f);

        dm3->setPosition(300, 200);
        this->addChild(dm3, 9, sk::tag::kMonster);

        auto dm4 = createMonsterRand();
        dm4->generatePhysics(20.f);

        dm4->setPosition(900, 200);
        this->addChild(dm4, 9, sk::tag::kMonster);

        FlameTrap* testFlame = FlameTrap::create();
        testFlame->setPosition(200, 400);
        this->addChild(testFlame, 3, sk::tag::kFlameTrap);

        FlameTrap* testFlame1 = FlameTrap::create();
        testFlame1->setPosition(900, 200);
        testFlame1->getChildByTag(sk::tag::kFlameTrap)->setTag(sk::tag::kFlameTrap + 50);
        this->addChild(testFlame1, 3, sk::tag::kFlameTrap + 50);

        WarStatue* testWar = WarStatue::create();
        testWar->setPosition(400, 600);
        this->addChild(testWar, 3, sk::tag::kWarStatue);
    }
    else if (m_mapNumber == 5 || m_mapNumber == 8)
    {
        int randNumber = cocos2d::random(1, 2);
        if (randNumber == 1)
        {
            auto potion = HealthPotion::create();
            potion->setPosition(440, 280);
            potion->setShopItem(5);
            this->addChild(potion, 10, sk::tag::kHealthPotion);
        }
        else
        {
            auto potion = ArmorPotion::create();
            potion->setPosition(440, 280);
            potion->setShopItem(5);
            this->addChild(potion, 10, sk::tag::kArmorPotion);
        }
        randNumber = cocos2d::random(1, 2);
        if (randNumber == 1)
        {
            auto potion = Gun::create();
            potion->setPosition(640, 250);
            potion->setShopItem(5);
            this->addChild(potion, 10, sk::tag::kGunWeapon);
        }
        else
        {
            auto potion = Shotgun::create();
            potion->setPosition(640, 250);
            potion->setShopItem(5);
            this->addChild(potion, 10, sk::tag::kShotgunWeapon);
        }
        randNumber = cocos2d::random(1, 2);
        if (randNumber == 1)
        {
            auto potion = Sword::create();
            potion->setPosition(840, 280);
            potion->setShopItem(5);
            this->addChild(potion, 10, sk::tag::kSwordWeapon);
        }
        else
        {
            auto potion = Spear::create();
            potion->setPosition(840, 280);
            potion->setShopItem(5);
            this->addChild(potion, 10, sk::tag::kSpearWeapon);
        }
    }
    else if (m_mapNumber == 4 || m_mapNumber == 9)
    {
        Monster::loadAllAnimate();
        auto dm1 = createMonsterRand();
        dm1->generatePhysics(20.f);

        dm1->setPosition(640, 600);
        this->addChild(dm1, 9, sk::tag::kMonster);

        auto dm2 = createMonsterRand();
        dm2->generatePhysics(20.f);

        dm2->setPosition(300, 360);
        this->addChild(dm2, 9, sk::tag::kMonster);

        auto dm3 = createMonsterRand();
        dm3->generatePhysics(20.f);

        dm3->setPosition(980, 360);
        this->addChild(dm3, 9, sk::tag::kMonster);
    }

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
            if (m_mapNumber == 10)
            {
                return true;
            }
            auto map = createTiled(m_mapNumber);
            if (!map)
            {
                return false;
            }
            auto nextRoom = createScene(map);
			auto hero = Hero::getInstance();
			hero->retain();
			hero->removeFromParentAndCleanup(false);
			hero->setPosition(640.f, 100.f);
			hero->generatePhysics();
			nextRoom->addChild(Hero::getInstance(), 3);
			auto keyBoardListener = EventListenerKeyboard::create();
			keyBoardListener->onKeyPressed = CC_CALLBACK_2(Hero::onKeyPressed, hero);
			keyBoardListener->onKeyReleased = CC_CALLBACK_2(Hero::onKeyReleased, hero);
			_eventDispatcher->addEventListenerWithSceneGraphPriority(keyBoardListener, nextRoom);

			BulletLayer* bulletLayer = BulletLayer::create();
			bulletLayer->retain();
			bulletLayer->bindHero(hero);
			nextRoom->addChild(bulletLayer, 8, 450);
            Director::getInstance()->replaceScene(nextRoom);

			Buff::HeroBuff->flamingEnd();
			Buff::HeroBuff->flamingEnd();
			Buff::HeroBuff->rootedEnd(100.f);

            return true;
        }
        if ((nodeA->getTag() == sk::tag::kHero && nodeB->getTag() == sk::tag::kBarrier)
            || (nodeB->getTag() == sk::tag::kHero && nodeA->getTag() == sk::tag::kBarrier))
        {
            auto p = nodeA->getPosition();
            auto v = nodeA->getPhysicsBody()->getVelocity();
            v.normalize();
            if (nodeA->getTag() == sk::tag::kHero)
            {
                nodeA->setPosition(-50*v);
                nodeA->getPhysicsBody()->setVelocity(-10*v);
                return true;
            }
            else
            {
                nodeB->setPosition(-50*v);
                nodeB->getPhysicsBody()->setVelocity(-10*v);
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

TMXTiledMap* RoomMap::createTiled(int mapNumber)
{
    if (mapNumber == 1) return TMXTiledMap::create("map/BirthRoom.tmx");
    if (mapNumber == 2) return TMXTiledMap::create("map/MonsterRoom1.tmx");
    if (mapNumber == 3) return TMXTiledMap::create("map/MonsterRoom2.tmx");
    if (mapNumber == 4) return TMXTiledMap::create("map/BossRoom.tmx");
    if (mapNumber == 5) return TMXTiledMap::create("map/ShopRoom.tmx");
    if (mapNumber == 6) return TMXTiledMap::create("map/MonsterRoom1.tmx");
    if (mapNumber == 7) return TMXTiledMap::create("map/MonsterRoom2.tmx");
    if (mapNumber == 8) return TMXTiledMap::create("map/ShopRoom.tmx");
    if (mapNumber == 9) return TMXTiledMap::create("map/BossRoom.tmx");
    return nullptr;
}

void RoomMap::update(float dt)
{
    if (m_mapNumber == 10)
    {
        auto hero = Hero::getInstance();
        hero->die();
    }
    auto node = this->getChildByTag(sk::tag::kMonster);
    if (node == nullptr)
    {
        if (!ifDoor)
        {
            if (m_mapNumber == 2 || m_mapNumber == 3
                || m_mapNumber == 4 || m_mapNumber == 6
                || m_mapNumber == 7)
            {
                Treasure* testTreasure = Treasure::create();
                testTreasure->setPosition(640, 200);
                this->addChild(testTreasure, 3, sk::tag::kTreasure);
            }
            if (m_mapNumber == 4 || m_mapNumber == 9)
            {
                auto transferGate = Sprite::create("map/transfergate.png");
                transferGate->setPosition(600, 320);
                transferGate->setAnchorPoint(Vec2::ZERO);
                this->addChild(transferGate, 6);
            }
            createDoor();
            ifDoor = true;
        }
    }
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
        hero->setPosition(Point(Vec2(visibleSize.width / 2 + origin.x + 75.0,
            visibleSize.height / 2 + origin.y + 150.0)));
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

Monster* RoomMap::createMonsterRand()
{
    int randNumber = cocos2d::random(1, 4);
    if (randNumber == 1)
    {
        return MonsterSnow::create();
    }
    else if (randNumber == 2)
    {
        return MonsterPig::create();
    }
    else if (randNumber == 3)
    {
        return MonsterCrawShoot::create();
    }
    else if (randNumber == 4)
    {
        return MonsterWithGun::create();
    }
}
