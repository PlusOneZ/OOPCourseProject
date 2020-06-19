/**
*@file SwordBullet.h
*@author 翟晨昊
*@date 6/13/2020
*/
#ifndef __SWORDBULLET_H__
#define __SWORDBULLET_H__

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
	void attack(float mouseX, float mouseY, Point heroPoint, int curFacing, Node *p_sprite) override;
protected:
	Vector<SpriteFrame*> m_rightActionVec;
    Vector<SpriteFrame*> m_leftActionVec;
};

#endif
