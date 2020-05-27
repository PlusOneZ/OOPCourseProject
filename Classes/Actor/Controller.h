/**
*@file Controller.h
*@author Ф��
*@date 2020.5.28
*/
#ifndef _Controller_H_
#define _Controller_H_

#include "cocos2d.h"
#include<Windows.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
//�궨����Դhttps://blog.csdn.net/everlasting_20141622/article/details/52222006
using namespace cocos2d;
/**
*@brief �󶨽����ƵĶ���
*@author Ф��
*/
class ControllerListener
{
public:
	/**
	*@brief ��������
	*@author Ф��
	*/
	virtual void setTagPosition(int x, int y) = 0;

	/**
	*@brief ��ȡ����
	*@author Ф��
	*/
	virtual Point getTagPosition() = 0;
};

/**
*@brief �������Ļ�������
*@author Ф��
*/
class ControllerBase:public Node
{
public:
	/**
	*@brief ���ü�������
	*@author Ф��
	*/
	void setControllerListener(ControllerListener* controllerListener);

protected:
	ControllerListener* m_controllerListener;
};

/**
*@brief �ƶ�������
*@author Ф��
*/
class MoveController:public ControllerBase
{
public:
	CREATE_FUNC(MoveController);
	/**
	*@brief �����ƶ�������
	*@author Ф��
	*/
	virtual bool init ();

	/**
	*@brief ��ÿ֡����
	*@author Ф��
	*/
	virtual void update(float dt);

	/**
	*@brief �����ƶ��ٶ�
	*@author Ф��
	*/
	void setSpeed(int speed);
private:
	int m_speed;
};
#endif // !_Controller_H_
