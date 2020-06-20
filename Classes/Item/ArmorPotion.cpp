/**
*@file ArmorPotion.cpp
*@author 翟晨昊
*@date 6/20/2020
*/
#include "ArmorPotion.h"
#include "../Actor/Hero.h"

static const std::string kArmorPotionMessage = "Armor Potion";
bool ArmorPotion::init()
{
	m_pSprite = Sprite::create("item/ArmorPotion.png");
	this->addChild(m_pSprite);
	generatePhysicalBody(kArmorPotionMessage, sk::tag::kArmorPotion);
	return true;
}

void ArmorPotion::interact()
{
	if (buyItem())
	{
		Hero::getInstance()->addArmor(1);
		log("Armor++");
		this->removeFromParentAndCleanup(true);//用完就释放
		AudioEngine::play2d(sk::files::kTakePotion);
		Hero::setPresentContactItem(nullptr);
	}
}