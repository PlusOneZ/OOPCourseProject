/**
*@file Hero.cpp
*@author 肖杨
*@date 2020.5.24
*/
#include "Hero.h"
#include "../Scene/PauseMenu.h"

Hero* Hero::m_pPresentHero = nullptr;
Item* Hero::m_pPresentContactItem = nullptr;

Weapon* Hero::getMainWeapon()
{
	return this->m_pMainWeapon;
}

int Hero::getFacing()
{
    return m_curFacing;
}

void Hero::shiftWeapon()
{
	if (m_pSecWeapon != nullptr)
	{
        m_pMainWeapon->setVisible(false);
        m_pSecWeapon->setVisible(true);
		Weapon* pTemp = m_pSecWeapon;
		m_pSecWeapon = m_pMainWeapon;
		m_pMainWeapon = pTemp;
	}
}

void Hero::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    log("Key %d pressed.", keyCode);
    m_ifStateChanged = true;
	using namespace cocos2d;
	if (keyCode == EventKeyboard::KeyCode::KEY_D ||
		keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		m_isKeyDown[sk::kRight] = true;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_W ||
		keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		m_isKeyDown[sk::kUp] = true;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_A ||
		keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		m_isKeyDown[sk::kLeft] = true;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_S ||
		keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
		m_isKeyDown[sk::kDown] = true;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_Q)
	{
		if (m_skillTime >= m_skillCD)
		{
			m_skillRemainTime=this->skill();
			m_skillTime = -m_skillRemainTime;
		}
		else
		{
			log("skill CDing");
		}
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_E)
	{
		// TODO: Shift weapon here.
		this->shiftWeapon();
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_F)
	{
		if (m_pPresentContactItem != nullptr)
		{
			m_pPresentContactItem->interact();
			m_pPresentContactItem = nullptr;
		}
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
	{
		Director::getInstance()->pushScene(PauseMenu::create(m_ID));
	}
}

void Hero::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    m_ifStateChanged = true;
	using namespace cocos2d;
	if (keyCode == EventKeyboard::KeyCode::KEY_D ||
		keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		m_isKeyDown[sk::kRight] = false;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_W ||
		keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		m_isKeyDown[sk::kUp] = false;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_A ||
		keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		m_isKeyDown[sk::kLeft] = false;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_S ||
		keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
		m_isKeyDown[sk::kDown] = false;
	}
}

void Hero::update(float dt)
{
    auto v = Vec2(0, 0);
    if (m_ifStateChanged) 
	{
        if (m_isKeyDown[sk::kUp])
            v.y += m_speed;
        if (m_isKeyDown[sk::kDown])
            v.y -= m_speed;
        if (m_isKeyDown[sk::kLeft])
            v.x -= m_speed;
        if (m_isKeyDown[sk::kRight])
            v.x += m_speed;

        getPhysicsBody()->setVelocity(v);
    }
    m_ifStateChanged = false;
    getPhysicsBody()->setAngularVelocity(0);

    if (v.x < 0 && m_curFacing == sk::kRight)
    {
        m_sprite->setFlippedX(true);
        m_pMainWeapon->getSprite()->setFlippedX(true);
        m_pMainWeapon->setPosition(Point(-20.0, 20.0));
        m_curFacing = sk::kLeft;
    }
    else if (v.x > 0 && m_curFacing == sk::kLeft)
    {
        m_sprite->setFlippedX(false);
        m_pMainWeapon->getSprite()->setFlippedX(false);
        m_pMainWeapon->setPosition(Point(20.0, 20.0));
        m_curFacing = sk::kRight;
    }

    if (getPhysicsBody()->getVelocity() != Vec2::ZERO)
    {
        if (!m_ifMoved)
        {
            m_ifMoved = true;
            move();
        }
    }
    else
    {
        if (m_ifMoved)
        {
            m_ifMoved = false;
            stopMove();
            rest();
        }
    }

	if (m_skillTime < m_skillCD)
	{
		m_skillTime += dt;
	}
	if (m_skillRemainTime > 0)
	{
		m_skillRemainTime -= dt;
		if (m_skillRemainTime <= 0)
		{
			skillEnd();
		}
	}

	if (m_recoverArmorTime < 1)
	{
		m_recoverArmorTime += dt;
	}
	else if (m_armor < m_maxArmor)
	{
		m_armor += 1;
		log("armor regain");
	}
	
	
}

void Hero::rest()
{
	m_sprite->runAction(m_pRestAnimate);
}

void Hero::move()
{
	m_sprite->stopAction(m_pRestAnimate);
	m_sprite->runAction(m_pMoveAnimate);
}

void Hero::stopMove()
{
	m_sprite->stopAction(m_pMoveAnimate);
}

bool Hero::reduceHP(int damage)
{
	if (m_ifMortal)
	{
		m_recoverArmorTime = -4;
		if (m_armor != 0)
		{
			if (damage > m_armor)
			{
				damage -= m_armor;
				m_armor = 0;
			}
			else
			{
				m_alive -= damage;
				return true;
			}
		}
		if (damage >= m_HP)
		{
			m_alive = false;
			return false;
		}
		else
		{
			m_HP -= damage;
			return true;
		}
	}
	return true;
}

void Hero::recoverHP(int healAmount)
{
	if (m_HP + healAmount <= m_maxHP)
	{
		m_HP += healAmount;
	}
	else
	{
		m_HP = m_maxHP;
	}
}

bool Hero::ifInjured()
{
	return m_HP < m_maxHP;
}

bool Hero::costCoins(int coin)
{
	if (m_coinNumber >= coin)
	{
		m_coinNumber -= coin;
		return true;
	}
	else
	{
		return false;
	}
}

void Hero::gainCoins(int coin)
{
	m_coinNumber += coin;
}

//Item中函数的实现
bool Item::onContactSeparate(PhysicsContact& contact)
{
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();
	if (nodeA != nullptr && nodeB != nullptr)
	{
		if ((nodeA->getTag() == sk::tag::kHero || nodeB->getTag() == sk::tag::kHero)
			&& (nodeA->getTag() == this->getTag() || nodeB->getTag() == this->getTag()))
		{
			if (Hero::m_pPresentContactItem == this)
			{
				Hero::m_pPresentContactItem = nullptr;
				m_pMessage->setVisible(false);
				if (m_ifShopItem)
				{
					m_pShopMessage->setVisible(false);
				}
			}
		}
	}
	return true;
}

bool Item::onContactBegin(PhysicsContact& contact)
{
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();
	if (nodeA != nullptr && nodeB != nullptr)
	{
		if ((nodeA->getTag() == sk::tag::kHero || nodeB->getTag() == sk::tag::kHero)
			&& (nodeA->getTag() == this->getTag() || nodeB->getTag() == this->getTag()))
		{
			if (Hero::m_pPresentContactItem == nullptr)
			{
				Hero::m_pPresentContactItem = this;
				m_pMessage->setVisible(true);
				if (m_ifShopItem)
				{
					m_pShopMessage->setVisible(true);
				}
			}
		}
	}
	return false;
}

bool Item::buyItem()
{
	if (m_ifShopItem)
	{
		if (Hero::m_pPresentHero->costCoins(m_price))//购买成功
		{
			log("buy item");
			m_ifShopItem = false;
			m_price = 0;
			m_pShopMessage->removeFromParentAndCleanup(true);
			m_pShopMessage = nullptr;
		}
		else
		{
			log("no enough money");
		}
	}
	return !m_ifShopItem;
}

