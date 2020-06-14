/**
*@file SwordBullet.h
*@author 翟晨昊
*@date 6/13/2020
*/
#ifndef _SWORDBULLET_H_
#define _SWORDLBULLET_H_

#include "Bullet.h"

/**
*@brief 剑攻击
*@author 翟晨昊
*/
class SwordBullet :public Bullet {
public:
	CREATE_FUNC(SwordBullet);

	/**
	*@brief 初始化
	*@author 翟晨昊
	*/
	bool init() override;

	/**
	*@brief 子弹攻击
	*@author 翟晨昊
	*/
	void attack(float mouseX, float mouseY, Point heroPoint, int curFacing) override;
protected:
	Vector<SpriteFrame*> actionVec;
};

#endif
