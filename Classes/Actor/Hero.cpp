/**
*@file Hero.cpp
*@author 肖杨
*@date 2020.5.24
*/
#include "Hero.h"

bool Hero::init()
{
	m_pPresentHero = nullptr;
	return true;
}

/**
 * @brief  创建
 * @bug    传参错误导致无法正常生成动画
 * @date   05/25/2020 [bug fixed: 卓正一]
 * @param  pAnimateName 动画文件名（字符串）
 * @author 肖杨
*/
Animate* Hero::creatHeroAnimate(const char * pAnimateName)
{
    log("Trying to create hero");
	int moveFrameNum = 4;
	SpriteFrame*frame = nullptr;
	Vector<SpriteFrame*> frameVec;
	for (int i = 1; i <= moveFrameNum; i++)
	{
		frame = SpriteFrame::create(StringUtils::format("%s%d.png", pAnimateName, i),
		                            Rect(0, 0, 64, 60));
		if (frame == nullptr)
		{
            log("animate %s%d.png lost", pAnimateName, i);
		}
		else
		{
		    frame->setAnchorPoint(Vec2(0.5, 0.));
			frameVec.pushBack(frame);
		}
	}
	Animation*animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.2f);
	Animate*action = Animate::create(animation);
	action->retain();
	return action;
}

void Hero::setMoveController(ControllerBase* controllerbase)
{
	m_pMoveController = controllerbase;
	m_pMoveController->setControllerListener(this);
}

void Hero::setAttackController(ControllerBase* controllerbase)
{
	m_pAttackController = controllerbase;
	m_pAttackController->setControllerListener(this);
}

void Hero::setTagPosition(int x, int y)
{
	this->setPosition(Point(x, y));
}

Point Hero::getTagPosition()
{
	return this->getPosition();
}

void Hero::shiftWeapon()
{
	if (m_pSecWeapon != NULL)
	{
		Weapon* pTemp = m_pSecWeapon;
		m_pSecWeapon = m_pMainWeapon;
		m_pMainWeapon = pTemp;
	}
}

void AttackController::update(float dt)
{
	if (m_controllerListener == NULL)
	{
		return;
	}

	Hero* myHero = Hero::m_pPresentHero;

	if (KEY_DOWN(VK_LBUTTON))
	{
		myHero->m_pMainWeapon->attack();
	}

	if (KEY_DOWN(VK_RBUTTON))
	{
		myHero->shiftWeapon();
	}

	if (KEY_DOWN('Q'))
	{
		myHero->skill();
	}
}
/*
左键调用主武器的攻击函数
右键调用切换武器
q键调用技能
请务必完善相应函数
*/

/**
*@bug 动画调用有问题，本周内修复，暂时注释掉
*@date 05/29/2020[bug fixed: 肖杨]
*/
void MoveController::update(float dt)
{
	if (m_controllerListener == NULL)
	{
		return;
	}

	Point pos = m_controllerListener->getTagPosition();
	Hero* myHero = Hero::m_pPresentHero;
	bool checkMove = myHero->ifMove;

	if (KEY_DOWN('W'))
	{
		pos.y += m_speed;
	}
	if (KEY_DOWN('S'))
	{
		pos.y -= m_speed;
	}
	if (KEY_DOWN('D'))
	{
		pos.x += m_speed;
	}
	if (KEY_DOWN('A'))
	{
		pos.x -= m_speed;
	}

	if (pos != m_controllerListener->getTagPosition())
	{
		myHero->ifMove = 1;
	}
	else
	{
		myHero->ifMove = 0;
	}
	if (checkMove != myHero->ifMove)
	{
		if (myHero->ifMove)//说明在开始移动
		{
			myHero->move();
		}
		else
		{
			myHero->stopMove();
			myHero->rest();
		}
		
	}

	m_controllerListener->setTagPosition(pos.x, pos.y);

}//TODO:改变方向，播放动画
