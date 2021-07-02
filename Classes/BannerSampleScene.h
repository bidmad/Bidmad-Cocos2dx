#ifndef __BANNERSAMPLE_SCENE_H__
#define __BANNERSAMPLE_SCENE_H__

#include "cocos2d.h"
#include "bidmad/BannerInterface.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
class BannerSampleScene : public cocos2d::Scene
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
class BannerSampleScene : public cocos2d::Scene, Application
#endif
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    BannerInterface* bi;
    BannerInterface* bi2;

    void initBanner();
    void loadBanner();
    void removeBanner();
    void hideBanner();
    void showBanner();

    void backScene();

    // implement the "static create()" method manually
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    virtual bool applicationDidFinishLaunching();
    virtual void applicationDidEnterBackground();
    virtual void applicationWillEnterForeground();
#endif
    CREATE_FUNC(BannerSampleScene);
};

#endif // __BANNERSAMPLE_SCENE_H__
