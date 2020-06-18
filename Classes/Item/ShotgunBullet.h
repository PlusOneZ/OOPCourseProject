/**
*@file ShotgunBullet.h
*@author 翟晨昊
*@date 6/6/2020
*/
#ifndef _SHOTGUNBULLET_H_
#define _SHOTGUNBULLET_H_

#include "Bullet.h"


/**
	*@brief 霰弹枪子弹
	*@author 翟晨昊
	*/
class ShotgunBullet :public Bullet {
public:
	CREATE_FUNC(ShotgunBullet);

	/**
	*@brief 初始化
	*@author 翟晨昊
	*/
	bool init() override;

	/**
	*@brief 子弹攻击
	*@author 翟晨昊
	*/
	void attack(float mouseX, float mouseY, Point heroPoint, int curFacing, Node *p_sprite) override;

	/**
	*@brief 子弹攻击路径
	*@author 翟晨昊
	*/
	void launchPath(float k, float shootDirection);
};

#endif