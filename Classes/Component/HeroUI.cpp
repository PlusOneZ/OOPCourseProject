/**
*@file   HeroUI.cpp
*@author 肖杨
*@date   6/14/2020
*/

#include "HeroUI.h"

bool HeroUI::init()
{
	m_pSprite = Sprite::create("item/ui/ui_board.png");
	this->addChild(m_pSprite, 1);

	m_pHero = Hero::m_pPresentHero;
	m_presentHP = m_pHero->m_HP;
	m_presentArmor = m_pHero->m_armor;
	m_presntCoin = m_pHero->m_coinNumber;

	m_pHealth = ProgressTimer::create(Sprite::create("item/ui/ui_health_bar.png"));
	m_pHealth->setPosition(16.5f, 33.f);
	m_pHealth->setType(ProgressTimer::Type::BAR);
	m_pHealth->setMidpoint(Point(0, 0.5));
	m_pHealth->setBarChangeRate(Point(1, 0));
	m_pHealth->setPercentage(100.f);
	this->addChild(m_pHealth, 2);

	m_pArmor = ProgressTimer::create(Sprite::create("item/ui/ui_armor_bar.png"));
	m_pArmor->setPosition(16.5f, 3.f);
	m_pArmor->setType(ProgressTimer::Type::BAR);
	m_pArmor->setMidpoint(Point(0, 0.5));
	m_pArmor->setBarChangeRate(Point(1, 0));
	m_pArmor->setPercentage(100.f);
	this->addChild(m_pArmor, 2);

	std::string healthMessage = std::to_string(m_pHero->m_HP) + "/" + std::to_string(m_pHero->m_maxHP);
	m_pHealthMessage = Label::createWithTTF(healthMessage, "Font/IRANYekanBold.ttf", 18.f);
	m_pHealthMessage->setPosition(16.5f, 33.f);
	this->addChild(m_pHealthMessage, 3);

	std::string armorMessage = std::to_string(m_pHero->m_armor) + "/" + std::to_string(m_pHero->m_maxArmor);
	m_pArmorMessage= Label::createWithTTF(armorMessage, "Font/IRANYekanBold.ttf", 18.f);
	m_pArmorMessage->setPosition(16.5f, 3.f);
	this->addChild(m_pArmorMessage, 3);

	std::string coinMessage = std::to_string(m_pHero->m_coinNumber);
	m_pCoinMessage=Label::createWithTTF(coinMessage, "Font/IRANYekanBold.ttf", 18.f);
	m_pCoinMessage->setPosition(8.f, -27.f);
	this->addChild(m_pCoinMessage, 3);

	schedule(CC_SCHEDULE_SELECTOR(HeroUI::scheduleUI), 0.1f);

	return true;
}

void HeroUI::scheduleUI(float dt)
{
	if (m_pHero->m_HP != m_presentHP)
	{
		m_presentHP = m_pHero->m_HP;
		m_pHealth->setPercentage((float)m_pHero->m_HP / m_pHero->m_maxHP * 100);
		std::string healthMessage = std::to_string(m_pHero->m_HP) + "/" + std::to_string(m_pHero->m_maxHP);
		m_pHealthMessage->setString(healthMessage);
	}

	if (m_pHero->m_armor != m_presentArmor)
	{
		m_presentArmor = m_pHero->m_armor;
		m_pArmor->setPercentage((float)m_pHero->m_armor / m_pHero->m_maxArmor * 100);
		std::string armorMessage = std::to_string(m_pHero->m_armor) + "/" + std::to_string(m_pHero->m_maxArmor);
		m_pArmorMessage->setString(armorMessage);
	}

	if (m_pHero->m_coinNumber != m_presntCoin)
	{
		m_presntCoin = m_pHero->m_coinNumber;
		std::string coinMessage = std::to_string(m_pHero->m_coinNumber);
		m_pCoinMessage->setString(coinMessage);
	}
}

void HeroUI::changeHero(Hero* newHero)
{
	m_pHero = newHero;
}