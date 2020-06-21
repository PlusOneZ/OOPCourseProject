/**
*@file   Trap.h
*@author 肖杨
*@date   6/12/2020
*/
#ifndef _TRAP_H_
#define _TRAP_H_

#include "Buff.h"
#include "../Scene/PauseMenu.h"

/**
*@brief 陷阱类
*@author 肖杨
*/
class Trap: public Node
{
public:
	/**
	*@brief 判断碰撞
	*@author 肖杨
	*/
	bool onContactBegin(PhysicsContact& contact);

	void update(float dt)override;

	/**
	*@brief 执行trap
	*@author 肖杨
	*/
	virtual void trapStart() = 0;

	/**
	*@brief trap结束
	*@author 肖杨
	*/
	virtual void trapEnd() = 0;

	/**
	*@brief 设置陷阱时间
	*@author 肖杨
	*/
	void setTrapTime(float time);

	/**
	*@brief 设置物理体积
	*@author 肖杨
	*/
	void generatePhysicalBody(const int trapTag);
protected:
	Sprite* m_pSprite = nullptr;
    float m_trapTime  = 0.f;
	float m_time = 0.f;
};


/**
*@brief 冰冻陷阱类
*@author 肖杨
*/
class FreezeTrap :public Trap
{
public:
	CREATE_FUNC(FreezeTrap)

	/**
	*@brief 生成函数
	*@author 肖杨
	*/
	bool init()override;

	/**
	*@brief 束缚
	*@author 肖杨
	*/
	void trapStart()override;

	/**
	*@brief 束缚结束
	*@author 肖杨
	*/
	void trapEnd()override;
};


/**
*@brief 火焰陷阱类
*@author 肖杨
*/
class FlameTrap :public Trap
{
public:
	CREATE_FUNC(FlameTrap)

	/**
	*@brief 生成函数
	*@author 肖杨
	*/
	bool init()override;

	void update(float dt)override;

	/**
	*@brief 持续燃烧
	*@author 肖杨
	*/
	void trapStart()override;

	/**
	*@brief 停止燃烧
	*@author 肖杨
	*/
	void trapEnd()override;
protected:
	float m_flameTime = 0.f;
};

#endif // !_TRAP_H_
