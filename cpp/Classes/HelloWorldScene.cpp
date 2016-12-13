
#include "HelloWorldScene.h"
#include "PluginApteligent/PluginApteligent.h"

USING_NS_CC;

using namespace std;

std::vector<std::string> msgbuf;
static void showMsg(const std::string& msg) {
    //
    Label *label = dynamic_cast<Label*>(Director::getInstance()->getNotificationNode());
    if (label == nullptr) {
        auto size = Director::getInstance()->getWinSize();
        label = Label::createWithSystemFont("test", "arial", 16);
        label->setAnchorPoint(ccp(0,0));
        label->setTextColor(Color4B(0, 255, 0, 255));
        label->setPosition(10, size.height*0.1);
        Director::getInstance()->setNotificationNode(label);
    }

    static int index = 0;
    stringstream buf;
    buf << (index++) << " " << msg;
    msgbuf.push_back(buf.str());
    if (msgbuf.size() > 10) {
        msgbuf.erase(msgbuf.cbegin());
    }


    std::string text = "";

    for (int i = 0; i < msgbuf.size(); i++) {
        stringstream buf;
        buf << msgbuf[i] << "\n";
        text = text + buf.str();
    }

    label->setString(text);
}

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
    auto label = Label::createWithSystemFont("see console log for more detail", "arial", 32);
    label->setPosition(Vec2(size.width/2, 100));
    addChild(label);
    
    MenuItemFont::setFontSize(48);
    
    Menu *menu = Menu::create(MenuItemFont::create("Test Crash 1", CC_CALLBACK_1(HelloWorld::onCreateCrash, this)),
                              MenuItemFont::create("Test Crash 2", CC_CALLBACK_1(HelloWorld::onCreateCrash2, this)),
                              NULL);
    menu->alignItemsVerticallyWithPadding(5);
    menu->setPosition(Vec2(size.width/2, size.height/2));

    stringstream buf;
    buf << (sdkbox::PluginApteligent::didCrashOnLastLoad() ? "crashed" : "no crash");
    showMsg(buf.str());
    
    addChild(menu);
}

void HelloWorld::onCreateCrash(cocos2d::Ref* sender)
{
    Node* empty_node;
    empty_node->getName();
}

void HelloWorld::onCreateCrash2(cocos2d::Ref* sender)
{
    int infinity = 1/0;
}
