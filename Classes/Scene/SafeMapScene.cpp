/**
*@file
*SafeMapScene.cpp
*@author 翟晨昊
*/

#include "SafeMapScene.h"
#include "BulletLayer.h"
#include "Const/Const.h"
#include "Item/Gun.h"
#include <iostream>
#include "Component/HeroUI.h"
#include "Item/Statue.h"
#include "Item/Treasure.h"

EventListenerKeyboard* SafeMap::keyBoardListenerOne = nullptr;
EventListenerKeyboard* SafeMap::keyBoardListenerTwo = nullptr;
Scene *SafeMap::createScene()
{
    auto scene = Scene::createWithPhysics();
    auto layer = SafeMap::create();
    scene->addChild(layer);
    scene->getPhysicsWorld()->setGravity(Vec2::ZERO);
    return scene;
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
    auto safeRoom = Sprite::create("interface/hire_room_0.png");
    if (safeRoom == nullptr)
    {
        log("saferoom.png not found");
    }
    else
    {
        safeRoom->setPosition(Vec2(visibleSize.width / 2 + origin.x,
                                   visibleSize.height / 2 + origin.y));
        auto edge = PhysicsBody::createEdgeBox(safeRoom->getContentSize());
        safeRoom->setPhysicsBody(edge);
		edge->setCategoryBitmask(sk::bitMask::kMapCategory);
		edge->setCollisionBitmask(sk::bitMask::kMapCollision);
		edge->setContactTestBitmask(sk::bitMask::kMapContact);
		addChild(safeRoom, 1, sk::bitMask::kMapCategory);
    }

    auto sofa = Sprite::create("sofa.png");
    if (sofa == nullptr)
    {
        log("sofa.png not found");
    }
    else
    {
        sofa->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100.0,
                               visibleSize.height / 2 + origin.y + 150.0));
        addChild(sofa, 3, 100);
    }

    auto carpet = Sprite::create("carpet.png");
    if (carpet == nullptr)
    {
        log("carpet.png not found");
    }
    else
    {
        carpet->setPosition(Vec2(visibleSize.width / 2 + origin.x,
                                 visibleSize.height / 2 + origin.y - 97.0));
        addChild(carpet, 2, 99);
    }

    auto table = Sprite::create("table.png");
    if (table == nullptr)
    {
        log("table.png not found");
    }
    else
    {
        table->setPosition(Vec2(visibleSize.width / 2 + origin.x,
                                visibleSize.height / 2 + origin.y - 97.0));
        addChild(table, 3, 101);
    }

    auto leftChair = Sprite::create("chair1.png");
    if (leftChair == nullptr)
    {
        log("chair1.png not found");
    }
    else
    {
        leftChair->setPosition(Vec2(visibleSize.width / 2 + origin.x - 70.0,
                                    visibleSize.height / 2 + origin.y - 97.0));
        addChild(leftChair, 3, 102);
    }

    auto rightChair = Sprite::create("chair2.png");
    if (rightChair == nullptr)
    {
        log("chair2.png not found");
    }
    else
    {
        rightChair->setPosition(Vec2(visibleSize.width / 2 + origin.x + 70.0,
                                     visibleSize.height / 2 + origin.y - 97.0));
        addChild(rightChair, 3, 101);
    }

    auto fridge = Sprite::create("fridge.png");
    if (fridge == nullptr)
    {
        log("fridge.png not found");
    }
    else
    {
        fridge->setPosition(Vec2(visibleSize.width / 2 + origin.x -270.0,
                                 visibleSize.height / 2 + origin.y + 160.0));
        addChild(fridge, 3, 103);
    }

    auto board = Sprite::create("board.png");
    if (board == nullptr)
    {
        log("board.png not found");
    }
    else
    {
        board->setPosition(Vec2(visibleSize.width / 2 + origin.x + 170.0,
                                visibleSize.height / 2 + origin.y + 270.0));
        addChild(board, 3, 104);
    }

    auto labTable = Sprite::create("labTable.png");
    if (labTable == nullptr)
    {
        log("labTable.png not found");
    }
    else
    {
        labTable->setPosition(Vec2(visibleSize.width / 2 + origin.x + 280.0,
                                   visibleSize.height / 2 + origin.y + 50.0));
        addChild(labTable, 3, 106);
    }

    auto television = Sprite::create("TV.png");
    if (television == nullptr)
    {
        log("TV.png not found");
    }
    else
    {
        television->setPosition(Vec2(visibleSize.width / 2 + origin.x + 300.0,
                                     visibleSize.height / 2 + origin.y - 240.0));
        addChild(television, 3, 105);
    }

    auto part = Sprite::create("part.png");
    if (part == nullptr)
    {
        log("part.png not found");
    }
    else
    {
        part->setPosition(Vec2(visibleSize.width / 2 + origin.x + 300.0,
                               visibleSize.height / 2 + origin.y - 150.0));
        addChild(part, 3, 107);
    }

    auto can = Sprite::create("can.png");
    if (can == nullptr)
    {
        log("can.png not found");
    }
    else
    {
        can->setPosition(Vec2(visibleSize.width / 2 + origin.x - 320.0,
                              visibleSize.height / 2 + origin.y - 230.0));
        addChild(can, 3, 108);
    }

    auto machine = Sprite::create("machine.png");
    if (machine == nullptr)
    {
        log("machine.png not found");
    }
    else
    {
        machine->setPosition(Vec2(visibleSize.width / 2 + origin.x - 320.0,
                                  visibleSize.height / 2 + origin.y + 10.0));
        addChild(machine, 3, 109);
    }

    auto plant = Sprite::create("plant.png");
    if (plant == nullptr)
    {
        log("plant.png not found");
    }
    else
    {
        plant->setPosition(Vec2(visibleSize.width / 2 + origin.x + 150.0,
                                visibleSize.height / 2 + origin.y + 170.0));
        addChild(plant, 3, 110);
    }

    auto box = Sprite::create("box.png");
    if (box == nullptr)
    {
        log("box.png not found");
    }
    else
    {
        box->setPosition(Vec2(visibleSize.width / 2 + origin.x + 200.0,
                              visibleSize.height / 2 + origin.y + 130.0));
        addChild(box, 3, 111);
    }

    auto eggTwist = Sprite::create("eggTwist.png");
    if (eggTwist == nullptr)
    {
        log("eggTwist.png not found");
    }
    else
    {
        eggTwist->setPosition(Vec2(visibleSize.width / 2 + origin.x - 220.0,
                                   visibleSize.height / 2 + origin.y + 160.0));
        addChild(eggTwist, 3, 112);
    }

    auto canBed = Sprite::create("canBed.png");
    if (canBed == nullptr)
    {
        log("canBed.png not found");
    }
    else
    {
        canBed->setPosition(Vec2(visibleSize.width / 2 + origin.x - 200.0,
                                 visibleSize.height / 2 + origin.y - 230.0));
        addChild(canBed, 3, 113);
    }

	addPlayerAssassin();

	Monster::loadAllAnimate();
	auto dm = MonsterWithGun::create();
	dm->generatePhysics(20.f);

	dm->setPosition(500, 500);
	addChild(dm, 5, sk::tag::kMonster);


	HealthPotion* testHP = HealthPotion::create();
	testHP->setPosition(Point(Vec2(visibleSize.width / 2 + origin.x + 75.0,
		visibleSize.height / 2 + origin.y)));
	testHP->setShopItem(1);
	this->addChild(testHP, 3, sk::tag::kHealthPotion);

    Weapon* testWeapon = Gun::create();
    testWeapon->setPosition(Point(Vec2(visibleSize.width / 2 + origin.x + 75.0,
        visibleSize.height / 2 + origin.y - 150.0)));
    testWeapon->setState(false);
    testWeapon->setTag(sk::tag::kGunWeapon);
    this->addChild(testWeapon, 3, sk::tag::kGunWeapon);

	Coin* testCoin = Coin::create();
	testCoin->setCoinAmount(20);
	testCoin->setPosition(Point(Vec2(visibleSize.width / 2 + origin.x,
		visibleSize.height / 2 + origin.y)));
	this->addChild(testCoin, 3, sk::tag::kCoin);

	Treasure* testTreasure = Treasure::create();
	testTreasure->setPosition(Point(Vec2(visibleSize.width / 2 + origin.x - 150.0,
		visibleSize.height / 2 + origin.y + 75)));
	testTreasure->setShopItem(5);
	this->addChild(testTreasure, 3, sk::tag::kTreasure);

	FreezeTrap* testFreeze = FreezeTrap::create();
	testFreeze->setPosition(Point(Vec2(visibleSize.width / 2 + origin.x - 150.0,
		visibleSize.height / 2 + origin.y)));
	this->addChild(testFreeze, 3, sk::tag::kFreezeTrap);

	FlameTrap* testFlame = FlameTrap::create();
	testFlame->setTrapTime(8);
	testFlame->setPosition(Point(Vec2(visibleSize.width / 2 + origin.x - 150.0,
		visibleSize.height / 2 + origin.y - 75.0)));
	this->addChild(testFlame, 3, sk::tag::kFlameTrap);

	WarStatue* testWar = WarStatue::create();
	testWar->setPosition(Point(Vec2(visibleSize.width / 2 + origin.x - 150.0,
		visibleSize.height / 2 + origin.y - 200.0)));
	this->addChild(testWar, 3, sk::tag::kWarStatue);

	AssassinStatue* testSpeed = AssassinStatue::create();
	testSpeed->setPosition(Point(Vec2(visibleSize.width / 2 + origin.x - 100.0,
		visibleSize.height / 2 + origin.y - 200.0)));
	this->addChild(testSpeed, 3, sk::tag::kAssassinStatue);

	HeroUI* testUI = HeroUI::create();
	testUI->setPosition(118.5f, 661.5f);
	this->addChild(testUI, 5, sk::tag::kHeroUI);

    Board* informationBoard = Board::create();
    informationBoard->setPosition(Point(Vec2(visibleSize.width / 2 + origin.x + 100.0,
        visibleSize.height / 2 + origin.y - 225.0)));
    this->addChild(informationBoard, 3, sk::tag::kBoard);
    auto keyBoardListenerBoard = EventListenerKeyboard::create();
    keyBoardListenerBoard->onKeyPressed = CC_CALLBACK_2(Board::onKeyPressed, informationBoard);
    //keyBoardListenerBoard->onKeyReleased = CC_CALLBACK_2(Board::onKeyReleased, informationBoard);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyBoardListenerBoard, this);
    keyBoardListenerBoard->setEnabled(false);
    SafeMap::keyBoardListenerTwo = keyBoardListenerBoard;
    
    return true;
}


