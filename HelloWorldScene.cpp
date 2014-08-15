#include "HelloWorldScene.h"
#include "MainScene.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !CCLayerColor::initWithColor(ccc4(255, 255, 255, 255) ))
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//start button & close button
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	auto StartItem = MenuItemImage::create(
                                           "title_btn.png",
                                           "title_btn_pu.png",
                                           CC_CALLBACK_1(HelloWorld::menuStartCallback, this));
    
	StartItem->setPosition(Vec2(origin.x + visibleSize.width/2 ,
                                origin.y + visibleSize.height/4+StartItem->getContentSize().height/2));
 
    // add buttons to menu
	auto menu = Menu::create(closeItem, StartItem,NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

	//central title
    HelloWorld::isprite = Sprite::create("title.png");

    // position the sprite on the center of the screen
    HelloWorld::isprite->setPosition(Vec2(visibleSize.width/2 + origin.x, 2*visibleSize.height/3 + origin.y));
    // add the sprite as a child to this layer
    this->addChild(HelloWorld::isprite, 0);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
void HelloWorld::menuStartCallback(Ref* pSender)
{
	//central sprite action 
	RotateBy * titlerote = RotateBy::create (1, 180);
	HelloWorld::isprite->runAction(titlerote);
	//scene transite
	CCScene * scene1=MainScene::createScene();
	CCTransitionScene * ss=CCTransitionProgressInOut::create(1,scene1);
	CCDirector::sharedDirector()->replaceScene(ss);
}
