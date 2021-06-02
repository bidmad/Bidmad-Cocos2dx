#include "BannerSampleScene.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* BannerSampleScene::createScene()
{
    return BannerSampleScene::create();
}

Label* bannerCallbackLabel;

void onBannerLoad(char* zoneId)
{
    bannerCallbackLabel->setString("onBannerLoad");
}
void onBannerFail(char* zoneId)
{
    bannerCallbackLabel->setString("BannerFail");
}

bool BannerSampleScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    initBanner(); //Bidmad Banner Init
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto label = Label::createWithTTF("BidmadPlugin Sample", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    this->addChild(label, 1);

    bannerCallbackLabel = Label::createWithTTF("Callback Print", "fonts/Marker Felt.ttf", 20);
    bannerCallbackLabel->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
    bannerCallbackLabel->setColor(Color3B(71, 200, 62));
    this->addChild(bannerCallbackLabel, 1);
    
    int font_size = 15;

    auto back_btn = MenuItemFont::create("Back", CC_CALLBACK_0(BannerSampleScene::backScene, this));
    back_btn->setFontSizeObj(font_size);
    auto back_btn_menu = Menu::create(back_btn, NULL);
    back_btn_menu->alignItemsVertically();
    back_btn_menu->setPositionX(visibleSize.width-60);
    back_btn_menu->setPositionY(origin.y + visibleSize.height - label->getContentSize().height);
    back_btn_menu->setColor(Color3B(67, 116, 217));
    this->addChild(back_btn_menu);

    auto banner_load_btn = MenuItemFont::create("Banner Load", CC_CALLBACK_0(BannerSampleScene::loadBanner, this));
    banner_load_btn->setFontSizeObj(font_size);
    auto banner_remove_btn = MenuItemFont::create("Banner Remove", CC_CALLBACK_0(BannerSampleScene::removeBanner, this));
    banner_remove_btn->setFontSizeObj(font_size);
    auto banner_hide_btn = MenuItemFont::create("Banner Hide", CC_CALLBACK_0(BannerSampleScene::hideBanner, this));
    banner_hide_btn->setFontSizeObj(font_size);
    auto banner_show_btn = MenuItemFont::create("Banner Show", CC_CALLBACK_0(BannerSampleScene::showBanner, this));
    banner_show_btn->setFontSizeObj(font_size);

    auto bannerMenus = Menu::create(banner_load_btn, banner_remove_btn, banner_hide_btn, banner_show_btn, NULL);
    bannerMenus->alignItemsVertically();
    bannerMenus->alignItemsVerticallyWithPadding(30);
    bannerMenus->setPositionX(80);
    bannerMenus->setColor(Color3B(67, 116, 217));
    this->addChild(bannerMenus);

    return true;
}

void BannerSampleScene::initBanner()
{
    char *banner50 = (char*)"944fe870-fa3a-4d1b-9cc2-38e50b2aed43";

    //Banner Create
    bi = new BannerInterface(banner50);

    bi->setInterval(90);

    //Callback Setting
    bi->setOnLoadCallback(onBannerLoad);
    bi->setOnFailCallback(onBannerFail);
}
void BannerSampleScene::loadBanner()
{
    int posX = 150;
    int posY = 90;

    //bi->load(20);
    bi->load(posX, posY);
}
void BannerSampleScene::removeBanner()
{
    bi->removeBanner();
}
void BannerSampleScene::hideBanner()
{
    bi->hideBannerView();
}
void BannerSampleScene::showBanner()
{
    bi->showBannerView();
}

void BannerSampleScene::backScene()
{
    removeBanner();
    auto pScene = HelloWorld::createScene();
    Director::getInstance()->replaceScene(pScene);
}

bool BannerSampleScene::applicationDidFinishLaunching() {

}

void BannerSampleScene::applicationDidEnterBackground() {
    if(bi != nullptr)
        bi->onPause();
}

void BannerSampleScene::applicationWillEnterForeground() {
    if(bi != nullptr)
        bi->onResume();
}

