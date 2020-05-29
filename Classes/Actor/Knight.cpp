/**
*@file   Knight.cpp
*@author 肖杨
*@date   5/24/2020
*/
#include"Knight.h"

Hero* Hero::pPresentHero = nullptr;

bool Knight::init()
{
	m_pMoveAnimate = creatMoveAnimate();
	m_pRestAnimate = creatRestAnimate();
	return true;
}


Animate* Knight::creatMoveAnimate()
{
	return creatHeroAnimate(sk::files::kKnightMove);
}

Animate* Knight::creatRestAnimate()
{
	return creatHeroAnimate(sk::files::kKnightRest);
}

void Knight::rest()
{
	m_sprite->runAction(m_pRestAnimate);
}

void Knight::move()
{
	m_sprite->stopAction(m_pRestAnimate);
	m_sprite->runAction(m_pMoveAnimate);
}

void Knight::stopMove()
{
	m_sprite->stopAction(m_pMoveAnimate);
}

bool Knight::skill()
{
	return true;
}