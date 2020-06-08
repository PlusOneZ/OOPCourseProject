/**
*@file   Assassin.cpp
*@author 肖杨
*@date   6/9/2020
*/
#include "Assassin.h"
#include "Item/Shotgun.h"
#include "Item/Sword.h"

bool Assassin::init()
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
	m_pMoveAnimate = creatActorAnimate("Actor/assassin_move");
	m_pRestAnimate = creatActorAnimate("Actor/assassin_rest");
	m_pSkillAnimate = creatActorAnimate("Actor/assassin_skill");
	m_pSkillTempA = m_pMoveAnimate;
	m_pSkillTempB = m_pRestAnimate;
	return true;
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
	m_ifMortal = false;
	return 1.;
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
	m_ifMortal = true;
}