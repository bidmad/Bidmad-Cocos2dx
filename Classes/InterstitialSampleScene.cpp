#include "InterstitialSampleScene.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* InterstitialSampleScene::createScene()
{
    return InterstitialSampleScene::create();
}

Label* interstitialCallbackLabel;

void onInterstitialLoad(char* zoneId)
{
    interstitialCallbackLabel->setString("onInterstitialLoad");
}
void onInterstitialShow(char* zoneId)
{
    interstitialCallbackLabel->setString("onInterstitialShow");
}
void InterstitialClose(char* zoneId)
{
    interstitialCallbackLabel->setString("InterstitialClose");
}
void InterstitialFail(char* zoneId, char* errorInfo)
{
    interstitialCallbackLabel->setString("InterstitialFail");
}

bool InterstitialSampleScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    initInterstitial(); //Bidmad Interstitial Init

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto label = Label::createWithTTF("BidmadPlugin Sample", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    this->addChild(label, 1);

    interstitialCallbackLabel = Label::createWithTTF("Callback Print", "fonts/Marker Felt.ttf", 20);
    interstitialCallbackLabel->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
    interstitialCallbackLabel->setColor(Color3B(71, 200, 62));
    this->addChild(interstitialCallbackLabel, 1);
    
    int font_size = 15;

    auto back_btn = MenuItemFont::create("Back", CC_CALLBACK_0(InterstitialSampleScene::backScene, this));
    back_btn->setFontSizeObj(font_size);
    auto back_btn_menu = Menu::create(back_btn, NULL);
    back_btn_menu->alignItemsVertically();
    back_btn_menu->setPositionX(visibleSize.width-60);
    back_btn_menu->setPositionY(origin.y + visibleSize.height - label->getContentSize().height);
    back_btn_menu->setColor(Color3B(67, 116, 217));
    this->addChild(back_btn_menu);

    auto interstitial_load_btn = MenuItemFont::create("Interstitial Load", CC_CALLBACK_0(InterstitialSampleScene::loadInterstitial, this));
    interstitial_load_btn->setFontSizeObj(font_size);
    auto interstitial_show_btn = MenuItemFont::create("Interstitial Show", CC_CALLBACK_0(InterstitialSampleScene::showInterstitial, this));
    interstitial_show_btn->setFontSizeObj(font_size);

    auto interstitialMenus = Menu::create(interstitial_load_btn, interstitial_show_btn, NULL);
    interstitialMenus->alignItemsVertically();
    interstitialMenus->alignItemsVerticallyWithPadding(50);
    interstitialMenus->setPositionX(80);
    interstitialMenus->setColor(Color3B(67, 116, 217));
    this->addChild(interstitialMenus);

    return true;
}

void InterstitialSampleScene::initInterstitial()
{
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    char *interstitial = (char*)"228b95a9-6f42-46d8-a40d-60f17f751eb1";
    #elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    char *interstitial = (char*)"e9acd7fc-a962-40e4-aaad-9feab1b4f821";
    #endif
    
    //Interstitial Create
    ii = new InterstitialInterface(interstitial);

    // Bidmad Interstitial Ads auto-reload after the interstitial ad is shown to the user.
    // You can disable the auto-reload feature by giving "false" for setAutoReload method.
    // ii->setAutoReload(false); //Default true

    // CommonInterface can be set with Custom Unique ID with the following method.
    // CommonInterface::setCUID((char *)"SET CUID TEST");
    
    //Callback Setting
    ii->setOnLoadCallback(onInterstitialLoad);
    ii->setOnShowCallback(onInterstitialShow);
    ii->setOnFailCallback(InterstitialFail);
    ii->setOnCloseCallback(InterstitialClose);
}
void InterstitialSampleScene::loadInterstitial()
{
    ii->load();
}
void InterstitialSampleScene::showInterstitial()
{
    if(ii->isLoaded()){
        ii->show();
    }
}

void InterstitialSampleScene::backScene()
{
    auto pScene = HelloWorld::createScene();
    Director::getInstance()->replaceScene(pScene);
}
