/**
*@file Weapon.h
*@author 翟晨昊
*@date 5/30/2020
*/

#ifndef _WEAPON_H_
#define _WEAPON_H_

#include "Item.h"
#include "Bullet.h"
#include "AudioEngine.h"

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
	*@brief 获取状态
	*@author 翟晨昊
	*/
	bool getState();

	/**
	*@brief 获取攻击力
	*@author 翟晨昊
	*/
	int getDamage();

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


	/**
	*@brief 判断是否被持有
	*@author 翟晨昊
	*/
	void setState(bool isInHand);

	/**
	*@brief 设置攻击力
	*@author 翟晨昊
	*/
	void setDamage(int ATK);

	/**
	*@brief 与手中武器交换
	@@author 肖杨
	*/
	void interact() override ;
	//TODO:与地面武器交换

protected:

    Sprite * m_weaponSprite = nullptr;

	float m_attackInterval;
	int   m_bulletCount;
	bool  m_isInHand = false;
	int   m_weaponDamage;
};
#endif // !_WEAPON_H_
