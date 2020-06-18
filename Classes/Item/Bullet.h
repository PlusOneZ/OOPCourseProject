/**
*@file Bullet.h
*@author 翟晨昊
*@date 5/30/2020
*/
#ifndef _BULLET_H_
#define _BULLET_H_

#include "cocos2d.h"
#include "Const/Const.h"



using namespace cocos2d;

/**
*@brief 子弹类
*@author 翟晨昊
*/
class Bullet :public Node{
public:

	/**
    *@brief 子弹攻击
    *@author 翟晨昊
    */
	virtual void attack(float mouseX, float mouseY, Point heroPoint, int curFacing,
                        Node *p_sprite = nullptr) = 0;

	/**
	*@brief 获取子弹速度
	*@author 翟晨昊
	*/
	float getSpeed();

	/**
	*@brief 设置子弹速度
	*@author 翟晨昊
	*/
	void setSpeed(float speed);

	/**
	*@brief 绑定图像
	*@author 翟晨昊
	*/
    void bindSprite(Sprite *pSprite, sk::Kind kind = sk::Kind::kSelf, int tag = sk::tag::kBullet);

    /**
     * @brief 设置伤害
     * @param damage
     */
    void setDamage(int damage);

    /**
     * @brief  获取伤害
     * @return
     */
    int getDamage();

protected:

	Sprite* m_pBulletSprite;
	float   m_bulletSpeed;
	bool    m_isArrive;
	int     m_damage;
	sk::Kind m_kind;

	void moveEnd();
};
#endif
