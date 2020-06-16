/**
*@file Treasure.cpp
*@author 肖杨
*@date 6/16/2020
*/

#include "Treasure.h"
#include "HealthPotion.h"
#include "Gun.h"
#include "Shotgun.h"
#include "Sword.h"
#include "Actor/Hero.h"

static const std::string kTreasureMessage = "get an unknown item";

bool Treasure::init()
{
	m_pSprite = Sprite::create("item/treasure_closed.png");
	this->addChild(m_pSprite);
	generatePhysicalBody(kTreasureMessage, sk::tag::kTreasure);

	return true;
}

void Treasure::interact()
{
	m_pSprite->removeFromParentAndCleanup(true);
	m_pSprite = Sprite::create("item/treasure_opened.png");
	this->addChild(m_pSprite);
	m_pMessage->setVisible(false);

	int TagNumber = cocos2d::random(10, 13);
	switch (TagNumber)
	{
	case 10:m_pUnknownItem = HealthPotion::create(); break;
	case 11:m_pUnknownItem = Gun::create(); break;
	case 12:m_pUnknownItem = Shotgun::create(); break;
	case 13:m_pUnknownItem = Sword::create(); break;
	default:log("treasureitem not found"); break;
	}

	if (m_pUnknownItem != nullptr)
	{
		m_pUnknownItem->setPosition(getPosition().x, getPosition().y - 20.f);
		this->getScene()->addChild(m_pUnknownItem, 3, TagNumber);
	}

	Hero::m_pPresentContactItem = nullptr;

}