#ifndef _GAME_MAP_H
#define _GAME_MAP_H

#include "cocos2d.h"
#include "Scene/RoomMap.h"

USING_NS_CC;

class GameMap :public Node
{
public:
	bool init() override;
	CREATE_FUNC(GameMap);
	void update(float dt) override;
protected:
	RoomMap* m_mainRoom;
};

#endif
