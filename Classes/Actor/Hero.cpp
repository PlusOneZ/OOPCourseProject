/**
*@file Hero.cpp
*@author 肖杨
*@date 2020.5.24
*/
#include "Hero.h"

bool Hero::init()
{
	return true;
}

/**
 * @brief  创建
 * @bug    传参错误导致无法正常生成动画
 * @date   05/25/2020 [bug fixed: 卓正一]
 * @param  pAnimateName 动画文件名（字符串）
 * @author 肖扬
*/
Animate* Hero::creatHeroAnimate(const char * pAnimateName)
{
    log("Trying to create hero");
	int moveFrameNum = 4;
	SpriteFrame*frame = nullptr;
	Vector<SpriteFrame*> frameVec;
	for (int i = 1; i <= moveFrameNum; i++)
	{
		frame = SpriteFrame::create(StringUtils::format("%s%d.png", pAnimateName, i),
		                            Rect(0, 0, 64, 60));
		if (frame == nullptr)
		{
            log("animate %s%d.png lost", pAnimateName, i);
		}
		else
		{
		    frame->setAnchorPoint(Vec2(0.5, 0.));
			frameVec.pushBack(frame);
		}
	}
	Animation*animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.2f);
	Animate*action = Animate::create(animation);
	return action;
}
