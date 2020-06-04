/**
*@file NormalBullet.h
*@author 翟晨昊
*@date 5/30/2020
*/
#ifndef _NORMALBULLET_H_
#define _NORMALBULLET_H_

#include "Bullet.h"

class NormalBullet :public Bullet {
public:
	CREATE_FUNC(NormalBullet);

	/**
	*@brief 初始化
	*@author 翟晨昊
	*/
	bool init() override;

	/**
	*@brief 子弹攻击
	*@author 翟晨昊
	*/
	void attack(float mouseX, float mouseY, Point heroPoint) override;
};

#endif