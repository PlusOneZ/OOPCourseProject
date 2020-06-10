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
*@details 里面的所有buff都对应：一个实现函数，一个终止函数和一个判断buff是否还存在的成员
*/
class Buff
{
private:
	bool m_immortal = false;
	bool m_speedUP = false;
public:
	void removeAllBuff()
	{
		immortalEnd();
	}

	void immortal()
	{
		Hero::m_pPresentHero->m_ifMortal = false;
		log("immortal");
		m_immortal = true;
	}

	void immortalEnd()
	{
		if (m_immortal)
		{
			Hero::m_pPresentHero->m_ifMortal = true;
			m_immortal = false;
		}
	}

	void speedUP(float up)
	{
		Hero::m_pPresentHero->m_speed *= up;
		log("speedup");
		m_speedUP = true;
	}

	void speedUPEnd(float up)
	{
		if (m_speedUP)
		{
			Hero::m_pPresentHero->m_speed /= up;
			m_speedUP = false;
		}
	}

}HeroBuff;

#endif // !_BUFF_H_

