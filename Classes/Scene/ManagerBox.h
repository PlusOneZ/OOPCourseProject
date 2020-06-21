/**
*@file ManagerBox.h
*@author 翟晨昊
*@date 6/21/2020
*/

#ifndef _MANAGERBOX_H_
#define _MANAGERBOX_H_

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui\CocosGUI.h"
#include "Actor/Hero.h"

USING_NS_CC;
USING_NS_CC_EXT;

using namespace cocos2d::ui;

/**
*@brief 秘籍类
*@author 翟晨昊
*/
class ManagerBox : public cocos2d::Layer, public EditBoxDelegate
{
public:
	CREATE_FUNC(ManagerBox)

	/**
	*@brief 生成一个秘籍输入框
	*@author 翟晨昊
	*/
	bool init() override;

	/**
	*@brief 输入框的交互
	*@author 翟晨昊
	*/
	virtual void editBoxEditingDidBegin(EditBox* editBox);    
	virtual void editBoxEditingDidEnd(EditBox* editBox);    
	virtual void editBoxTextChanged(EditBox* editBox, const std::string& text);   
	virtual void editBoxReturn(EditBox* editBox);
private:
	std::string curText;
};

#endif