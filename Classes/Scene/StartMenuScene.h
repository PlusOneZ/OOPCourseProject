/**
 * @file   StartMenuScene.h
 * @author 卓正一
 */

#ifndef _START_MENU_SCENE_H
#define _START_MENU_SCENE_H

#include "cocos2d.h"
#include "SafeMapScene.h"

USING_NS_CC;

class StartMenu : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();

    /**
    * @author 卓正一
    * @brief  初始化场景
    * @return true
    */
    bool init() override ;

    CREATE_FUNC(StartMenu);

    void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);

};


#endif //_START_MENU_SCENE_H
