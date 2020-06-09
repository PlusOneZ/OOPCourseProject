/**
 * @file  DistantMonster.h
 * @brief 远程攻击怪
 * @date  06/07/2020 [created by zzy]
 */
#ifndef __DISTANT_MONSTER_H__
#define __DISTANT_MONSTER_H__

#include "Monster.h"

class DistantMonster : public Monster
{
public:

    CREATE_FUNC(DistantMonster);

    /**
     * @brief 更新函数
     * @param dt
     */
    void update(float dt) override ;

    /**
     * @brief  重载初始化
     * @return
     */
    bool init() override ;

    void move();

    /**
     * @brief 见基类
     * @brief
     */
    void followSpeed(float dt) override ;

    /**
     * @brief 见基类
     * @param st
     */
    void attack(float st) override ;

protected:
    float m_backUpDistance = 100.;

};


#endif // DISTANT_MONSTER_H
