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

void MonInvisibleWithFiveWayGun::attackFromTo(Point from, Point to, int facing, Node *pBulletLayer)
{
    if (getBulletCount() == 0)
    {
        auto* pBullet = createBullet();
        pBullet->attack(from.x, from.y, to, facing);
        pBulletLayer->addChild(pBullet);
    }
    else
    {
        for (int i = 0; i < getBulletCount(); i++)
        {
            Bullet *pBullet = nullptr;
            pBullet = createBullet();
            pBullet->attack(from.x, from.y, to, facing);
            pBulletLayer->addChild(pBullet);
        }
    }
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

void MonOneShotGun::attackFromTo(Point from, Point to, int facing, Node *pBulletLayer)
{
    if (getBulletCount() == 0)
    {
        auto* pBullet = createBullet();
        pBullet->attack(from.x, from.y, to, facing);
        pBulletLayer->addChild(pBullet);
    }
    else
    {
        for (int i = 0; i < getBulletCount(); i++)
        {
            Bullet *pBullet = nullptr;
            pBullet = createBullet();
            pBullet->attack(from.x, from.y, to, facing);
            pBulletLayer->addChild(pBullet);
        }
    }
}

