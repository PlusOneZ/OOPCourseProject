/**
 * @file Sta
 * @author ZZY
 *
 */

#ifndef SOULKNIGHT_STARTMENUSCENE_H
#define SOULKNIGHT_STARTMENUSCENE_H

#include "cocos2d.h"
#include "SafeMapScene.h"

USING_NS_CC;

class StartMenu : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();

    bool init() override ;

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(StartMenu);

    void onSpacePressed(EventKeyboard::KeyCode keyCode, Event* event);

};


#endif //SOULKNIGHT_STARTMENUSCENE_H
