#ifndef __BANNERSAMPLE_SCENE_H__
#define __BANNERSAMPLE_SCENE_H__

#include "cocos2d.h"
#include "bidmad/BannerInterface.h"

class BannerSampleScene : public cocos2d::Scene, Application
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
    virtual bool applicationDidFinishLaunching();
    virtual void applicationDidEnterBackground();
    virtual void applicationWillEnterForeground();
    CREATE_FUNC(BannerSampleScene);
};

#endif // __BANNERSAMPLE_SCENE_H__
