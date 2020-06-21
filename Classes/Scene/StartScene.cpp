/**
 * @file   StartScene.cpp
 * @date   05/24/2020 [modified]
 * @author 卓正一
 */

#include "StartScene.h"
#include "Actor/Hero.h"

USING_NS_CC;
using namespace cocos2d::ui;

Scene* Start::createScene()
{
    return Start::create();
}

/**
 @author Cocos
 @brief  print file loading error
 */
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
}


bool Start::init()
{
    // Check if successfully initialized.
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto prompt = Label::createWithTTF("Press Any Key", "Font/LockClock.ttf", 50);
    auto startBackground = Sprite::create("interface/start.png");
    if (startBackground == nullptr || prompt == nullptr)
    {
        problemLoading("'start.png' / 'Font/LockClock.ttf'");
    }
    else
    {
        auto spriteSize = startBackground->getContentSize();
        startBackground->setScale(visibleSize.width / spriteSize.width,
                         visibleSize.height / spriteSize.height);
        // position the sprite on the center of the screen
        startBackground->setPosition(Vec2(visibleSize.width / 2 + origin.x,
                                 visibleSize.height / 2 + origin.y));
        prompt->setPosition(Vec2(visibleSize.width / 2 + origin.x, 50));
        this->addChild(startBackground, 1);
        this->addChild(prompt, 2);
    }

    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(Start::onKeyPressed, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
    return true;
}



void Start::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event) {
    log("Key with keyCode %d pressed", keyCode);
    Director::getInstance()->replaceScene(TitleScene::create());
}

void Hero::dieToStartMenu()
{
    m_pPresentHero = nullptr;
    this->removeFromParentAndCleanup(false);
    auto start = Start::createScene();
    Director::getInstance()->replaceScene(start);
}