/**
 * @file  DistantMonster.h
 * @brief 远程攻击怪
 * @date  06/07/2020 [created by zzy]
 */
#include "DistantMonster.h"

bool DistantMonster::init()
{
    if (!Monster::init())
        return false;
    schedule(CC_SCHEDULE_SELECTOR(DistantMonster::wanderSpeed), 0.5);
    schedule(CC_SCHEDULE_SELECTOR(DistantMonster::followSpeed), 1.5f);
    schedule(CC_SCHEDULE_SELECTOR(DistantMonster::attack), 5.f);
    // TODO 参数化
    m_pMoveAnimation = creatActorAnimate(sk::files::kYellowCrawMove,
            50, 48, 6);
    m_pDieSprite = sk::files::kYellowCrawDie;
    this->setTag(sk::tag::kMonster);

    m_pWeapon = MonInvisibleWithFiveWayGun::create();
    addChild(m_pWeapon);
    return true;
}

void DistantMonster::followSpeed(float dt)
{
    if (Hero::m_pPresentHero == nullptr)
        return;
    auto targetPos = Hero::m_pPresentHero->getPosition();
    auto selfPos = getPosition();

    auto d = targetPos - selfPos;
    if (d.length() < m_vision)
    {
        m_canFollow = true;
        auto v = d;
        v.normalize();
        v *= m_wanderSpeed;

        if (d.getLength() < m_backUpDistance)
            v = -v;
        m_curSpeed = v;
        getPhysicsBody()->setVelocity(m_curSpeed);
        m_facing = (v.x > 0 ? sk::kRight : sk::kLeft);
        if (m_facing == sk::kRight)
        {
            m_sprite->setFlippedX(false);
        }
        else
        {
            m_sprite->setFlippedX(true);
        }
    }
    else
    {
        m_canFollow = false;
    }
}

void DistantMonster::attack(float dt)
{
    if (!m_canFollow)
        return;
    const auto kOffSet = Vec2(0, m_sprite->getContentSize().height / 2);
    // TODO 接口完整之后再射击
    CCASSERT(m_pWeapon != nullptr, "Monster no weapon");
    AudioEngine::play2d(sk::files::kMonThorn);
    for (int i = 0; i < m_pWeapon->getBulletCount(); i++)
    {
        Bullet *pBullet = m_pWeapon->createBullet();

        auto pos = Hero::m_pPresentHero->getPosition();
        pBullet->attack(pos.x, pos.y, getPosition() + kOffSet, m_facing);
        BulletLayer::m_pPresentBulletLayer->addChild(pBullet);
    }
}

void DistantMonster::update(float dt)
{
    // empty
}

void DistantMonster::move()
{
    m_sprite->runAction(m_pMoveAnimation);
}

