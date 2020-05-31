/**
*@file
*RoomMap.h
*@author 李嘉树
*/

#ifndef _ROOM_MAP_H
#define _ROOM_MAP_H

#include "cocos2d.h"
#include "Actor/Knight.h"

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

	CREATE_FUNC(RoomMap);

	/**
	*@brief close all the doors
	*@author 李嘉树
	*/
	void closeDoor(){}

	/**
	*@brief open all the doors
	*@author 李嘉树
	*/
	void openDoor(){}

	/**
	*@brief create the enemies
	*@author 李嘉树
	*/
	void createEnemy() {}

	/**
	*@brief add the player and start the game
	*@author 李嘉树
	*/
	void addPlayer(RoomMap* pMap) {}

protected:
	TMXTiledMap* m_pMap;
	int m_enemyNumber;
};

#endif