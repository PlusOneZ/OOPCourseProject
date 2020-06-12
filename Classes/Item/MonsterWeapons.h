//
// Created by Zhengyi on 2020/6/11.
//

#ifndef __MONSTER_WEAPONS_H__
#define __MONSTER_WEAPONS_H__

#include "Bullet.h"
#include "Weapon.h"
#include "MonsterBullets.h"


class MonInvisibleWithFiveWayGun : public Weapon {
public:

    CREATE_FUNC(MonInvisibleWithFiveWayGun);

    /**
    *@brief  创造子弹
    *@author 卓正一
    */
    Bullet* createBullet() override;


    /**
    *@brief  初始化
    *@author 卓正一
    */
    bool init() override;

protected:
    void attackFromTo(Point from, Point to, int facing, Node *pBulletLayer);
};

class MonOneShotGun : public Weapon {
public:

    CREATE_FUNC(MonOneShotGun);

    /**
    *@brief  创造子弹
    *@author 卓正一
    */
    Bullet* createBullet() override;

    /**
    *@brief  初始化
    *@author 卓正一
    */
    bool init() override;

protected:
    void attackFromTo(Point from, Point to, int facing, Node *pBulletLayer);
};


#endif // MONSTER_WEAPONS_H