void SafeMap::addPlayerKnight()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto fig = AutoPolygon::generatePolygon("Actor/knight_rest1.png");
	Sprite* knightSprite = Sprite::create(fig);
	if (knightSprite == nullptr)
	{
		log("knight_rest1.png not found");
	}
	else
	{
		Knight* knight = Knight::create();
		knight->bindSprite(knightSprite);
		knight->generatePhysics();
		knight->setPosition(Point(Vec2(visibleSize.width / 2 + origin.x + 75.0,
			visibleSize.height / 2 + origin.y + 150.0)));
		this->addChild(knight, 4, sk::tag::kHero);
		knight->rest();

        BulletLayer* bulletLayer = BulletLayer::create();
        bulletLayer->retain();
        bulletLayer->bindHero(knight);
        this->addChild(bulletLayer, 8, 450);

//		MoveController* moveController = MoveController::create();
//		this->addChild(moveController);
//		knight->setMoveController(moveController);
//		//这里在安全地图不应该加载这个控制器，为了调试方便先加上
//		AttackController* attackController = AttackController::create();
//		this->addChild(attackController);
//		knight->setAttackController(attackController);

        auto keyBoardListenerKnight = EventListenerKeyboard::create();
        keyBoardListenerKnight->onKeyPressed = CC_CALLBACK_2(Hero::onKeyPressed, knight);
        keyBoardListenerKnight->onKeyReleased = CC_CALLBACK_2(Hero::onKeyReleased, knight);

        _eventDispatcher->addEventListenerWithSceneGraphPriority(keyBoardListenerKnight, this);
        SafeMap::keyBoardListenerOne = keyBoardListenerKnight;
	}
}

