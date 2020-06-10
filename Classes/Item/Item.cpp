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

ui::Scale9Sprite* showMessage(int price)
{
	auto board = ui::Scale9Sprite::create("interface/voidboard.png");
	board->retain();

	char cprice[5];
	itoa(price, cprice,10);
	std::string message = "$ ";
	message += cprice;
	board->setContentSize(Size(message.size() * 5, 30));

	auto showMessage = Label::createWithTTF(message, "Font/IRANYekanBold.ttf", 20.);
	const Vec2 messagePos = { message.size() * (float)2.5,15 };
	showMessage->setPosition(messagePos);
	board->addChild(showMessage, 3);

	return board;
}


void Item::setShopItem(int price)
{
	m_ifShopItem = true;
	m_price = price;
	m_pShopMessage=showMessage(m_price);
	m_pShopMessage->setVisible(false);
	m_pShopMessage->setPosition(this->getPosition().x, this->getPosition().y - 30);
	this->addChild(m_pShopMessage);
}
