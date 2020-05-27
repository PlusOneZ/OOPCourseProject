/**
*@file Hero.h
*@author 肖杨
*@date 2020.5.24
*/
#ifndef _Hero_H_
#define _Hero_H_

#include "Actor.h"
#include "Controller.h"
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
	void setController(ControllerBase* controllerBase);

protected:
	ControllerBase* m_moveController;
};
#endif
