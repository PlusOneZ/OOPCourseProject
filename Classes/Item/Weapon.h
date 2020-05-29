/**
*@file Weapon.h
*@author 肖杨
*@date 5/28/2020
*/

#ifndef _WEAPON_H_
#define _WEAPON_H_

#include"Item.h"

/**
*@brief 武器类
*@author 肖杨(仅创建)
*/
class Weapon :public Item
{
public:
	void attack();
};
#endif // !_WEAPON_H_

