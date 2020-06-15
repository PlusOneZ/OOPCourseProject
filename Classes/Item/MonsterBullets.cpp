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
    bindSprite(pSprite, sk::Kind::kMonster, sk::tag::kMonsterBullet);
    setSpeed(200);
    m_isArrive = false;
    return true;
}

void MonFiveWayBullet::attack(float mouseX, float mouseY, Point pos, int curFacing)
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
    bindSprite(pSprite, sk::Kind::kMonster, sk::tag::kMonsterBullet);
    setSpeed(100);
    m_isArrive = false;
    return true;
}

void MonOneShotBullet::attack(float mouseX, float mouseY, Point heroPoint, int curFacing)
{
    heroPoint.x += (curFacing == 0 ? 25.f : -25.f);
    heroPoint.y += 20.0f;
    m_pBulletSprite->setPosition(heroPoint);

    auto v = Vec2(mouseX - heroPoint.x, mouseY - heroPoint.y);
    v.normalize();
    v *= m_bulletSpeed;
    m_pBulletSprite->getPhysicsBody()->setVelocity(v);
}
