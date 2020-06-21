/**
 * @file  DistantMonster.h
 * @brief 远程攻击怪
 * @date  06/07/2020 [created by zzy]
 */
#ifndef __DISTANT_MONSTER_H__
#define __DISTANT_MONSTER_H__

#include "Monster.h"
#include "Item/MonsterWeapons.h"

class MonsterCrawShoot : public Monster
{
public:

    CREATE_FUNC(MonsterCrawShoot);

    /**
     * @brief 更新函数
     * @param dt
     * @author 卓正一
     */
    void update(float dt) override ;

    /**
     * @brief  重载初始化
     * @return true for success
     * @author 卓正一
     */
    bool init() override ;


    /**
     * @brief  见基类
     * @author 卓正一
     */
    void followSpeed(float dt) override ;

    /**
     * @brief  见基类
     * @param  dt
     * @author 卓正一
     */
    void attack(float dt) override ;

protected:
    float m_backUpDistance = 100.;

};



class MonsterWithGun : public Monster
{
public:

    CREATE_FUNC(MonsterWithGun);

    /**
     * @brief 更新函数
     * @param dt
     * @author 卓正一
     */
    void update(float dt) override ;

    /**
     * @brief  重载初始化
     * @return true for success
     * @author 卓正一
     */
    bool init() override ;


    /**
     * @brief  见基类
     * @author 卓正一
     */
    void followSpeed(float dt) override ;

    /**
     * @brief  见基类
     * @param  dt
     * @author 卓正一
     */
    void attack(float dt) override ;

protected:
    float m_backUpDistance = 100.;

};

class Boss : public Monster
{
public:

    CREATE_FUNC(Boss);

    /**
     * @brief 更新函数
     * @param dt
     * @author 卓正一
     */
    void update(float dt) override;

    /**
     * @brief  重载初始化
     * @return true for success
     * @author 卓正一
     */
    bool init() override;


    /**
     * @brief  见基类
     * @author 卓正一
     */
    void followSpeed(float dt) override;

    /**
     * @brief  见基类
     * @param  dt
     * @author 卓正一
     */
    void attack(float dt) override;

protected:
    float m_backUpDistance = 100.;

};

#endif // DISTANT_MONSTER_H
