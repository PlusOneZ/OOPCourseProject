/**
*@file Bullet.h
*@author 翟晨昊
*@date 5/30/2020
*/
#ifndef _BULLET_H_
#define _BULLET_H_

#include "cocos2d.h"

using namespace cocos2d;

/**
*@brief 子弹类
*@author 翟晨昊
*/
class Bullet :public Node {
public:

	/**
	*@brief 子弹攻击
	*@author 翟晨昊
	*/
	virtual void attack(float mouseX, float mouseY, Point heroPoint) = 0;

	/**
	*@brief 获取子弹速度
	*@author 翟晨昊
	*/
	float getSpeed();

	/**
	*@brief 设置子弹速度
	*@author 翟晨昊
	*/
	void setSpeed(float speed);

	/**
	*@brief 绑定图像
	*@author 翟晨昊
	*/
	void bindSprite(Sprite* pSprite);

protected:

	Sprite* m_pBulletSprite;
	float   m_bulletSpeed;
	bool    m_isArrive;
	void moveEnd();
};
#endif