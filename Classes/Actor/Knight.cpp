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
	auto fig = AutoPolygon::generatePolygon("item/swordaction1.png");
	Sprite* swordSprite = Sprite::create(fig);
	m_pMainWeapon = Sword::create();
	m_pMainWeapon->bindSprite(swordSprite);
	m_pMainWeapon->setPosition(Point(this->getPosition().x + 20.0, this->getPosition().y + 20.0));
	m_pSecWeapon = Shotgun::create();
	m_pSecWeapon->setPosition(Point(this->getPosition().x + 20.0, this->getPosition().y + 20.0));
	this->addChild(m_pMainWeapon, 2);
	this->addChild(m_pSecWeapon, 2);
	m_pSecWeapon->setVisible(false);
	m_pMoveAnimate = creatActorAnimate(sk::files::kKnightMove);
	m_pRestAnimate = creatActorAnimate(sk::files::kKnightRest);
	return true;
}

double Knight::skill()
{
	return 0;
}

void Knight::skillEnd()
{

}