/**
*@file HealthPotion.cpp
*@author 肖杨
*@date 6/4/2020
*/
#include "HealthPotion.h"
#include "../Actor/Hero.h"

bool HealthPotion::init()
{
	m_pSprite = Sprite::create("item/HealthPotion.png");
	m_pSprite->setTag(10);

	auto size = m_pSprite->getContentSize();
	size.width *= 1.8;
	size.height *= 1.8;
	auto body = PhysicsBody::createBox(size);
	body->setDynamic(false);
	body->setGravityEnable(false);
	body->setCategoryBitmask(0x01);
	body->setCollisionBitmask(0x01);
	body->setContactTestBitmask(0x01);
	m_pSprite->setPhysicsBody(body);

	this->addChild(m_pSprite);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(HealthPotion::onContactBegin, this);
	contactListener->onContactSeparate = CC_CALLBACK_1(HealthPotion::onContactSeparate, this);
	contactListener->onContactPreSolve = CC_CALLBACK_1(HealthPotion::voidOnContactPreSolve, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	return true;
}

void HealthPotion::interact()
{
	Hero::m_pPresentHero->recoverHP();
	log("message hide");
	this->removeFromParentAndCleanup(true);//用完就释放
}

bool HealthPotion::onContactBegin(PhysicsContact& contact)
{
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();
	if (nodeA->getTag() == 500 || nodeB->getTag() == 500)//确保其中一个是英雄对象的时候执行
	{
		Hero::m_pPresentContactItem = this;
		log("message");
		//TODO:显示信息
		return true;
	}
	else
	{
		return false;
	}
}

bool HealthPotion::onContactSeparate(PhysicsContact& contact)
{
	Hero::m_pPresentContactItem = nullptr;
	log("message hide");
	//TODO:隐藏信息
	return true;
}
