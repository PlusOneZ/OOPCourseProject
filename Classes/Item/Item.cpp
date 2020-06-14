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

	std::string message = "$ ";
	message += std::to_string(price);
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
	m_pShopMessage->setPosition(this->getPosition().x, this->getPosition().y - 30);
	this->addChild(m_pShopMessage);
}

void Item::generatePhysicalBody(std::string message, const int itemTag)
{
	m_pSprite->setTag(itemTag);
	m_pMessage = showMessage(message);
	m_pMessage->setVisible(false);
	m_pMessage->setPosition(this->getPosition().x, this->getPosition().y + 40);
	this->addChild(m_pMessage);
	auto size = m_pSprite->getContentSize();
	size.width *= 1.2;
	size.height *= 1.2;
	auto body = PhysicsBody::createBox(size);
	body->setDynamic(false);
	body->setGravityEnable(false);
	body->setCategoryBitmask(sk::bitMask::kItemCategory);
	body->setCollisionBitmask(sk::bitMask::kItemCollision);
	body->setContactTestBitmask(sk::bitMask::kItemContact);
	m_pSprite->setPhysicsBody(body);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Item::onContactBegin, this);
	contactListener->onContactSeparate = CC_CALLBACK_1(Item::onContactSeparate, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
}

