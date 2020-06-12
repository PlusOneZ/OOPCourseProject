/**
*@file   Assassin.cpp
*@author 肖杨
*@date   6/9/2020
*/
#include "Assassin.h"
#include "Item/Shotgun.h"
#include "Item/Sword.h"
#include "Buff.h"

bool Assassin::init()
{
	if (m_pPresentHero == nullptr)
	{
		m_pPresentHero = this;
		scheduleUpdate();
		setMainWeapon(Shotgun::create());
		setSecondWeapon(Sword::create());
		m_pSecWeapon->setVisible(false);
		m_pMoveAnimate = creatActorAnimate("Actor/assassin_move");
		m_pRestAnimate = creatActorAnimate("Actor/assassin_rest");
		m_pSkillAnimate = creatActorAnimate("Actor/assassin_skill");
		m_pSkillTempA = m_pMoveAnimate;
		m_pSkillTempB = m_pRestAnimate;
		return true;
	}
	else
	{
		return false;
	}
}

double Assassin::skill()
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
	HeroBuff.immortal();
	HeroBuff.speedUp(m_speedUP);
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
	HeroBuff.immortalEnd();
	HeroBuff.speedUpEnd(m_speedUP);
}