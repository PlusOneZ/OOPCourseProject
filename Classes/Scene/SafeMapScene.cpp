﻿/**
*@file
*SafeMapScene.cpp
*@author 翟晨昊
*/

#include "SafeMapScene.h"
#include <iostream>

Scene *SafeMap::createScene()
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
    auto safeRoom = Sprite::create("saferoom.png");
    if (safeRoom == nullptr)
    {
        log("saferoom.png not found");
    }
    else
    {
        safeRoom->setPosition(Vec2(visibleSize.width / 2 + origin.x,
                                   visibleSize.height / 2 + origin.y));
        addChild(safeRoom, 1, 98);
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

	addPlayerKnight(this);

    return true;
}


void SafeMap::addPlayerKnight(SafeMap* pMap)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Sprite* knightSprite = Sprite::create("Actor/knight_rest1.png");
	if (knightSprite == nullptr)
	{
		log("knight_rest1.png not found");
	}
	else
	{
		Knight* knight = Knight::create();
		knight->retain();
		Hero::pPresentHero = knight;
		knight->bindSprite(knightSprite);
		knight->setPosition(Point(Vec2(visibleSize.width / 2 + origin.x + 75.0,
			visibleSize.height / 2 + origin.y + 150.0)));
		pMap->addChild(knight, 3, 500);
		knight->rest();

		MoveController* moveController = MoveController::create();
		this->addChild(moveController);
		knight->setMoveController(moveController);
		//这里在安全地图不应该加载这个控制器，为了调试方便先加上
		AttackController* attackController = AttackController::create();
		this->addChild(attackController);
		knight->setAttackController(attackController);
	}
}

