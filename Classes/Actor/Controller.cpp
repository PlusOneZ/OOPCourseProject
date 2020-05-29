/**
*@file Controller.cpp
*@author 肖杨
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

void MoveController::setSpeed(float speed)
{
	m_speed = speed;
}

bool AttackController::init()
{
	scheduleUpdate();
	return true;
}
