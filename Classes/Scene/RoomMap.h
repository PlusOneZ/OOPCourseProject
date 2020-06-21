/**
*@file
*RoomMap.h
*@author 李嘉树
*/

#ifndef _ROOM_MAP_H
#define _ROOM_MAP_H

#include "cocos2d.h"
#include "BulletLayer.h"
#include "Const/Const.h"
#include "Item/Gun.h"
#include "Item/Shotgun.h"
#include "Item/Sword.h"
#include "Item/Spear.h"
#include <iostream>
#include "Component/HeroUI.h"
#include "Item/Statue.h"
#include "Item/Treasure.h"
#include "Actor/Assassin.h"
#include "Actor/Knight.h"
#include "Component/Trap.h"
#include "Item/HealthPotion.h"
#include "Item/ArmorPotion.h"
#include "Actor/DistantMonster.h"
#include "Actor/CloseMonster.h"

USING_NS_CC;

/**
*@brief A roommap scene
*@fn CREATE_FUNC contains the definition of the create function
*@author 李嘉树
*/
class RoomMap :public cocos2d::Scene
{
public:

	/**
	 * @brief Self Defined CTOR
	 * @param map : initialize field m_pMap
	 * @author 卓正一
	 */
	RoomMap(TMXTiledMap* map) : m_pMap(map){ };

	/**
	*@brief Call the create function
	*@return A Scene instance
	*@author 李嘉树
	*/
	static Scene* createScene(TMXTiledMap* map);

	/**
	 *@brief Initialize the scene
	 *@details Add tilemap to the game map
	 *@return true
	 *@author 李嘉树
	 */
	bool init() override;

	/**
	 * @brief Self defined create
	 * @param map : initialize field m_pMap
	 * @return
	 */
	static RoomMap* create(TMXTiledMap* map);

	/**
	*@brief close all the barriers
	*@author 李嘉树
	*/
	void createBarrier();

	/**
	*@brief create all the doors
	*@author 李嘉树
	*/
	void createDoor();

	/**
	*@brief 触碰门切换房间
	*@author 李嘉树
	*/
	bool onContactBegin(PhysicsContact& contact);

	/**
	*@brief 获取瓦片地图
	*@author 李嘉树
	*/
	static TMXTiledMap* createTiled(int mapNumber);

	/**
	*@brief 绑定逐帧检测
	*@author 李嘉树
	*/
	void update(float dt) override;

	/**
	 *@brief 添加骑士 子弹层 键盘监控
	*@author 肖杨  翟晨昊 卓正一
	 */
	void addPlayer(sk::HeroID id);

	static int m_mapNumber;
protected:
	TMXTiledMap* m_pMap;
	Assassin* myHero;
	bool ifDoor;
};

#endif