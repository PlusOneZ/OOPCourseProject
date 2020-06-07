//
// Created by Zhengyi on 2020/6/7.
//

#ifndef __DISTANT_MONSTER_H__
#define __DISTANT_MONSTER_H__

#include "Monster.h"

class DistantMonster : public Monster
{
public:

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

    /**
     * @brief 见基类
     * @brief
     */
    void followSpeed() override ;

    /**
     * @brief 见基类
     * @param st
     */
    void attack(float st) override ;

protected:
    float m_backUpDistant = 100.;

};


#endif // DISTANTMONSTER_H
