/**
*@brief 创建
*@details 射击时间间隔没有实装 没有设置子弹击中后消失
*@bug 无法正确获取获取鼠标位置
*@date 2020.5.30
*@author 翟晨昊
*/
#include "Actor/Hero.h"
#include "BulletLayer.h"
#include "Const/Const.h"
#include "Actor/Monster.h"

BulletLayer* BulletLayer::m_pPresentBulletLayer = nullptr;

bool BulletLayer::init()
{
    auto mouseListener = cocos2d::EventListenerMouse::create();
    mouseListener->onMouseDown = CC_CALLBACK_1(BulletLayer::onMouseDown, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(BulletLayer::onContactBegin, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
	//scheduleUpdate();
	m_pPresentBulletLayer = this;
	return true;
}

void BulletLayer::bindHero(Hero* pNowHero)
{
    m_pHero = pNowHero;
}

/*void BulletLayer::update(float dt)
{
}*/

bool BulletLayer::onMouseDown(Event* event)
{
    auto curTime = std::clock();
    if (static_cast<double>(curTime - m_lastShotTime) / CLOCKS_PER_SEC
            < m_pHero->getMainWeapon()->getInterval())
    {
        return true;
    }
    m_lastShotTime = curTime;
    auto e = dynamic_cast<EventMouse* >(event);
    if (m_pHero->getMainWeapon()->getBulletCount() == 0)
    {
        m_pHero->getMainWeapon()->getSprite()->setVisible(false);
        Bullet* pBullet = m_pHero->getMainWeapon()->createBullet();
        pBullet->attack(0, 0, m_pHero->getPosition(), m_pHero->getFacing());
        this->addChild(pBullet);
        m_pHero->getMainWeapon()->getSprite()->setVisible(true);
    }
    else
    {
        for (int i = 0; i < m_pHero->getMainWeapon()->getBulletCount(); i++)
        {
            Bullet* pBullet = m_pHero->getMainWeapon()->createBullet();
            log("Cursor at: %f, %f", e->getCursorX(), e->getCursorY());
            log("  Hero at: %f, %f", m_pHero->getPosition().x, m_pHero->getPosition().y);
            //m_pWeaponBullet.pushBack(pBullet);
            pBullet->attack(e->getCursorX(), e->getCursorY(), m_pHero->getPosition(),m_pHero->getFacing());
            this->addChild(pBullet);
        }
    }
	return true;
}

bool BulletLayer::onContactBegin(PhysicsContact& contact)
{
    auto body1 = contact.getShapeA()->getBody()->getNode();
    auto body2 = contact.getShapeB()->getBody()->getNode();
    if (body1 != nullptr && body2 != nullptr)
    {
        if (body1->getTag() == sk::tag::kBullet || body1->getTag() == sk::tag::kCloseDamage)
        {
            log("Monster shot");
            if (body2->getTag() == sk::tag::kMonster)
            {
                dynamic_cast<Monster*>(body2)->reduceHealth(
                        m_pHero->getBaseDamage() + m_pHero->getMainWeapon()->getDamage());
            }
            if (body1->getTag() == sk::tag::kBullet)
            {
                body1->setVisible(false);
                body1->removeFromParentAndCleanup(true);
            }
        }
        else if (body2->getTag() == sk::tag::kBullet || body2->getTag() == sk::tag::kCloseDamage)
        {
            log("Monster shot");
            if (body1->getTag() == sk::tag::kMonster)
            {
                dynamic_cast<Monster*>(body1)->reduceHealth(
                        m_pHero->getBaseDamage() + m_pHero->getMainWeapon()->getDamage());
            }
            if (body2->getTag() == sk::tag::kBullet)
            {
                body2->setVisible(false);
                body2->removeFromParentAndCleanup(true);
            }
        }
        else if (body1->getTag() == sk::tag::kMonsterBullet || body1->getTag() == sk::tag::kMonsterClose)
        {
            log("Hero shot");
            if (body2->getTag() == sk::tag::kHero)
            {
                Hero::getInstance()->reduceHealth(
                        dynamic_cast<Bullet* >(body1->getParent())->getDamage());
            }
            if (body1->getTag() == sk::tag::kMonsterBullet)
            {
                body1->setVisible(false);
                body1->removeFromParentAndCleanup(true);
            }
        }
        else if (body2->getTag() == sk::tag::kMonsterBullet || body2->getTag() == sk::tag::kMonsterClose)
        {
            log("Hero shot");
            if (body1->getTag() == sk::tag::kHero)
            {
                Hero::getInstance()->reduceHealth(
                        dynamic_cast<Bullet* >(body2->getParent())->getDamage());
            }
            if (body2->getTag() == sk::tag::kMonsterBullet)
            {
                body2->setVisible(false);
                body2->removeFromParentAndCleanup(true);
            }
        }
    }
    return true;
}

BulletLayer *BulletLayer::getInstance()
{
    return m_pPresentBulletLayer;
}
