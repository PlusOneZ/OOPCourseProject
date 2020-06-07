/**
*@file Sword.h
*@author 翟晨昊
*@date 6/6/2020
*/
#ifndef _SWORD_H_
#define _SWORD_H_

#include "Weapon.h"

/**
*@brief 初始剑类
*@author 翟晨昊
*/
class Sword :public Weapon {
public:
    CREATE_FUNC(Sword);

	/**
	*@brief 初始
	*@author 翟晨昊
	*/
	bool init();

	/**
	*@brief 近战攻击
	*@author 翟晨昊
	*/
	Animate* attack() override;
protected:
	Vector<SpriteFrame*> actionVec;
};

#endif