/**
*@file HealthPotion.h
*@author 肖杨
*@date 6/4/2020
*/

#ifndef _HEALTH_POTION_H_
#define _HEALTH_POTION_H_

#include "item.h"

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
	bool init();

	/**
	*@brief 交互时消耗并恢复生命
	*@author 肖杨
	*/
	void interact() override;

	/**
	*@brief 修改m_pPresentContactItem
	*@author 肖杨
	*/
	bool onContactBegin(PhysicsContact& contact);
	bool onContactSeparate(PhysicsContact& contact);

	//TODO:显示信息
};
#endif // !_HEALTH_POTION_H_

