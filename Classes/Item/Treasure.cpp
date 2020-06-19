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
	if (buyItem())
	{
		m_pSprite->removeFromParentAndCleanup(true);
		m_pSprite = Sprite::create("item/treasure_opened.png");
		this->addChild(m_pSprite);
		m_pMessage->setVisible(false);

		int TagNumber = cocos2d::random(1001, 1003);
		switch (TagNumber)
		{
		case 1001:m_pUnknownItem = HealthPotion::create(); break;
		case 1002:m_pUnknownItem = Gun::create(); break;
		case 1003:m_pUnknownItem = Shotgun::create(); break;
		case 1004:m_pUnknownItem = Sword::create(); break;
		default:log("treasureitem not found"); break;
		}

		while (this->getParent()->getChildByTag(TagNumber) != nullptr)
		{
			TagNumber += 50;
		}


		if (m_pUnknownItem != nullptr)
		{
			m_pUnknownItem->getSprite()->setTag(TagNumber);
			m_pUnknownItem->setPosition(getPosition().x, getPosition().y - 20.f);
			this->getParent()->addChild(m_pUnknownItem, 3, TagNumber);
		}

		Hero::setPresentContactItem(nullptr);
	}
}