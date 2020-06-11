//
// Created by Zhengyi on 2020/6/11.
//

#ifndef __MONSTER_BULLETS_H__
#define __MONSTER_BULLETS_H__


#include "Bullet.h"

class MonFiveWayBullet : public Bullet
{
public:
    CREATE_FUNC(MonFiveWayBullet);

    /**
    *@brief 初始化
    *@author 卓正一
    */
    bool init() override;

    /**
    *@brief 子弹攻击
    *@author 卓正一
    */
    void attack(float mouseX, float mouseY, Point pos, int curFacing) override;


};

class MonOneShotBullet : public Bullet
{
public:
    CREATE_FUNC(MonOneShotBullet);

    /**
    *@brief 初始化
    *@author 卓正一
    */
    bool init() override;

    /**
    *@brief 子弹攻击
    *@author 卓正一
    */
    void attack(float mouseX, float mouseY, Point heroPoint, int curFacing) override;
};

#endif // MONSTER_BULLETS_H
