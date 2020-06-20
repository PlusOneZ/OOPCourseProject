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
    Sprite* pSprite = Sprite::create("item/monster_shoot.png");
    if (pSprite == nullptr)
    {
        log("Empty sprite not initialized");
    }
    bindSprite(pSprite);
    setBulletCount(1);
    m_weaponDamage = 2;
    return true;
}

/// ------- Close -------

bool MonInvisiblePigDash::init()
{
    Sprite* pSprite = Sprite::create("item/bullets/effect_dash.png");
    m_weaponSprite = pSprite;
    if (pSprite == nullptr)
    {
        log("Empty sprite not initialized");
    }
    bindSprite(pSprite);
    setInterval(.2f);
    setBulletCount(0);
    setDamage(3);
    return true;
}

Bullet *MonInvisiblePigDash::createBullet()
{
    Bullet* pBullet = MonPigDashAttack::create();
    pBullet->setDamage(m_weaponDamage);
    return pBullet;
}


bool MonInvisibleSnowQuake::init()
{
    Sprite* pSprite = Sprite::create("item/bullets/shock.png");
    m_weaponSprite = pSprite;
    if (pSprite == nullptr)
    {
        log("Empty sprite not initialized");
    }
    bindSprite(pSprite);
    setInterval(.2f);
    setBulletCount(0);
    setDamage(2);
    return true;
}

Bullet *MonInvisibleSnowQuake::createBullet()
{
    Bullet* pBullet = MonSnowQuakeAttack::create();
    pBullet->setDamage(m_weaponDamage);
    return pBullet;
}