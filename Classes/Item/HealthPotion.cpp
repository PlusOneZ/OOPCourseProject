﻿/**
*@file HealthPotion.cpp
*@author 肖杨
*@date 6/4/2020
*/
#include "HealthPotion.h"
#include "../Actor/Hero.h"

static const std::string kHealthPotionMessage = "Health Potion";
bool HealthPotion::init()
{
	m_pSprite = Sprite::create("item/HealthPotion.png");
	m_pSprite->setTag(sk::tag::kHealthPotionTag);

	auto size = m_pSprite->getContentSize();
	size.width *= 1.3;
	size.height *= 1.2;
	auto body = PhysicsBody::createBox(size);
	body->setDynamic(false);
	body->setGravityEnable(false);
	body->setCategoryBitmask(sk::bitMask::kItemCategory);
	body->setCollisionBitmask(sk::bitMask::kItemCollision);
	body->setContactTestBitmask(sk::bitMask::kItemContact);
	m_pSprite->setPhysicsBody(body);

	this->addChild(m_pSprite);

	m_pMessage = showMessage(kHealthPotionMessage);
	m_pMessage->setVisible(false);
	m_pMessage->setPosition(this->getPosition().x,this->getPosition().y+40);
	this->addChild(m_pMessage);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(HealthPotion::onContactBegin, this);
	contactListener->onContactSeparate = CC_CALLBACK_1(Item::onContactSeparate, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
	this->setShopItem(1);
	return true;
}

void HealthPotion::interact()
{
	if (buyItem())
	{
		Hero::m_pPresentHero->recoverHP(2);
		log("HP++");
		this->removeFromParentAndCleanup(true);//用完就释放
	}
}

bool HealthPotion::onContactBegin(PhysicsContact& contact)
{
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();
	if (nodeA != nullptr && nodeB != nullptr)
	{
		if ((nodeA->getTag() == sk::tag::kHero || nodeB->getTag() == sk::tag::kHero)
			&& (nodeA->getTag() == sk::tag::kHealthPotionTag || nodeB->getTag() == sk::tag::kHealthPotionTag))
			//确保其中一个是英雄一个是血瓶的时候执行
		{
			if (Hero::m_pPresentContactItem == nullptr)
			{
				Hero::m_pPresentContactItem = this;
				m_pMessage->setVisible(true);
				if (m_ifShopItem)
				{
					m_pShopMessage->setVisible(true);
				}
			}
		}
	}
	return false;
}
