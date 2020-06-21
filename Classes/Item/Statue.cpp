/**
*@file Statue.cpp
*@author 肖杨
*@date 6/15/2020
*/

#include "Statue.h"

static const std::string kStatueMessage = "use money to enhance yourself";


bool WarStatue::init()
{
	m_pSprite = Sprite::create("item/statue_war.png");
	this->addChild(m_pSprite);
	generatePhysicalBody(kStatueMessage, sk::tag::kWarStatue);
	m_pMessage->setPosition(0., 60.);
	m_damage = 2;
	setShopItem(10);
	return true;
}

void WarStatue::setDamage(int damage)
{
	m_damage = damage;
}

void WarStatue::interact()
{
	if (buyItem())
	{
		Buff::getInstance()->increaseATK(m_damage);
		m_pSprite->getPhysicsBody()->setEnabled(false);
		Hero::setPresentContactItem(nullptr);
		m_pMessage->setVisible(false);
	}
}

bool AssassinStatue::init()
{
	m_pSprite = Sprite::create("item/statue_assassin.png");
	this->addChild(m_pSprite);
	generatePhysicalBody(kStatueMessage, sk::tag::kAssassinStatue);
	m_pMessage->setPosition(0., 60.);
	m_increaseSpeed = 1.2f;
	setShopItem(10);
	return true;
}

void AssassinStatue::setSpeed(float speed)
{
	m_increaseSpeed = speed;
}

void AssassinStatue::interact()
{
	if (buyItem())
	{
		Buff::getInstance()->speedUp(m_increaseSpeed);
		m_pSprite->getPhysicsBody()->setEnabled(false);
		Hero::setPresentContactItem(nullptr);
		m_pMessage->setVisible(false);
	}
}