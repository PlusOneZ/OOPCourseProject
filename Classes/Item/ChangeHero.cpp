/**
*@file ChangeHero.cpp
*@author 肖杨
*@date 6/17/2020
*/
#include "ChangeHero.h"
#include "Scene/SafeMapScene.h"
#include "Component/HeroUI.h"


static const std::string kChangeToKnight = "change to knight";
static const std::string kChangeToAssassin = "change to assassin";

bool ChangeHero::init()
{
	if (Hero::getInstance()->getHeroID() == sk::HeroID::kAssassin)
	{
		m_ID = sk::HeroID::kKnight;
		m_pSprite = Sprite::create("Actor/knight_down.png");
		this->addChild(m_pSprite);
		generatePhysicalBody(kChangeToKnight, sk::tag::kChangeHero);
	}
	else
	{
		m_ID = sk::HeroID::kAssassin;
		m_pSprite = Sprite::create("Actor/assassin_down.png");
		this->addChild(m_pSprite);
		generatePhysicalBody(kChangeToAssassin, sk::tag::kChangeHero);
	}
	return true;
}

void ChangeHero::interact()
{
	SafeMap* pMap;
	pMap = dynamic_cast<SafeMap*>(Hero::getInstance()->getParent());
	if (pMap != nullptr)
	{
		pMap->getChildByTag(sk::tag::kHeroUI)->removeFromParentAndCleanup(true);
		pMap->getChildByTag(sk::tag::kBulletLayer)->removeFromParentAndCleanup(true);
		pMap->keyBoardListenerOne->setEnabled(false);
		pMap->removeKeyboard(Hero::getInstance());
        Hero::getInstance()->unscheduleUpdate();

        Hero::getInstance()->removeFromParentAndCleanup(true);
        Hero::clearPresentHero();

		pMap->addPlayer(m_ID);
		Hero::setPresentContactItem(nullptr);

		this->removeFromParentAndCleanup(true);

		auto testUI = HeroUI::create();
		testUI->setPosition(118.5f, 661.5f);
		pMap->addChild(testUI, 5, sk::tag::kHeroUI);

		auto newChangeHero = ChangeHero::create();
		newChangeHero->setPosition(920, 360);
		pMap->addChild(newChangeHero, 3, sk::tag::kChangeHero);
	}
}