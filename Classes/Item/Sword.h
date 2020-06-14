/**
*@file Sword.h
*@author 翟晨昊
*@date 6/6/2020
*/
#ifndef _SWORD_H_
#define _SWORD_H_

#include "Weapon.h"

static const std::string kSwordMessage = "Sword";
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
	bool init() override;

	/**
    *@brief 创造子弹
    *@author 翟晨昊
    */
	Bullet* createBullet() override;
};

#endif
