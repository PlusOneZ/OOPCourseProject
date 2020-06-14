/**
 * @file  DistantMonster.h
 * @brief 远程攻击怪
 * @date  06/07/2020 [created by zzy]
 */
#include "DistantMonster.h"

bool DistantMonster::init()
{
    if(!Monster::init())
        return false;
    schedule(CC_SCHEDULE_SELECTOR(DistantMonster::wanderSpeed), 0.5);
    schedule(CC_SCHEDULE_SELECTOR(DistantMonster::followSpeed), 1.5f);
    schedule(CC_SCHEDULE_SELECTOR(DistantMonster::attack), 3.f);
    // TODO 参数化
    m_pMoveAnimation = creatActorAnimate("Actor/Monster/Y_craw_monster", 50, 48);
//    m_pMoveAnimation = creatMonsterAnimate(sk::files::kYellowCrawName, 6);
//    m_pDieAnimation  = creatMonsterAnimate(sk::files::kYellowCrawDie, 1);

    m_pWeapon = MonInvisibleWithFiveWayGun::create();
    addChild(m_pWeapon);
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
    getPhysicsBody()->setVelocity(m_curSpeed);
}

void DistantMonster::attack(float st)
{
    const auto kOffSet = Vec2(0, m_sprite->getContentSize().height / 2);
    // TODO 接口完整之后再射击
     CCASSERT(m_pWeapon != nullptr, "Monster no weapon");
    for (int i = 0; i < m_pWeapon->getBulletCount(); i++)
    {
        Bullet* pBullet = m_pWeapon->createBullet();

        auto pos = Hero::m_pPresentHero->getPosition();
        pBullet->attack(pos.x, pos.y, getPosition() + kOffSet, m_facing);
        BulletLayer::m_pPresentBulletLayer->addChild(pBullet);
    }
}

void DistantMonster::update(float dt)
{
    //getPhysicsBody()->setVelocity(m_curSpeed);
}

void DistantMonster::move()
{
    m_sprite->runAction(m_pMoveAnimation);
}
