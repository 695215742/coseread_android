#include "MainScene.h"
#include "ui\UITextField.h"
#include "network/HttpClient.h"
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
    
	//http client
	cocos2d::network::HttpRequest* request = new cocos2d::network::HttpRequest();
	request->setUrl("http://www.coseread.herokuapp.com");
	request->setRequestType(cocos2d::network::HttpRequest::Type::GET);
	//request->setResponseCallback(CC_CALLBACK_2(HelloWorld::onHttpRequestCompleted,this));
	request->setTag("GET test");
	cocos2d::network::HttpClient::getInstance()->send(request);
	request->release();

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
void MainScene::menuNULLCallback(Ref* pSender)
{

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

	//add photo's menu
	auto PhotoItem = MenuItemImage::create(
                                           "photo_btn.png",
                                           "photo_btn.png",
                                           CC_CALLBACK_1(MainScene::menuNULLCallback, this));
    
	PhotoItem->setPosition(Vec2(origin.x+visibleSize.width/6,
		origin.y +visibleSize.height/4*3));
    // create menu, it's an autorelease object
	auto menu = Menu::create(PhotoItem,NULL);
    menu->setPosition(Vec2::ZERO);
	readinglayer->addChild(menu, 1);

	cocos2d::Label *username = Label::create("tourist","Î¢ÈíÑÅºÚ",30);
	username->setColor(ccc3(46, 117, 182));
	username->setPosition(Vec2(origin.x+visibleSize.width/6,
		origin.y +visibleSize.height/4*3-PhotoItem->getContentSize().height));
	readinglayer->addChild(username);
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

	MainScene::searchlayer = CCLayerGradient::create(ccc4(255, 255, 255, 255), ccc4(255, 255, 255, 255));
	MainScene::searchlayer->setContentSize(CCSizeMake(300, 300));
	MainScene::searchlayer->setPosition(ccp(100,50));
	//get size
	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//four layers,control by tuttons
	//search layer
	cocos2d::ui::TextField* textField = cocos2d::ui::TextField::create();
    textField->setTouchEnabled(true);
	textField->setFontName("Î¢ÈíÑÅºÚ");
    textField->setFontSize(40);
	textField->setColor(ccc3(46, 117, 182));
    textField->setPlaceHolder("input words here");
    textField->setPosition(Point(visibleSize.width *2/5, visibleSize.height / 4*3));
    searchlayer->addChild(textField);

	auto SearchLayerItem = MenuItemImage::create(
                                           "search_layer_btn.png",
                                           "search_layer_btn_pu.png",
                                           CC_CALLBACK_1(MainScene::menuSettingCallback, this));
    
	SearchLayerItem->setPosition(Vec2(origin.x+visibleSize.width*4/5,
		origin.y +visibleSize.height/4*3));
    // create menu, it's an autorelease object
	auto menu = Menu::create(SearchLayerItem,NULL);
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

	cocos2d::ui::TextField* username_txt = cocos2d::ui::TextField::create();
    username_txt->setTouchEnabled(true);
	username_txt->setFontName("Î¢ÈíÑÅºÚ");
    username_txt->setFontSize(40);
	username_txt->setColor(ccc3(46, 117, 182));
    username_txt->setPlaceHolder("input your username here");
    username_txt->setPosition(Point(visibleSize.width /2, visibleSize.height / 4*3));
    settinglayer->addChild(username_txt);

	cocos2d::ui::TextField* password_txt = cocos2d::ui::TextField::create();
    password_txt->setTouchEnabled(true);
	password_txt->setFontName("Î¢ÈíÑÅºÚ");
    password_txt->setFontSize(40);
	password_txt->setColor(ccc3(46, 117, 182));
    password_txt->setPlaceHolder("input your password here");
    password_txt->setPosition(Point(visibleSize.width /2, visibleSize.height / 4*2));
    settinglayer->addChild(password_txt);
	//add textarea
	auto VoiceItem = MenuItemImage::create(
                                           "voice_btn.png",
                                           "voice_btn_pu.png",
										   CC_CALLBACK_1(MainScene::menuCloseCallback, this));
	VoiceItem->setPosition(Vec2(origin.x+visibleSize.width/2,
		origin.y +visibleSize.height/6*4));
	auto SigninItem = MenuItemImage::create(
                                           "sign_in_btn.png",
                                           "sign_in_btn.png",
										   CC_CALLBACK_1(MainScene::menuCloseCallback, this));
	SigninItem->setPosition(Vec2(origin.x+visibleSize.width/3*2,
		origin.y +visibleSize.height/6*2));
	auto QuitItem = MenuItemImage::create(
                                           "close_btn.png",
                                           "qclose_btn_pu.png",
										   CC_CALLBACK_1(MainScene::menuCloseCallback, this));
	QuitItem->setPosition(Vec2(origin.x+visibleSize.width/3,
		origin.y +visibleSize.height/6*2));
    // create menu, it's an autorelease object
	auto menu = Menu::create(SigninItem,QuitItem,NULL);
    menu->setPosition(Vec2::ZERO);
	settinglayer->addChild(menu, 1);

	addChild(settinglayer);
}
void MainScene::SearchBookCallback(Ref* pSender)
{
	//central sprite action 
	RotateBy * titlerote = RotateBy::create (1, 180);
	//scene transite
}