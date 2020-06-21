/**
*@file   Assassin.cpp
*@author 肖杨
*@date   6/9/2020
*/
#include "Assassin.h"
#include "Item/Shotgun.h"
#include "Item/Spear.h"
#include "Component/Buff.h"

bool Assassin::init()
{
	if (m_pPresentHero == nullptr)
	{
		m_pPresentHero = this;
		scheduleUpdate();
		setMainWeapon(Shotgun::create());
		setSecondWeapon(Spear::create());
		m_pSecWeapon->setVisible(false);
		m_pMoveAnimate = creatActorAnimate("Actor/assassin_move", 46, 54);
		m_pRestAnimate = creatActorAnimate("Actor/assassin_rest", 50, 54);
		m_pSkillAnimate = creatActorAnimate("Actor/assassin_skill", 52, 56);
		m_pSkillTempA = m_pMoveAnimate;
		m_pSkillTempB = m_pRestAnimate;
		m_maxArmor = 3;
		m_armor = 3;
		m_ID = sk::HeroID::kAssassin;
		return true;
	}
	else
	{
		return false;
	}
}

float Assassin::skill()
{
	if (m_ifMoved)
	{
		stopMove();
	}
	else
	{
		m_sprite->stopAction(m_pRestAnimate);
	}
	m_pMoveAnimate = m_pSkillAnimate;
	m_pRestAnimate = m_pSkillAnimate;
	rest();
	if (m_ifMoved)
	{
		move();
	}
	Buff::HeroBuff->immortal();
	Buff::HeroBuff->speedUp(m_speedUP);
	return m_skillLastTime;
}

void Assassin::skillEnd()
{
	m_sprite->stopAction(m_pSkillAnimate);
	m_pMoveAnimate = m_pSkillTempA;
	m_pRestAnimate = m_pSkillTempB;
	rest();
	if (m_ifMoved)
	{
		move();
	}
	Buff::HeroBuff->immortalEnd();
	Buff::HeroBuff->speedUpEnd(m_speedUP);
}