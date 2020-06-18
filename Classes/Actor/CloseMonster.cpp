
#include "CloseMonster.h"

void MonsterPig::update(float dt)
{
    // empty
}

bool MonsterPig::init()
{
    if (!Monster::init())
        return false;
    schedule(CC_SCHEDULE_SELECTOR(MonsterPig::followSpeed), .5f);
    schedule(CC_SCHEDULE_SELECTOR(MonsterPig::attack), 2.f);
    m_pMoveAnimation = creatActorAnimate(sk::files::kPigMove,
                                         50, 48, 5);
    m_pDieSprite = sk::files::kPigDie;
    this->setTag(sk::tag::kMonster);

    auto dms = Sprite::create(StringUtils::format("%s1.png", sk::files::kPigMove));
    bindSprite(dms);
    Monster::move();

    m_pWeapon = MonInvisiblePigDash::create();
    addChild(m_pWeapon);

    generatePhysics(20.f);
    return true;
}

void MonsterPig::followSpeed(float dt)
{
    if (Hero::m_pPresentHero == nullptr || m_isDashing)
        return;
    auto targetPos = Hero::m_pPresentHero->getPosition();
    auto selfPos = getPosition();

    auto d = targetPos - selfPos;
    m_canAttack = d.length() < m_attackRange;
    if (d.length() < m_vision)
    {
        m_canFollow = true;
        auto v = d;
        v.normalize();
        v *= m_wanderSpeed;

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
        wanderSpeed(0.);
    }
}

void MonsterPig::attack(float dt)
{
    if (!m_canAttack || m_pWeapon == nullptr || Hero::m_pPresentHero == nullptr
        || BulletLayer::getInstance() == nullptr || m_isDashing)
        return;

    AudioEngine::play2d(sk::files::kGunShot, false, 0.25);

    Bullet *pBullet = m_pWeapon->createBullet();

    auto pos = Hero::m_pPresentHero->getPosition();
    pBullet->attack(pos.x, pos.y, getPosition(), m_facing, this);
    BulletLayer::getInstance()->addChild(pBullet);
    dash();
}

void MonsterPig::dash()
{
    if (Hero::m_pPresentHero == nullptr)
        return;
    m_isDashing = true;
    auto d = Hero::m_pPresentHero->getPosition() - getPosition();
    d.normalize();
    d *= m_dashSpeed;

    getPhysicsBody()->setVelocity(d);
    scheduleOnce(CC_CALLBACK_1(MonsterPig::stopDashing, this), 1.f, "stopDashing");
}

void MonsterPig::wanderSpeed(float dt)
{
    if (m_isDashing)
        return;
    float xSpeed = RandomHelper::random_real(-1., 1.);
    float ySpeed = RandomHelper::random_real(-1., 1.);
    auto vTemp   = Vec2(xSpeed, ySpeed);
    m_curSpeed   = vTemp / vTemp.getLength() * m_wanderSpeed;
    getPhysicsBody()->setVelocity(m_curSpeed);
    // TODO 增强随机性

    m_facing = (m_curSpeed.x > 0 ? sk::kRight : sk::kLeft);
    if (m_facing == sk::kRight)
    {
        m_sprite->setFlippedX(false);
    }
    else
    {
        m_sprite->setFlippedX(true);
    }
}

void MonsterPig::stopDashing(float dt)
{
    m_isDashing = false;
    getPhysicsBody()->setVelocity(Vec2(0, 0));
    schedule([&](float st) {
        m_canAttack = false;
    }, 0.2f, 15, 0., "Don't Attack");
}

