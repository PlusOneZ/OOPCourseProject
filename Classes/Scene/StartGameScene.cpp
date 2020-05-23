/**
*@file
*StartGameScene.cpp
*@author µÔ³¿ê»
*/

#include "StartGameScene.h"
#include "SafeMapScene.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocos2d::ui;

/**
*@brief Call the create function
*@return A Scene instance
*@author µÔ³¿ê»
*/
Scene* TitleScene::createScene()
{
    return TitleScene::create();
}

/**
*@brief Error adding resource
*@author µÔ³¿ê»
*/
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartGameScene.cpp\n");
}

/**
*@brief Initialize the scene
*@details Add images, buttons, and label to the scene
*@return true
*@author µÔ³¿ê»
*/
bool TitleScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

 

    auto startMenu = MenuItemImage::create(
                                           "startNormal.png",
                                           "startSelected.png",
                                           CC_CALLBACK_1(TitleScene::menuStartCallback, this));
    if (startMenu == nullptr ||
        startMenu->getContentSize().width <= 0 ||
        startMenu->getContentSize().height <= 0)
    {
        problemLoading("'startNormal.png' and 'startSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width / 2 - startMenu->getContentSize().width/2;
        float y = origin.y + startMenu->getContentSize().height/2 + 90.0;
        startMenu->setPosition(Vec2(x,y));
    }

    auto endMenu = MenuItemImage::create(
        "endNormal.png",
        "endSelected.png",
        CC_CALLBACK_1(TitleScene::menuEndCallback, this));
    if (endMenu == nullptr ||
        endMenu->getContentSize().width <= 0 ||
        endMenu->getContentSize().height <= 0)
    {
        problemLoading("'endNormal.png' and 'endSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - endMenu->getContentSize().width / 2;
        float y = origin.y + visibleSize.height - endMenu->getContentSize().height / 2;
        endMenu->setPosition(Vec2(x, y));
    }

    auto menu = Menu::create(startMenu, endMenu, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    auto endLabel = Label::createWithTTF("X", "fonts/Marker Felt.ttf", 32);
    if (endLabel == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        endLabel->setPosition(Vec2(origin.x + visibleSize.width - 44.0,
                                   origin.y + visibleSize.height - 38.0));
        this->addChild(endLabel, 1);
    }

    auto startLabel = Label::createWithTTF("Start Game", "fonts/Marker Felt.ttf", 28);
    if (startLabel == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        startLabel->setPosition(Vec2(origin.x + visibleSize.width / 2 -110.0,
                                     origin.y + startLabel->getContentSize().height / 2 + 140.0));
        this->addChild(startLabel, 1);
    }
    //´´½¨¾«Áé
    auto gameCover = Sprite::create("fengmian.png");
    if (gameCover == nullptr)
    {
        problemLoading("'fengmian.png'");
    }
    else
    {
        gameCover->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
        this->addChild(gameCover, 0);
    }

    auto coverElement = Sprite::create("title 02.png");
    if (coverElement == nullptr)
    {
        problemLoading("'title 02.png'");
    }
    else
    {
        coverElement->setPosition(Vec2(visibleSize.width / 2 + origin.x + 240.0,
                                       visibleSize.height / 2 + origin.y + 30.0));
        this->addChild(coverElement, 0);
    }

    auto gameName = Sprite::create("gameName.png");
    if (gameName == nullptr ||
        gameName->getContentSize().width <= 0 ||
        gameName->getContentSize().height <= 0)
    {
        problemLoading("'gameName.png'");
    }
    else
    {
        gameName->setPosition(Vec2(origin.x + gameName->getContentSize().width / 2 + 50, 
                                   visibleSize.height + origin.y - gameName->getContentSize().height));
        this->addChild(gameName, 0);
    }
    return true;
}

/**
*@brief Go to the next scene
*@author µÔ³¿ê»
*/
void TitleScene::menuStartCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(SafeMap::createScene());
}

/**
*@brief Exit the game
*@author µÔ³¿ê»
*/
void TitleScene::menuEndCallback(Ref* pSender)
{
    Director::getInstance()->end();
}
