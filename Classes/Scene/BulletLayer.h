/**
*@file BulletLayer.h
*@author 翟晨昊
*@date 2020.5.30
*/
#ifndef _BULLETLAYER_H_
#define _BULLETLAYER_H_

#include "Actor/Hero.h"
#include "Item/Bullet.h"
#include <vector>
#include <ctime>

/*
*@brief 子弹层
*@author 翟晨昊
*/
class BulletLayer :public cocos2d::Layer {
public:
	CREATE_FUNC(BulletLayer);

	/*
	*@brief 初始化
	*@author 翟晨昊
	*/
	bool init();

	/**
	*@brief 将当前英雄加入子弹层 
	*@author 翟晨昊
	*/
	void bindHero(Hero* pNowHero);

	/**
	*@brief 绑定每帧操作
	*@author 翟晨昊
	*/
	void update(float dt);

	/*
	*@brief 鼠标按下后的操作
	*@author 翟晨昊
	*/
    bool onMouseDown(Event* event);

private:
	Hero*            m_pHero;
    clock_t          m_lastShotTime;
	Vector<Bullet* > m_pWeaponBullet;
	SpriteBatchNode* m_pBulletBatchNode;
};

#endif