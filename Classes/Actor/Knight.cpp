/**
*@file Knight.cpp
*@author 肖杨
*@date 2020.5.24
*/
#include"Knight.h"

bool Knight::init()
{
	return true;
}


Animate* Knight::creatMoveAnimate()
{
	return creatHeroAnimate("knight_move");
}

Animate* Knight::creatRestAnimate()
{
	return creatHeroAnimate("knight_rest");
}

void Knight::rest()
{
	m_sprite->runAction(creatRestAnimate());
}

void Knight::move()
{
	m_sprite->runAction(creatMoveAnimate());
}