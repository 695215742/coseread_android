#include "MainScene.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{

    if ( !CCLayerColor::initWithColor(ccc4(255, 255, 255, 255) ))
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //left menu with four buttons and a label (reading,search,setting,list&system information)
    auto BookItem = MenuItemImage::create(
                                           "reading_btn.png",
                                           "reading_btn_pu.png",
                                           CC_CALLBACK_1(MainScene::menuReadingCallback, this));
    
	BookItem->setPosition(Vec2(origin.x +BookItem->getContentSize().width/2,
		origin.y +visibleSize.height- BookItem->getContentSize().height/2));
	auto ListItem = MenuItemImage::create(
                                           "list_btn.png",
                                           "list_btn_pu.png",
                                           CC_CALLBACK_1(MainScene::menuListCallback, this));
    
	ListItem->setPosition(Vec2(origin.x +BookItem->getContentSize().width/2 ,
		origin.y +visibleSize.height- 3*BookItem->getContentSize().height/2));
	auto SearchItem = MenuItemImage::create(
                                           "search_btn.png",
                                           "search_btn_pu.png",
                                           CC_CALLBACK_1(MainScene::menuSearchCallback, this));
    
	SearchItem->setPosition(Vec2(origin.x +BookItem->getContentSize().width/2 ,
		origin.y +visibleSize.height- 5*BookItem->getContentSize().height/2));
	auto SettingItem = MenuItemImage::create(
                                           "setting_btn.png",
                                           "setting_btn_pu.png",
                                           CC_CALLBACK_1(MainScene::menuSettingCallback, this));
    
	SettingItem->setPosition(Vec2(origin.x +BookItem->getContentSize().width/2 ,
		origin.y +visibleSize.height- 7*BookItem->getContentSize().height/2));
    // create menu, it's an autorelease object
	auto menu = Menu::create(BookItem, ListItem,SearchItem,SettingItem,NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    MainScene::isprite = Sprite::create("title.png");

    // position the sprite on the center of the screen
    MainScene::isprite->setPosition(Vec2(visibleSize.width/2 + origin.x, 2*visibleSize.height/3 + origin.y));
    // add the sprite as a child to this layer
    //this->addChild(MainScene::isprite, 0);
    
    return true;
}


void MainScene::menuCloseCallback(Ref* pSender)
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
void MainScene::menuReadingCallback(Ref* pSender)
{
	//get original state and change it 
	int oristate = MainScene::state;
	MainScene::state = 1; 
	//state 1:reading,2:list,3:search,4:setting
	if(oristate == 1)
	{
		readinglayer->removeAllChildrenWithCleanup(true);
	}
	else if(oristate == 2)
	{
		listlayer->removeAllChildrenWithCleanup(true);
	}
	else if(oristate == 3)
	{
		searchlayer->removeAllChildrenWithCleanup(true);
	}
	else if(oristate == 4)
	{
		settinglayer->removeAllChildrenWithCleanup(true);
	}
	//get size
	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//four layers,control by tuttons
	//search layer
	MainScene::readinglayer = CCLayerGradient::create(ccc4(255, 255, 255, 255), ccc4(255, 255, 255, 255));
	MainScene::readinglayer->setContentSize(CCSizeMake(300, 300));
	MainScene::readinglayer->setPosition(ccp(100,50));
	addChild(readinglayer);
}
void MainScene::menuSearchCallback(Ref* pSender)
{
	//get original state and change it 
	int oristate = MainScene::state;
	MainScene::state = 3; 
	//state 1:reading,2:list,3:search,4:setting
	if(oristate == 1)
	{
		readinglayer->removeAllChildrenWithCleanup(true);
	}
	else if(oristate == 2)
	{
		listlayer->removeAllChildrenWithCleanup(true);
	}
	else if(oristate == 3)
	{
		searchlayer->removeAllChildrenWithCleanup(true);
	}
	else if(oristate == 4)
	{
		settinglayer->removeAllChildrenWithCleanup(true);
	}
	//get size
	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//four layers,control by tuttons
	//search layer
	MainScene::searchlayer = CCLayerGradient::create(ccc4(255, 255, 255, 255), ccc4(255, 255, 255, 255));
	MainScene::searchlayer->setContentSize(CCSizeMake(300, 300));
	MainScene::searchlayer->setPosition(ccp(100,50));
	//searchlayer content
	auto SettingItem = MenuItemImage::create(
                                           "setting_btn.png",
                                           "setting_btn_pu.png",
                                           CC_CALLBACK_1(MainScene::menuSettingCallback, this));
    
	SettingItem->setPosition(Vec2(origin.x +100 ,
		origin.y +visibleSize.height- 100));
    // create menu, it's an autorelease object
	auto menu = Menu::create(SettingItem,NULL);
    menu->setPosition(Vec2::ZERO);
	searchlayer->addChild(menu, 1);
	addChild(searchlayer);
}
void MainScene::menuListCallback(Ref* pSender)
{
	//get original state and change it 
	int oristate = MainScene::state;
	MainScene::state = 2; 
	//state 1:reading,2:list,3:search,4:setting
	if(oristate == 1)
	{
		readinglayer->removeAllChildrenWithCleanup(true);
	}
	else if(oristate == 2)
	{
		listlayer->removeAllChildrenWithCleanup(true);
	}
	else if(oristate == 3)
	{
		searchlayer->removeAllChildrenWithCleanup(true);
	}
	else if(oristate == 4)
	{
		settinglayer->removeAllChildrenWithCleanup(true);
	}
	//get size
	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//four layers,control by tuttons
	//search layer
	MainScene::listlayer = CCLayerGradient::create(ccc4(255, 255, 255, 255), ccc4(255, 255, 255, 255));
	MainScene::listlayer->setContentSize(CCSizeMake(300, 300));
	MainScene::listlayer->setPosition(ccp(100,50));
	addChild(listlayer);
}
void MainScene::menuSettingCallback(Ref* pSender)
{
	//get original state and change it 
	int oristate = MainScene::state;
	MainScene::state = 4; 
	//state 1:reading,2:list,3:search,4:setting
	if(oristate == 1)
	{
		readinglayer->removeAllChildrenWithCleanup(true);
	}
	else if(oristate == 2)
	{
		listlayer->removeAllChildrenWithCleanup(true);
	}
	else if(oristate == 3)
	{
		searchlayer->removeAllChildrenWithCleanup(true);
	}
	else if(oristate == 4)
	{
		settinglayer->removeAllChildrenWithCleanup(true);
	}
	//get size
	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//four layers,control by tuttons
	//search layer
	MainScene::settinglayer = CCLayerGradient::create(ccc4(255, 255, 255, 255), ccc4(255, 255, 255, 255));
	MainScene::settinglayer->setContentSize(CCSizeMake(300, 300));
	MainScene::settinglayer->setPosition(ccp(100,50));
	addChild(settinglayer);
}
