/**
*@file Hero.h
*@author 肖杨
*@date 2020.5.24
*/
#ifndef _HERO_H_
#define _HERO_H_

#include "Actor.h"
#include "Controller.h"
#include "../Item/Weapon.h"
/**
*@brief 主角类
*@author 肖杨
*/
class Hero :public Actor,public ControllerListener
{
public:
	/**
	*@brief 生成主角
	*@author 肖杨
	*/
	bool init() override ;

	/**
	*@brief 主角移动
	*@author 肖杨
	*/
	virtual void move()=0;

	/**
	*@brief 主角停止移动
	*@author 肖杨
	*/
	virtual void stopMove()=0;

	/**
	*@brief 主角静止
	*@author 肖杨
	*/
	virtual void rest()=0;

	/**
	*@brief 生成动画
	*@author 肖杨
	*@return 对应动画
	@param arg1 要生成的动画对应文件名称
	*/
	static Animate* creatHeroAnimate(const char * pAnimateName);

	/**
	*@brief 实现控制器接口
	*@author 肖杨
	*/
	virtual void setTagPosition(int x, int y);

	/**
	*@brief 实现控制器接口
	*@author 肖杨
	*@return 当前坐标点
	*/
	virtual Point getTagPosition();

	/**
	*@brief 设置控制器
	*@author 肖杨
	*/
	void setMoveController(ControllerBase* controllerBase);
	void setAttackController(ControllerBase* controllerBase);

	/**
	*@brief 技能接口
	*@author 肖杨
	*@return 技能是否释放成功(暂定)
	*/
	virtual bool skill() = 0;

	/**
	*@brief 切换武器
	*@author 肖杨
	*/
	void shiftWeapon();

	//声明为友元函数
	friend void AttackController::update(float dt);
	friend void MoveController::update(float dt);

	static Hero* m_pPresentHero;
protected:
	ControllerBase* m_pMoveController;
	ControllerBase* m_pAttackController;
	
	Weapon* m_pMainWeapon;
	Weapon* m_pSecWeapon;

	Animate* m_pRestAnimate;
	Animate* m_pMoveAnimate;

	bool ifMove;
};
#endif
