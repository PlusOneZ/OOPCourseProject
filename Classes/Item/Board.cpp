/**
*@file Board.cpp
*@author 翟晨昊
*@date 6/14/2020
*/
#include "Board.h"

static const std::string kBoardMessage = "Information Board";
bool Board::init()
{
	m_pSprite = Sprite::create("item/informationboard.png");
	this->addChild(m_pSprite);
	generatePhysicalBody(kBoardMessage, sk::tag::kBoard);
	m_message.pushBack(putMessage(sk::message::kGunMessage));
	m_message.pushBack(putMessage(sk::message::kShotgunMessage));
	m_message.pushBack(putMessage(sk::message::kSwordMessage));
	m_message.pushBack(putMessage(sk::message::kSpearMessage));
	m_message.pushBack(putMessage(sk::message::kHealthPotionMessage));
	m_message.pushBack(putMessage(sk::message::kArmorPotionMessage));
	m_message.pushBack(putMessage(sk::message::kMonsterMessage));
	m_message.pushBack(putMessage(sk::message::kMonsterCrawShootMessage));
	m_message.pushBack(putMessage(sk::message::kMonsterWithGunMessage));
	m_message.pushBack(putMessage(sk::message::kMonsterPigMessage));
	m_message.pushBack(putMessage(sk::message::kMonsterSnowMessage));
	m_message.pushBack(putMessage(sk::message::kMonsterBossMessage));
	for (auto num : m_message)
	{
		num->setVisible(false);
		num->setPosition(this->getPosition().x, this->getPosition().y + 40);
		this->addChild(num);
	}
	return true;
}

ui::Scale9Sprite* putMessage(const std::string& message)
{
	auto board = ui::Scale9Sprite::create("interface/voidboard.png");
	board->retain();
	board->setContentSize(Size(message.size() * 5, 40));

	auto showMessage = Label::createWithTTF(message, "Font/IRANYekanBold.ttf", 15.);

	const Vec2 messagePos = { message.size() * (float)2.5,25 };

	showMessage->setPosition(messagePos);
	board->addChild(showMessage, 3);
	return board;
}

void Board::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	log("Key %d pressed.", keyCode);
	using namespace cocos2d;
	if (keyCode == EventKeyboard::KeyCode::KEY_D ||
		keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		if (curNumber < m_message.size() - 1)
		{
			m_message.at(curNumber)->setVisible(false);
			curNumber++;
			m_message.at(curNumber)->setVisible(true);
		}
		else
		{
			log("Already the last one");
		}
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_A ||
		keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		if (curNumber > 0)
		{
			m_message.at(curNumber)->setVisible(false);
			curNumber--;
			m_message.at(curNumber)->setVisible(true);
		}
		else
		{
			log("Already the first one");
		}
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_Z)
	{
		controlListener();
	}
}