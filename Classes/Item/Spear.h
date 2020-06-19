/**
*@file Spear.h
*@author 翟晨昊
*@date 6/19/2020
*/
#ifndef _SPEAR_H_
#define _SPEAR_H_

#include "Weapon.h"

static const std::string kSpearMessage = "Spear";
/**
*@brief 初始剑类
*@author 翟晨昊
*/
class Spear :public Weapon {
public:
	CREATE_FUNC(Spear);

	/**
	*@brief 初始
	*@author 翟晨昊
	*/
	bool init() override;

	/**
	*@brief 创造子弹
	*@author 翟晨昊
	*/
	Bullet* createBullet() override;
};

#endif

