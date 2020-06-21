/**
*@file Coin.cpp
*@author 肖杨
*@date 6/11/2020
*/

#include "Coin.h"
#include "Scene/PauseMenu.h"

bool Coin::init()
{
	m_pSprite = Sprite::create("item/HealthPotion.png");
	m_pSprite->setTag(sk::tag::kCoin);
	auto size = m_pSprite->getContentSize();
	auto body = PhysicsBody::createBox(size);
//	body->setDynamic(false);
	body->setGravityEnable(false);
	body->setCategoryBitmask(sk::bitMask::kItemCategory);
	body->setCollisionBitmask(sk::bitMask::kItemCollision);
	body->setContactTestBitmask(sk::bitMask::kItemContact);
	this->setPhysicsBody(body);
    m_pCoinAnimate = Actor::creatActorAnimate("item/coin_", 7, 9);
	m_pSprite->runAction(m_pCoinAnimate);

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
            Hero::getInstance()->gainCoins(m_coinAmount);
            m_pSprite->stopAllActions();
			this->removeFromParentAndCleanup(true);
            if (gIsEffectPlaying)
    			AudioEngine::play2d(sk::files::kCoin);
			log("coin collected");
		}
	}
	return false;
}

void Coin::setCoinAmount(int amount)
{
	m_coinAmount = amount;
}

void Coin::setTag(int tag)
{
    Node::setTag(tag);
    if (m_pSprite)
        m_pSprite->setTag(tag);
}
