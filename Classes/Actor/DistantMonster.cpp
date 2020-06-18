/**
 * @file  DistantMonster.h
 * @brief 远程攻击怪
 * @date  06/07/2020 [created by zzy]
 */
#include "DistantMonster.h"

bool MonsterCrawShoot::init()
{
    if (!Monster::init())
        return false;
    schedule(CC_SCHEDULE_SELECTOR(MonsterCrawShoot::wanderSpeed), 0.5);
    schedule(CC_SCHEDULE_SELECTOR(MonsterCrawShoot::followSpeed), 1.5f);
    schedule(CC_SCHEDULE_SELECTOR(MonsterCrawShoot::attack), 3.f);
    // TODO 参数化
    m_pMoveAnimation = creatActorAnimate(sk::files::kYellowCrawMove,
            50, 48, 6);
    m_pDieSprite = sk::files::kYellowCrawDie;
    this->setTag(sk::tag::kMonster);

    auto dms = Sprite::create("Actor/Monster/Y_craw_monster1.png");
    bindSprite(dms);
    Monster::move();

    m_pWeapon = MonInvisibleWithFiveWayGun::create();
    addChild(m_pWeapon);
    return true;
}

void MonsterCrawShoot::followSpeed(float dt)
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
        log("following");
    }
    else
    {
        m_canFollow = false;
    }
}

void MonsterCrawShoot::attack(float dt)
{
    log("Try attacking.");
    if (!m_canFollow || m_pWeapon == nullptr || Hero::m_pPresentHero == nullptr
        || BulletLayer::getInstance() == nullptr)
        return;
    const auto kOffSet = Vec2(0, m_sprite->getContentSize().height / 2);

    log("att");
    AudioEngine::play2d(sk::files::kMonThorn, false, 0.25);
    auto num = m_pWeapon->getBulletCount();
    for (int i = 0; i < num; i++)
    {
        Bullet *pBullet = m_pWeapon->createBullet();

        auto pos = Hero::m_pPresentHero->getPosition();
        pBullet->attack(pos.x, pos.y, getPosition() + kOffSet, m_facing);
        BulletLayer::getInstance()->addChild(pBullet);
    }
}

void MonsterCrawShoot::update(float dt)
{
    // empty
}


/// -------------MonsterWithGun-------------


void MonsterWithGun::update(float dt)
{
    // empty
}

bool MonsterWithGun::init()
{
    if (!Monster::init())
        return false;
    m_pMoveAnimation = creatActorAnimate(sk::files::kOrangeSmallMove,
                                         50, 48, 6);
    m_pDieSprite     = sk::files::kOrangeSmallDie;

    auto dms = Sprite::create("Actor/Monster/Y_craw_monster1.png");
    bindSprite(dms);
    Monster::move();

    schedule(CC_SCHEDULE_SELECTOR(MonsterWithGun::wanderSpeed), 0.5);
    schedule(CC_SCHEDULE_SELECTOR(MonsterWithGun::followSpeed), 1.5f);
    schedule(CC_SCHEDULE_SELECTOR(MonsterWithGun::attack), 4.f);

    m_pWeapon = MonOneShotGun::create();
    m_pWeapon->setPosition(25, 20);
    if (m_pWeapon && m_sprite)
        m_sprite->addChild(m_pWeapon);
    return true;
}


void MonsterWithGun::followSpeed(float dt)
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

void MonsterWithGun::attack(float dt)
{
    if (!m_canFollow || m_pWeapon == nullptr || Hero::m_pPresentHero == nullptr
        || BulletLayer::getInstance() == nullptr)
        return;

    AudioEngine::play2d(sk::files::kGunShot, false, 0.25);

    Bullet *pBullet = m_pWeapon->createBullet();

    auto pos = Hero::m_pPresentHero->getPosition();
    pBullet->attack(pos.x, pos.y, getPosition(), m_facing);
    BulletLayer::getInstance()->addChild(pBullet);
}


