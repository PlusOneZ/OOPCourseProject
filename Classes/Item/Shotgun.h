/**
*@file Shotgun.h
*@author 翟晨昊
*@date 6/6/2020
*/
#ifndef _SHOTGUN_H_
#define _SHOTGUN_H_

#include "Weapon.h"
#include "Scene/PauseMenu.h"

using namespace cocos2d;

static const std::string kShotgunMessage = "Shotgun";
/**
*@brief 初始霰弹枪类
*@author 翟晨昊
*/
class Shotgun :public Weapon {
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
	CREATE_FUNC(Shotgun);
};

#endif

