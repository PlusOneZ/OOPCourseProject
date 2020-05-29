/**
*@file Controller.h
*@author 肖杨
*@date 2020.5.28
*/
#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "cocos2d.h"
using namespace cocos2d;


/**
*@brief 绑定将控制的对象
*@author 肖杨
*/
class ControllerListener
{
public:
	/**
	*@brief 设置坐标
	*@author 肖杨
	*/
	virtual void setTagPosition(float x, float y) = 0;

	/**
	*@brief 获取坐标
	*@author 肖杨
	*/
	virtual Point getTargetPosition() = 0;
};


/**
*@brief 控制器的基本内容
*@author 肖杨
*/
class ControllerBase : public Node
{
public:
	/**
	*@brief 设置监听对象
	*@author 肖杨
	*/
	void setControllerListener(ControllerListener* controllerListener);

protected:
	ControllerListener* m_controllerListener;
};



/**
*@brief 移动控制器
*@author 肖杨
*/
class MoveController : public ControllerBase
{
public:
	CREATE_FUNC(MoveController);

	/**
	*@brief 生成移动控制器
	*@author 肖杨
	*/
	bool init () override ;

	/**
	*@brief 绑定每帧操作
	*@author 肖杨
	*/
	void update(float dt) override ;

	/**
	*@brief 设置移动速度
	*@author 肖杨
	*/
	void setSpeed(float speed);
private:
    float m_speed;
};



/**
*@brief 攻击控制器
*@author 肖杨
*/
class AttackController :public ControllerBase
{
public:
	CREATE_FUNC(AttackController);

	/**
	*@brief 生成攻击控制器
	*@author 肖杨
	*/
	bool init() override ;

	/**
	*@brief 绑定每帧操作
	*@author 肖杨
	*/
	void update(float dt)override ;
};
#endif // !_Controller_H_
