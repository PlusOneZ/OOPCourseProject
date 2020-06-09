/**
*@file Actor.h
*@author 肖杨
*/
#ifndef _ACTOR_H_
#define _ACTOR_H_
#include "cocos2d.h"
#include "Const/Const.h"

using namespace cocos2d;
/**
*@brief 可移动类
*@author 肖杨
*/
class Actor :public Node
{
public:

	bool generatePhysics();
	/**
    *@brief 绑定精灵
    *@author 肖杨
    */
    void bindSprite(Sprite* pSprite);

	/**
	*@brief 生成动画
	*@author 肖杨
	*@return 对应动画
	@param arg1 要生成的动画对应文件名称
	*/
	static Animate* creatActorAnimate(const char * pAnimateName, int width = 64, int height = 60);

protected:
    Sprite* m_sprite;
};
#endif