
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
                                         60, 48, 5);
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
    if (Hero::getInstance() == nullptr || m_isDashing)
        return;
    auto targetPos = Hero::getInstance()->getPosition();
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
    if (!m_canAttack || m_pWeapon == nullptr || Hero::getInstance() == nullptr
        || BulletLayer::getInstance() == nullptr || m_isDashing)
        return;

    if (gIsEffectPlaying)
        AudioEngine::play2d(sk::files::kGunShot, false, 0.25);

    Bullet *pBullet = m_pWeapon->createBullet();

    auto pos = Hero::getInstance()->getPosition();
    pBullet->attack(pos.x, pos.y, getPosition(), m_facing, this);
    BulletLayer::getInstance()->addChild(pBullet);
    dash();
}

void MonsterPig::dash()
{
    if (Hero::getInstance() == nullptr)
        return;
    m_isDashing = true;
    auto d = Hero::getInstance()->getPosition() - getPosition();
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

/// --------- MonsterSnow -------------

void MonsterSnow::update(float dt)
{
    // empty
}

bool MonsterSnow::init()
{
    if (!Monster::init())
        return false;
    schedule(CC_SCHEDULE_SELECTOR(MonsterSnow::followSpeed), .5f);
    schedule(CC_SCHEDULE_SELECTOR(MonsterSnow::attackUpdate), 5.f);
    m_pMoveAnimation = creatActorAnimate(sk::files::kSnowMove,
                                         42, 52, 4);
    m_pStayAnimation = creatActorAnimate(sk::files::kSnowStay,
                                         42, 52, 4);
    m_pDieSprite = sk::files::kSnowDie;
    this->setTag(sk::tag::kMonster);

    auto dms = Sprite::create(StringUtils::format("%s1.png", sk::files::kSnowStay));
    bindSprite(dms);
    Monster::move();

    m_pWeapon = MonInvisibleSnowQuake::create();
    m_pWeapon->setAnchorPoint(Vec2(0.5, 0));
    addChild(m_pWeapon);

    generatePhysics(15.f);
    return true;
}

void MonsterSnow::followSpeed(float dt)
{
    if (Hero::getInstance() == nullptr || m_isAttacking)
        return;
    auto targetPos = Hero::getInstance()->getPosition();
    auto selfPos   = getPosition();

    auto d = targetPos - selfPos;
    if (d.length() < m_attackRange)
    {
        if (m_canAttack)
        {
            attack(0.);
            m_canAttack = false;
        }
        return;
    }
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

void MonsterSnow::wanderSpeed(float dt)
{
    if (m_isAttacking)
        return;
    float xSpeed = RandomHelper::random_real(-1., 1.);
    float ySpeed = RandomHelper::random_real(-1., 1.);
    auto vTemp   = Vec2(xSpeed, ySpeed);
    m_curSpeed   = vTemp / vTemp.getLength() * m_wanderSpeed;
    getPhysicsBody()->setVelocity(m_curSpeed);

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

void MonsterSnow::attack(float dt)
{
    if (!m_canAttack || m_pWeapon == nullptr || Hero::getInstance() == nullptr
        || BulletLayer::getInstance() == nullptr || m_isAttacking)
        return;

    m_canAttack = false;
    auto pos = Hero::getInstance()->getPosition();
    auto attackFunc = CallFunc::create([&](){
        if (gIsEffectPlaying)
            AudioEngine::play2d(sk::files::kMonQuake, false, 0.25);
        Bullet *pBullet = m_pWeapon->createBullet();
        pBullet->attack(pos.x, pos.y, getPosition(), m_facing);
        BulletLayer::getInstance()->addChild(pBullet);
        this->stay();
    });
    auto delay    = DelayTime::create(3.);
    auto moveFunc = CallFunc::create([&](){
        this->startMoving(1);
    });
    attackFunc->retain();
    moveFunc->retain();

    auto seq = Sequence::create(jump(pos), attackFunc, delay, moveFunc, nullptr);
    runAction(seq);
}

void MonsterSnow::stay()
{
    if (m_pStayAnimation && m_pMoveAnimation && !m_animateState)
    {
        m_canAttack = false;
        m_sprite->stopAction(m_pMoveAnimation);
        m_sprite->runAction(m_pStayAnimation);
        m_animateState = true;
        getPhysicsBody()->setVelocity(Vec2::ZERO);
        unschedule(CC_SCHEDULE_SELECTOR(MonsterSnow::followSpeed));
    }
}

void MonsterSnow::startMoving(float dt)
{
    if (m_pMoveAnimation && m_pStayAnimation && m_animateState)
    {
        m_canAttack = false;
        m_sprite->stopAction(m_pStayAnimation);
        m_sprite->runAction(m_pMoveAnimation);
        m_animateState = false;
        schedule(CC_SCHEDULE_SELECTOR(MonsterSnow::followSpeed), .5f);
    }
}

JumpBy * MonsterSnow::jump(Point heroPoint)
{
    m_canAttack = false;
    auto d = heroPoint - getPosition();
    if (d.length() > m_jumpDistance)
    {
        d.normalize();
        d *= m_jumpDistance;
    }
    auto jumpAction = JumpBy::create(1.f, d, 20.f, 1);
    return jumpAction;
}

void MonsterSnow::attackUpdate(float dt)
{
    m_canAttack = true;
}


