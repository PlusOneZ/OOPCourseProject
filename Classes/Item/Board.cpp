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
	m_message.pushBack(putMessage(sk::message::kHealthPotionMessage));
	m_message.pushBack(putMessage(sk::message::kMonsterMessage));
	for (unsigned int num = 0; num < m_message.size();num++)
	{
		m_message.at(num)->setVisible(false);
		m_message.at(num)->setPosition(this->getPosition().x, this->getPosition().y + 40);
		this->addChild(m_message.at(num));
	}
	return true;
}

ui::Scale9Sprite* putMessage(const std::string& message)
{
	auto board = ui::Scale9Sprite::create("interface/voidboard.png");
	board->retain();
	board->setContentSize(Size(message.size() * 5, 40));

	//auto arrow = ui::Scale9Sprite::create("interface/ui_arrow.png");
	auto showMessage = Label::createWithTTF(message, "Font/IRANYekanBold.ttf", 20.);

	const Vec2 messagePos = { message.size() * (float)2.5,25 };
	//const Vec2 arrowPos = { message.size() * (float)2.5,10 };

	showMessage->setPosition(messagePos);
	//arrow->setPosition(arrowPos);
	board->addChild(showMessage, 3);
	//board->addChild(arrow, 2);
	return board;
}

void Board::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	log("Key %d pressed.", keyCode);
	//m_ifStateChanged = true;
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
	/*else if (keyCode == EventKeyboard::KeyCode::KEY_W ||
		keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		m_isKeyDown[sk::kUp] = true;
	}*/
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
	/*else if (keyCode == EventKeyboard::KeyCode::KEY_S ||
		keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
		m_isKeyDown[sk::kDown] = true;
	}*/
	else if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
	{
		controlListener();
	}
}