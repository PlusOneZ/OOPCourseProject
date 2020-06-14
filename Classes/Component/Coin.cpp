/**
*@file Coin.cpp
*@author 肖杨
*@date 6/11/2020
*/

#include "Coin.h"

Animate* Coin::pCoinAnimate = Actor::creatActorAnimate("item/coin_",7,9);

bool Coin::init()
{
	m_pSprite = Sprite::create("item/HealthPotion.png");
	m_pSprite->setTag(sk::tag::kCoin);
	auto size = m_pSprite->getContentSize();
	auto body = PhysicsBody::createBox(size);
	body->setDynamic(false);
	body->setGravityEnable(false);
	body->setCategoryBitmask(sk::bitMask::kItemCategory);
	body->setCollisionBitmask(sk::bitMask::kItemCollision);
	body->setContactTestBitmask(sk::bitMask::kItemContact);
	m_pSprite->setPhysicsBody(body);
	m_pSprite->runAction(pCoinAnimate);

	this->addChild(m_pSprite);


	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Coin::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	return true;
}

bool Coin::onContactBegin(PhysicsContact& contact)
{
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();

	if (nodeA != nullptr && nodeB != nullptr)
	{
		if ((nodeA->getTag() == sk::tag::kHero || nodeB->getTag() == sk::tag::kHero)
			&& (nodeA->getTag() == this->getTag() || nodeB->getTag() == this->getTag()))
			//确保其中一个是英雄一个是金币的时候执行
		{
			Hero::m_pPresentHero->gainCoins(m_coinAmount);
			this->removeFromParentAndCleanup(true);
			log("coin collected");
		}
	}
	return false;
}

void Coin::setCoinAmount(int amount)
{
	m_coinAmount = amount;
}