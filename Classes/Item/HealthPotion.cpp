/**
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
	this->addChild(m_pSprite);
	generatePhysicalBody(kHealthPotionMessage, sk::tag::kHealthPotion);
	this->setShopItem(1);
	return true;
}

void HealthPotion::interact()
{
	if (buyItem())
	{
        Hero::m_pPresentHero->recoverHealth(2);
		log("HP++");
		this->removeFromParentAndCleanup(true);//用完就释放
		AudioEngine::play2d(sk::files::kTakePotion);
	}
}
