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

	int m_speedUp = 0;

	double m_rootedTime = 0;

	int m_increaseDamage = 0;

	int m_flaming = 0;

	Animate* m_pFlaming;

	static Buff* HeroBuff;
public:
	Buff()
	{
		m_pFlaming = creatBuffAnimate("item/flame_effect");
		HeroBuff = this;
	}

	Buff &operator=(Buff& ) = default;

	Animate* creatBuffAnimate(const char * pAnimateName);
	
	void immortal();
	
	void immortalEnd();

	void speedUp(float up);
	
	void speedUpEnd(float up);
	
	void rooted(double rootedTime);
	
	void rootedEnd(double rootedTime);

	void increaseATK(int amount);
	
	void increaseATKEnd(int amount);

	void flaming();	

	void flamingEnd();

	static Buff* getInstance();
};


#endif // !_BUFF_H_

