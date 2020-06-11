/**
*@file   Buff.h
*@author 肖杨
*@date   6/10/2020
*/

#ifndef _BUFF_H_
#define _BUFF_H_

#include "Actor/Hero.h"

/**
*@brief buff类
*@author 肖杨
*@details 里面的所有buff都对应：一个实现函数，一个终止函数和一个判断buff是否还持续的成员
*/
class Buff
{
private:
	int m_immortal = 0;

	int m_speedUP = 0;

	double m_rootedTime = 0;

public:

	void immortal()
	{
		Hero::m_pPresentHero->m_ifMortal = false;
		log("immortal");
		m_immortal++;
	}

	void immortalEnd()
	{
		if (m_immortal > 0)
		{
			Hero::m_pPresentHero->m_ifMortal = true;
			m_immortal--;
		}
	}

	void speedUp(float up)
	{
		Hero::m_pPresentHero->m_speed *= up;
		log("speedup");
		m_speedUP++;
	}

	void speedUpEnd()
	{
		if (m_speedUP > 0)
		{
			Hero::m_pPresentHero->m_speed =kHeroSpeed;
			log("speedup end");
			m_speedUP--;
		}
	}

	void rooted(double rootedTime)
	{
		Hero::m_pPresentHero->m_speed = 0;
		auto freeze = Sprite::create("item/freeze_effect.png");
		freeze->setTag(sk::tag::kFreezeTrap);
		Hero::m_pPresentHero->addChild(freeze);
		log("rooted");
		m_rootedTime = m_rootedTime > rootedTime ? m_rootedTime : rootedTime;
	}

	void rootedEnd(double rootedTime)
	{
		if (m_rootedTime - rootedTime <= 0.1)
		{
			Hero::m_pPresentHero->m_speed = kHeroSpeed;
			m_rootedTime = 0;
			log("rooted end");
			auto freeze = Hero::m_pPresentHero->getChildByTag(sk::tag::kFreezeTrap);
			freeze->removeFromParentAndCleanup(true);
		}
		else
		{
			m_rootedTime -= rootedTime;
		}
	}


}static HeroBuff;

#endif // !_BUFF_H_

