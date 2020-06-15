/**
*@file Statue.h
*@author 肖杨
*@date 6/15/2020
*/
#ifndef _STATUE_H_
#define _STATUE_H_

#include "Item.h"
#include "Component/Buff.h"

/**
*@brief 战神雕像类
*@author 肖杨
*/
class WarStatue :public Item
{
private:
	int m_damage;
public:
	/**
	*@brief 设置提升攻击力幅度
	*@author 肖杨
	*/
	void setDamage(int damage);

	/**
	*@brief 生成一个基础攻击力+2的雕像
	*@author 肖杨
	*/
	bool init()override;

	/**
	*@brief 花钱变强
	*@author 肖杨
	*/
	void interact()override;

	CREATE_FUNC(WarStatue)
};


/**
*@brief 刺客雕像类
*@author 肖杨
*/
class AssassinStatue :public Item
{
private:
	float m_increaseSpeed;
public:
	/**
	*@brief 设置提升速度幅度
	*@author 肖杨
	*/
	void setSpeed(float speed);

	/**
	*@brief 生成一个基础加20%移动速度的雕像
	*@author 肖杨
	*/
	bool init()override;

	/**
	*@brief 花钱变强
	*@author 肖杨
	*/
	void interact()override;

	CREATE_FUNC(AssassinStatue)
};



#endif // !_STATUE_H_
