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
*@bug 传参错误导致无法正常生成动画
*/
Animate* Hero::creatHeroAnimate(std::string pAnimateName)
{
	int moveFrameNum = 4;
	SpriteFrame*frame = NULL;
	Vector<SpriteFrame*> frameVec;
	for (int i = 1; i <= moveFrameNum; i++)
	{
		frame = SpriteFrame::create(StringUtils::format("%s%d.png", pAnimateName.c_str(), i), Rect(0, 0, 64, 55));
		if (frame == nullptr)
		{
			log("animate %s%d.png lost", pAnimateName,i);
		}
		else
		{
			frameVec.pushBack(frame);
		}
	}
	Animation*animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.2f);
	Animate*action = Animate::create(animation);
	return action;
}
