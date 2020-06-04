/**
*@file Gun.h
*@author 翟晨昊
*@date 5/30/2020
*/
#ifndef _GUN_H_
#define _GUN_H_

#include "Weapon.h"

using namespace cocos2d;

/**
*@brief 初始手枪类
*@author 翟晨昊
*/
class Gun :public Weapon {
public:

	/**
	*@brief 创造子弹
	*@author 翟晨昊
	*/
	Bullet* createBullet() override;

	/**
	*@brief 初始
	*@author 翟晨昊
	*/
	bool init() override;
	CREATE_FUNC(Gun);
};
#endif