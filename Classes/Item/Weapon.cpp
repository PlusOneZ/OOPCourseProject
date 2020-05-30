/**
*@file Weapon.cpp
*@author 翟晨昊
*@date 5/30/2020
*/
#include"Weapon.h"

float Weapon::getInterval()
{
	return shootInterval;
}

void Weapon::setInterval(float interval)
{
	shootInterval = interval;
}