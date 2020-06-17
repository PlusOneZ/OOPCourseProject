/**
*@file ChangeHero.h
*@author 肖杨
*@date 6/17/2020
*/
#ifndef _CHANGE_HERO_H_
#define _CHANGE_HERO_H_

#include "Item.h"

/**
*@brief 仅用来更换英雄
*@author 肖杨
*/
class ChangeHero :public Item
{
public:
	/**
	*@brief 生成一个倒下的英雄
	*@author 肖杨
	*/
	bool init()override;

	/**
	*@brief 和倒下的英雄交换
	*@author 肖杨
	*/
	void interact()override;

	CREATE_FUNC(ChangeHero)
protected:
	sk::HeroID m_ID;
};



#endif // !_CHANGE_HERO_H_

