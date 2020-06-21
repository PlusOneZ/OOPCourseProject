/**
*@file ManagerBox.cpp
*@author 翟晨昊
*@date 6/21/2020
*/
#include "ManagerBox.h"

bool ManagerBox::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto EsotericaBox = EditBox::create(Size(250, 50), Scale9Sprite::create("interface/voidboard.png"));
	EsotericaBox->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	EsotericaBox->setFontColor(Color3B(0, 0, 0));
	EsotericaBox->setPlaceHolder("Esoterica:");
	EsotericaBox->setMaxLength(12);
	EsotericaBox->setInputMode(cocos2d::ui::EditBox::InputMode::SINGLE_LINE);
	EsotericaBox->setInputFlag(cocos2d::ui::EditBox::InputFlag::INITIAL_CAPS_WORD);
	EsotericaBox->setReturnType(cocos2d::ui::EditBox::KeyboardReturnType::DONE);
	EsotericaBox->setDelegate(this);
	EsotericaBox->setTag(101);
	this->addChild(EsotericaBox);
	return true;
}

void ManagerBox::editBoxEditingDidBegin(EditBox* editBox) 
{ 
	log("start edit"); 
}  

void ManagerBox::editBoxEditingDidEnd(EditBox* editBox) 
{ 
	log("end edit"); 
}

void ManagerBox::editBoxReturn(EditBox* editBox) 
{ 
	if (curText == "addcoin")//增加金币
	{
		Hero::getInstance()->gainCoins(50);
	}
	else if (curText == "raiseatk")//提高攻击力
	{
		Hero::getInstance()->raiseDamage(10);
	}
	else if (curText == "addarmor")//提高护甲
	{
		Hero::getInstance()->addArmor(3);
	}
	else if (curText == "become zch")
    {
        Hero::getInstance()->gainCoins(10000);
        Hero::getInstance()->addArmor(1000);
        Hero::getInstance()->addCurrentArmor(1000);
    }
	else if (curText == "become ljs")
    {
        Hero::getInstance()->raiseDamage(50);
    }
	log("editbox return"); 
}

void ManagerBox::editBoxTextChanged(EditBox* editBox, const std::string& text) 
{
	curText = text;
	log("text change=%s", text.c_str());
}
