#include "MonsterWeapons.h"


Bullet *MonInvisibleWithFiveWayGun::createBullet()
{
    Bullet* pBullet = MonFiveWayBullet::create();
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
    return true;
}


Bullet *MonOneShotGun::createBullet()
{
    Bullet* pBullet = MonOneShotBullet::create();
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
    return true;
}
