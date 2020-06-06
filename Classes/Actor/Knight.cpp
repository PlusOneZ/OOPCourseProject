/**
*@file   Knight.cpp
*@author 肖杨
*@date   5/24/2020
*/
#include"Knight.h"
#include "Item/Gun.h"

Hero* Hero::m_pPresentHero = nullptr;
Item* Hero::m_pPresentContactItem = nullptr;

bool Knight::init()
{
	m_pMainWeapon = Gun::create();
	m_pMainWeapon->setPosition(Point(this->getPosition().x + 25.0, this->getPosition().y + 20.0));
	this->addChild(m_pMainWeapon);
	m_pMoveAnimate = creatActorAnimate(sk::files::kKnightMove);
	m_pRestAnimate = creatActorAnimate(sk::files::kKnightRest);
	return true;
}

bool Knight::skill()
{
	return true;
}