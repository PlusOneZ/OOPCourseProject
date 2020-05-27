/**
*@file Controller.cpp
*@author Р¤Со
*@date 2020.5.28
*/
#include "Controller.h"
using namespace cocos2d;
void ControllerBase::setControllerListener(ControllerListener* controllerListener)
{
	m_controllerListener = controllerListener;
}

bool MoveController::init()
{
	m_speed = 3;
	scheduleUpdate();
	return true;
}

void MoveController::update(float dt)
{
	if (m_controllerListener == NULL)
	{
		return;
	}

	bool ifMove=0;
	Point pos = m_controllerListener->getTagPosition();

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
	m_controllerListener->setTagPosition(pos.x, pos.y);
}

void MoveController::setSpeed(int speed)
{
	m_speed = speed;
}