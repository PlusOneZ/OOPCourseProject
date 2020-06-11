/**
*@file HealthPotion.h
*@author 肖杨
*@date 6/4/2020
*/

#ifndef _HEALTH_POTION_H_
#define _HEALTH_POTION_H_

#include "Item.h"

/**
*@brief 生命药水类
*@author 肖杨
*/
class HealthPotion :public Item
{
public:
	CREATE_FUNC(HealthPotion)

	/**
	*@brief 生成一个生命药水
	*@author 肖杨
	*/
	bool init() override;

	/**
	*@brief 交互时消耗并恢复生命
	*@author 肖杨
	*/
	void interact() override;

};
#endif // !_HEALTH_POTION_H_

