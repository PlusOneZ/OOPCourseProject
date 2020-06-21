/**
 * @file Monster.h
 * @date 06/08/2020 [created by 卓正一]
 */

#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "Actor.h"
#include "Hero.h"
#include "../Item/MonsterWeapons.h"
#include "../Const/Const.h"
#include "../Scene/BulletLayer.h"
#include <string>
#include "../Const/Const.h"
#include "../Component/Coin.h"
#include "../Scene/PauseMenu.h"


class Monster : public Actor
{
public:
    typedef const std::string& cStr;

    /**
     * @brief  重载一下
     * @return
     */
    bool init() override ;

    /**
     * @brief  计算随便走的速度，随机的
     * @param  dt 是一个更新函数
     * @date 06/08/2020 [created by 卓正一]
     * @author 卓正一
     */
    virtual void wanderSpeed(float dt);

    /**
     * @brief  计算跟随英雄的速度
     * @date   06/08/2020 [created by 卓正一]
     * @author 卓正一
     */
    virtual void followSpeed(float dt) = 0;

    /**
     * @brief   攻击
     * @param   dt 是一个更新函数
     * @date    06/08/2020 [created by 卓正一]
     * @author  卓正一
     */
    virtual void attack(float dt) = 0;

    /**
     * @brief  怪被杀就会死
     * @date   06/08/2020 [created by 卓正一]
     * @author 卓正一
     */
    void die();

    /**
     * @brief  扣血
     * @param  amount 扣的值
     * @author 卓正一
     */
    void reduceHealth(int amount);

    /**
     * @brief 用质量创建物理体积
     * @param mass
     * @return
     * @author 卓正一
     */
    bool generatePhysics(float mass);

    /**
     * @brief 撞墙判断
     * @todo  还没写完
     * @param contact
     * @return
     */
    bool onContactBegin(PhysicsContact& contact);

    /**
     * @brief  播放移动动画
     * @author 卓正一
     */
    virtual void move();

protected:
    Weapon *m_pWeapon = nullptr;
    float   m_wanderSpeed = 85.f;

    int  m_curHealth  = 30;
    int  m_fullHealth = 30;

    Animate* m_pMoveAnimation = nullptr;
    std::string m_pDieSprite ;

    Vec2 m_curSpeed = Vec2::ZERO;

    float m_vision     = 300.;
    float m_shootRange = 300.;

    int m_facing    = sk::kRight;
    int m_canFollow = false;

};


#endif // MONSTER_H
