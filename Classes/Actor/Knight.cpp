/**
*@file   Knight.cpp
*@author 肖杨
*@date   5/24/2020
*/
#include"Knight.h"

bool Knight::init()
{
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
	m_sprite->runAction(creatRestAnimate());
}

void Knight::move()
{
	m_sprite->runAction(creatMoveAnimate());
}