/**
 * @file   StartMenuScene.h
 * @date   5/24/2020 [Modified]
 * @author 卓正一
 */

#ifndef _START_MENU_SCENE_H
#define _START_MENU_SCENE_H

#include "cocos2d.h"
#include "StartGameScene.h"
#include "ui/CocosGUI.h"
#include "AudioEngine.h"
#include "Const/Const.h"

USING_NS_CC;

class Start : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();

    /**
    * @brief  初始化场景
    * @return true
    * @author 卓正一
    */
    bool init() override ;

    /**
     * 自动生成的创建函数
     * @return Start 实例
     */
    CREATE_FUNC(Start);

    /**
     * @brief  响应任意键按下，跳到真的播放界面并开始播放音乐
     * @param  keyCode, event 没用到
     * @author 卓正一
     */
    void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);

};


#endif //_START_MENU_SCENE_H