void SafeMap::addPlayerAssassin()
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
		assassin->generatePhysics();
		assassin->setPosition(Point(Vec2(visibleSize.width / 2 + origin.x + 75.0,
			visibleSize.height / 2 + origin.y + 150.0)));
		this->addChild(assassin, 4, sk::tag::kHero);
		assassin->rest();

		BulletLayer* bulletLayer = BulletLayer::create();
		bulletLayer->retain();
		bulletLayer->bindHero(assassin);
		this->addChild(bulletLayer, 8, 450);

		auto keyBoardListenerAssassin = EventListenerKeyboard::create();
		keyBoardListenerAssassin->onKeyPressed = CC_CALLBACK_2(Hero::onKeyPressed, assassin);
		keyBoardListenerAssassin->onKeyReleased = CC_CALLBACK_2(Hero::onKeyReleased, assassin);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(keyBoardListenerAssassin, this);
        SafeMap::keyBoardListenerOne = keyBoardListenerAssassin;
	}
}

void Board::interact()
{
    SafeMap::keyBoardListenerOne->setEnabled(false);
    SafeMap::keyBoardListenerTwo->setEnabled(true);
    m_pMessage->setVisible(false);
    m_message.at(0)->setVisible(true);
}

void Board::controlListener()
{
    SafeMap::keyBoardListenerOne->setEnabled(true);
    SafeMap::keyBoardListenerTwo->setEnabled(false);
    m_message.at(curNumber)->setVisible(false);
    m_pMessage->setVisible(true);
    curNumber = 0;
}
