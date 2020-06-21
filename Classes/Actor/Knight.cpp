/**
*@file   Knight.cpp
*@author 肖杨
*@date   5/24/2020
*/
#include"Knight.h"
#include "Item/Gun.h"
#include "Item/Shotgun.h"
#include "Item/Sword.h"
#include "Component/Buff.h"

bool Knight::init()
{
	if (m_pPresentHero == nullptr)
	{
		m_pPresentHero = this;
		scheduleUpdate();
		setMainWeapon(Shotgun::create());
		setSecondWeapon(Sword::create());
		m_pSecWeapon->setVisible(false);
		m_pMoveAnimate = creatActorAnimate(sk::files::kKnightMove);
		m_pRestAnimate = creatActorAnimate(sk::files::kKnightRest);
		m_skillCD = 15;
		m_skillTime = 15;
		m_skillLastTime = 5;
		m_ID = sk::HeroID::kKnight;
		return true;
	}
	else
	{
		return false;
	}
}

float Knight::skill()
{
	Buff::getInstance()->increaseATK(m_increaseAmount);
	return m_skillLastTime;
}

void Knight::skillEnd()
{
	Buff::getInstance()->increaseATKEnd(m_increaseAmount);
}