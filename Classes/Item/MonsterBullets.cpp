#include "MonsterBullets.h"

bool MonFiveWayBullet::init()
{
    if (!Bullet::init())
        return false;
    Sprite* pSprite = Sprite::create("item/bullets/monster_bullet_1.png");
    if (pSprite == nullptr)
    {
        log("monster_bullet_1.png not found");
    }
    bindSprite(pSprite, sk::Kind::kMonster, sk::BulletShape::kRectangle, sk::tag::kMonsterBullet);
    setSpeed(200);
    m_isArrive = false;
    return true;
}

void MonFiveWayBullet::attack(float mouseX, float mouseY, Point pos, int curFacing, Node *p_sprite)
{
    static int   shotCount = 0;
    static float lastAngle = 9.2345;
    float k     = (mouseY - pos.y) / (mouseX - pos.x);
    float angle = atan(k) / (2.f * 3.14f) * 180.f;
    float sign  = (mouseX - pos.x > 0 ? 1.f : -1.f);
    if (shotCount % 5 == 0)
    {
        lastAngle = angle;
    }
    m_pBulletSprite->setAnchorPoint(Vec2(0, 0.5));
    m_pBulletSprite->getPhysicsBody()->setLinearDamping(0.f);
    if (abs(lastAngle - angle) < 5.)
    {
        lastAngle = angle + RandomHelper::random_real(-180.f, 180.f);
    }
    else
    {
        lastAngle += 73.92f;
    }
    m_pBulletSprite->setRotation(-lastAngle);
    auto random = lastAngle * 2.f * 3.14f / 180.f;

    auto v = Vec2(sign, sign * tan(random));
    v.normalize();
    m_pBulletSprite->setPosition(pos + v * 20.);
    v *= m_bulletSpeed;
    m_pBulletSprite->getPhysicsBody()->setVelocity(v);
    ++shotCount;
}

bool MonOneShotBullet::init()
{
    if (!Bullet::init())
        return false;
    Sprite* pSprite = Sprite::create("item/bullets/monster_bullet_2.png");
    if (pSprite == nullptr)
    {
        log("monster_bullet_2.png not found");
    }
    bindSprite(pSprite, sk::Kind::kMonster, sk::BulletShape::kRectangle, sk::tag::kMonsterBullet);
    setSpeed(100);
    m_isArrive = false;
    return true;
}

void MonOneShotBullet::attack(float mouseX, float mouseY, Point heroPoint, int curFacing, Node *p_sprite)
{
    heroPoint.x += (curFacing == 0 ? 25.f : -25.f);
    heroPoint.y += 20.0f;
    m_pBulletSprite->setPosition(heroPoint);

    auto v = Vec2(mouseX - heroPoint.x, mouseY - heroPoint.y);
    v.normalize();
    v *= m_bulletSpeed;
    m_pBulletSprite->getPhysicsBody()->setVelocity(v);
}


/// ----------- PigDash ------------

bool MonPigDashAttack::init()
{
    if (!Bullet::init())
        return false;
    int actionStep = 3;
    SpriteFrame* frame_r = nullptr;
    SpriteFrame* frame_l = nullptr;
    for (int i = 1; i <= actionStep; i++)
    {
        frame_r = SpriteFrame::create(StringUtils::format("item/bullets/effect_dash%d.png", i),
                                      Rect(0, 0, 60, 60));
        frame_l = SpriteFrame::create(StringUtils::format("item/bullets/effect_dash%d.png", i),
                                      Rect(0, 0, 60, 60));
        if (frame_l == nullptr || frame_r == nullptr)
        {
            log("animate sword_action%d.png lost", i);
        }
        else
        {
            frame_r->setAnchorPoint(Vec2(0.f, 0.5f));
            m_rightActionVec.pushBack(frame_r);
            frame_l->setAnchorPoint(Vec2(1.f, 0.5f));
            m_leftActionVec.pushBack(frame_l);
        }
    }
    auto fig ="item/bullets/effect_dash1.png";
    m_pBulletSprite = Sprite::create(fig);
    bindSprite(m_pBulletSprite, sk::Kind::kMonster, sk::BulletShape::kRectangle,
            sk::tag::kMonsterClose);
    return true;
}

void MonPigDashAttack::attack(float mouseX, float mouseY, Point heroPoint, int curFacing, Node *p_sprite)
{
    if (p_sprite == nullptr)
        return;
    if (curFacing == sk::kLeft)
    {
        m_pBulletSprite->setFlippedX(true);
    }
    auto point = heroPoint;
    m_pBulletSprite->setPosition(point);

    auto joint = PhysicsJointFixed::construct(p_sprite->getPhysicsBody(),
                                              m_pBulletSprite->getPhysicsBody(), heroPoint);
    joint->setCollisionEnable(false);
    p_sprite->getScene()->getPhysicsWorld()->addJoint(joint);

    Animation* animation = nullptr;
    if (curFacing == sk::kRight)
    {
        animation = Animation::createWithSpriteFrames(m_rightActionVec);
    }
    else
    {
        animation = Animation::createWithSpriteFrames(m_leftActionVec);
    }
    animation->setLoops(1);
    animation->setDelayPerUnit(0.3f);
    Animate* actionOne = Animate::create(animation);
    auto end = CallFunc::create([&](){
//        getScene()->getPhysicsWorld()->removeJoint(joint);
        this->removeFromParentAndCleanup(true);
    });
    actionOne->retain();
    auto seq = Sequence::create(actionOne, end, nullptr);
    m_pBulletSprite->runAction(seq);
    log("Pig dash!");
}


/// ----------- SnowQuake ------------
bool MonSnowQuakeAttack::init()
{
    if (!Bullet::init())
        return false;
    int actionStep = 4;
    SpriteFrame* frame = nullptr;
    for (int i = 1; i <= actionStep; i++)
    {
        frame = SpriteFrame::create(StringUtils::format("item/bullets/shock_%d.png", i),
                                      Rect(0, 0, 60, 60));
        if (frame == nullptr)
        {
            log("animate shock_%d.png lost", i);
        }
        else
        {
            frame->setAnchorPoint(Vec2(0.5f, 0.f));
            m_ActionVec.pushBack(frame);
        }
    }
    auto fig ="item/bullets/shock.png";
    m_pBulletSprite = Sprite::create(fig);
    m_pBulletSprite->setAnchorPoint(Vec2(0.5f, 0.f));
    bindSprite(m_pBulletSprite, sk::Kind::kMonster, sk::BulletShape::kRectangle,
               sk::tag::kMonsterClose);
    return true;
}

void MonSnowQuakeAttack::attack(float mouseX, float mouseY, Point heroPoint, int curFacing, Node *p_sprite)
{
    m_pBulletSprite->setPosition(heroPoint);

    Animation* animation = Animation::createWithSpriteFrames(m_ActionVec);

    animation->setLoops(1);
    animation->setDelayPerUnit(0.2f);
    Animate* actionOne = Animate::create(animation);
    auto end = CallFunc::create([&](){
//        getScene()->getPhysicsWorld()->removeJoint(joint);
        this->removeFromParentAndCleanup(true);
    });
    actionOne->retain();
    auto seq = Sequence::create(actionOne, end, nullptr);
    m_pBulletSprite->runAction(seq);
    log("Snow Quake!");
}


