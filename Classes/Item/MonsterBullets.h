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
    void attack(float mouseX, float mouseY, Point pos, int curFacing, Node *p_sprite) override;


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
    void attack(float mouseX, float mouseY, Point heroPoint, int curFacing, Node *p_sprite) override;
};

class MonPigDashAttack : public  Bullet
{
public:
    CREATE_FUNC(MonPigDashAttack);

    /**
    *@brief 初始化
    *@author
    */
    bool init() override;

    /**
    *@brief 子弹攻击
    *@author
    */
    void attack(float mouseX, float mouseY, Point heroPoint, int curFacing, Node *p_sprite) override;

protected:
    Vector<SpriteFrame*> m_rightActionVec;
    Vector<SpriteFrame*> m_leftActionVec;
};

class MonSnowQuakeAttack : public Bullet
{
public:
    CREATE_FUNC(MonSnowQuakeAttack);

    /**
    *@brief 初始化
    *@author
    */
    bool init() override;

    /**
    *@brief 子弹攻击
    *@author
    */
    void attack(float mouseX, float mouseY, Point heroPoint, int curFacing, Node *p_sprite) override;

protected:
    Vector<SpriteFrame*> m_ActionVec;
};

#endif // MONSTER_BULLETS_H
