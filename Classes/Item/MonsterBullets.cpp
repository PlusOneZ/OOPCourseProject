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
    bindSprite(pSprite, sk::Kind::kMonster);
    setSpeed(200);
    m_isArrive = false;
    return true;
}

void MonFiveWayBullet::attack(float mouseX, float mouseY, Point pos, int curFacing)
{
    m_pBulletSprite->setPosition(pos);
    float k     = (mouseY - pos.y) / (mouseX - pos.x);
    float angle = atan(k) / (2.f * 3.14f) * 180.f;
    float sign  = (curFacing == 0 ? 1.f : -1.f);
    angle       = angle + RandomHelper::random_real(-180.f, 180.f);
    auto random = static_cast<float >(angle * 2 * 3.14 / 180);

    auto v = Vec2(sign, sign * random);
    v.normalize();
    v *= m_bulletSpeed;
    m_pBulletSprite->getPhysicsBody()->setVelocity(v);
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
    bindSprite(pSprite, sk::Kind::kMonster);
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
