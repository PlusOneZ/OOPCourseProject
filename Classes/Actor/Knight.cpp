/**
*@file   Knight.cpp
*@author 肖杨
*@date   5/24/2020
*/
#include"Knight.h"
#include "Item/Gun.h"
#include "Item/Shotgun.h"
#include "Item/Sword.h"

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
		return true;
	}
	else
	{
		return false;
	}
}

double Knight::skill()
{
	return 0;
}

void Knight::skillEnd()
{

}