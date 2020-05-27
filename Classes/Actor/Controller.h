/**
*@file Controller.h
*@author 肖杨
*@date 2020.5.28
*/
#ifndef _Controller_H_
#define _Controller_H_

#include "cocos2d.h"
#include<Windows.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
//宏定义来源https://blog.csdn.net/everlasting_20141622/article/details/52222006
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
	virtual void setTagPosition(int x, int y) = 0;

	/**
	*@brief 获取坐标
	*@author 肖杨
	*/
	virtual Point getTagPosition() = 0;
};

/**
*@brief 控制器的基本内容
*@author 肖杨
*/
class ControllerBase:public Node
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
class MoveController:public ControllerBase
{
public:
	CREATE_FUNC(MoveController);
	/**
	*@brief 生成移动控制器
	*@author 肖杨
	*/
	virtual bool init ();

	/**
	*@brief 绑定每帧操作
	*@author 肖杨
	*/
	virtual void update(float dt);

	/**
	*@brief 设置移动速度
	*@author 肖杨
	*/
	void setSpeed(int speed);
private:
	int m_speed;
};
#endif // !_Controller_H_
