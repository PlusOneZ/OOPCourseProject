#ifndef __CLOSE_MONSTER_H__
#define __CLOSE_MONSTER_H__

#include "Monster.h"
#include "Item/MonsterWeapons.h"

class MonsterPig : public Monster
{
public:

    CREATE_FUNC(MonsterPig);

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

    void wanderSpeed(float dt) override ;

    /**
     * @brief  见基类
     * @param  dt
     * @author 卓正一
     */
    void attack(float dt) override ;

    void dash();

    void stopDashing(float dt);

protected:
    float m_dashSpeed   = 150.f;
    float m_attackRange = 75.0f;

    bool m_isDashing = false;
    bool m_canAttack = false;

};

#endif // CLOSE_MONSTER_H
