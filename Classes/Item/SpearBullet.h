/**
*@file SpearBullet.h
*@author 翟晨昊
*@date 6/19/2020
*/
#ifndef __SPEARBULLET_H__
#define __SPEARBULLET_H__

#include "Bullet.h"

/**
*@brief 长枪攻击
*@author 翟晨昊
*/
class SpearBullet :public Bullet {
public:
	CREATE_FUNC(SpearBullet);

	/**
	*@brief 初始化
	*@author 翟晨昊
	*/
	bool init() override;

	/**
	*@brief 子弹攻击
	*@author 翟晨昊
	*/
	void attack(float mouseX, float mouseY, Point heroPoint, int curFacing, Node* p_sprite) override;
protected:
	Vector<SpriteFrame*> m_rightActionVec;
	Vector<SpriteFrame*> m_leftActionVec;
};

#endif