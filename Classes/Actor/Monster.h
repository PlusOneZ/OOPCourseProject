/**
 * @file Monster.h
 * @date 06/08/2020 [created by 卓正一]
 */

#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "Actor.h"
#include "Hero.h"
#include "../Item/Weapon.h"
#include "../Const/Const.h"
#include <string>

class Monster : public Actor
{
public:
    typedef const std::string& cStr;

    /**
     * @brief  计算随便走的速度，随机的
     * @param  dt 是一个更新函数
     * @date 06/08/2020 [created by 卓正一]
     * @author 卓正一
     */
    void wanderSpeed(float dt);

    /**
     * @brief  计算跟随英雄的速度
     * @date   06/08/2020 [created by 卓正一]
     * @author 卓正一
     */
    virtual void followSpeed() = 0;

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
     * @brief  创建动画
     * @param  textureName 用在 plist 里的名字做模板
     * @param  num 有几张
     * @return 一个动画
     * @author 卓正一
     */
    static Animate *creatMonsterAnimate(const std::string &textureName, int num);

    /**
     * @brief  在初始场景加载所有的怪物动画
     * @return 是否成功
     * @author 卓正一
     */
    static bool loadAllAnimate();

protected:
    Weapon *m_pWeapon = nullptr;
    float   m_wanderSpeed = 150.;

    int  m_curHealth;
    int  m_fullHealth = 10;

    Animate* m_pMoveAnimation = nullptr;
    Animate* m_pDieAnimation  = nullptr;

    Vec2 m_curSpeed;

    float m_vision     = 300.;
    float m_shootRange = 300.;

};


#endif // MONSTER_H
