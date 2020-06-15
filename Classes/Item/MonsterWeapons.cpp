#include "MonsterWeapons.h"


Bullet *MonInvisibleWithFiveWayGun::createBullet()
{
    Bullet* pBullet = MonFiveWayBullet::create();
    pBullet->setDamage(m_weaponDamage);
    return pBullet;
}

bool MonInvisibleWithFiveWayGun::init()
{
    Sprite* pSprite = Sprite::create();
    if (pSprite == nullptr)
    {
        log("Empty sprite not initialized");
    }
    bindSprite(pSprite);
    setInterval(1.5f);
    setBulletCount(5);
    m_weaponDamage = 1;
    return true;
}


Bullet *MonOneShotGun::createBullet()
{
    Bullet* pBullet = MonOneShotBullet::create();
    pBullet->setDamage(m_weaponDamage);
    return pBullet;
}

bool MonOneShotGun::init()
{
    Sprite* pSprite = Sprite::create();
    if (pSprite == nullptr)
    {
        log("Empty sprite not initialized");
    }
    bindSprite(pSprite);
    setInterval(1.f);
    setBulletCount(1);
    m_weaponDamage = 2;
    return true;
}


