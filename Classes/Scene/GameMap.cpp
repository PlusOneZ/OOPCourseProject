#include "GameMap.h"

bool GameMap::init()
{
    this->scheduleUpdate();

    auto room1 = TMXTiledMap::create("map/room1_1.tmx");
    auto room2 = TMXTiledMap::create("map/room1_2.tmx");
    auto room3 = TMXTiledMap::create("map/room1_3.tmx");
    auto room4 = TMXTiledMap::create("map/room1_4.tmx");
    auto roomShop = TMXTiledMap::create("map/room1_shop.tmx");
    auto roomBoss = TMXTiledMap::create("map/room1_boss.tmx");
    auto gameRoom1 = RoomMap::createScene(room1);
    auto gameRoom2 = RoomMap::createScene(room2);
    auto gameRoom3 = RoomMap::createScene(room3);
    auto gameRoom4 = RoomMap::createScene(room4);
    auto gameRoomShop = RoomMap::createScene(roomShop);
    auto gameRoomBoss = RoomMap::createScene(roomBoss);

    m_mainRoom = dynamic_cast<RoomMap*>(gameRoom1);
    m_mainRoom->addPlayerAssassin();

    return true;
}

void GameMap::update(float dt)
{
    if (m_mainRoom->ifMoveToAnotherRoom())
    {
        m_mainRoom->moveStatusChange();
        auto room2 = TMXTiledMap::create("map/room1_2.tmx");
        auto gameRoom2 = RoomMap::createScene(room2);
        m_mainRoom = dynamic_cast<RoomMap*>(gameRoom2);
        m_mainRoom->addPlayerAssassin();
        Director::getInstance()->pushScene(m_mainRoom);
    }
}