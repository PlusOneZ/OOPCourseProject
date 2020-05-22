//
// Created by Zhengyi on 2020/5/8.
//

#ifndef SOULKNIGHT_SAFEMAPSCENE_H
#define SOULKNIGHT_SAFEMAPSCENE_H

#include "cocos2d.h"
USING_NS_CC;

class SafeMap : public cocos2d::Scene
{
public:
    static Scene* createScene();

    bool init() override ;

    // implement the "static create()" method manually
    CREATE_FUNC(SafeMap);

};


#endif //SOULKNIGHT_SAFEMAPSCENE_H
