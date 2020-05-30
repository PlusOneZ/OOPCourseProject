/**
*@file Weapon.h
*@author 翟晨昊
*@date 5/30/2020
*/

#ifndef _WEAPON_H_
#define _WEAPON_H_

#include"Item.h"
#include"Bullet.h"

using namespace cocos2d;

/**
*@brief 武器类
*@author 翟晨昊
*/
class Weapon :public Item
{
public:

	/**
	*@brief 创造一枚子弹
	*@author 翟晨昊
	*/
	virtual Bullet* createBullet() = 0;

	/**
	*@brief 获取武器发射速度
	*@author 翟晨昊
	*/
	float getInterval();

	/**
	*@brief 设置武器发射速度
	*@author 翟晨昊
	*/
	void setInterval(float interval);
protected:
	float shootInterval;
};
#endif // !_WEAPON_H_

