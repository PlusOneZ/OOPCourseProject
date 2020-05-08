/**
 * @file Sta
 * @author ZZY
 *
 */

#ifndef SOULKNIGHT_STARTMENUSCENE_H
#define SOULKNIGHT_STARTMENUSCENE_H

#include "cocos2d.h"

class StartMenu : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(StartMenu);
};


#endif //SOULKNIGHT_STARTMENUSCENE_H
