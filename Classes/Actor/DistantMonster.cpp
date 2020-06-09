/**
 * @file  DistantMonster.h
 * @brief 远程攻击怪
 * @date  06/07/2020 [created by zzy]
 */
#include "DistantMonster.h"

bool DistantMonster::init()
{
    schedule(CC_SCHEDULE_SELECTOR(DistantMonster::wanderSpeed), 0.5);
    schedule(CC_SCHEDULE_SELECTOR(DistantMonster::followSpeed), 1.5f);
    schedule(CC_SCHEDULE_SELECTOR(DistantMonster::attack), 2.);
    // TODO 参数化
    m_pMoveAnimation = creatMonsterAnimate(sk::files::kYellowCrawName, 6);
//    m_pDieAnimation  = creatMonsterAnimate(sk::files::kYellowCrawDie, 1);

    runAction(m_pMoveAnimation);
    return true;
}

void DistantMonster::followSpeed(float dt)
{
    auto targetPos = Hero::m_pPresentHero->getPosition();
    auto selfPos   = getPosition();

    auto d = targetPos - selfPos;
    auto v = d;
    v.normalize();
    v *= m_wanderSpeed;

    if (d.getLength() < m_backUpDistance)
        v = -v;
    m_curSpeed = v;
}

void DistantMonster::attack(float st)
{
    // TODO 接口完整之后再射击
    // CCASSERT(m_pWeapon != nullptr, "Monster no weapon");
    // m_pWeapon->attack();
}

void DistantMonster::update(float dt)
{

    getPhysicsBody()->setVelocity(m_curSpeed);
}
