
#include "HelloWorldScene.h"
#include "PluginApteligent/PluginApteligent.h"

USING_NS_CC;

class CustomListener : public sdkbox::ApteligentListener {
public:

    void onCrashOnLastLoad() {
        CCLOG("Apteligent: crashOnLastLoad.");
    }
};

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
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    CCLOG("Sample Startup");

    // add logo
    auto winsize = Director::getInstance()->getWinSize();
    auto logo = Sprite::create("Logo.png");
    auto logoSize = logo->getContentSize();
    logo->setPosition(Vec2(logoSize.width / 2,
                           winsize.height - logoSize.height / 2));
    addChild(logo);

    // add quit button
    auto label = Label::createWithSystemFont("QUIT", "sans", 32);
    auto quit = MenuItemLabel::create(label, [](Ref*){
        exit(0);
    });
    auto labelSize = label->getContentSize();
    quit->setPosition(Vec2(winsize.width / 2 - labelSize.width / 2 - 16,
                           -winsize.height / 2 + labelSize.height / 2 + 16));
    addChild(Menu::create(quit, NULL));

    // add test menu
    createTestMenu();

    return true;
}

void HelloWorld::createTestMenu()
{
    sdkbox::PluginApteligent::setListener(new CustomListener());

    //
    // sdkbox::PluginApteligent::sendAppLoadData();

    // filter
    sdkbox::PluginApteligent::addFilter("sensitiveURL");
    sdkbox::PluginApteligent::addFilter("additionalURL");

    sdkbox::PluginApteligent::setLoggingLevel(sdkbox::CRLoggingLevelInfo);
    sdkbox::PluginApteligent::setAsyncBreadcrumbMode(true);
    sdkbox::PluginApteligent::updateLocation(30.67, 104.06);

    sdkbox::PluginApteligent::setUsername("MrsCritter");
    sdkbox::PluginApteligent::setValueforKey("5", "Game Level");

    sdkbox::PluginApteligent::leaveBreadcrumb("User tapped start button");


    // flow test
    CCLOG("begin user flow: login");
    sdkbox::PluginApteligent::beginUserflow("login");
    float v = cocos2d::random(10, 100);
    if (v > 50) {
        CCLOG("end user flow: login");
        sdkbox::PluginApteligent::setValueforUserflow(int(CCRANDOM_0_1()*10), "login");
        int value = sdkbox::PluginApteligent::valueForUserflow("login");
        sdkbox::PluginApteligent::setValueforUserflow(value+5, "login");
        sdkbox::PluginApteligent::endUserflow("login");
    } else if (v > 30) {
        CCLOG("fail user flow: login");
        sdkbox::PluginApteligent::failUserflow("login");
    } else {
        CCLOG("cancel user flow: login");
        sdkbox::PluginApteligent::cancelUserflow("login");
    }


    // logging network requests
    sdkbox::PluginApteligent::logNetworkRequest("GET", "http://www.abc123def456.com", 2.0, 1000, 100, 200);


    auto size = Director::getInstance()->getWinSize();
    auto label = Label::createWithSystemFont("see console log", "arial", 64);
    label->setPosition(size/2);
    addChild(label);
}

