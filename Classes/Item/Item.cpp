#include "Item.h"

void Item::bindSprite(Sprite* pSprite)
{
    m_pSprite = pSprite;
    this->addChild(m_pSprite);
}

Sprite* Item::getSprite()
{
    return m_pSprite;
}

//为weapon添加交互函数后删掉本函数，把原函数改成纯虚函数
void Item::interact()
{
	return;
}

bool Item::voidOnContactPreSolve(PhysicsContact& contact)
{
	return false;
}

ui::Scale9Sprite* showMessage(const std::string& message)
{
	auto board = ui::Scale9Sprite::create("interface/voidboard.png");
	board->retain();
	board->setContentSize(Size(message.size() * 5, 40));

	auto arrow = ui::Scale9Sprite::create("interface/ui_arrow.png");
	auto showMessage = Label::createWithTTF(message,"Font/IRANYekanBold.ttf",20.);

	const Vec2 messagePos = { message.size() * (float)2.5,25 };
	const Vec2 arrowPos = { message.size() * (float)2.5,10 };

	showMessage->setPosition(messagePos);
	arrow->setPosition(arrowPos);
	board->addChild(showMessage, 3);
	board->addChild(arrow, 2);
	return board;
}

