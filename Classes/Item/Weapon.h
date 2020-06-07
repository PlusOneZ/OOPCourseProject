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
	virtual Bullet* createBullet();

	virtual Animate* attack();

	/**
	*@brief 获取武器发射速度
	*@author 翟晨昊
	*/
	float getInterval();

	/**
	*@brief 获取武器一次发射几枚子弹
	*@author 翟晨昊
	*/
	int getBulletCount();

	/**
	*@brief 设置武器发射速度
	*@author 翟晨昊
	*/
	void setInterval(float interval);

	/**
	*@brief 设置武器一次发射几枚子弹
	*@author 翟晨昊
	*/
	void setBulletCount(int count);

protected:
	float m_attackInterval;
	int m_bulletCount;
};
#endif // !_WEAPON_H_

